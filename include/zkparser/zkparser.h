#ifndef ZK_ZKPARSER_H
#define ZK_ZKPARSER_H

/** \brief incomplete definition of struct expression **/
struct expression;

/** \brief array of strings **/
struct stringlist {
    /** \brief number of strings in array **/
    unsigned n;

    /** \brief array of strings. All strings must be allocated and freeable with free() **/
    char **s;
};

union userdata {
    int i;
    void *p;
    char *s;
};

/** \brief represents a group as defined in the input
 *
 * if type == group_atomic, `atomic' and `l' must be set
 * if type == group_tuple, `n' and `sub' must be set
 **/
struct group {
    /** \brief type of group **/
    enum group_type {
        /** \brief group defined by the user, e.g. "Z" or "Z_mul_n" **/
        group_atomic,
        /** \brief cartesian product of other groups **/
        group_tuple
    } type;

    /** \brief unique name of group **/
    char *name;

    /** \brief family of groups, e.g. "Z" or "Z_mul_n". "Z" must exist **/
    char *atomic;

    /** \brief parameters used for atomic group **/
    struct stringlist *l;

    /** \brief number of groups in array `sub' **/
    unsigned n;

    /** \brief array of group pointers. All groups must be in statementlist as well **/
    struct group **sub;

    /** \brief to be used by the user **/
    union userdata ud;
};

/** \brief represents a variable as defined in the input, or an anonymous variable **/
struct var {
    /** \brief unique name of variable **/
    char *name;

    /** \brief group this varibable is in **/
    struct group *g;

    /** \brief initializer of variable (optional) **/
    struct stringlist *init;

    /** \brief to be used by the user **/
    union userdata ud;
};

/** \brief reference to a variable
 **
 ** Each object of this type must be used only by one other object.
 **/
struct varref {
    /** \brief type of variable referenced **/
    enum var_type {
        /** \brief Source of homomorphism **/
        var_src,

        /** \brief Destination of homomorphism **/
        var_dst,

        /** \brief The variable referenced by `v' **/
        var_var 
    } type;

    /** \brief A variable. Only with type == var_var **/
    struct var *v;

    /** \brief subscript depth of variable, number of elements in array **/
    unsigned ns;

    /** Array of subscripts of variable **/
    unsigned *s;
};

/** \brief a node in the expr-list; represents a single operation **/
struct expr {
    /** \brief next operation (currently: previous!!) **/
    struct expr *next;

    /** \brief group of result **/
    struct group *g;

    /** \brief reference to destination variable **/
    struct varref *dst;

    /** \brief type of expr **/
    enum expr_type {
        /** \brief set dst to the identity in the group **/
        expr_id,

        /** \brief set dst to minimum in the group **/
        expr_min,

        /** \brief set dst to maximum in the group **/
        expr_max,

        /** \brief set dst to inverse of `a' **/
        expr_inv,

        /** \brief set dst to `a' OP `b' **/
        expr_op,
        
        /** \brief set dst to `a' IOP `b' **/
        expr_iop,
        
        /** \brief set dst to `a' ^ `b' **/
        expr_pow,
        
        /** \brief set dst to `a' ^- `b' **/
        expr_ipow,
        
        /** \brief set dst to a random element in the group **/
        expr_rnd,

        /** \brief set dst to `a' **/
        expr_set,

        /** \brief set dst to `a', groups may differ **/
        expr_cast
    } type;

    /** \brief first operand **/
    struct varref *a;
    
    /** \brief second operand **/
    struct varref *b;
};

/** \brief homomorphism **/
struct hom {
    /** \brief unique name of homomorphism **/
    char *name;

    /** \brief source group of homomorphism */
    struct group *src;
    
    /** \brief destination group of homomorphism */
    struct group *dst;
    
    /** \brief number of nodes in expr-list **/
    unsigned n;

    /** \brief expr-list (currently backwards!) **/
    struct expr *e;

    /** \brief opaque pointer to internal representation of hom
     *
     * To handle the "hom(expr)" syntax we need access to the expression tree of the called
     * homomorphism.
     **/
    struct expression *tree;

    /** \brief to be used by the user **/
    union userdata ud;
};

/** \brief sigma protocol **/
struct sigma {
    /** \brief unique name of sigma protocol **/
    char *name;

    /** \brief sigma protocol to use **/
    char *type;

    /** \brief nonempty list of parameters **/
    struct stringlist *l;

    /** \brief to be used by the user **/
    union userdata ud;
};

/** \brief callbacks to retrieve external parser objects **/
struct identifier_callbacks {
    /** \brief arg to pass to the callbacks **/
    void *arg;

    /** \brief callback to call for groups; may be NULL **/
    struct group *(*get_group)(void *arg, unsigned long id);

    /** \brief callback to call for vars; may be NULL **/
    struct var *(*get_var)(void *arg, unsigned long id);

    /** \brief callback to call for homs; may be NULL **/
    struct hom *(*get_hom)(void *arg, unsigned long id);

    /** \brief callback to call for sigmas; may be NULL **/
    struct sigma *(*get_sigma)(void *arg, unsigned long id);
};

/** \brief data structure generated by zkparser **/
struct statementlist {
    /** \brief number of groups in array **/
    unsigned ngroups;
    /** \brief array of all defined groups **/
    struct group **groups;

    /** \brief number of variables in array **/
    unsigned nvars;
    /** \brief array of all defined variables; homomorphisms may add anonymous variables **/
    struct var **vars;

    /** \brief number of homomorphisms in array **/
    unsigned nhoms;
    /** \brief array of all defined homomorphisms **/
    struct hom **homs;

    /** \brief number of sigmas in array **/
    unsigned nsigmas;
    /** \brief array of all defined sigmas **/
    struct sigma **sigmas;

    /** \brief callbacks to retrieve external parser objects **/
    struct identifier_callbacks idcb;
};

/** \brief parse an input file
 **
 ** \param getchr function pointer to a function which returns the next character converted to unsigned char or EOF
 ** \param arg argument to be passed to getchr function
 ** \param idcb callbacks to lookup identifiers. May be NULL.
 ** \return pointer to struct statementlist or NULL on error
 **/
struct statementlist *zkparser_parse(int(*getchr)(void *), void *arg, struct identifier_callbacks *idcb);

/** \brief free ressources used by statementlist
 **
 ** \param sl pointer to statementlist which is to be freed
 **/
void zkparser_free(struct statementlist *sl);

/** \brief get group by name
 **
 ** \param sl pointer to statementlist
 ** \param name name of group
 ** \return pointer to group or NULL if it does not exist
 **/
struct group *zkparser_get_group(struct statementlist *sl, const char *name);

/** \brief get var by name
 **
 ** \param sl pointer to statementlist
 ** \param name name of var
 ** \return pointer to var or NULL if it does not exist
 **/
struct var   *zkparser_get_var  (struct statementlist *sl, const char *name);

/** \brief get hom by name
 **
 ** \param sl pointer to statementlist
 ** \param name name of hom
 ** \return pointer to hom or NULL if it does not exist
 **/
struct hom   *zkparser_get_hom  (struct statementlist *sl, const char *name);

/** \brief get sigma by name
 **
 ** \param sl pointer to statementlist
 ** \param name name of sigma
 ** \return pointer to sigma or NULL if it does not exist
 **/
struct sigma *zkparser_get_sigma(struct statementlist *sl, const char *name);

void zkparser_dump(struct statementlist *sl);

#endif
