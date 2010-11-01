/** \file z_add_n.hpp
 ** \brief Contains the definition of the group::Z_add_n class
 **/
#ifndef ZK_GROUP_ZADDN_HPP
#define ZK_GROUP_ZADDN_HPP

#include "group/group.hpp"

namespace ZKCompiler {
    namespace group {
        /** \brief Represents a Z_add_n group with its operations
         **
         ** Operation is the usual addition, but modulo \a n
         ** All elements are in the range 0 .. \a n-1
         **/
        class Z_add_n : public Group {
            public:
                /** \brief constructor for group::Z_add_n
                 ** \param n modulus \a n, must be >= 1
                 **/
                Z_add_n(CMV::zk_ulong_t n);

                /** \brief constructor for group::Z_add_n
                 ** \param n modulus \a n, must be >= 1
                 **/
                Z_add_n(const CMV::bnz_t& n);

                /** \brief constructor for group::Z_add_n
                 ** \param parser pointer to Parser Object
                 ** \param n number of parameters in \a params; should be 1
                 ** \param params pointer to \a n CStrings; should be { "\a n" }
                 **               where \a n is an integer >= 1
                 **/
                Z_add_n(Parser *parser, unsigned n, const char * const params[]);

                /** \brief destructor for group::Z_add_n **/
                ~Z_add_n();

                /** \brief set \a dst to the identity 0
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void identity(CMV::bnz_t *dst);

                /** \brief set \a dst to 0
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void min(CMV::bnz_t *dst);

                /** \brief set \a dst to 0
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void max(CMV::bnz_t *dst);

                /** \brief compute dst = -src % \a n
                 ** \param dst pointer to destination
                 ** \param src pointer to operand
                 ** \return nothing
                 **/
                void inverse(CMV::bnz_t *dst, const CMV::bnz_t *src);

                /** \brief compute \a dst = \a src0 + \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1);

                /** \brief compute \a dst = \a src0 - \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1);

                /** \brief compute \a dst = \a src0 * \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1);

                /** \brief compute \a dst = \a src0 * \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 second operand
                 ** \return nothing
                 **/
                void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1);

                /** \brief compute \a dst = - \a src0 * \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1);

                /** \brief set \a dst to a random value from the set [0, \a n-1]
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void random(CMV::bnz_t *dst);

                /** \brief set \a dst to a random value from the set [0, \a n-1]
                 ** \param dst pointer to destination
                 ** \param tightness unused
                 ** \return nothing
                 **/
                void random(CMV::bnz_t *dst, const CMV::bnz_t& tightness);

                /** \brief compare two \link Element Elements \endlink
                 ** \param a pointer to first operand
                 ** \param b pointer to second operand
                 ** \return R_ID, R_UN if \a a is equal to, not equal to \a b
                 **/
                CMV::Relation cmp(const CMV::bnz_t *a, const CMV::bnz_t *b);

                /** \brief check, if element is in group, i.e. if it's in [0,n)
                 ** \param src element to check
                 ** \return true=is in group, false=is not in group
                 **/
                CMV::zk_bool_t inGroup(const CMV::bnz_t *src);

            private:
                /** \brief modulus **/
                CMV::bnz_t n;
        };
    }
}

#endif
