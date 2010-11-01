/** \file group.hpp
 ** \brief Contains the definition of the Group class
 **/
#ifndef ZK_GROUP_HPP
#define ZK_GROUP_HPP

namespace ZKCompiler {
    class Group;
}

#include "bignum/bignum.hpp"
#include "element/element.hpp"
#include "parser/parser.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    /** \brief Represents a group with its operations **/
    class Group {
        public:
            /** \brief Group factory; creates Group objects for subclasses
             ** \param parser pointer to Parser Object
             ** \param type the implementing subclass, one of
             **     \link ZKCompiler::group::Z Z \endlink,
             **     \link ZKCompiler::group::Z_add_n \endlink,
             **     \link ZKCompiler::group::Z_mul_n Z_mul_n \endlink
             **     This object lives until Parser is destroyed.
             ** \param n number of parameters in \a params
             ** \param params pointer to \a n CStrings
             **     This object lives until Parser is destroyed; must not be changed.
             ** \return pointer to new group object upcast to Group
             **/
            static Group *create(Parser *parser, const char *type, unsigned n, const char * const params[]);

            /** \brief constructor for Group
             ** \param size number of bnz_t an Element of this Group consists of
             **/
            Group(unsigned size);

            /** \brief destructor for Group **/
            virtual ~Group() = 0;

            /** \brief returns the number of bnz_t an Element of this Group consists of
             ** \return the number of bnz_t an Element of this Group consists of
             **/
            unsigned getSize();

            /** \brief set \a dst to the identity
             ** \param dst pointer to destination
             ** \return nothing
             **/
            virtual void identity(CMV::bnz_t *dst) = 0;

            /** \brief set \a dst to minimum value (or identity if there is no minimum)
             ** \param dst pointer to destination
             ** \return nothing
             **/
            virtual void min(CMV::bnz_t *dst) = 0;

            /** \brief set \a dst to maximum value (or identity if there is no maximum)
             ** \param dst pointer to destination
             ** \return nothing
             **/
            virtual void max(CMV::bnz_t *dst) = 0;

            /** \brief compute the inverse of \a src and write it to \a dst
             ** \param dst pointer to destination
             ** \param src pointer to operand
             ** \return nothing
             **/
            virtual void inverse(CMV::bnz_t *dst, const CMV::bnz_t *src) = 0;

            /** \brief compute \a dst = \a src0 OP \a src1
             ** \param dst pointer to destination
             ** \param src0 pointer to first operand
             ** \param src1 pointer to second operand
             ** \return nothing
             **/
            virtual void op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1) = 0;

            /** \brief compute \a dst = \a src0 OP \a src1^-1
             ** \param dst pointer to destination
             ** \param src0 pointer to first operand
             ** \param src1 pointer to second operand
             ** \return nothing
             **/
            virtual void iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1) = 0;

            /** \brief raise \a src0 to the power of \a src1 and store result in \a dst
             ** \param dst pointer to destination
             ** \param src0 pointer to base
             ** \param src1 exponent
             ** \return nothing
             **/
            virtual void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1) = 0;

            /** \brief raise \a src0 to the power of \a src1 and store result in \a dst
             ** \param dst pointer to destination
             ** \param src0 pointer to base
             ** \param src1 exponent
             ** \return nothing
             **/
            virtual void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1) = 0;

            /** \brief raise inverse of \a src0 to the power of \a src1 and store result in \a dst
             ** \param dst pointer to destination
             ** \param src0 pointer to base
             ** \param src1 exponent
             ** \return nothing
             **/
            virtual void ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1) = 0;

            /** \brief set \a dst to a random Element
             ** \param dst pointer to destination
             ** \return nothing
             **/
            virtual void random(CMV::bnz_t *dst) = 0;

            /** \brief set \a dst to a random Element with additional \a tightness property
             ** \param dst pointer to destination
             ** \param tightness if it makes sense, enlarge the set of random \link Element Elements \endlink by this factor
             ** \return nothing
             **/
            virtual void random(CMV::bnz_t *dst, const CMV::bnz_t& tightness) = 0;

            /** \brief compare two \link Element Elements \endlink
             ** \param a pointer to first operand
             ** \param b pointer to second operand
             ** \return the \a Relation between the two operands
             **/
            virtual CMV::Relation cmp(const CMV::bnz_t *a, const CMV::bnz_t *b) = 0;

            /** \brief set \a dst to \a src by copying all bnz_t
             ** \param dst pointer to destination
             ** \param src pointer to source
             ** \return nothing
             **/
            void set(CMV::bnz_t *dst, const CMV::bnz_t *src);

            /** \brief check, if element is in group
             ** \param src element to check
             ** \return true=might be in group, false=is definitely not in group
             **/
            virtual CMV::zk_bool_t inGroup(const CMV::bnz_t *src) = 0;

        protected:
            /** \brief number of bnz_t an Element of this Group consists of **/
            unsigned size;
    };
}

#endif
