#include <cstring>

#include "group/z_mul_n.hpp"
#include "random/random.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    CMO_USING_OPERATORS;
    namespace group {
        Z_mul_n::Z_mul_n(CMV::zk_ulong_t n_, Z_mul_n_randmode randmode_) : Group(1), CMV_CONSTRUCT(n)
        {
            CMI(bnz_init_set_ui(n, n_));
            CMM_IF(CMI(bnz_cmp_ui(n, CMV_IN(1ul))) <= CMV_IN(0))
                CMI(bnz_clear(n));
                ZK_CMI_HANDLE_ERROR_CMV_IN("modulus must be > 1");
            CMM_ENDIF
            randmode = randmode_;
        }

        Z_mul_n::Z_mul_n(const CMV::bnz_t& n_, Z_mul_n_randmode randmode_) : Group(1), CMV_CONSTRUCT(n)
        {
            CMI(bnz_init_set(n, n_));
            CMM_IF(CMI(bnz_cmp_ui(n, CMV_IN(1ul))) <= CMV_IN(0))
                CMI(bnz_clear(n));
                ZK_CMI_HANDLE_ERROR_CMV_IN("modulus must be > 1");
            CMM_ENDIF
            randmode = randmode_;
        }

        Z_mul_n::Z_mul_n(Parser *parser, unsigned n_, const char * const params[]) : Group(1), CMV_CONSTRUCT(n)
        {
            (void)parser;
            if(n_ != 2) ZK_HANDLE_ERROR("Z_mul_n needs 2 parameters");
            bnz_t tmpN;
            if(bnz_init_set_str(tmpN, params[0], 0)) {
                bnz_clear(tmpN);
                ZK_HANDLE_ERROR("conversion error");
            }
            if(bnz_cmp_ui(tmpN, 1) <= 0) {
                bnz_clear(tmpN);
                ZK_HANDLE_ERROR("modulus must be > 1");
            }
            if(!strcmp(params[1], "default")) {
                randmode = z_mul_n_randmode_default;
            } else if(!strcmp(params[1], "qr")) {
                randmode = z_mul_n_randmode_qr;
            } else {
                bnz_clear(tmpN);
                ZK_HANDLE_ERROR("second parameter must be 'default' or 'qr'");
            }
            CMI(bnz_init_set(n, CMV_IN(tmpN)));
            bnz_clear(tmpN);
        }

        Z_mul_n::~Z_mul_n()
        {
            CMI(bnz_clear(n));
        }

        void Z_mul_n::identity(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(1ul)));
        }
        
        void Z_mul_n::min(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(1ul)));
        }
        
        void Z_mul_n::max(CMV::bnz_t *dst)
        {
            CMI(bnz_set_ui(*dst, CMV_IN(1ul)));
        }

        void Z_mul_n::inverse(CMV::bnz_t *dst, const CMV::bnz_t *src)
        {
            CMM_IF(!CMI(bnz_invert(*dst, *src, n)))
                ZK_CMI_HANDLE_ERROR_CMV_IN("no inverse exists");
            CMM_ENDIF
        }

        void Z_mul_n::op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1)
        {
            CMI(bnz_mul(*dst, *src0, *src1));
            CMI(bnz_mod(*dst, *dst, n));
        }

        void Z_mul_n::iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1)
        {
            CMV(bnz_t tmp);
            CMI(bnz_init(tmp));
            CMM_IF(!CMI(bnz_invert(tmp, *src1, n)))
                ZK_CMI_HANDLE_ERROR_CMV_IN("no inverse exists");
            CMM_ENDIF
            CMI(bnz_mul(*dst, tmp, *src0));
            CMI(bnz_mod(*dst, *dst, n));
            CMI(bnz_clear(tmp));
        }

        void Z_mul_n::pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1)
        {
            CMI(bnz_powm(*dst, *src0, src1, n));
        }

        void Z_mul_n::ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1)
        {
            CMV(bnz_t tmp);
            CMI(bnz_init(tmp));
            CMI(bnz_neg(tmp, src1));
            CMI(bnz_powm(*dst, *src0, tmp, n));
            CMI(bnz_clear(tmp));
        }

        void Z_mul_n::pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1)
        {
            CMM_IF(src1 < CMV_IN(0))
                CMM_IF(!CMI(bnz_invert(*dst, *src0, n)))
                    ZK_CMI_HANDLE_ERROR_CMV_IN("no inverse exists");
                CMM_ENDIF
                CMI(bnz_powm_ui(*dst, *dst, CMV::zk_ulong_t(-src1), n));
            CMM_ELSE
                CMI(bnz_powm_ui(*dst, *src0, CMV::zk_ulong_t(src1), n));
            CMM_ENDIF

            // Workaround without using any if-clauses, but slower...
            //CMV(bnz_t exp);
            //CMI(bnz_init_set_si(exp, src1));
            //CMI(bnz_powm(*dst, *src0, exp, n));
            //CMI(bnz_clear(exp));
        }

        void Z_mul_n::random(CMV::bnz_t *dst)
        {
            CMI(Random::rangeinv0(*dst, n));
            
            if(randmode == z_mul_n_randmode_qr) pow(dst, dst, CMV_IN(2l));
        }

        void Z_mul_n::random(CMV::bnz_t *dst, const CMV::bnz_t& tightness)
        {
            (void) tightness;
            random(dst);
        }
        
        CMV::Relation Z_mul_n::cmp(const CMV::bnz_t *a, const CMV::bnz_t *b)
        {
            CMV(Relation result);
            CMM_IF(CMI(bnz_cmp(*a, *b)))
                result = CMV_IN(R_UN);
            CMM_ELSE
                result = CMV_IN(R_ID);
            CMM_ENDIF
            return result;
        }
        
        CMV::zk_bool_t Z_mul_n::inGroup(const CMV::bnz_t *src)
        {
            CMV(zk_bool_t ret);

            /* src must be in [1, n) */
            CMM_IF((CMI(bnz_cmp_ui(*src, CMV_IN(1ul))) < CMV_IN(0)))
                ret = CMV_IN(false);
            CMM_ELIF(CMI(bnz_cmp(*src, n)) >= CMV_IN(0))
                ret = CMV_IN(false);
            CMM_ELSE
                /* check if gcd(src, n) is 1 */
                CMV(bnz_t tmp);
                CMI(bnz_init(tmp));
                CMI(bnz_gcd(tmp, *src, n));

                CMM_IF(CMI(bnz_cmp_ui(tmp, CMV_IN(1ul))) == CMV_IN(0))
                    ret = CMV_IN(true);
                CMM_ELSE
                    ret = CMV_IN(false);
                CMM_ENDIF

                CMI(bnz_clear(tmp));

                /* as the factorization of n is not known, it can't be verified if the element is indeed in the group */
            CMM_ENDIF

            return ret;
        }
    }
}
