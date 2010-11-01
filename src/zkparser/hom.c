/** \brief destruct an expr structure
 ** \param e expr to destruct
 **/
static void expr_destruct(struct expr *e)
{
    /* destruct e and all other nodes in the list */
    while(e) {
        struct expr *next = e->next;;
        varref_destruct(e->dst);
        varref_destruct(e->a);
        varref_destruct(e->b);
        free(e);
        e = next;
    }
}

/** \brief destruct a homomorphism
 ** \param h homomorphism to destruct
 **/
static void hom_destruct(struct hom *h)
{
    if(!h) return;

    string_destruct(h->name);
    expr_destruct(h->e);
    expression_destruct(h->tree);
    free(h);
}

/** \brief create a new homomorphism
 ** \param name name of homomorphism (consumed)
 ** \param src source group of homomorphism
 ** \param dst destination group of homomorphism
 ** \param tree expression tree
 ** \return new homomorphism or 0 on error
 **/
static struct hom *hom_new(char *name, struct group *src, struct group *dst, struct expression *tree)
{
    struct hom *h;

    ASSERT(name);
    ASSERT(src);
    ASSERT(dst);

    if(!MALLOC(h, 1)) {
        string_destruct(name);
        return 0;
    }

    h->ud.i = 0;
    h->name = name;
    h->src = src;
    h->dst = dst;

    h->n = 0;
    h->e = 0;

    h->tree = tree;

    return h;
}

/** \brief create a new expr struct and append to expr list in homomorphism
 ** \param h homomorphism
 ** \param type type of expr
 ** \param g group of dst
 ** \param dst reference to destination var (consumed)
 ** \param a reference to first operand (consumed)
 ** \param b reference to second operand (consumed)
 ** \return 0 == error, 1 == success
 **/
static int hom_append_expr(struct hom *h, enum expr_type type, struct group *g, struct varref *dst, struct varref *a, struct varref *b)
{
    struct expr *e;

    if(!MALLOC(e, 1)) {
        varref_destruct(dst);
        varref_destruct(a);
        varref_destruct(b);
        return 0;
    }

    e->type = type;
    e->g = g;
    e->dst = dst;
    e->a = a;
    e->b = b;
    
    e->next = h->e;
    h->e = e;
    ++h->n;

    return 1;
}

/** \brief create a reference to a new temporary variable of group g
 ** \param sl statementlist
 ** \param g group of variable
 ** \return new variable reference or 0 on error
 **/
static struct varref *tmpvar(struct statementlist *sl, struct group *g)
{
    struct var *v = anon_var(sl, g, 0);
    return v ? varref_new(var_var, v, 0, 0) : 0;
}

static int convert_getvarref1(struct varref **r, struct expression *e, struct node *node, unsigned ns, unsigned **s)
{
    unsigned i, *tmp;

    if(e->leaf == node) {
        *r = varref_new(var_dst, 0, ns, *s);
        return !!*r;
    }

    if(!REALLOC(*s, tmp, ns + 1)) return 0;

    for(i = 0; i < e->n; ++i) {
        (*s)[ns] = i;
        if(!convert_getvarref1(r, e->childs[i], node, ns + 1, s)) return 0;
        if(*r) break;
    }
    return 1;
}

static int convert_getvarref(struct varref **r, struct expression *e, struct node *node)
{
    unsigned *s = 0;
    int ret = convert_getvarref1(r, e, node, 0, &s);
    free(s);
    return ret;
}

/** \brief convert a node
 ** \param sl statementlist
 ** \param h homomorphism
 ** \param e expression root
 ** \param node node to convert
 ** \return 0 == error, 1 == success
 **/
static int convert_node(struct statementlist *sl, struct hom *h, struct expression *e, struct node *node)
{
    unsigned is_rootnode;

    /* node already converted; nothing to be done */
    if(node->dst) return 1;

    /* convert the subnodes */
    if(node->a) if(!convert_node(sl, h, e, node->a)) return 0;
    if(node->b) if(!convert_node(sl, h, e, node->b)) return 0;

    /* check if this node is a root node and get var_dst reference in this case */
    if(!convert_getvarref(&node->dst, e, node)) return 0;

    if(node->dst) {
        is_rootnode = 1;
    } else {
        is_rootnode = 0;
        if(node->type == expr_set) {
            /* node is a variable reference and it's not a root node. No expr needs to be generated */

            /* set dst to variable reference */
            node->dst = varref_dup(node->v);
            return !!node->dst;
        }
        
        node->dst = tmpvar(sl, node->g);
        if(!node->dst) return 0;
    }

    if(node->type == expr_set) {
        struct varref *dst, *v;
        dst = varref_dup(node->dst);
        v = varref_dup(node->v);
        if(!dst || !v) {
            varref_destruct(dst);
            varref_destruct(v);
            return 0;
        }
        return hom_append_expr(h, expr_set, node->g, dst, v, 0);
    } else {
        struct varref *dst, *a, *b;
        dst = varref_dup(node->dst);
        a = node->a ? varref_dup(node->a->dst) : 0;
        b = node->b ? varref_dup(node->b->dst) : 0;
        if(!dst || (node->a && !a) || (node->b && !b)) {
            varref_destruct(dst);
            varref_destruct(a);
            varref_destruct(b);
            return 0;
        }
        return hom_append_expr(h, node->type, node->g, dst, a, b);
    }
}

/** \brief check if r is a var_dst ref and if the subscripts in r match s
 ** \param r varref
 ** \param ns subscript depth
 ** \param s array of subscripts
 ** \return 0 == no match, 1 == matches
 **/
static int sameref(struct varref *r, unsigned ns, unsigned *s)
{
    unsigned i;
    if(r->type != var_dst) return 0;
    if(r->ns != ns) return 0;
    for(i = 0; i < ns; ++i) if(r->s[i] != s[i]) return 0;
    return 1;
}

/** \brief convert expression/node tree to list of exprs
 ** \param sl statementlist
 ** \param h homomorphism
 ** \param e root of expression tree
 ** \param cur current expression
 ** \param ns recursion depth
 ** \param s subscripts
 ** \return 0 == error, 1 == success
 **/
static int convert_expression_recursive(struct statementlist *sl, struct hom *h, struct expression *e, struct expression *cur, unsigned ns, unsigned **s)
{
    unsigned i, *tmp;

    if(cur->leaf) {
        struct varref *src, *dst;

        /* cur->leaf is a root node */

        /* if current node wasn't yet converted, do it now */
        if(!cur->leaf->dst) return convert_node(sl, h, e, cur->leaf);

        /* current node is already converted */

        /* if the destination of the current node is already correct, there's nothing to do */
        if(sameref(cur->leaf->dst, ns, *s)) return 1;

        /* two or more roots share the same node. It's already converted but assigned to a different root.
         * Copy result to new root */
        src = varref_dup(cur->leaf->dst);
        if(!src) return 0;
        dst = varref_new(var_dst, 0, ns, *s);
        if(!dst) {
            varref_destruct(src);
            return 0;
        }

        return hom_append_expr(h, expr_set, cur->leaf->g, dst, src, 0);
    }

    /* cur is not a leaf. Call this function again for every child expression */
    if(!REALLOC(*s, tmp, ns + 1)) return 0;

    for(i = 0; i < cur->n; ++i) {
        (*s)[ns] = i;
        /* if conversion fails for any child, result is 0 */
        if(!convert_expression_recursive(sl, h, e, cur->childs[i], ns + 1, s)) return 0;
    }
    return 1;
}

/** \brief convert expression/node tree to list of exprs
 ** \param sl statementlist
 ** \param h homomorphism
 ** \param e expression tree
 ** \return 0 == error, 1 == success
 **/
static int convert_expression(struct statementlist *sl, struct hom *h, struct expression *e)
{
    int ret;
    unsigned *s = 0;
    ret = convert_expression_recursive(sl, h, e, e, 0, &s);
    free(s);
    return ret;
}

/** \brief create new homomorphism and append to statementlist
 ** \param sl statementlist
 ** \param ps parserstate
 ** \param name name of homomorphism (consumed)
 ** \param src source group of homomorphism
 ** \param dst destination group of homomorphism
 ** \param e expression which describes the computations made (consumed)
 ** \return 0 == error, 1 == success
 **/
static int statement_hom(struct statementlist *sl, struct zk_parserstate *ps, char *name, struct group *src, struct group *dst, struct expression *e)
{
    struct hom *h = 0;

    ASSERT(sl && ps && name && src && dst && e);

    if(!expression_isgroup(dst, e)) {
        fprintf(stderr, "Expression does not match destination group.\n");
        goto err2;
    }

    h = hom_new(name, src, dst, e);
    if(!h) goto err0;

    /* create a linear list of expr from e */
    if(!convert_expression(sl, h, e)) goto err1;

    /* append h to statementlist */
    if(!statementlist_append_hom(sl, h)) goto err0;
    return 1;

err2:
    string_destruct(name);
err1:
    hom_destruct(h);
err0:
    expression_destruct(e);
    return 0;
}
