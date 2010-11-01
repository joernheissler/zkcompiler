#include "element/tuple.hpp"
#include "util/basictypes.hpp"
#include "util/errorhandling.hpp"
#include "util/zkprint.hpp"

using namespace std;

#define C(x) ((Tuple*)(x))
#define assert_samegroup(o) if((o)->getType() != Element_Tuple || this->n != C(o)->n) ZK_HANDLE_ERROR("different groups")

namespace ZKCompiler {
    CMO_USING_OPERATORS;

    namespace element {
        /** \brief list of Elements, used by cast() method **/
        struct ElementList {
            /** \brief next node in list **/
            ElementList *next;
            /** payload of list node; pointer to the Element **/
            Element *e;
        };

        ElementList *Tuple::getAtomList(Element *x)
        {
            // create a new list which contains the Tuple as sole Element
            ElementList *list = new ElementList;
            list->next = 0;
            list->e = x;

            // traverse the list and replace each Tuple with the sub Elements of the tuple
            for(ElementList *p = list; p; p = p->next) {
                // Atoms need no changes, skip over them
                if(p->e->getType() != Element_Tuple) continue;

                // change current list node to first sub element; remember pointer to tuple
                Tuple *tuple = C(p->e);
                p->e = tuple->sub[0];
                
                ElementList *cur = p;

                // for each other sub element, create a new node and insert it after `cur'
                for(unsigned i = 1; i < tuple->n; ++i) {
                    ElementList *e = new ElementList;
                    e->next = cur->next;
                    e->e = tuple->sub[i];
                    cur->next = e;
                    cur = e;
                }
            }
            return list;
        }

        Tuple::Tuple(unsigned n_, Element **sub_)
        {
            n = n_;
            if(n == 0) ZK_HANDLE_ERROR("zero-sized tuple is invalid");
            sub = sub_;
        }

        Tuple::~Tuple()
        {
            /* FIXME: Flag, um Unterelemente nicht zu löschen! Uh, wozu war die Idee noch gleich? */
            for(unsigned i = 0; i < n; ++i) delete sub[i];
            delete[] sub;
        }

        Element_Type Tuple::getType()
        {
            return Element_Tuple;
        }

        unsigned Tuple::getSize()
        {
            unsigned s = 0;
            for(unsigned i = 0; i < n; ++i) s += sub[i]->getSize();
            return s;
        }
        
        Element *Tuple::getSub(unsigned k)
        {
            if(k >= n) ZK_HANDLE_ERROR("invalid sub index");
            return sub[k];
        }

        void Tuple::print()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Tuple::print() is not allowed to be called in not executed code regions when code is collecting!");
            printf("[");
            sub[0]->print();
            for(unsigned i = 1; i < n; ++i) { printf(", "); sub[i]->print(); }
            printf("]\n");
        }

        Element *Tuple::element()
        {
            Element **sub_ = new Element*[n];
            for(unsigned i = 0; i < n; ++i) sub_[i] = sub[i]->element();
            return new Tuple(n, sub_);
        }

        void Tuple::identity()
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->identity();
        }

        void Tuple::min()
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->min();
        }

        void Tuple::max()
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->max();
        }

        void Tuple::inverse(Element *src)
        {
            assert_samegroup(src);

            for(unsigned i = 0; i < n; ++i) sub[i]->inverse(C(src)->sub[i]);
        }

        void Tuple::op(Element *src0, Element *src1)
        {
            assert_samegroup(src0);
            assert_samegroup(src1);

            for(unsigned i = 0; i < n; ++i) sub[i]->op(C(src0)->sub[i], C(src1)->sub[i]);
        }

        void Tuple::iop(Element *src0, Element *src1)
        {
            assert_samegroup(src0);
            assert_samegroup(src1);

            for(unsigned i = 0; i < n; ++i) sub[i]->iop(C(src0)->sub[i], C(src1)->sub[i]);
        }

        void Tuple::pow(Element *src0, const CMV::bnz_t& src1)
        {
            assert_samegroup(src0);

            for(unsigned i = 0; i < n; ++i) sub[i]->pow(C(src0)->sub[i], src1);
        }

        void Tuple::pow(Element *src0, Element *src1)
        {
            assert_samegroup(src0);

            for(unsigned i = 0; i < n; ++i) sub[i]->pow(C(src0)->sub[i], src1);
        }

        void Tuple::pow(Element *src0, CMV::zk_long_t src1)
        {
            assert_samegroup(src0);

            for(unsigned i = 0; i < n; ++i) sub[i]->pow(C(src0)->sub[i], src1);
        }

        void Tuple::ipow(Element *src0, const CMV::bnz_t& src1)
        {
            assert_samegroup(src0);

            for(unsigned i = 0; i < n; ++i) sub[i]->ipow(C(src0)->sub[i], src1);
        }

        void Tuple::ipow(Element *src0, Element *src1)
        {
            assert_samegroup(src0);

            for(unsigned i = 0; i < n; ++i) sub[i]->ipow(C(src0)->sub[i], src1);
        }

        void Tuple::random()
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->random();
        }

        void Tuple::random(const CMV::bnz_t& tightness)
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->random(tightness);
        }

        void Tuple::cast(Element *src)
        {
            ElementList *a = getAtomList(this);
            ElementList *b = getAtomList(src);

            // traverse both lists, cast the Atomic elements and clean up the nodes
            while(a && b) {
                a->e->cast(b->e);
                
                ElementList *anext = a->next;
                delete a;
                a = anext;
                
                ElementList *bnext = b->next;
                delete b;
                b = bnext;
            }
            if(a || b) ZK_HANDLE_ERROR("incompatible Elements while casting");
        }

        void Tuple::set(Element *src)
        {
            assert_samegroup(src);
            for(unsigned i = 0; i < n; ++i) sub[i]->set(C(src)->sub[i]);
        }

        void Tuple::set(CMV::zk_pcchar_t str)
        {
            if(n != 1) ZK_HANDLE_ERROR("wrong size");
            sub[0]->set(str);
        }

        void Tuple::set(const CMV::bnz_t& src)
        {
            if(n != 1) ZK_HANDLE_ERROR("wrong size");
            sub[0]->set(src);
        }

        void Tuple::set(CMV::zk_pcchar_t const * str, unsigned u)
        {
            for(unsigned i = 0; i < n; ++i) {
                unsigned s = sub[i]->getSize();
                if(u < s) ZK_HANDLE_ERROR("wrong size");
                sub[i]->set(str, s);
                str += s;
                u -= s;
            }
            if(u != 0) ZK_HANDLE_ERROR("wrong size");
        }

        void Tuple::set(const CMV::bnz_t *src, unsigned u)
        {
            for(unsigned i = 0; i < n; ++i) {
                unsigned s = sub[i]->getSize();
                if(u < s) ZK_HANDLE_ERROR("wrong size");
                sub[i]->set(src, s);
                src += s;
                u -= s;
            }
            if(u != 0) ZK_HANDLE_ERROR("wrong size");
        }

        void Tuple::set(const CMV::bnz_t* vpSrc[], unsigned u)
        {
            for(unsigned i = 0; i < n; ++i) {
                unsigned s = sub[i]->getSize();
                if(u < s) ZK_HANDLE_ERROR("wrong size");
                sub[i]->set(vpSrc, s);
                vpSrc += s;
                u -= s;
            }
            if(u != 0) ZK_HANDLE_ERROR("wrong size");
        }

        void Tuple::set(Message msg)
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Tuple::set(Message) is not allowed to be called in not executed code regions when code is collecting!");
            CMM_COMMENT("WARNING: Tuple::set(Message) called in compiler mode!\n"
                "You CAN NOT collect the structure Message currently! Use it only for testing.\n"
                "If you want to collect code, use the getter/setter with CMV::bnz_t-types...");
            if(n == 1) {
                sub[0]->set(msg);
                return;
            }
            Message *tmp = new Message[n];
            Convert::messageToMessages(msg, tmp, n, 0);
            for(unsigned i = 0; i < n; ++i) sub[i]->set(tmp[i]);
            delete[] tmp;
        }

        void Tuple::get(CMV::bnz_t& dst)
        {
            if(n != 1) ZK_HANDLE_ERROR("wrong size");
            sub[0]->get(dst);
        }

        void Tuple::get(CMV::bnz_t *dst, unsigned u)
        {
            for(unsigned i = 0; i < n; ++i) {
                unsigned s = sub[i]->getSize();
                if(u < s) ZK_HANDLE_ERROR("wrong size");
                sub[i]->get(dst, s);
                dst += s;
                u -= s;
            }
            if(u != 0) ZK_HANDLE_ERROR("wrong size");
        }

        void Tuple::getPtrs(const CMV::bnz_t* vpDst[], unsigned u) const
        {
            for(unsigned i = 0; i < n; ++i) {
                unsigned s = sub[i]->getSize();
                if(u < s) ZK_HANDLE_ERROR("wrong size");
                sub[i]->getPtrs(vpDst, s);
                vpDst += s;
                u -= s;
            }
            if(u != 0) ZK_HANDLE_ERROR("wrong size");
        }

        Message Tuple::get()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Message Tuple::get() is not allowed to be called in not executed code regions when code is collecting!");
            CMM_COMMENT("WARNING: Message Tuple::get() called in compiler mode!\n"
                "You CAN NOT collect the structure Message currently! Use it only for testing.\n"
                "If you want to collect code, use the getter/setter with CMV::bnz_t-types...");
            if(n == 1) return sub[0]->get();

            Message *tmp = new Message[n];
            for(unsigned i = 0; i < n; ++i) tmp[i] = sub[i]->get();
            Message msg = Convert::messagesToMessage(tmp, n);
            for(unsigned i = 0; i < n; ++i) delete[] tmp[i].data;
            delete[] tmp;
            return msg;
        }

        CMV::Relation Tuple::cmp(Element *other)
        {
            assert_samegroup(other);

            CMV(zk_uint_t r);
            r = CMV_IN(0u);

            // the resulting relation is the bitwise or of each sub relation.
            for(unsigned i = 0; i < n; ++i)
                r |= CMV_CCAST(zk_uint_t, sub[i]->cmp(C(other)->sub[i]));

            // 14 and 15 has the same meaning. Use a single value: 15 (R_LG)
            CMM_IF(r == CMV_IN(14u))
                r = CMV_IN(15u); // R_LG
            CMM_ENDIF

            return CMV_CCAST(Relation, r);
        }

        bool Tuple::isSet()
        {
            if (!CMM_IS_EXECUTING)
                ZK_HANDLE_ERROR("Tuple::isSet() is not allowed to be called in not executed code regions when code is collecting!");
            for(unsigned i = 0; i < n; ++i) if(!sub[i]->isSet()) return false;
            return true;
        }

        void Tuple::set()
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->set();
        }

        void Tuple::unset()
        {
            for(unsigned i = 0; i < n; ++i) sub[i]->unset();
        }
    }
}
