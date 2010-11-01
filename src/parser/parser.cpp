#include <cstdlib>
#include <cstdio>

#include "parser/parser.hpp"
#include "hom/hom.hpp"
#include "element/atomic.hpp"
#include "element/tuple.hpp"
#include "util/errorhandling.hpp"

extern "C" {
    #include "zkparser/zkparser.h"
}

using namespace ZKCompiler;
using namespace ZKCompiler::hom;

extern "C" {
    struct parserLookup {
        unsigned long ngroups;
        struct group **groups;

        unsigned long nvars;
        struct var **vars;

        unsigned long nhoms;
        struct hom **homs;

        unsigned long nsigmas;
        struct sigma **sigmas;
    };
}

namespace {

    Varref *convert_varref(struct varref *src)
    {
        if(!src) return 0;

        Varref *dst = new Varref;

        switch(src->type) {
            case varref::var_src:
                dst->type = Varref_src;
                dst->e = 0;
                break;
            case varref::var_dst:
                dst->type = Varref_dst;
                dst->e = 0;
                break;
            case varref::var_var:
                dst->type = Varref_var;
                dst->e = (Element *)src->v->ud.p;
                dst->nsub = 0;
                dst->sub = 0;
                for(unsigned i = 0; i < src->ns; ++i) dst->e = dst->e->getSub((unsigned)src->s[i]);
                return dst;
            default:
                ZK_HANDLE_ERROR("invalid varref type");
        }

        dst->nsub = src->ns;
        dst->sub = new unsigned[dst->nsub];
        for(unsigned i = 0; i < dst->nsub; ++i) dst->sub[i] = (unsigned)src->s[i];

        return dst;
    }

    extern "C" { 
        struct str {
            const unsigned char *p;
        };

        int getchar_stdio(void *arg)
        {
            return fgetc((FILE*)arg);
        }

        int getchar_str(void *arg)
        {
            struct str *str = (struct str *)arg;

            if(!*str->p) return EOF;
            return *str->p++;
        }

        struct group *lookup_group(void *arg, unsigned long id)
        {
            struct parserLookup *p = (struct parserLookup *)arg;
            return id >= p->ngroups ? 0 : p->groups[id];
        }

        struct var *lookup_var(void *arg, unsigned long id)
        {
            struct parserLookup *p = (struct parserLookup *)arg;
            return id >= p->nvars ? 0 : p->vars[id];
        }

        struct hom *lookup_hom(void *arg, unsigned long id)
        {
            struct parserLookup *p = (struct parserLookup *)arg;
            return id >= p->nhoms ? 0 : p->homs[id];
        }

        struct sigma *lookup_sigma(void *arg, unsigned long id)
        {
            struct parserLookup *p = (struct parserLookup *)arg;
            return id >= p->nsigmas ? 0 : p->sigmas[id];
        }
    }

    Element *genElement(struct group *g, Group **groups)
    {
        if(g->type == ::group::group_atomic) return new element::Atomic((Group *)g->ud.p);
        Element **sub = new Element*[g->n];
        for(unsigned i = 0; i < g->n; ++i) sub[i] = genElement(g->sub[i], groups);
        return new element::Tuple(g->n, sub);
    }
}

#define INIT_ELE(x) for(lu->n##x##s = 0; proxy->x##s && proxy->x##s[lu->n##x##s]; ++lu->n##x##s) {} \
                    if(lu->n##x##s) {                                                               \
                        lu->x##s = new struct x *[lu->n##x##s];                                     \
                        for(unsigned long i = 0; i < lu->n##x##s; ++i) {                            \
                            lu->x##s[i] = zkparser_get_##x(proxy->p->sl, proxy->x##s[i]);           \
                            if(!lu->x##s[i]) ZK_HANDLE_ERROR("unknown " #x " in proxy lookup");     \
                        }                                                                           \
                        cb.get_##x = lookup_##x;                                                    \
                    } else {                                                                        \
                        lu->x##s = 0;                                                               \
                        cb.get_##x = 0;                                                             \
                    }

namespace ZKCompiler {
    Parser *Parser::createGeneric(int(*getchr)(void *), void *arg, struct ProxyLookup *proxy)
    {
        if(!proxy) return new Parser(zkparser_parse(getchr, arg, 0), 0);

        struct identifier_callbacks cb;
        struct parserLookup *lu = new parserLookup;

        cb.arg = lu;

        INIT_ELE(group)
        INIT_ELE(var)
        INIT_ELE(hom)
        INIT_ELE(sigma)
        
        return new Parser(zkparser_parse(getchr, arg, &cb), lu);
    }

    Parser *Parser::fromFile(const char *file)
    {
        return fromFile(file, 0);
    }

    Parser *Parser::fromFile(const char *file, struct ProxyLookup *proxy)
    {
        FILE *fd = fopen(file, "r");
        if(!fd) ZK_HANDLE_ERROR("Can't open file");
        Parser *p = createGeneric(getchar_stdio, (void *)fd, proxy);
        fclose(fd);
        return p;
    }

    Parser *Parser::fromString(const char *str)
    {
        return fromString(str, 0);
    }

    Parser *Parser::fromString(const char *str, struct ProxyLookup *proxy)
    {
        struct str s;
        s.p = (const unsigned char *)str;
        return createGeneric(getchar_str, (void *)&s, proxy);
    }

    Parser::Parser(struct statementlist *sl_, struct parserLookup *lu_)
    {
        if(sl_ == 0) ZK_HANDLE_ERROR("parser failed");
        sl = sl_;
        lu = lu_;
        
        groups = new Group*[sl->ngroups];
        vars = new Element*[sl->nvars];
        homs = new Hom*[sl->nhoms];

        /* generate groups */
        for(unsigned i = 0; i < sl->ngroups; ++i) switch(sl->groups[i]->type) {
            case ::group::group_atomic:
                groups[i] = Group::create(this, sl->groups[i]->atomic, sl->groups[i]->l->n, sl->groups[i]->l->s);
                sl->groups[i]->ud.p = (void *)groups[i];
                break;

            case ::group::group_tuple:
                /* don't create tuple groups */
                groups[i] = 0; 
                sl->groups[i]->ud.p = (void *)0;
                break;

            default:
                ZK_HANDLE_ERROR("invalid group type");
        }

        /* generate variables */
        for(unsigned i = 0; i < sl->nvars; ++i) {
            vars[i] = genElement(sl->vars[i]->g, groups);
            sl->vars[i]->ud.p = (void *)vars[i];
            if(sl->vars[i]->init)
            {
                CMV::zk_pcchar_t* pInitStrings;
                CMV_NEW_ARRAY(pInitStrings, zk_pcchar_t, sl->vars[i]->init->n);
                for(unsigned j = 0; j < sl->vars[i]->init->n; ++j)
                    pInitStrings[j] = CMV_IN((zk_pcchar_t)sl->vars[i]->init->s[j]);
                vars[i]->set(pInitStrings, sl->vars[i]->init->n);
                CMV_DELETE_ARRAY(pInitStrings, zk_pcchar_t, sl->vars[i]->init->n);
            }
        }

        /* generate homomorphisms */
        for(unsigned i = 0; i < sl->nhoms; ++i) {
            if(sl->homs[i]->n == 0) ZK_HANDLE_ERROR("homomorphism without expressions");
            Expr *expr = new Expr[sl->homs[i]->n];
            /* curnew points to the last element of the array, curold to the first of the list. Move curnew backwards and curold forwards and */
            Expr *curnew = expr + (sl->homs[i]->n - 1);
            struct expr *curold = sl->homs[i]->e;

            while(curold) {
                curnew->dst = convert_varref(curold->dst);
                switch(curold->type) {
                    case expr::expr_id  : curnew->type = Expr_id  ; break;
                    case expr::expr_min : curnew->type = Expr_min ; break;
                    case expr::expr_max : curnew->type = Expr_max ; break;
                    case expr::expr_inv : curnew->type = Expr_inv ; break;
                    case expr::expr_op  : curnew->type = Expr_op  ; break;
                    case expr::expr_iop : curnew->type = Expr_iop ; break;
                    case expr::expr_pow : curnew->type = Expr_pow ; break;
                    case expr::expr_ipow: curnew->type = Expr_ipow; break;
                    case expr::expr_rnd : curnew->type = Expr_rnd ; break;
                    case expr::expr_set : curnew->type = Expr_set ; break;
                    case expr::expr_cast: curnew->type = Expr_cast; break;
                    default: abort(); break;
                }
                curnew->a = convert_varref(curold->a);
                curnew->b = convert_varref(curold->b);
                curold = curold->next;
                --curnew;
            }
            homs[i] = new Hom(genElement(sl->homs[i]->dst, groups), genElement(sl->homs[i]->src, groups), sl->homs[i]->n, expr);
            sl->homs[i]->ud.p = (void *)homs[i];
        }
    }

    Parser::~Parser()
    {
        for(unsigned i = 0; i < sl->nhoms; ++i) delete homs[i];
        for(unsigned i = 0; i < sl->nvars; ++i) delete vars[i];
        for(unsigned i = 0; i < sl->ngroups; ++i) delete groups[i];
        delete[] groups;
        delete[] vars;
        delete[] homs;
        zkparser_free(sl);
        if(lu) {
            delete[] lu->groups;
            delete[] lu->vars;
            delete[] lu->homs;
            delete[] lu->sigmas;
            delete lu;
        }
    }

    Element *Parser::getElement(const char *name)
    {
        struct group *g = zkparser_get_group(sl, name);
        if(!g) ZK_HANDLE_ERROR("unknown group");
        return genElement(g, groups);
    }

    Element *Parser::getVar(const char *name)
    {
        struct var *v = zkparser_get_var(sl, name);
        if(!v) ZK_HANDLE_ERROR("unknown variable");
        return (Element *)v->ud.p;
    }

    Hom *Parser::getHom(const char *name)
    {
        struct hom *h = zkparser_get_hom(sl, name);
        if(!h) ZK_HANDLE_ERROR("unknown homomorphism");
        return (Hom *)h->ud.p;
    }

    Sigma *Parser::getSigma(const char *name)
    {
        struct sigma *s = zkparser_get_sigma(sl, name);
        if(!s) ZK_HANDLE_ERROR("unknown sigma protocol");
        return Sigma::create(this, s->type, s->l->n, s->l->s);
    }

    void Parser::map(const char *dst, const char *hom, const char *src)
    {
        getVar(dst)->map(getHom(hom), getVar(src));
    }
}
