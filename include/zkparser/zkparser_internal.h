#ifndef ZK_ZKPARSER_INTERNAL_H
#define ZK_ZKPARSER_INTERNAL_H

/** \brief additional information kept by parser while parsing **/
struct zk_parserstate {
    /** \brief group for variable definitions
     *
     * This is set as soon as a variable definition begins (after ':' is read).
     * after the variable name (+ optional initializer) is read, this is used to
     * create the variable before the statement is even finished. Removes the need
     * for another data structure
     **/
    struct group *vgrp;

    /** \brief source group of current homomorphism
     *
     * As the expression/node tree is created while reading the expressions, we need
     * the source group for handling the "$" case.
     **/
    struct group *sgrp;

    /** \brief stack of temporary expressions, used for "expr : expr" syntax.
     *
     * Must be 0 before and after each homomorphism definition. The previous element in
     * the stack is tmp->prev.
     * In case of parser error, this might still be set and needs to be cleaned up after
     * parser finishes.
     **/
    struct expression *tmp;
};

/** \brief array of groups used for creating a tuple group **/
struct grouplist {
    /** \brief number of groups in array **/
    unsigned n;

    /** \brief the array of groups **/
    struct group **g;
};

/** \brief node of the tree built to represent a homomorphism
 *
 * A homomorphism is represented as an acyclic graph (or tree) of nodes where each root
 * (node without successor) represents an output variable of the homomorphism.
 * Each node has a type and an atomic group.
 **/
struct node {
    /** \brief type of node
     **
     ** the semantics are the same as for the `struct expr' type with exception for `expr_set'.
     ** expr_set here means a variable reference.
     **/
    enum expr_type type;

    /** \brief group of the node (result after computation). Must be set for all types.
     ** Only atomic groups may be used here. */
    struct group *g;

    /** \brief first operand for computations
     ** used by expr_op, expr_iop, expr_pow, expr_ipow, expr_inv, expr_cast
     **/
    struct node *a;

    /** \brief second operand for computations
     ** used by expr_op, expr_iop, expr_pow, expr_ipow
     **/
    struct node *b;

    /** \brief Variable reference for expr_set type
     **
     ** only var_src and var_var are valid, both with subscript
     **/
    struct varref *v;

    /** \brief reference counter
     **
     ** a new node has refcount == 1.
     ** node_use() increases count by 1
     ** node_destruct() decreases count by 1. If it falls to 0, node is actually destructed
     **/
    unsigned refcount;

    /** \brief variable reference used by convert_tree_to_list()
     **
     ** If converted to a linear list of expr, every node needs a variable where
     ** the result is to be stored.
     ** Only var_var without subscript and var_dst with subscript are allowed.
     **/
    struct varref *dst;

    /** \brief pointer to copy of this node
     **
     ** Used by node_copy which is needed for "hom(expr)" syntax
     **/
    struct node *cn;
};

/** \brief Tree of expressions to represent arbitrary group elements
 **
 ** Either `leaf' or (`n' and `childs') must be set.
 **/
struct expression {
    /** \brief used by `struct zk_parserstate' to represent a stack of expressions **/
    struct expression *prev;

    /** \brief pointer to a node **/
    struct node *leaf;

    /** \brief number of childs in childs array **/
    unsigned n;

    /** \brief child array **/
    struct expression **childs;
};

/** \brief current state of character input function **/
struct zk_lexstate {
    /** \brief callback to get next character from input **/
    int(*getchr)(void *);

    /** \brief argument to getchr, e.g. a FILE pointer **/
    void *arg;

    /** \brief line of next character to be read. First line in a file is 1. **/
    int line;

    /** \brief column of next character to be read. First column in a line is 1. **/
    int column;

    /** \brief number of characters in pushback buffer **/
    int n;

    /** \brief pushback buffer
     *
     * If one character is in buffer, it's p[0]
     * If two characters are in buffer, p[1] is read before p[0]
     **/
    struct lex_char {
        /** \brief character as retrieved from getchr **/
        int c;

        /** \brief line of this character **/
        int line;

        /** \brief column of this character **/
        int column;
    } p[2];
};

/** \brief append hom to statementlist
 **
 ** \param sl statementlist
 ** \param h homomorphism
 ** \return 0 == fail, 1 == success
 **/
static int statementlist_append_hom(struct statementlist *sl, struct hom *h);

/** \brief append group to statementlist
 **
 ** \param sl statementlist
 ** \param g group
 ** \return 0 == fail, 1 == success
 **/
static int statementlist_append_group(struct statementlist *sl, struct group *g);

/** \brief append variable to statementlist
 **
 ** \param sl statementlist
 ** \param v variable
 ** \return 0 == fail, 1 == success
 **/
static int statementlist_append_var(struct statementlist *sl, struct var *v);

/** \brief append sigma to statementlist
 **
 ** \param sl statementlist
 ** \param s sigma
 ** \return 0 == fail, 1 == success
 **/
static int statementlist_append_sigma(struct statementlist *sl, struct sigma *s);

#endif
