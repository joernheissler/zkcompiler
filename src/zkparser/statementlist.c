/* destruct statementlist */
static void statementlist_destruct(struct statementlist *sl)
{
    unsigned i;

    if(!sl) return;

    for(i = 0; i < sl->ngroups; ++i) group_destruct(sl->groups[i]);
    for(i = 0; i < sl->nvars  ; ++i)   var_destruct(sl->vars  [i]);
    for(i = 0; i < sl->nhoms  ; ++i)   hom_destruct(sl->homs  [i]);
    for(i = 0; i < sl->nsigmas; ++i) sigma_destruct(sl->sigmas[i]);

    free(sl->groups);
    free(sl->vars  );
    free(sl->homs  );
    free(sl->sigmas);
    free(sl);
}

/* create new statementlist */
static struct statementlist *statementlist_new(struct identifier_callbacks *idcb)
{
    struct statementlist *sl;
    struct identifier_callbacks tmp = { 0,0,0,0,0 };

    if(!MALLOC(sl, 1)) return 0;

    sl->ngroups = 0;
    sl->groups = 0;

    sl->nvars = 0;
    sl->vars = 0;

    sl->nhoms = 0;
    sl->homs = 0;

    sl->nsigmas = 0;
    sl->sigmas = 0;

    sl->idcb = idcb ? *idcb : tmp;

    return sl;
}

static int statementlist_append_hom(struct statementlist *sl, struct hom *h)
{
    struct hom **tmp;
    ASSERT(sl && h);

    if(zkparser_get_hom(sl, h->name)) {
        fprintf(stderr, "Homomorphism '%s' already defined.\n", h->name);
        goto err;
    }
    if(!REALLOC(sl->homs, tmp, sl->nhoms + 1)) goto err;
    sl->homs[sl->nhoms++] = h;
    return 1;
err:
    hom_destruct(h);
    return 0;
}

static int statementlist_append_group(struct statementlist *sl, struct group *g)
{
    struct group **tmp;
    ASSERT(sl && g);

    if(zkparser_get_group(sl, g->name)) {
        fprintf(stderr, "Group '%s' already defined.\n", g->name);
        goto err;
    }
    if(!REALLOC(sl->groups, tmp, sl->ngroups + 1)) goto err;
    sl->groups[sl->ngroups++] = g;
    return 1;
err:
    group_destruct(g);
    return 0;
}

static int statementlist_append_var(struct statementlist *sl, struct var *v)
{
    struct var **tmp;
    ASSERT(sl && v);

    if(zkparser_get_var(sl, v->name)) {
        fprintf(stderr, "Variable '%s' already defined.\n", v->name);
        goto err;
    }
    if(!REALLOC(sl->vars, tmp, sl->nvars + 1)) goto err;
    sl->vars[sl->nvars++] = v;
    return 1;
err:
    var_destruct(v);
    return 0;
}

static int statementlist_append_sigma(struct statementlist *sl, struct sigma *s)
{
    struct sigma **tmp;
    ASSERT(sl && s);

    if(zkparser_get_sigma(sl, s->name)) {
        fprintf(stderr, "Sigma '%s' already defined.\n", s->name);
        goto err;
    }
    if(!REALLOC(sl->sigmas, tmp, sl->nsigmas + 1)) goto err;
    sl->sigmas[sl->nsigmas++] = s;
    return 1;
err:
    sigma_destruct(s);
    return 0;
}

static int decode_extname(unsigned long *l, const char *name)
{
    char *p;
    if(name[0] != '_' || name[1] == 0) return 0;
    errno = 0;
    *l = strtoul(name + 1, &p, 0);
    if(errno || *p != 0) return 0;
    return 1;
}

struct group *zkparser_get_group(struct statementlist *sl, const char *name)
{
    unsigned i;
    unsigned long x;
    if(decode_extname(&x, name)) return sl->idcb.get_group ? sl->idcb.get_group(sl->idcb.arg, x) : 0;
    for(i = 0; i < sl->ngroups; ++i) if(!strcmp(name, sl->groups[i]->name)) return sl->groups[i];
    return 0;
}

struct var *zkparser_get_var(struct statementlist *sl, const char *name)
{
    unsigned i;
    unsigned long x;
    if(decode_extname(&x, name)) return sl->idcb.get_var ? sl->idcb.get_var(sl->idcb.arg, x) : 0;
    for(i = 0; i < sl->nvars; ++i) if(!strcmp(name, sl->vars[i]->name)) return sl->vars[i];
    return 0;
}

struct hom *zkparser_get_hom(struct statementlist *sl, const char *name)
{
    unsigned i;
    unsigned long x;
    if(decode_extname(&x, name)) return sl->idcb.get_hom ? sl->idcb.get_hom(sl->idcb.arg, x) : 0;
    for(i = 0; i < sl->nhoms; ++i) if(!strcmp(name, sl->homs[i]->name)) return sl->homs[i];
    return 0;
}

struct sigma *zkparser_get_sigma(struct statementlist *sl, const char *name)
{
    unsigned i;
    unsigned long x;
    if(decode_extname(&x, name)) return sl->idcb.get_sigma ? sl->idcb.get_sigma(sl->idcb.arg, x) : 0;
    for(i = 0; i < sl->nsigmas; ++i) if(!strcmp(name, sl->sigmas[i]->name)) return sl->sigmas[i];
    return 0;
}
