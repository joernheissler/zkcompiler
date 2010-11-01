/** \brief destruct a node
 ** \param n node to destruct
 **
 ** if refcount is 1, actually destruct it, else decrement by 1 and do nothing
 **/
static void node_destruct(struct node *n)
{
    if(!n) return;
    ASSERT(n->refcount);
    if(--n->refcount) return;
    node_destruct(n->a);
    node_destruct(n->b);
    varref_destruct(n->v);
    varref_destruct(n->dst);
    free(n);
}

/** \brief create new node
 ** \param type node type
 ** \param g node group
 ** \param a first operand (consumed)
 ** \param b second operand (consumed)
 ** \param v variable reference (consumed)
 ** \return new node or 0 on error
 **/
static struct node *node_new(enum expr_type type, struct group *g, struct node *a, struct node *b, struct varref *v)
{
    struct node *node;

    ASSERT(g);
    ASSERT(g->type == group_atomic);

    switch(type) {
        case expr_op:
        case expr_iop:
        case expr_pow:
        case expr_ipow:
            ASSERT(a && b && !v);
            break;
        case expr_id:
        case expr_min:
        case expr_max:
        case expr_rnd:
            ASSERT(!a && !b && !v);
            break;
        case expr_inv:
        case expr_cast:
            ASSERT(a && !b && !v);
            break;
        case expr_set:
            ASSERT(!a && !b && v);
            break;
        default:
            ASSERT(!"invalid node type");
            break;
    }
    if(!MALLOC(node, 1)) {
        node_destruct(a);
        node_destruct(b);
        varref_destruct(v);
        return 0;
    }
    node->type = type;
    node->g = g;
    node->a = a;
    node->b = b;
    node->v = v;
    node->dst = 0;
    node->cn = 0;
    node->refcount = 1;
    return node;
}

/** \brief increase refcounter **/
static void node_use(struct node *n)
{
    if(n) ++n->refcount;
}

/** \brief set cn to 0 in all nodes **/
static void node_copy_set0(struct node *n)
{
    if(!n) return;
    n->cn = 0;
    node_copy_set0(n->a);
    node_copy_set0(n->b);
}

/** \brief Create a copy of node n
 ** \param n node to copy
 ** \param e expression to get `src nodes' from
 **
 ** Create a copy of node n and store pointer to copy in old node. If n
 ** is a `src varref', replace it with the corresponding node from e
 **/
static struct node *node_copy(struct node *n, struct expression *e)
{
    struct node *a, *b;
    struct varref *v;

    /* copy of 0 is 0 */
    if(!n) return 0;

    /* copy already created. Increase use counter and return copy */
    if(n->cn) {
        node_use(n->cn);
        return n->cn;
    }

    /* n is a `src varref' node */
    if(n->v && n->v->type == var_src) {
        unsigned i;
        /* descend in e according to subscripts in n->v */
        for(i = 0; i < n->v->ns; ++i) {
            ASSERT(n->v->s[i] < e->n);
            e = e->childs[n->v->s[i]];
        }
        /* e must now be a leaf with same group as n */
        ASSERT(e->leaf && e->leaf->g == n->g);

        /* don't copy the node, as it already exists. But increase use counter. */
        n->cn = e->leaf;
        node_use(n->cn);
        return n->cn;
    }

    /* create copies of the node components */
    a = node_copy(n->a, e);
    b = node_copy(n->b, e);
    v = varref_dup(n->v);
    if((n->a && !a) || (n->b && !b) || (n->v && !v)) {
        node_destruct(a);
        node_destruct(b);
        varref_destruct(v);
        return 0;
    }
    /* create the copy and return it */
    n->cn = node_new(n->type, n->g, a, b, v);
    return n->cn;
}

/** \brief create op node
 ** \param a first operand
 ** \param b second operand
 ** \return new node or 0 on error
 **/
static struct node *node_op(struct node *a, struct node *b)
{
    ASSERT(a && b);
    if(a->g != b->g) {
        fprintf(stderr, "Different groups for + operator\n");
        return 0;
    }
    return node_new(expr_op, a->g, a, b, 0);
}

/** \brief create iop node
 ** \param a first operand
 ** \param b second operand
 ** \return new node or 0 on error
 **/
static struct node *node_iop(struct node *a, struct node *b)
{
    ASSERT(a && b);
    if(a->g != b->g) {
        fprintf(stderr, "Different groups for - operator\n");
        return 0;
    }
    return node_new(expr_iop, a->g, a, b, 0);
}

/** \brief create pow node
 ** \param a base operand
 ** \param b exponent operand
 ** \return new node or 0 on error
 **/
static struct node *node_pow(struct node *a, struct node *b)
{
    return node_new(expr_pow, a->g, a, b, 0);
}

/** \brief create inv node
 ** \param a node to invert
 ** \return new node or 0 on error
 **/
static struct node *node_inv(struct node *a)
{
    return node_new(expr_inv, a->g, a, 0, 0);
}

/** \brief create cast node
 ** \param g group
 ** \param a node to cast
 ** \return new node or 0 on error
 **/
static struct node *node_cast(struct group *g, struct node *a)
{
    return node_new(expr_cast, g, a, 0, 0);
}

/** \brief create var node
 ** \param v variable (if 0, it's the source var)
 ** \param g group
 ** \param ns number of subscripts
 ** \param s array of subscripts (may be 0, not consumed)
 ** \return new node or 0 on error
 **/
static struct node *node_var(struct var *v, struct group *g, unsigned ns, unsigned *s)
{
    struct varref *r = varref_new(v ? var_var : var_src, v, ns, s);
    return r ? node_new(expr_set, g, 0, 0, r) : 0;
}

/** \brief create rnd node
 ** \param g group
 ** \return new node or 0 on error
 **/
static struct node *node_rnd(struct group *g)
{
    return node_new(expr_rnd, g, 0, 0, 0);
}

/** \brief create min node
 ** \param g group
 ** \return new node or 0 on error
 **/
static struct node *node_min(struct group *g)
{
    return node_new(expr_min, g, 0, 0, 0);
}

/** \brief create max node
 ** \param g group
 ** \return new node or 0 on error
 **/
static struct node *node_max(struct group *g)
{
    return node_new(expr_max, g, 0, 0, 0);
}

/** \brief create id node
 ** \param g group
 ** \return new node or 0 on error
 **/
static struct node *node_id(struct group *g)
{
    return node_new(expr_id, g, 0, 0, 0);
}
