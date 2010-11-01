#include "group/z.hpp"
#include "random/random.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    CMO_USING_OPERATORS;

    namespace group {

        Z::Z(const CMV::bnz_t& mini_, const CMV::bnz_t& maxi_) : Group(1),
            CMV_CONSTRUCT(mini), CMV_CONSTRUCT(maxi), CMV_CONSTRUCT(minitight), CMV_CONSTRUCT(maxitight)
        {
            CMI(bnz_init_set(mini, mini_));
            CMI(bnz_init_set(maxi, maxi_));
            CMM_IF(CMI(bnz_cmp(mini, maxi)) > CMV_IN(0))
                CMI(bnz_clear(mini));
                CMI(bnz_clear(mini));
                ZK_CMI_HANDLE_ERROR_CMV_IN("minimum > maximum");
            CMM_ENDIF
            CMI(bnz_init(minitight));
            CMI(bnz_init(maxitight));
        }

        Z::Z(Parser *parser, unsigned n, const char * const params[]) : Group(1),
            CMV_CONSTRUCT(mini), CMV_CONSTRUCT(maxi), CMV_CONSTRUCT(minitight), CMV_CONSTRUCT(maxitight)
        {
            (void)parser;
            if(n != 2) ZK_HANDLE_ERROR("Z needs 2 parameters");
            bnz_t tmpMinI;
            if(bnz_init_set_str(tmpMinI, params[0], 0)) {
                bnz_clear(tmpMinI);
                ZK_HANDLE_ERROR("conversion error");
            }
            bnz_t tmpMaxI;
            if(bnz_init_set_str(tmpMaxI, params[1], 0)) {
                bnz_clear(tmpMinI);
                bnz_clear(tmpMaxI);
                ZK_HANDLE_ERROR("conversion error");
            }
            if(bnz_cmp(tmpMinI, tmpMaxI) > 0) {
                bnz_clear(tmpMinI);
                bnz_clear(tmpMaxI);
                ZK_HANDLE_ERROR("minimum > maximum");
            }
            CMI(bnz_init_set(mini, CMV_IN(tmpMinI)));
            bnz_clear(tmpMinI);
            CMI(bnz_init_set(maxi, CMV_IN(tmpMaxI)));
            bnz_clear(tmpMaxI);
            CMI(bnz_init(minitight));
            CMI(bnz_init(maxitight));
        }

        Z::~Z()
        {
            CMI(bnz_clear(mini));
            CMI(bnz_clear(maxi));
            CMI(bnz_clear(minitight));
            CMI(bnz_clear(maxitight));
        }

        void Z::identity(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(0ul)));
        }

        void Z::min(CMV::bnz_t *dst)
        {
            CMI(bnz_set(*dst, mini));
        }

        void Z::max(CMV::bnz_t *dst)
        {
            CMI(bnz_set(*dst, maxi));
        }

        void Z::inverse(CMV::bnz_t *dst, const CMV::bnz_t *src)
        {
            CMI(bnz_neg(*dst, *src));
        }

        void Z::op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1)
        {
            CMI(bnz_add(*dst, *src0, *src1));
        }

        void Z::iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1)
        {
            CMI(bnz_sub(*dst, *src0, *src1));
        }

        void Z::pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1)
        {
            CMI(bnz_mul(*dst, *src0, src1));
        }

        void Z::ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1)
        {
            CMI(bnz_mul(*dst, *src0, src1));
            CMI(bnz_neg(*dst, *dst));
        }

        void Z::pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1)
        {
            CMI(bnz_mul_si(*dst, *src0, src1));
        }

        void Z::random(CMV::bnz_t *dst)
        {
            CMI(Random::irange(*dst, mini, maxi));
        }

        void Z::random(CMV::bnz_t *dst, const CMV::bnz_t& tightness)
        {
            CMI(bnz_mul(minitight, mini, tightness));
            CMI(bnz_mul(maxitight, maxi, tightness));
            CMI(Random::irange(*dst, minitight, maxitight));
        }
        
        CMV::Relation Z::cmp(const CMV::bnz_t *a, const CMV::bnz_t *b)
        {
            CMV(Relation result);
            CMV(zk_int_t r);
            r = CMI(bnz_cmp(*a, *b));

            CMM_IF(r < CMV_IN(0))
                result = CMV_IN(R_LT);
            CMM_ELIF(r > CMV_IN(0))
                result = CMV_IN(R_GT);
            CMM_ELSE
                result = CMV_IN(R_EQ);
            CMM_ENDIF

            return result;
        }
        
        CMV::zk_bool_t Z::inGroup(const CMV::bnz_t *src)
        {
            (void)src;
            /* all elements are in Z */
            return CMV_IN(true);
        }
    }
}
