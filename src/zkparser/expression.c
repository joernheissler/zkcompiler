/** \brief destruct an expression
 ** \param e expression to destruct
 **/
static void expression_destruct(struct expression *e)
{
    unsigned i;
    if(!e) return;
    node_destruct(e->leaf);
    for(i = 0; i < e->n; ++i) expression_destruct(e->childs[i]);
    free(e->childs);
    free(e);
}

/** \brief create new expression
 ** \param leaf leaf node (consumed)
 ** \param n size of childs array
 ** \param childs array of size (consumed)
 ** \return new expression or 0 on error
 **/
static struct expression *expression_new(struct node *leaf, unsigned n, struct expression **childs)
{
    struct expression *e;

    /* If leaf is  set, neither n nor childs  is set.
     * If leaf is not set, both n and childs are set. */
    ASSERT(!n == !childs && !n != !leaf);

    if(!MALLOC(e, 1)) {
        unsigned i;
        node_destruct(leaf);
        for(i = 0; i < n; ++i) expression_destruct(childs[i]);
        free(childs);
        return 0;
    }
    e->prev = 0;
    e->leaf = leaf;
    e->n = n;
    e->childs = childs;

    return e;
}

/** \brief recursive algorithm to create a var node for each leaf
 ** \param v optional variable
 ** \param g group
 ** \param ns depth of recursion / number of subscripts (first level == 0)
 ** \param s pointer to (first element of) array of ns subscripts
 ** \return expression or 0 on error
 **/
static struct expression *expression_var2(struct var *v, struct group *g, unsigned ns, unsigned **s)
{
    unsigned i, *tmp;
    struct expression **childs;

    ASSERT(g && s);
    /* if group type is atomic, create var node and return leaf node */
    if(g->type == group_atomic) {
        struct node *node = node_var(v, g, ns, *s);
        return node ? expression_new(node, 0, 0) : 0;
    }

    if(!REALLOC(*s, tmp, ns + 1)) return 0;
    if(!MALLOC(childs, g->n)) return 0;

    /* create array of g->n childs */
    for(i = 0; i < g->n; ++i) {
        (*s)[ns] = i;
        childs[i] = expression_var2(v, g->sub[i], ns + 1, s);
        if(!childs[i]) goto err;
    }
    /* create and return expression */
    return expression_new(0, g->n, childs);

err:
    /* clean up in case of error */
    while(i--) expression_destruct(childs[i]);
    free(childs);
    return 0;
}

/* helper function, v is optional, g mandatory */
static struct expression *expression_var1(struct var *v, struct group *g)
{
    /* define dynamic array which is reallocated by expression_var2() */
    unsigned *s = 0;
    struct expression *e = expression_var2(v, g, 0, &s);
    free(s);
    return e;
}

/** \brief create variable expression
 ** \param v variable
 ** \return pointer to new expression or 0 on error
 **/
static struct expression *expression_var(struct var *v)
{
    return expression_var1(v, v->g);
}

/** \brief create src expression
 ** \param g group of source
 ** \return pointer to new expression or 0 on error
 **/
static struct expression *expression_src(struct group *g)
{
    return expression_var1(0, g);
}

/** \brief create constant expression
 ** \param sl statementlist
 ** \param g group of variable
 ** \param init initializer (consumed)
 ** \return pointer to new expression or 0 on error
 **
 ** first create anonymous varibale, then handle it the same as a real variable definition
 **/
static struct expression *expression_const(struct statementlist *sl, struct group *g, struct stringlist *init)
{
    struct var *v;
    ASSERT(init);
    v = anon_var(sl, g, init);
    return v ? expression_var1(v, g) : 0;
}

/** \brief create new expression list
 ** \param e first child of expression (consumed)
 ** \return new expression or 0 on error
 **/
static struct expression *exprlist_new(struct expression *e)
{
    struct expression **childs;
    ASSERT(e);
    if(!MALLOC(childs, 1)) {
        expression_destruct(e);
        return 0;
    }
    childs[0] = e;
    return expression_new(0, 1, childs);
}

/** \brief append expression to expression list
 ** \param l expression list (consumed)
 ** \param e new child of expression (consumed)
 ** \return l or 0 on error
 **/
static struct expression *exprlist_append(struct expression *l, struct expression *e)
{
    struct expression **tmp;
    ASSERT(l && e);
    if(!REALLOC(l->childs, tmp, l->n + 1)) {
        expression_destruct(l);
        expression_destruct(e);
        return 0;
    }
    l->childs[l->n++] = e;
    return l;
}

/** \brief create expression for group functions (rnd,max,min,id) without parameters
 ** \param fptr pointer to function (struct group *g) returning pointer to struct node
 ** \param g group of node
 **/
static struct expression *expression_group(struct node *(*fptr)(struct group *), struct group *g)
{
    unsigned i;
    struct expression **childs;

    ASSERT(fptr && g);
    /* if g is atomic, create a node with the function pointer and return leaf expression */
    if(g->type == group_atomic) {
        struct node *node = fptr(g);
        return node ? expression_new(node, 0, 0) : 0;
    }

    if(!MALLOC(childs, g->n)) return 0;

    /* create array of g->n child expressions */
    for(i = 0; i < g->n; ++i) {
        childs[i] = expression_group(fptr, g->sub[i]);
        if(!childs[i]) goto err;
    }
    return expression_new(0, g->n, childs);
err:
    /* clean up in case of error */
    while(i--) expression_destruct(childs[i]);
    free(childs);
    return 0;
}

/** \brief create rnd expression
 ** \param g group
 **/
static struct expression *expression_rnd(struct group *g)
{
    return expression_group(node_rnd, g);
}

/** \brief create max expression
 ** \param g group
 **/
static struct expression *expression_max(struct group *g)
{
    return expression_group(node_max, g);
}

/** \brief create min expression
 ** \param g group
 **/
static struct expression *expression_min(struct group *g)
{
    return expression_group(node_min, g);
}

/** \brief create id expression
 ** \param g group
 **/
static struct expression *expression_id(struct group *g)
{
    return expression_group(node_id, g);
}

/** \brief return subscript of expression; destruct the others
 ** \param e expression to get subscript from (consumed)
 ** \param k subscript in decimal representation (consumed)
 ** \return subscript of e or 0 on error
 **/
static struct expression *expression_dot(struct expression *e, char *k)
{
    unsigned long x;
    struct expression *f;
    int err;

    ASSERT(e && k);
    /* decode decimal number */
    errno = 0;
    x = strtoul(k, 0, 0);
    err = errno;

    string_destruct(k);
    /* check if number is valid */
    if(err || x >= e->n) {
        fprintf(stderr, "invalid subscript\n");
        expression_destruct(e);
        return 0;
    }

    /* save the child and destruct everything else */
    f = e->childs[x];
    e->childs[x] = 0;
    expression_destruct(e);
    return f;
}

/** \brief add expr_inv node after each node, update leafs of expression tree
 ** \param e expression to invert (consumed)
 ** \return e on success or 0 on error
 **/
static struct expression *expression_inv(struct expression *e)
{
    unsigned i;

    ASSERT(e);
    /* if leaf, append inv node after it and update expression */
    if(e->leaf) {
        e->leaf = node_inv(e->leaf);
        if(!e->leaf) goto err;
        return e;
    }

    /* run this function on every child node */
    for(i = 0; i < e->n; ++i) {
        e->childs[i] = expression_inv(e->childs[i]);
        if(!e->childs[i]) goto err;
    }
    return e;
err:
    /* on error clean up */
    expression_destruct(e);
    return 0;
}


/* FIXME: g and e currently need to have the same structure. But it would be great if the
 *        structure could differ as long as the number of atomic groups / leafs is the same */
/** \brief add expr_cast node after each node, update leafs of expression tree
 ** \param g group
 ** \param e expression to cast to g (consumed)
 ** \return e on success or 0 on error
 **/
static struct expression *expression_cast(struct group *g, struct expression *e)
{
    unsigned i;

    ASSERT(g && e);
    /* make sure that both are leaf/atomic or both are tupels with same size */
    if(g->n != e->n) {
        fprintf(stderr, "invalid cast\n");
        goto err;
    }
    /* if leaf, append cast node after it and update expression */
    if(e->leaf) {
        e->leaf = node_cast(g, e->leaf);
        if(!e->leaf) goto err;
        return e;
    }

    /* run this function on every child node */
    for(i = 0; i < e->n; ++i) {
        e->childs[i] = expression_cast(g->sub[i], e->childs[i]);
        if(!e->childs[i]) goto err;
    }
    return e;
err:
    expression_destruct(e);
    return 0;
}

/* get the group of constant exponents "_constexp" of type Z. If it does not exist, create it. */
static struct group *get_constexp_group(struct statementlist *sl)
{
    struct group *g;
    char *name, *atomic, *tmp;
    struct stringlist *param;

    ASSERT(sl);
    /* if it already exists, return it */
    g = zkparser_get_group(sl, "_constexp");
    if(g) return g;

    /* create stringlist (0, 0) for parameters to group */
    tmp = my_strdup("0");
    if(!tmp) return 0;

    param = stringlist_new(tmp);
    if(!param) return 0;

    tmp = my_strdup("0");
    if(!tmp) {
        stringlist_destruct(param);
        return 0;
    }

    param = stringlist_append(param, tmp);
    if(!param) return 0;

    /* create variables for name and atomic type */
    name = my_strdup("_constexp");
    atomic = my_strdup("Z");
    if(!name || !atomic) {
        /* on error clean up */
        string_destruct(name);
        string_destruct(atomic);
        stringlist_destruct(param);
        return 0;
    }

    /* create group */
    if(!statement_atomicgroup(sl, name, atomic, param)) return 0;

    /* group now exists. Get it and return it */
    g = zkparser_get_group(sl, "_constexp");
    ASSERT(g);
    return g;
}

/** \brief create variable for constant exponent
 ** \param sl statementlist
 ** \param n exponent (consumed)
 ** \return new expression or 0 on error
 **/
static struct expression *expression_constexp(struct statementlist *sl, char *n)
{
    struct stringlist *l;
    struct group *g;

    /* create a stringlist from n */
    l = stringlist_new(n);
    if(!l) goto err0;

    /* get group of constant exponents */
    g = get_constexp_group(sl);
    if(!g) goto err1;

    /* create constant */
    return expression_const(sl, g, l);
err1:
    stringlist_destruct(l);
err0:
    return 0;
}

static struct expression *expression_pow2(struct expression *a, struct node *b)
{
    unsigned i;

    /* if leaf, append pow node after it and update expression */
    if(a->leaf) {
        node_use(b);
        a->leaf = node_pow(a->leaf, b);
        if(!a->leaf) goto err;
        return a;
    }

    /* run this function on every child node */
    for(i = 0; i < a->n; ++i) {
        a->childs[i] = expression_pow2(a->childs[i], b);
        if(!a->childs[i]) goto err;
    }
    return a;
err:
    expression_destruct(a);
    return 0;
}

/** \brief create pow expression
 ** \param a base (consumed)
 ** \param b exponent (consumed)
 ** \return a on success or 0 on error
 **/
static struct expression *expression_pow(struct expression *a, struct expression *b)
{
    if(!b->leaf) {
        expression_destruct(a);
        expression_destruct(b);
        fprintf(stderr, "Exponent must be in atomic group.\n");
        return 0;
    }
    a = expression_pow2(a, b->leaf);
    expression_destruct(b);
    return a;
}

/** \brief create op/iop expression
 ** \param fptr pointer to function (pointer to struct node, pointer to struct node) returning pointer to struct node
 ** \param a first operand (consumed)
 ** \param b second operand (consumed)
 ** \return a on success or 0 on error
 **/
static struct expression *expression_xop(struct node *(*fptr)(struct node *, struct node *), struct expression *a, struct expression *b)
{
    unsigned i;

    ASSERT(a && b);

    /* make sure both are leafs or both are not */
    if(!a->leaf != !b->leaf) {
        fprintf(stderr, "Different groups in + or - operator\n");
        return 0;
    }

    /* if leaf, create new node, update a and destruct b */
    if(a->leaf) {
        a->leaf = fptr(a->leaf, b->leaf);
        /* b->leaf is either destructed or part of a->leaf, must unset pointer before destructing b */
        b->leaf = 0;
        if(!a->leaf) goto err;
        expression_destruct(b);
        return a;
    }
    /* run this function on every child node */
    for(i = 0; i < a->n; ++i) {
        a->childs[i] = expression_xop(fptr, a->childs[i], b->childs[i]);
        /* b->childs[i] was destructed, must unset pointer before destructing b */
        b->childs[i] = 0;
        if(!a->childs[i]) goto err;
    }
    expression_destruct(b);
    return a;
err:
    expression_destruct(a);
    expression_destruct(b);
    return 0;
}

/** \brief create op expression
 ** \param a first operand (consumed)
 ** \param b second operand (consumed)
 ** \return a on success or 0 on error
 **/
static struct expression *expression_op(struct expression *a, struct expression *b)
{
    return expression_xop(node_op, a, b);
}

/** \brief create iop expression
 ** \param a first operand (consumed)
 ** \param b second operand (consumed)
 ** \return a on success or 0 on error
 **/
static struct expression *expression_iop(struct expression *a, struct expression *b)
{
    return expression_xop(node_iop, a, b);
}

/** \brief copy tmp expression
 ** \param tmp source expression; don't destruct it, even if an error occurs
 ** \return copy of tmp or 0 on error
 **/
static struct expression *expression_tmp(struct expression *tmp)
{
    unsigned i;
    struct expression **childs;
    if(tmp->leaf) {
        node_use(tmp->leaf);
        return expression_new(tmp->leaf, 0, 0);
    }
    if(!MALLOC(childs, tmp->n)) return 0;
    for(i = 0; i < tmp->n; ++i) {
        childs[i] = expression_tmp(tmp->childs[i]);
        if(!childs[i]) goto err;
    }
    return expression_new(0, tmp->n, childs);
err:
    while(i--) expression_destruct(childs[i]);
    free(childs);
    return 0;
}

/** \brief set `cn' in all nodes to 0 **/
static void expression_zero(struct expression *h)
{
    unsigned i;

    if(h->leaf) {
        node_copy_set0(h->leaf);
        return;
    }

    for(i = 0; i < h->n; ++i) expression_zero(h->childs[i]);
}

/** \brief check if e is in group g
 ** \param g group
 ** \param e expression
 ** \return 0 if groups differ, 1 if they are equal
 **/
static int expression_isgroup(struct group *g, struct expression *e)
{
    unsigned i;
    /* if one is leaf/atomic and the other is not or if both are tupels but with different sizes, return 0 */
    if(g->n != e->n) return 0;

    /* if g is atomic, then e is a leaf. return the result */
    if(g->type == group_atomic) return e->leaf->g == g;

    /* both are tupels of same size; if one of the childs differs, the result is 0 */
    for(i = 0; i < g->n; ++i) if(!expression_isgroup(g->sub[i], e->childs[i])) return 0;

    /* both tupels equal, return 1 */
    return 1;
}

/** \brief make a copy of `h' and all nodes; replace each `src varref' with the corresponding node from `e'
 ** \param h homomorphism
 ** \param e parameter to h
 ** \return new expression or 0 on error
 **/
static struct expression *expression_hom1(struct expression *h, struct expression *e)
{
    unsigned i;
    struct expression **childs;
    /* if h is leaf, copy node */
    if(h->leaf) {
        struct node *n = node_copy(h->leaf, e);
        return n ? expression_new(n, 0, 0) : 0;
    }
    if(!MALLOC(childs, h->n)) return 0;
    /* create array of h->n child expressions */
    for(i = 0; i < h->n; ++i) {
        childs[i] = expression_hom1(h->childs[i], e);
        if(!childs[i]) goto err;
    }
    return expression_new(0, h->n, childs);
err:
    while(i--) expression_destruct(childs[i]);
    free(childs);
    return 0;
}

/** \brief make a copy of `h' and all nodes; replace each `src varref' with the corresponding node from `e'. Then destruct `e'.
 ** \param h homomorphism
 ** \param g source group of h
 ** \param e parameter to h (consumed)
 ** \return new expression or 0 on error
 **/
static struct expression *expression_hom(struct expression *h, struct group *g, struct expression *e)
{
    struct expression *x;
    if(!expression_isgroup(g, e)) {
        fprintf(stderr, "Homomorphism expects a parameter of a different group.\n");
        expression_destruct(e);
        return 0;
    }
    /* set `cn' in all nodes to 0 */
    expression_zero(h);

    /* create copy of h */
    x = expression_hom1(h, e);
    
    /* destruct e */
    expression_destruct(e);
    return x;
}
