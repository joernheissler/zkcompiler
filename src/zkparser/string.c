/* destruct a string */
static void string_destruct(char *s)
{
    free(s);
}

/* destruct a stringlist */
static void stringlist_destruct(struct stringlist *strl)
{
    unsigned i;

    if(!strl) return;

    for(i = 0; i < strl->n; ++i) string_destruct(strl->s[i]);
    free(strl->s);
    free(strl);
}

/* Construct a new stringlist and initialize it with one string s; consumes s.
 * On error, destruct s and return 0 */
static struct stringlist *stringlist_new(char *s)
{
    struct stringlist *strl;
    ASSERT(s);
    if(!MALLOC(strl, 1)) goto err0;
    strl->n = 0;
    if(!MALLOC(strl->s, 1)) goto err1;
    strl->s[strl->n++] = s;
    return strl;
err1:
    stringlist_destruct(strl);
err0:
    string_destruct(s);
    return 0;
}

/* append s to strl. On error, destruct strl and s and return 0; on success return strl */
static struct stringlist *stringlist_append(struct stringlist *strl, char *s)
{
    char **tmp;
    ASSERT(strl);
    ASSERT(s);
    if(!REALLOC(strl->s, tmp, strl->n + 1)) {
        stringlist_destruct(strl);
        string_destruct(s);
        return 0;
    }
    strl->s[strl->n++] = s;
    return strl;
}

