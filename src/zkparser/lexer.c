/* return next character from the pushback buffer or from the stream */
static struct lex_char nextchr(struct zk_lexstate *ls)
{
    struct lex_char c;

    /* return character from pushback buffer is possible */
    if(ls->n) return ls->p[--ls->n];

    /* retrieve character from stream using callback function */
    c.c = ls->getchr(ls->arg);
    c.line = ls->line;
    c.column = ls->column;

    /* update position (line / column) of input file */
    if(c.c == '\n') {
        ++ls->line;
        ls->column = 1;
    } else {
        ++ls->column;
    }
    return c;
}

/* finate state machine which returns the next character of the input stream which does not belong to a comment */
static struct lex_char nextchar(struct zk_lexstate *ls)
{
    struct lex_char c,slash;
    enum { NC_DEFLT, NC_SLASH, NC_DSLSH, NC_MLCMT, NC_ASTRX } s = NC_DEFLT;
    for(;;) {
        c = nextchr(ls);
        switch(s) {
            case NC_DEFLT: switch(c.c) {
                case '/': s = NC_SLASH; slash = c; break;
                default: return c;
            } break;

            case NC_SLASH: switch(c.c) {
                case '/': s = NC_DSLSH; break;
                case '*': s = NC_MLCMT; break;
                case EOF: return slash;
                default: ls->p[ls->n++] = c; return slash; /* push back c and return '/' */
            } break;

            case NC_DSLSH: switch(c.c) {
                case '\r': case '\n': s = NC_DEFLT; break;
                case EOF: return c;
                default: break;
            } break;

            case NC_MLCMT: switch(c.c) {
                case '*': s = NC_ASTRX; break;
                case EOF: c.c = INVALID; return c;
                default: break;
            } break;

            case NC_ASTRX: switch(c.c) {
                case '/': s = NC_DEFLT; break;
                case '*': break;
                case EOF: c.c = INVALID; return c;
                default: s = NC_MLCMT; break;
            } break;
        }
    }
}

#define ALPHA \
'_': \
case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': \
case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z': \
case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': \
case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z'

#define NUM '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9'

/* return next token
 * return value is:
 * 0       = EOF
 * NUL     = null character
 * INVALID = error (allocation or invalid comment syntax)
 * NUMBER  = decimal number with optional leading '-', string is passed in lvalp->string
 * ASTRING = string which begins with a-zA-Z, string is passed in lvalp->string
 * STRING  = all other strings, string is passed in lvalp->string
 * 'x'     = all other characters
 */
static int zklex(YYSTYPE *lvalp, YYLTYPE *loc, struct zk_lexstate *ls)
{
    struct lex_char c;
    char *string = 0, *tmp;
    unsigned len = 0;
    enum { LEX_START, LEX_MINUS, LEX_ALPHA, LEX_NUMBR } s = LEX_START;

    for(;;) {
        c = nextchar(ls);
        if(isspace(c.c)) continue;

        switch(s) {
            case LEX_START:
                /* initialize location. This code is run exactly once. */
                loc->first_line   = loc->last_line   = c.line;
                loc->first_column = loc->last_column = c.column;
                switch(c.c) {
                    case 0    : return NUL;
                    case ALPHA: s = LEX_ALPHA; break;
                    case NUM  : s = LEX_NUMBR; break;
                    case '-'  : s = LEX_MINUS; continue;
                    case EOF  : return 0;
                    default   : return c.c;
                } break;

            case LEX_MINUS: switch(c.c) {
                case NUM  : s = LEX_NUMBR;
                            /* initialize string with "-" */
                            if(!MALLOC(string, 2)) return INVALID;
                            string[len++] = '-';
                            string[len] = 0;
                            break;
                default   : ls->p[ls->n++] = c; /* push back c */
                            return '-';
            } break;

            case LEX_NUMBR: switch(c.c) {
                case ALPHA: s = LEX_ALPHA; break;
                default   : break;
            } /* fall through */

            case LEX_ALPHA: switch(c.c) {
                case ALPHA: break;
                case NUM  : break;
                default   : ls->p[ls->n++] = c; /* push back c */
                            lvalp->string = string;
                            return (s == LEX_NUMBR) ? NUMBER : (string[0] < '0' || string[0] > '9') && string[0] != '_' ? ASTRING : STRING;
            } break;
        }

        /* append c to string */
        if(!REALLOC(string, tmp, len + 2)) {
            free(string);
            return INVALID;
        }
        string[len++] = (char)c.c;
        string[len] = 0;
        loc->last_line = c.line;
        loc->last_column = c.column;
    }
}
