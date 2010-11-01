/** \file sha1.hpp
 ** \brief Contains the definition of the SHA1 Hash class
 **/
#ifndef ZK_HASH_SHA1_HPP
#define ZK_HASH_SHA1_HPP

#include "hash/hash.hpp"
#include "sysdeps.hpp"

namespace ZKCompiler {
    /** \brief implementation of the SHA1 hash function **/
    class SHA1 : public Hash {
        public:
            /** \brief constructor for SHA1 **/
            SHA1();

            /** \brief destructor for SHA1 **/
            ~SHA1();

            /** \brief hash some data
             ** \param data pointer to the data; will be interpreted as array of unsigned char with \a len bytes
             ** \param len length of \a data, measured in bytes
             ** \param copy if \a copy is false, \a data will be modified; pass \a false, if
             **             data can be written and you don't need it anymore after hashing.
             **             Else pass \a true.
             ** \return nothing
             **
             ** Hashes \a len bytes from \a data. Use \a update until all data has been hashed, then call \a final().
             **/
            void update(void *data, unsigned long len, bool copy);

            /** \brief finish hashing and get hash value
             ** \return pointer into array of \a size bytes
             **
             ** There is exactly one digest buffer per Hash object. It must not be freed, it will be overwritten if
             ** you call \a final() again.
             **
             ** Will also \a reset the state.
             **/
            unsigned char *final();

            /** \brief reset state to what it was directly after object creation
             ** \return nothing
             **/
            void reset();

        private:
            /** \brief internal state: state **/
            UINT32_T state[5];

            /** \brief internal state: count **/
            UINT32_T count[2];

            /** \brief internal state: buffer **/
            unsigned char buffer[64];

            /** \brief buffer for the digest, will be returned by \a final() **/
            unsigned char digest[20];
    };
}

#endif
