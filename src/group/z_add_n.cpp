#include "group/z_add_n.hpp"
#include "random/random.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    CMO_USING_OPERATORS;
    namespace group {
        Z_add_n::Z_add_n(CMV::zk_ulong_t n_) : Group(1), CMV_CONSTRUCT(n)
        {
            CMI(bnz_init_set_ui(n, n_));
            CMM_IF(CMI(bnz_cmp_ui(n, CMV_IN(0ul))) <= CMV_IN(0))
                CMI(bnz_clear(n));
                ZK_CMI_HANDLE_ERROR_CMV_IN("modulus must be > 0");
            CMM_ENDIF
        }

        Z_add_n::Z_add_n(const CMV::bnz_t& n_) : Group(1), CMV_CONSTRUCT(n)
        {
            CMI(bnz_init_set(n, n_));
            CMM_IF(CMI(bnz_cmp_ui(n, CMV_IN(0ul))) <= CMV_IN(0))
                CMI(bnz_clear(n));
                ZK_CMI_HANDLE_ERROR_CMV_IN("modulus must be > 0");
            CMM_ENDIF
        }

        Z_add_n::Z_add_n(Parser *parser, unsigned n_, const char * const params[]) : Group(1), CMV_CONSTRUCT(n)
        {
            (void)parser;
            if(n_ != 1) ZK_HANDLE_ERROR("Z_add_n needs 1 parameter");
            bnz_t tmpN;
            if(bnz_init_set_str(tmpN, params[0], 0)) {
                bnz_clear(tmpN);
                ZK_HANDLE_ERROR("conversion error");
            }
            if(bnz_cmp_ui(tmpN, 0) <= 0) {
                bnz_clear(tmpN);
                ZK_HANDLE_ERROR("modulus must be > 0");
            }
            CMI(bnz_init_set(n, CMV_IN(tmpN)));
            bnz_clear(tmpN);
        }

        Z_add_n::~Z_add_n()
        {
            CMI(bnz_clear(n));
        }

        void Z_add_n::identity(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(0ul)));
        }

        void Z_add_n::min(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(0ul)));
        }
        
        void Z_add_n::max(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(0ul)));
        }

        void Z_add_n::inverse(CMV::bnz_t *dst, const CMV::bnz_t *src)
        {
            CMI(bnz_neg(*dst, *src));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_add_n::op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1)
        {
            CMI(bnz_add(*dst, *src0, *src1));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_add_n::iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1)
        {
            CMI(bnz_sub(*dst, *src0, *src1));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_add_n::pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1)
        {
            CMI(bnz_mul(*dst, *src0, src1));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_add_n::ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1)
        {
            CMI(bnz_mul(*dst, *src0, src1));
            CMI(bnz_neg(*dst, *dst));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_add_n::pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1)
        {
            CMI(bnz_mul_si(*dst, *src0, src1));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_add_n::random(CMV::bnz_t *dst)
        {
            CMI(Random::range0(*dst, n));
        }

        void Z_add_n::random(CMV::bnz_t *dst, const CMV::bnz_t& tightness)
        {
            (void) tightness;
            random(dst);
        }

        CMV::Relation Z_add_n::cmp(const CMV::bnz_t *a, const CMV::bnz_t *b)
        {
            CMV(Relation result);
            CMM_IF(CMI(bnz_cmp(*a, *b)))
                result = CMV_IN(R_UN);
            CMM_ELSE
                result = CMV_IN(R_ID);
            CMM_ENDIF
            return  result;
        }
        
        CMV::zk_bool_t Z_add_n::inGroup(const CMV::bnz_t *src)
        {
            CMV(zk_bool_t result);
            CMM_IF(!(CMI(bnz_cmp_ui(*src, CMV_IN(0ul))) >= CMV_IN(0)))
                result = CMV_IN(false);
            CMM_ELIF(!(CMI(bnz_cmp(*src, n)) < CMV_IN(0)))
                result = CMV_IN(false);
            CMM_ELSE
                result = CMV_IN(true);
            CMM_ENDIF;
            return result;
        }
    }
}
