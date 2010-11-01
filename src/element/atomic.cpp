#include "element/atomic.hpp"
#include "element/tuple.hpp"
#include "util/errorhandling.hpp"
#include "util/zkprint.hpp"

using namespace std;

#define C(x) ((Atomic*)(x))

/* assert_samegroup_set(src0); becomes:
 * if((src0)->getType() != Element_Atomic || this->g != ((Atomic*)(src0))->g) ZK_HANDLE_ERROR("different groups");
 * if(CMM_IS_EXECUTING && !(src0)->isSet()) ZK_HANDLE_ERROR("src0 not set");
 */
#define assert_samegroup_set(o) if((o)->getType() != Element_Atomic || this->g != C(o)->g) ZK_HANDLE_ERROR("different groups");\
                                if(CMM_IS_EXECUTING && !(o)->isSet()) ZK_HANDLE_ERROR(#o " not set")

namespace ZKCompiler {
    CMO_USING_OPERATORS;
    namespace element {
        Atomic::Atomic(Group *g_)
        {
            g = g_;
            size = g->getSize();
            CMV_NEW_ARRAY(z, bnz_t, size);
            for(unsigned i = 0; i < size; ++i)
                CMI(bnz_init(z[i]));
            isset = false;
        }

        Atomic::~Atomic()
        {
            for(unsigned i = 0; i < size; ++i)
                CMI(bnz_clear(z[i]));
            CMV_DELETE_ARRAY(z, bnz_t, size);
        }

        Element_Type Atomic::getType()
        {
            return Element_Atomic;
        }

        unsigned Atomic::getSize()
        {
            return size;
        }

        Element *Atomic::getSub(unsigned k)
        {
            (void) k;
            ZK_HANDLE_ERROR("getSub can not be used with Atomic Elements");
            return NULL;
        }

        void Atomic::print()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Atomic::print() is not allowed to be called in not executed code regions when code is collecting!");
            if(CMM_IS_EXECUTING && !isset) {
                printf("unset\n");
                return;
            }
            if(size == 1) {
                printf("%s\n", bnToStr(CMV_OUT(z[0])).c_str());
            } else {
                printf("(%s", bnToStr(CMV_OUT(z[0])).c_str());
                for(unsigned i = 1; i < size; ++i) printf(",%s", bnToStr(CMV_OUT(z[i])).c_str());
                printf(")\n");
            }
        }

        Element *Atomic::element()
        {
            return new Atomic(g);
        }

        void Atomic::identity()
        {
            g->identity(z);
            isset = true;
        }

        void Atomic::min()
        {
            g->min(z);
            isset = true;
        }

        void Atomic::max()
        {
            g->max(z);
            isset = true;
        }

        void Atomic::inverse(Element *src)
        {
            assert_samegroup_set(src);

            g->inverse(z, C(src)->z);
            isset = true;
        }

        void Atomic::op(Element *src0, Element *src1)
        {
            assert_samegroup_set(src0);
            assert_samegroup_set(src1);

            g->op(z, C(src0)->z, C(src1)->z);
            isset = true;
        }

        void Atomic::iop(Element *src0, Element *src1)
        {
            assert_samegroup_set(src0);
            assert_samegroup_set(src1);

            g->iop(z, C(src0)->z, C(src1)->z);
            isset = true;
        }

        void Atomic::pow(Element *src0, const CMV::bnz_t& src1)
        {
            assert_samegroup_set(src0);

            g->pow(z, C(src0)->z, src1);
            isset = true;
        }

        void Atomic::pow(Element *src0, Element *src1)
        {
            if(src1->getType() != Element_Atomic || src1->getSize() != 1) ZK_HANDLE_ERROR("invalid exponent");
            if(CMM_IS_EXECUTING && !src1->isSet()) ZK_HANDLE_ERROR("src1 not set");

            pow(src0, C(src1)->z[0]);
        }

        void Atomic::pow(Element *src0, CMV::zk_long_t src1)
        {
            assert_samegroup_set(src0);

            g->pow(z, C(src0)->z, src1);
            isset = true;
        }

        void Atomic::ipow(Element *src0, const CMV::bnz_t& src1)
        {
            assert_samegroup_set(src0);

            g->ipow(z, C(src0)->z, src1);
            isset = true;
        }

        void Atomic::ipow(Element *src0, Element *src1)
        {
            if(src1->getType() != Element_Atomic || src1->getSize() != 1) ZK_HANDLE_ERROR("invalid exponent");
            if(CMM_IS_EXECUTING && !src1->isSet()) ZK_HANDLE_ERROR("src1 not set");

            ipow(src0, C(src1)->z[0]);
        }

        void Atomic::random()
        {
            g->random(z);
            isset = true;
        }

        void Atomic::random(const CMV::bnz_t& tightness)
        {
            g->random(z, tightness);
            isset = true;
        }
        
        void Atomic::cast(Element *src)
        {
            if(size != src->getSize()) ZK_HANDLE_ERROR("incompatible groups");
            /* FIXME: ugly code. Atomic should not know about Tuple and vice versa. */
            if(src->getType() == Element_Tuple) {
                cast(((Tuple*)src)->getSub(0));
                return;
            }
            if(CMM_IS_EXECUTING && !src->isSet()) ZK_HANDLE_ERROR("src not set");
            g->set(z, C(src)->z);
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }
    
        void Atomic::set(Element *src)
        {
            assert_samegroup_set(src);
            
            g->set(z, C(src)->z);
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }

        void Atomic::set(CMV::zk_pcchar_t str)
        {
            if(size != 1) ZK_HANDLE_ERROR("wrong size");
            CMM_IF(CMI(bnz_set_str(z[0], str, CMV_IN(0))))
                ZK_CMI_HANDLE_ERROR_CMV_IN("conversion error");
            CMM_ENDIF
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }

        void Atomic::set(const CMV::bnz_t& src)
        {
            if(size != 1) ZK_HANDLE_ERROR("wrong size");
            CMI(bnz_set(z[0], src));
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }

        void Atomic::set(CMV::zk_pcchar_t const * str, unsigned n)
        {
            if(size != n) ZK_HANDLE_ERROR("wrong size");
            for(unsigned i = 0; i < n; ++i)
            {
                CMM_IF(CMI(bnz_set_str(z[i], str[i], CMV_IN(0))))
                    ZK_CMI_HANDLE_ERROR_CMV_IN("conversion error");
                CMM_ENDIF
            }
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }

        void Atomic::set(const CMV::bnz_t *src, unsigned n)
        {
            if(size != n) ZK_HANDLE_ERROR("wrong size");
            for(unsigned i = 0; i < n; ++i) CMI(bnz_set(z[i], src[i]));
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }

        void Atomic::set(const CMV::bnz_t* vpSrc[], unsigned n)
        {
            if(size != n) ZK_HANDLE_ERROR("wrong size");
            for(unsigned i = 0; i < n; ++i) CMI(bnz_set(z[i], *vpSrc[i]));
            CMM_IF(!g->inGroup(z))
                ZK_CMI_HANDLE_ERROR_CMV_IN("element not in group");
            CMM_ENDIF
            isset = true;
        }

        void Atomic::set(Message msg)
        {
#ifdef CM_ENABLE_CODE_COLLECTING
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Atomic::set(Message) is not allowed to be called in not executed code regions when code is collecting!");
            CMM_COMMENT("WARNING: Atomic::set(Message) called in compiler mode!\n"
                "You CAN NOT collect the structure Message currently! Use it only for testing.\n"
                "If you want to collect code, use the getter/setter with CMV::bnz_t-types...");
            if (size == 1)
            {
                bnz_t zIn;
                bnz_init(zIn);
                Convert::messageToMpzt(msg, zIn);
                CMI(bnz_set(z[0], CMV_IN(zIn)));
                bnz_clear(zIn);
            }
            else
            {
                bnz_t* pZIn = new bnz_t[size];
                for (unsigned i = 0; i < size; ++i)
                    bnz_init(pZIn[i]);
                Convert::messageToMpzt(msg, pZIn, size);
                for (unsigned i = 0; i < size; ++i)
                {
                    CMI(bnz_set(z[i], CMV_IN(pZIn[i])));
                    bnz_clear(pZIn[i]);
                }
                delete[] pZIn;
            }
#else
            if(size == 1) Convert::messageToMpzt(msg, z[0]);
            else Convert::messageToMpzt(msg, z, size);
#endif
            if (!CMV_OUT(g->inGroup(z)))
                ZK_HANDLE_ERROR("element not in group");
            isset = true;
        }

        void Atomic::get(CMV::bnz_t& dst)
        {
            if(CMM_IS_EXECUTING && !isset) ZK_HANDLE_ERROR("this not set");
            if(size != 1) ZK_HANDLE_ERROR("wrong size");
            CMI(bnz_set(dst, z[0]));
        }

        void Atomic::get(CMV::bnz_t *dst, unsigned n)
        {
            if(CMM_IS_EXECUTING && !isset) ZK_HANDLE_ERROR("this not set");
            if(size != n) ZK_HANDLE_ERROR("wrong size");
            for(unsigned i = 0; i < n; ++i) CMI(bnz_set(dst[i], z[i]));
        }

        void Atomic::getPtrs(const CMV::bnz_t* vpDst[], unsigned n) const
        {
            if(CMM_IS_EXECUTING && !isset) ZK_HANDLE_ERROR("this not set");
            if(size != n) ZK_HANDLE_ERROR("wrong size");
            for(unsigned i = 0; i < n; ++i) vpDst[i] = &z[i];
        }

        Message Atomic::get()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Message Atomic::get() is not allowed to be called in not executed code regions when code is collecting!");
            CMM_COMMENT("WARNING: Message Atomic::get() called in compiler mode!\n"
                "You CAN NOT collect the structure Message currently! Use it only for testing.\n"
                "If you want to collect code, use the getter/setter with CMV::bnz_t-types...");
            if (CMM_IS_EXECUTING && !isset)
                ZK_HANDLE_ERROR("this not set");
#ifdef CM_ENABLE_CODE_COLLECTING
            Message msg;
            if (size == 1)
                msg = Convert::mpztToMessage(CMV_OUT(z[0]));
            else
            {
                bnz_t* pZOut = new bnz_t[size];
                for (unsigned i = 0; i < size; ++i)
                    bnz_init_set(pZOut[i], CMV_OUT(z[i]));
                msg = Convert::mpztToMessage(pZOut, size);;
                for (unsigned i = 0; i < size; ++i)
                    bnz_clear(pZOut[i]);
                delete[] pZOut;
            }
            return msg;
#else
            return size == 1 ? Convert::mpztToMessage(z[0]) : Convert::mpztToMessage(z, size);
#endif
        }

        CMV::Relation Atomic::cmp(Element *other)
        {
            assert_samegroup_set(other);
            if(CMM_IS_EXECUTING && !isset) ZK_HANDLE_ERROR("this not set");
            return g->cmp(z, C(other)->z);
        }

        bool Atomic::isSet()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Atomic::isSet() is not allowed to be called in not executed code regions when code is collecting!");
            return isset;
        }

        void Atomic::set()
        {
            isset = true;
        }

        void Atomic::unset()
        {
            isset = false;
        }
    }
}
