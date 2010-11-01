/** \file hash.hpp
 ** \brief Contains the definition of the abstract Hash class
 **/
#ifndef ZK_HASH_HPP
#define ZK_HASH_HPP

namespace ZKCompiler {
    /** \brief abstract interface for all hash functions **/
    class Hash {
        public:
            /** \brief get the name of this hash function
             ** \return name of the hash function
             **/
            const char *getName();

            /** \brief get the size of the digest in bytes
             ** \return size of digest
             **/
            unsigned getSize();

            /** \brief destructor for Hash **/
            virtual ~Hash() = 0;

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
            virtual void update(void *data, unsigned long len, bool copy) = 0;

            /** \brief finish hashing and get hash value
             ** \return pointer into array of \a size bytes
             **
             ** There is exactly one digest buffer per Hash object. It must not be freed, it will be overwritten if
             ** you call \a final() again.
             **
             ** Will also \a reset the state.
             **/
            virtual unsigned char *final() = 0;

            /** \brief reset state to what it was directly after object creation
             ** \return nothing
             **/
            virtual void reset() = 0;

        protected:
            /** \brief constructor, only used by inheriting classes
             ** \param name name of the hash function, e.g. "SHA1". Only the pointer is copied, not the string itself!
             ** \param size number of bytes in digest, e.g. 20
             **/
            Hash(const char *name, unsigned size);

        private:
            /** \brief name of hash function **/
            const char *name;

            /** \brief number of bytes in digest **/
            unsigned size;
    };
}

#endif
