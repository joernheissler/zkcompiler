/** \file z.hpp
 ** \brief Contains the definition of the group::Z class
 **/
#ifndef ZK_GROUP_Z_HPP
#define ZK_GROUP_Z_HPP

#include "group/group.hpp"

namespace ZKCompiler {
    namespace group {
        /** \brief Represents a Z group with its operations **/
        class Z : public Group {
            public:
                /** \brief constructor for group::Z
                 ** \param min minimum value elements usually have
                 ** \param max maximum value elements usually have
                 **/
                Z(const CMV::bnz_t& min, const CMV::bnz_t& max);

                /** \brief constructor for group::Z
                 ** \param parser pointer to Parser Object
                 ** \param n number of parameters in \a params; should be 2
                 ** \param params pointer to \a n CStrings; should be { "min", "max" }
                 **/
                Z(Parser *parser, unsigned n, const char * const params[]);

                /** \brief destructor for group::Z **/
                ~Z();

                /** \brief set \a dst to the identity 0
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void identity(CMV::bnz_t *dst);

                /** \brief set \a dst to minimum value as given in the constructor
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void min(CMV::bnz_t *dst);

                /** \brief set \a dst to maximum value as given in the constructor
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void max(CMV::bnz_t *dst);

                /** \brief compute dst = -src
                 ** \param dst pointer to destination
                 ** \param src pointer to operand
                 ** \return nothing
                 **/
                void inverse(CMV::bnz_t *dst, const CMV::bnz_t *src);

                /** \brief compute \a dst = \a src0 + \a src1
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void op(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1);

                /** \brief compute \a dst = \a src0 - \a src1
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void iop(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t *src1);

                /** \brief compute \a dst = \a src0 * \a src1
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1);

                /** \brief compute \a dst = \a src0 * \a src1
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void pow(CMV::bnz_t *dst, const CMV::bnz_t *src0, CMV::zk_long_t src1);

                /** \brief compute \a dst = - \a src0 * \a src1
                 ** \param dst pointer to destination
                 ** \param src0 pointer to first operand
                 ** \param src1 pointer to second operand
                 ** \return nothing
                 **/
                void ipow(CMV::bnz_t *dst, const CMV::bnz_t *src0, const CMV::bnz_t& src1);

                /** \brief set \a dst to a random value from the set [\a mini, \a maxi]
                 ** \param dst pointer to destination
                 ** \return nothing
                 **/
                void random(CMV::bnz_t *dst);

                /** \brief set \a dst to a random value from the set [\a mini * \a tightness, \a maxi * \a tightness]
                 ** \param dst pointer to destination
                 ** \param tightness factor to enlarge the range [\a mini, \a maxi] by
                 ** \return nothing
                 **/
                void random(CMV::bnz_t *dst, const CMV::bnz_t& tightness);

                /** \brief compare two \link Element Elements \endlink
                 ** \param a pointer to first operand
                 ** \param b pointer to second operand
                 ** \return R_LT, R_EQ, R_GT if \a a is smaller than, equal to, larger than \a b
                 **/
                CMV::Relation cmp(const CMV::bnz_t *a, const CMV::bnz_t *b);

                /** \brief check, if element is in group. Every element is in Z
                 ** \param src element to check
                 ** \return true; false won't be returned.
                 **/
                CMV::zk_bool_t inGroup(const CMV::bnz_t *src);

            private:
                /** \brief minimum value for random functions **/
                CMV::bnz_t mini;

                /** \brief maximum value for random functions **/
                CMV::bnz_t maxi;

                /** temporary variable **/
                CMV::bnz_t minitight;

                /** temporary variable **/
                CMV::bnz_t maxitight;
        };
    }
}

#endif
