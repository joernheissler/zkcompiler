/** \file random.hpp
 ** \brief Contains the definition of the Random class
 **/
#ifndef ZK_RANDOM_HPP
#define ZK_RANDOM_HPP

#include "bignum/bignum.hpp"

namespace ZKCompiler {
    /** \brief Random class **/
    class Random {
        public:
            /** \brief initialize random seed; needs to be called before all other functions, e. g. at program start **/
            static void init(void);

            /** \brief uninitialize random seed; needs to be called after all other functions, e. g. at program exit **/
            static void free(void);

            /** \brief get random number from [min, max)
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void range(bnz_t& d, const bnz_t& min, const bnz_t& max);

            /** \brief get random number from [0, max)
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void range0(bnz_t& d, const bnz_t& max);

            /** \brief get random [min, max) with existing multiplicative inverse modulus max
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void rangeinv(bnz_t& d, const bnz_t& min, const bnz_t& max);

            /** \brief get random [0, max) with existing multiplicative inverse modulus max
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void rangeinv0(bnz_t& d,  const bnz_t& max);

            /** \brief get random number from [0, max)
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void posrange(bnz_t& d, const bnz_t& max);
            
            /** \brief get random number from [min, max]
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void irange(bnz_t& d, const bnz_t& min, const bnz_t& max);
            
            /** \brief get random number from [0, max]
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void irange0(bnz_t& d, const bnz_t& max);

            /** \brief get random number from [0, 2^b)
             ** \param d destination
             ** \param b maximum number of bits
             ** \return nothing
             **/
            static void bits(bnz_t& d, unsigned b);
            
            /** \brief get random number from [2^(b-1), 2^b)
             ** \param d destination
             ** \param b exact number of bits
             ** \return nothing
             **/
            static void exactbits(bnz_t& d, unsigned b);
            
            /** \brief probabilistic primality test
             ** \param p number to check for primality
             ** \return true = is probably prime, false = is definitely not prime
             **/
            static int  is_prime(const bnz_t& p);

            /** \brief get prime random number from [min, max)
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void prange(bnz_t& d, const bnz_t& min, const bnz_t& max);

            /** \brief get prime random number from [0, max)
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void prange0(bnz_t& d, const bnz_t& max);

            /** \brief get prime random number from [0, max)
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void pposrange(bnz_t& d, const bnz_t& max);
            
            /** \brief get prime random number from [min, max]
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void pirange(bnz_t& d, const bnz_t& min, const bnz_t& max);
            
            /** \brief get prime random number from [0, max]
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void pirange0(bnz_t& d, const bnz_t& max);

            /** \brief get prime random number from [0, 2^b)
             ** \param d destination
             ** \param b maximum number of bits
             ** \return nothing
             **/
            static void pbits(bnz_t& d, unsigned b);
            
            /** \brief get prime random number from [2^(b-1), 2^b)
             ** \param d destination
             ** \param b exact number of bits
             ** \return nothing
             **/
            static void pexactbits(bnz_t& d, unsigned b);
            
            /** \brief probabilistic primality test for safe primes
             ** \param p number to check for primality
             ** \return true = is probably safe prime, false = is definitely not safe prime
             **/
            static int  is_safeprime(const bnz_t& p);

            /** \brief get safe prime random number from [min, max)
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void srange(bnz_t& d, const bnz_t& min, const bnz_t& max);

            /** \brief get safe prime random number from [0, max)
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void srange0(bnz_t& d, const bnz_t& max);

            /** \brief get safe prime random number from [0, max)
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void sposrange(bnz_t& d, const bnz_t& max);
            
            /** \brief get safe prime random number from [min, max]
             ** \param d destination
             ** \param min minimum
             ** \param max maximum
             ** \return nothing
             **/
            static void sirange(bnz_t& d, const bnz_t& min, const bnz_t& max);
            
            /** \brief get safe prime random number from [0, max]
             ** \param d destination
             ** \param max maximum
             ** \return nothing
             **/
            static void sirange0(bnz_t& d, const bnz_t& max);

            /** \brief get safe prime random number from [0, 2^b)
             ** \param d destination
             ** \param b maximum number of bits
             ** \return nothing
             **/
            static void sbits(bnz_t& d, unsigned b);
            
            /** \brief get safe prime random number from [2^(b-1), 2^b)
             ** \param d destination
             ** \param b exact number of bits
             ** \return nothing
             **/
            static void sexactbits(bnz_t& d, unsigned b);

        private:
            /** \brief was init called? **/
            static int initialized;

            /** \brief state of prng **/
            static bn_randstate_t randstate;

            /** \brief get random number from [0,max) **/
            static void urandomm(bnz_t& d, const bnz_t& max);

            /** \brief get random number from [0, 2^b) **/
            static void urandomb(bnz_t& d, unsigned b);

            /** \brief probabilistic primality test **/
            static int probable_prime_p(const bnz_t& p, int prob, unsigned long div);
    };
}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

CMD_CODE_DEFINITIONS_BLOCK_EX(ZKCompiler)
{
    //void init(void);
    //void free(void);
    CMD_PROCEDURE_o1i2_sm(Random, range, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_PROCEDURE_o1i1_sm(Random, range0, bnz_t, bnz_t, const bnz_t&)
    CMD_PROCEDURE_o1i2_sm(Random, rangeinv, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_PROCEDURE_o1i1_sm(Random, rangeinv0, bnz_t, bnz_t, const bnz_t&)
    //void posrange(bnz_t& d, const bnz_t& max);
    CMD_PROCEDURE_o1i2_sm(Random, irange, bnz_t, bnz_t, bnz_t, const bnz_t&, const bnz_t&)
    CMD_PROCEDURE_o1i1_sm(Random, irange0, bnz_t, bnz_t, const bnz_t&)
    //void bits(bnz_t& d, unsigned b);
    //void exactbits(bnz_t& d, unsigned b);
    //int  is_prime(const bnz_t& p);
    //void prange(bnz_t& d, const bnz_t& min, const bnz_t& max);
    //void pposrange(bnz_t& d, const bnz_t& max);
    //void pirange(bnz_t& d, const bnz_t& min, const bnz_t& max);
    //void pbits(bnz_t& d, unsigned b);
    //void pexactbits(bnz_t& d, unsigned b);
    //int  is_safeprime(const bnz_t& p);
    //void srange(bnz_t& d, const bnz_t& min, const bnz_t& max);
    //void sposrange(bnz_t& d, const bnz_t& max);
    //void sirange(bnz_t& d, const bnz_t& min, const bnz_t& max);
    //void sbits(bnz_t& d, unsigned b);
    //void sexactbits(bnz_t& d, unsigned b);
}

#endif

#endif
