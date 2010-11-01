/** \brief destruct sigma object
 ** \param s object to destruct
 **/
static void sigma_destruct(struct sigma *s)
{
    if(!s) return;

    string_destruct(s->name);
    string_destruct(s->type);
    stringlist_destruct(s->l);
    free(s);
}

/** \brief create new sigma object
 ** \param name name of sigma protocol; is consumed and must be free()able
 ** \param type type of sigma protocol; is consumed and must be free()able
 ** \param l nonempty list of parameters for protocol; is consumed and must be free()able
 ** \return pointer to new sigma object or 0 on error
 **/
static struct sigma *sigma_new(char *name, char *type, struct stringlist *l)
{
    struct sigma *s;

    ASSERT(name);
    ASSERT(type);
    ASSERT(l && l->n && l->s);

    if(!MALLOC(s, 1)) {
        string_destruct(name);
        string_destruct(type);
        stringlist_destruct(l);
        return 0;
    }

    s->ud.i = 0;
    s->name = name;
    s->type = type;
    s->l = l;

    return s;
}

/** \brief create new sigma object and append to statementlist
 ** \param sl statementlist
 ** \param name name of sigma protocol; is consumed and must be free()able
 ** \param type type of sigma protocol; is consumed and must be free()able
 ** \param l nonempty list of parameters for protocol; is consumed and must be free()able
 ** \return 0 == error, 1 == success
 **/
static int statement_sigma(struct statementlist *sl, char *name, char *type, struct stringlist *l)
{
    struct sigma *s;
    s = sigma_new(name, type, l);
    return s && statementlist_append_sigma(sl, s);
}
