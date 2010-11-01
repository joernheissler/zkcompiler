/* each symbol in the grammar has a type and sometimes additional data. Different symbol types have different data types: */
%union {
    struct stringlist    *stringlist;
    struct expression    *expression;
    char                 *string;
    struct group         *group;
    struct grouplist     *grouplist;
    struct var           *var;
    struct hom           *hom;
}

/* track locations for better error messages */
%locations

/* make parser reentrant */
%define api.pure

/* add parameters to zkparse() function.
 * sl is the pointer to the resulting data structure
 * state is the lexer state (contains e.g. pushback buffer )
 * ps is additional state of the parser, e.g. current group or stack of expressions
 */
%parse-param { struct statementlist  *sl    }
%parse-param { struct zk_lexstate    *state }
%parse-param { struct zk_parserstate *ps    }

/* lexer needs access to its state */
%lex-param   { struct zk_lexstate    *state }

/* define terminal symbols.
 * INVALID = lexer error (unexpected EOF, read error, etc.)
 * NUL = null character
 * STRING,ASTRING,NUMBER = different string types
 */
%token                INVALID
%token                NUL
%token <string>       STRING        ASTRING     NUMBER

/* define associativity */
%left '+' '-' '^'
%right ':'

/* define data types for nonterminal symbols */
%type <stringlist>    numberlist stringlist
%type <expression>    expr addexpr powexpr castexpr unaryexpr dotexpr atomexpr exprlist constexp tmpvar
%type <string>        string string2 ident
%type <group>         group
%type <grouplist>     grouplist
%type <var>           variable
%type <hom>           hom

/* define destructor functions. Some types must not be listed here! */
%destructor {    stringlist_destruct($$); } <stringlist>
%destructor {    expression_destruct($$); } <expression>
%destructor {     grouplist_destruct($$); } <grouplist>
%destructor {        string_destruct($$); } <string>

%{

/* evaluate `cond' once.
   If it's false, print the location of the symbol and evaluate `msg'.
   execute `code', regardless of cond.
   if cond is false, call YYABORT.

   msg and code are optional.
*/
#define ASRT(cond, loc, msg, code) {                  \
    int fail = !(cond);                               \
    if(fail) {                                        \
        fprintf(stderr, "In input %d:%d - %d:%d",  \
                (loc).first_line, (loc).first_column, \
                (loc).last_line, (loc).last_column);  \
        msg;                                          \
        fprintf(stderr, "\n");                        \
    }                                                 \
    code;                                             \
    if(fail) YYABORT;                                 \
}

/* alias for fprintf(stderr, " : "); fprintf(stderr, fmt, ...); */
static void ERR(const char *fmt, ...)
{
    va_list ap;
    fprintf(stderr, " : ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

static int zklex(YYSTYPE *lvalp, YYLTYPE *loc, struct zk_lexstate *ls);
static void zkerror(YYLTYPE *loc, struct statementlist *sl, struct zk_lexstate *ls, struct zk_parserstate *ps, char const *s);

%}

/* the grammar follows.
   Every action (that within { }) converts the input ($1,$2,...) into a new variable $$.
   If an error occurs, all resources used by the variables must be freed and YYABORT called (done if ASRT(false) is called).
   Else $$ must be set and all resources not used by $$ must be freed. I.e. if $$ were freed after this, all resources would be freed.
 */

%%

statementlist   :/* empty */                           { /* noop */                                                      }
                |statementlist statement ';'           { /* noop */                                                      }
;
statement       :ident '=' ident '(' stringlist ')'    { ASRT(statement_atomicgroup(sl, $1, $3, $5), @$,,);              }
                |ident '=' '(' grouplist ')'           { ASRT(statement_tuplegroup(sl, $1, $4), @$,,);                   }
                |group ':'                             { ps->vgrp = $1;                                                  }
                  varlist                              { /* noop */                                                      }
                |ident '[' group '-' '>' group ']' '=' { ps->sgrp = $3; ASRT(!ps->tmp, @$,,);                            }
                  expr                                 { ASRT(!ps->tmp, @$,,);
                                                         ASRT(statement_hom(sl, ps, $1, $3, $6, $10), @$,,);             }
                |ident '=' ident '[' stringlist ']'    { ASRT(statement_sigma(sl, $1, $3, $5), @$,,);                    }
;
varlist         :var                                   { /* noop */                                                      }
                |varlist ',' var                       { /* noop */                                                      }
;
var             :ident                                 { ASRT(statement_var(sl, ps->vgrp, $1,  0,  0), @$,,);            }
                |ident '=' NUMBER                      { ASRT(statement_var(sl, ps->vgrp, $1, $3,  0), @$,,);            }
                |ident '=' '(' numberlist ')'          { ASRT(statement_var(sl, ps->vgrp, $1,  0, $4), @$,,);            }
;
expr            :expr ':'                              { $1->prev = ps->tmp; ps->tmp = $1; /* push $1 onto stack */      }
                  expr                                 { struct expression *tmp = ps->tmp->prev; /* pop $1 from stack */
                                                         expression_destruct(ps->tmp); ps->tmp = tmp; $$ = $4;           }
                |addexpr                               { $$ = $1;                                                        }
;
addexpr         :addexpr '+' addexpr                   { ASRT($$ = expression_op($1, $3), @$,,);                         }
                |addexpr '-' addexpr                   { ASRT($$ = expression_iop($1, $3), @$,,);                        }
                |powexpr                               { $$ = $1;                                                        }
;
powexpr         :powexpr '^' powexpr                   { ASRT($$ = expression_pow($1, $3), @$,,);                        }
                |powexpr '^' constexp                  { ASRT($$ = expression_pow($1, $3), @$,,);                        }
                |castexpr                              { $$ = $1;                                                        }
;
castexpr        :'<' group '>' castexpr                { ASRT($$ = expression_cast($2, $4), @$,,);                       }
                |unaryexpr                             { $$ = $1;                                                        }
;
unaryexpr       :'-' unaryexpr                         { ASRT($$ = expression_inv($2), @$,,);                            }
                |dotexpr                               { $$ = $1;                                                        }
;
dotexpr         :dotexpr '.' NUMBER                    { ASRT($$ = expression_dot($1, $3), @$,,);                        }
                |atomexpr                              { $$ = $1;                                                        }
;
atomexpr        :'(' expr ')'                          { $$ = $2;                                                        }
                |'$'                                   { ASRT($$ = expression_src(ps->sgrp), @$,,);                      }
                |tmpvar                                { ASRT($$ = expression_tmp($1), @$,,);                            }
                |variable                              { ASRT($$ = expression_var($1), @$,,);                            }
                |hom '(' expr ')'                      { ASRT($$ = expression_hom($1->tree, $1->src, $3), @$,,);         }
                |group '{' numberlist '}'              { ASRT($$ = expression_const(sl, $1, $3), @$,,);                  }
                |'[' exprlist ']'                      { $$ = $2;                                                        }
                |'?' group                             { ASRT($$ = expression_rnd($2),@$,,);                             }
                |'<' group                             { ASRT($$ = expression_min($2),@$,,);                             }
                |'>' group                             { ASRT($$ = expression_max($2),@$,,);                             }
                |'~' group                             { ASRT($$ = expression_id ($2),@$,,);                             }
;
tmpvar          :'#'                                   { ASRT($$ = ps->tmp, @$, ERR("no tmpvar available"),);            }
                |tmpvar '#'                            { ASRT($$ = $1->prev, @$, ERR("no tmpvar available"),);           }
;
constexp        :NUMBER                                { ASRT($$ = expression_constexp(sl, $1), @$,,);                   }
;
exprlist        :expr                                  { ASRT($$ = exprlist_new($1), @$,,);                              }
                |exprlist ',' expr                     { ASRT($$ = exprlist_append($1, $3), @$,,);                       }
;
grouplist       :group                                 { ASRT($$ = grouplist_new($1), @$,,);                             }
                |grouplist ',' group                   { ASRT($$ = grouplist_append($1, $3), @$,,);                      }
;
group           :string2                               { ASRT($$ = zkparser_get_group(sl, $1), @$,
                                                         ERR("Unknown Group '%s'", $1), string_destruct($1));            }
;
variable        :string2                               { ASRT($$ = zkparser_get_var(sl, $1), @$,
                                                         ERR("Unknown Variable '%s'", $1), string_destruct($1));         }
;
hom             :string2                               { ASRT($$ = zkparser_get_hom(sl, $1), @$,
                                                         ERR("Unknown Homomorphism '%s'", $1), string_destruct($1));     }
;
stringlist      :string                                { ASRT($$ = stringlist_new($1), @$,,);                            }
                |stringlist ',' string                 { ASRT($$ = stringlist_append($1, $3), @$,,);                     }
;
numberlist      :NUMBER                                { ASRT($$ = stringlist_new($1), @$,,);                            }
                |numberlist ',' NUMBER                 { ASRT($$ = stringlist_append($1, $3), @$,,);                     }
;
ident           :ASTRING                               { $$ = $1;                                                        }
;
string          :STRING                                { $$ = $1;                                                        }
                |ASTRING                               { $$ = $1;                                                        }
                |NUMBER                                { $$ = $1;                                                        }
;
string2         :STRING                                { $$ = $1;                                                        }
                |ASTRING                               { $$ = $1;                                                        }
;
