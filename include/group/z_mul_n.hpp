/** \file z_mul_n.hpp
 ** \brief Contains the definition of the group::Z_mul_n class
 **/
#ifndef ZK_GROUP_ZMULN_HPP
#define ZK_GROUP_ZMULN_HPP

#include "group/group.hpp"

namespace ZKCompiler {
    namespace group {
        /** \brief when picking random numbers, do so from the whole group or only from quadratic residues **/
        enum Z_mul_n_randmode {
            z_mul_n_randmode_default, /**< choose random numbers from whole group **/
            z_mul_n_randmode_qr       /**< choose randoms numbers from subgroup of quadratic residues **/
        };

        /** \brief Represents a Z_mul_n group with its operations
         **
         ** Operation is the usual multiplication, but modulo \a n
         ** All elements are in the range 1 .. n-1 and coprime to \a n
         **/
        class Z_mul_n : public Group {
            public:
                /** \brief constructor for group::Z_mul_n
                 ** \param n modulus \a n, must be >= 2
                 ** \param randmode member of Z_mul_n_randmode
                 **/
                Z_mul_n(CMV::zk_ulong_t n, Z_mul_n_randmode randmode);

                /** \brief constructor for group::Z_mul_n
                 ** \param n modulus \a n, must be >= 2
                 ** \param randmode member of Z_mul_n_randmode
                 **/
                Z_mul_n(const CMV::bnz_t& n, Z_mul_n_randmode randmode);

                /** \brief constructor for group::Z_mul_n
                 ** \param parser pointer to Parser Object
                 ** \param n number of parameters in \a params; should be 2
                 ** \param params pointer to \a n CStrings; should be { "\a n", "randmode" }
                 **               where \a n is an integer >= 2 and randmode is
                 **               a member of Z_mul_n_randmode
                 **/
                Z_mul_n(Parser *parser, unsigned n, const char * const params[]);

                /** \brief destructor for group::Z_mul_n **/
                ~Z_mul_n();

                /** \brief set \a dst to the identity 1
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void identity(CMV::bnz_t *dst);

                /** \brief set \a dst to 1
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void min(CMV::bnz_t *dst);

                /** \brief set \a dst to 1
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void max(CMV::bnz_t *dst);

                /** \brief compute dst = src^-1 % \a n
                 ** \param dst pointer to destination
                 ** \param src pointer to operand
                 ** \return nothing
                 **
                 ** dst * src = 1 % \a n
                 **/
                void inverse(CMV::bnz_t *dst, const CMV::bnz_t *src);

                /** \brief compute \a dst = \a src0 * \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1);

                /** \brief compute \a dst = \a src0 * \a src1^-1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1);

                /** \brief compute \a dst = \a src0 ^ \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1);

                /** \brief compute \a dst = \a src0 ^ \a src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 second operand
                 ** \return nothing
                 **/
                void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1);

                /** \brief compute \a dst = \a src0 ^ \a -src1 % \a n
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1);

                /** \brief set \a dst to a random value from the set [1, \a n-1] according to the randmode
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void random(CMV::bnz_t *dst);

                /** \brief set \a dst to a random value from the set [1, \a n-1] according to the randmode
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

                /** \brief check, if element is in group, i.e. if it's in [1,n) and gcd(src, n) is 1
                 ** \param src element to check
                 ** \return true=might be in group, false=is not in group
                 **
                 ** it's not possible to check if e.g. src is a quadratic residue or is generated
                 ** by a given generator. The sender of the element must prove it.
                 **/
                CMV::zk_bool_t inGroup(const CMV::bnz_t *src);

            private:
                /** \brief modulus **/
                CMV::bnz_t n;

                /** \brief random mode **/
                Z_mul_n_randmode randmode;
        };
    }
}

#endif
