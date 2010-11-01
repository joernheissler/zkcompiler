/** \brief destruct a group object
 **
 ** \param g group to destruct
 **/
static void group_destruct(struct group *g)
{
    if(!g) return;

    string_destruct(g->name);
    string_destruct(g->atomic);
    stringlist_destruct(g->l);
    /* do not destruct g->sub[i], this must be done elsewhere (e.g. in statementlist_destruct) */
    free(g->sub);
    free(g);
}

/** \brief create a new group
 **
 ** \param type type of group, either group_atomic or group_tuple
 ** \param name name of group; is consumed and must be free()able
 ** \param atomic type of atomic group (e.g. Z_mul_n); is consumed and must be free()able
 ** \param param nonempty list of parameters for atomic group; is consumed and must be free()able
 ** \param n number of subgroups
 ** \param sub array of subgroups; is consumed and must be free()able
 ** \return pointer to new object or 0 in case of error
 **/
static struct group *group_new(enum group_type type, char *name, char *atomic, struct stringlist *param, unsigned n, struct group **sub)
{
    struct group *g;

    ASSERT(type == group_atomic || type == group_tuple);
    ASSERT(name);

    if(type == group_atomic) {
        ASSERT(atomic);
        ASSERT(param && param->n && param->s);
        ASSERT(!n);
        ASSERT(!sub);
    } else {
        ASSERT(!atomic);
        ASSERT(!param);
        ASSERT(n);
        ASSERT(sub);
    }

    if(!MALLOC(g, 1)) {
        string_destruct(name);
        string_destruct(atomic);
        stringlist_destruct(param);
        free(sub);
        return 0;
    }

    g->ud.i = 0;
    g->type = type;
    g->name = name;
    g->atomic = atomic;
    g->l = param;
    g->n = n;
    g->sub = sub;

    return g;
}

/** \brief create a new atomic group and append to statementlist
 **
 ** \param sl statementlist
 ** \param name name of group; is consumed and must be free()able
 ** \param atomic type of atomic group (e.g. Z_mul_n); is consumed and must be free()able
 ** \param param nonempty list of parameters for atomic group; is consumed and must be free()able
 ** \return 0 == error, 1 == success
 **/
static int statement_atomicgroup(struct statementlist *sl, char *name, char *atomic, struct stringlist *param)
{
    struct group *g;
    g = group_new(group_atomic, name, atomic, param, 0, 0);
    return g && statementlist_append_group(sl, g);
}

/** \brief create a new tuple group and append to statementlist
 **
 ** \param sl statementlist
 ** \param name name of group; is consumed and must be free()able
 ** \param gl list of groups; is consumed and must be free()able
 ** \return 0 == error, 1 == success
 **/
static int statement_tuplegroup(struct statementlist *sl, char *name, struct grouplist *gl)
{
    struct group *g;
    g = group_new(group_tuple, name, 0, 0, gl->n, gl->g);
    free(gl);
    return g && statementlist_append_group(sl, g);
}

/** \brief destruct a group list
 **
 ** \param l group list to destruct
 **/
static void grouplist_destruct(struct grouplist *l)
{
    if(!l) return;
    free(l->g);
    free(l);
}

/** \brief create a new grouplist with initial element
 **
 ** \param g initial element
 ** \return pointer to new grouplist
 **/
static struct grouplist *grouplist_new(struct group *g)
{
    struct grouplist *l;
    ASSERT(g);
    if(!MALLOC(l, 1)) return 0;
    if(!MALLOC(l->g, 1)) {
        free(l);
        return 0;
    }
    l->n = 1;
    l->g[0] = g;
    return l;
}

/** \brief append a group to a grouplist
 ** \param l grouplist
 ** \param g group to append
 ** \return l on success, else 0
 **/
static struct grouplist *grouplist_append(struct grouplist *l, struct group *g)
{
    struct group **tmp;
    ASSERT(l && g);
    if(!REALLOC(l->g, tmp, l->n + 1)) {
        grouplist_destruct(l);
        return 0;
    }
    l->g[l->n++] = g;
    return l;
}
