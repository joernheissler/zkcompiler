/** \brief destruct a varref object
 **
 ** \param vr object to destruct
 **/
static void varref_destruct(struct varref *vr)
{
    if(!vr) return;
    free(vr->s);
    free(vr);
}

/** \brief create a new varref
 **
 ** \param type varref type
 ** \param v variable reference. Must be set iff type == var_var
 ** \param ns subscript depth
 ** \param s array of subscripts. This parameter is not `consumed' but duplicated.
 ** \return new varref object or 0 on error
 **/
static struct varref *varref_new(enum var_type type, struct var *v, unsigned ns, const unsigned *s)
{
    struct varref *r;
    ASSERT((type != var_var) == !v);
    if(!MALLOC(r, 1)) return 0;
    r->type = type;
    r->v = v;
    r->ns = ns;
    if(ns) {
        /* duplicate array of subscripts */
        unsigned i;
        if(!MALLOC(r->s, ns)) {
            free(r);
            return 0;
        }
        for(i = 0; i < ns; ++i) r->s[i] = s[i];
    } else {
        r->s = 0;
    }
    return r;
}

/** \brief duplicate a variable reference
 **
 ** \param r varref to duplicate or 0
 ** \return 0 if r == 0, else a duplicate (or 0 on error)
 **/
static struct varref *varref_dup(struct varref *r)
{
    return r ? varref_new(r->type, r->v, r->ns, r->s) : 0;
}
