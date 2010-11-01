/** \brief destruct a var object
 **
 ** \param v object to destruct
 **/
static void var_destruct(struct var *v)
{
    if(!v) return;

    string_destruct(v->name);
    stringlist_destruct(v->init);
    free(v);
}

/** \brief create a new var object
 **
 ** \param name name of the variable; is consumed and must be free()able
 ** \param g; group this variable is in
 ** \param init; optional initializer; is consumed and must be free()able
 ** \return pointer to new var object or 0 on error
 **/
static struct var *var_new(char *name, struct group *g, struct stringlist *init)
{
    struct var *v;

    ASSERT(name);
    ASSERT(g);
    ASSERT(!init || (init->n && init->s));

    if(!MALLOC(v, 1)) {
        string_destruct(name);
        stringlist_destruct(init);
        return 0;
    }

    v->ud.i = 0;
    v->name = name;
    v->g = g;
    v->init = init;

    return v;
}

/** \brief create a new variable and append to statementlist
 ** \param sl statementlist
 ** \param g group of variable
 ** \param name name of variable; is consumed and must be free()able
 ** \param init optional initializer (single value); is consumed and must be free()able
 ** \param list optional list of initializers; is consumed and must be free()able
 ** \return 0 == error, 1 == success
 **/
static int statement_var(struct statementlist *sl, struct group *g, char *name, char *init, struct stringlist *list)
{
    struct var *v;

    ASSERT(sl);
    ASSERT(g);
    ASSERT(name);
    ASSERT(!init || !list);

    if(init) {
        /* turn init into a list */
        list = stringlist_new(init);
        if(!list) goto err;
    }

    v = var_new(name, g, list);
    return v && statementlist_append_var(sl, v);

err:
    string_destruct(name);
    stringlist_destruct(list);
    return 0;
}

/* number of decimal digits an unsigned integer type can have at most.
 * One needs log_10(2) digits per bit, 28/93 is slightly above this value.
 * If bits * 28 is not divisible by 93, the result is truncated and one byte
 * short, hence add 1.
 *
 * E.g. one needs 32 * l(2)/l(10) ~ 9.6323 ~ 10 bytes for 32 bit unsigned int.
 * floor(32 * 28 / 93) + 1 = floor(9.6344) + 1 = 10
 */
#define DIGITS(v) (sizeof(v) * CHAR_BIT * 28 / 93 + 1)

/** \brief create a temporary variable and append it to statementlist
 ** \param sl statementlist
 ** \param g group of variable
 ** \param list optional initializer; is consumed and must be free()able
 ** \return pointer to new var on success, 0 on error
 **/
static struct var *anon_var(struct statementlist *sl, struct group *g, struct stringlist *list)
{
    char *name;
    struct var *v;

    ASSERT(sl);
    ASSERT(g);
    if(!MALLOC(name, 7 + DIGITS(sl->nvars))) { /* _anon_ is 6 chars, terminating 0 is 1 */
        stringlist_destruct(list);
        return 0;
    }
    sprintf(name, "_anon_%u", sl->nvars);
    v = var_new(name, g, list);
    return v && statementlist_append_var(sl, v) ? v : 0;
}
