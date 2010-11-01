#include "hom/hom.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler::hom;

namespace {
    /** \brief extract a pointer to an Element from a variable reference
     ** \param var variable reference
     ** \param dst destination element (for Varref_dst)
     ** \param src source element (for Varref_src)
     ** \return pointer to the referenced Element
     **/
    Element *decode_varref(struct Varref *vr, Element *dst, Element *src)
    {
        /* if the ref is 0, the result is 0 */
        if(!vr) return 0;

        Element *e = 0;

        switch(vr->type) {
            case Varref_var: return vr->e; /* sub vars are not used for Varref_var */
            case Varref_dst: e = dst; break;
            case Varref_src: e = src; break;
            default: ZK_HANDLE_ERROR("invalid Varref type");
        }
        /* e can be a Tuple. return the correct sub var of it, which is an Atom. */
        for(unsigned i = 0; i < vr->nsub; ++i) e = e->getSub(vr->sub[i]);
        return e;
    }

    void free_varref(struct Varref *vr)
    {
        if(!vr) return;
        delete[] vr->sub;
        delete vr;
    }
}

namespace ZKCompiler {
    Hom::Hom(Element *dstElement_, Element *srcElement_, unsigned nexpr_, Expr *expr_)
    {
        dstElement = dstElement_;
        srcElement = srcElement_;
        nexpr = nexpr_;
        expr = expr_;
    }

    Hom::~Hom()
    {
        delete dstElement;
        delete srcElement;
        for(unsigned i = 0; i < nexpr; ++i) {
            free_varref(expr[i].dst);
            free_varref(expr[i].a);
            free_varref(expr[i].b);
        }
        delete[] expr;
    }

    void Hom::map(Element *dst, Element *src)
    {
        for(unsigned i = 0; i < nexpr; ++i) {
            Element *d,*a,*b;

            d = decode_varref(expr[i].dst, dst, src);
            a = decode_varref(expr[i].a, dst, src);
            b = decode_varref(expr[i].b, dst, src);

            switch(expr[i].type) {
                case Expr_id:   d->identity(); break;
                case Expr_min:  d->min();      break;
                case Expr_max:  d->max();      break;
                case Expr_inv:  d->inverse(a); break;
                case Expr_op:   d->op(a, b);   break;
                case Expr_iop:  d->iop(a, b);  break;
                case Expr_pow:  d->pow(a, b);  break;
                case Expr_ipow: d->ipow(a, b); break;
                case Expr_rnd:  d->random();   break;
                case Expr_set:  d->set(a);     break;
                case Expr_cast: d->cast(a);    break;

                default:
                    ZK_HANDLE_ERROR("invalid Expr type");
            }
        }
    }

    Element *Hom::getDstElement()
    {
        return dstElement->element();
    }

    Element *Hom::getSrcElement()
    {
        return srcElement->element();
    }
}
