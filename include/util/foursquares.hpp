/** \file foursquares.hpp
 ** \brief contains definition of \a foursquares
 **/
#ifndef ZK_FOURSQUARES_HPP
#define ZK_FOURSQUARES_HPP

namespace ZKCompiler {
    /** \brief convert a nonnegative number \a w to 4 numbers \a w1,\a w2,\a w3,\a w4 such w1^2 + w2^2 + w3^2 + w4^2 = w
     ** \param w1 first destination
     ** \param w2 second destination
     ** \param w3 third destination
     ** \param w4 fourth destination
     ** \param w source
     ** \return nothing
     **/
    void foursquares(bnz_t& w1, bnz_t& w2, bnz_t& w3, bnz_t& w4, const bnz_t& w);
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

CMD_CODE_DEFINITIONS_BLOCK_EX(ZKCompiler)
{
    CMD_PROCEDURE_o4i1(foursquares, bnz_t, bnz_t, bnz_t, bnz_t, bnz_t, const bnz_t&)
}

#endif

#endif
