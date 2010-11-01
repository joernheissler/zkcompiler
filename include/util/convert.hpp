/** \file convert.hpp
 ** \brief Contains the definition of the Convert class and Message type
 **/
#ifndef ZK_CONVERT_HPP
#define ZK_CONVERT_HPP

#include "bignum/bignum.hpp"

namespace ZKCompiler {
    /** \brief Represents a serialization of numbers, etc.
     **
     ** Format is: LLLL M*, i.e. 4 length bytes and a variable number of message bytes.
     **
     ** Each byte has 8 bits and everything is stored in big endian.
     ** The length includes itself
     **
     ** Binary data is stored as LLLL B*, i.e. just the binary data.
     ** Example: "Hello" = 00 00 00 0a 48 65 6c 6c 6f 00
     **
     ** A number (bnz_t) is stored as LLLL S N*, i.e. the sign (byte with value 0 or 1) and N*
     ** the number in base 256. Example: -123456 = 00 00 00 08 01 01 e2 40
     **
     ** Multiple numbers (bnz_t[]) are just stored one after each other, each with a length:
     ** LLLL LLLL N* LLLL N* LLLL N* ... Example: (31337, -3735928559, 15731626) =
     ** 00 00 00 1c 00 00 00 07 00 7A 69 00 00 00 09 01 DE AD BE EF 00 00 00 08 00 F0 0B AA
     **
     ** same format is used for multiple messages.
     **
     ** It is not stored how a message is to be interpreted; the communication partners must know themselves.
     **/
    struct Message {
        /** \brief pointer to message bytes, i.e. to first byte of the message length **/
        unsigned char *data;

        /** \brief total length of message including the length **/
        unsigned long length;
    };

    /** \brief class to convert from/to Message **/
    class Convert {
        public:
            /** \brief convert a single bnz_t to a Message
             ** \param src the number to be converted
             ** \return serialized number
             **/
            static Message mpztToMessage(const bnz_t& src);

            /** \brief convert a Message to a single bnz_t
             ** \param src serialized number
             ** \param dst the number goes here
             ** \return nothing
             **/
            static void messageToMpzt(Message src, bnz_t& dst);

            /** \brief convert \a u bnz_t to a Message
             ** \param src the numbers to be converted
             ** \param u count of numbers
             ** \return serialized numbers
             **/
            static Message mpztToMessage(bnz_t *src, unsigned int u);

            /** \brief convert a Message to multiple bnz_t
             ** \param src serialized numbers
             ** \param dst the numbers goes here
             ** \param u count of numbers; must match the count of sub messages in \a src, else an exception is thrown
             ** \return nothing
             **/
            static void messageToMpzt(Message src, bnz_t *dst, unsigned int u);
            
            /** \brief convert \a u Messages to a single Message
             ** \param src the Messages to be converted
             ** \param u count of Messages
             ** \return serialized Messages
             **/
            static Message messagesToMessage(Message *src, unsigned int u);
            
            /** \brief convert a Message to multiple Messages
             ** \param src serialized Messages
             ** \param dst the Messages goes here
             ** \param u count of Messages; must match the count of sub messages in \a src, else an exception is thrown
             ** \param copy false = dst[i].p will point into src.data; true = new memory is allocated and must be deleted by the user
             ** \return nothing
             **/
            static void messageToMessages(Message src, Message *dst, unsigned int u, bool copy);
            
            /** \brief convert a binary blob to a Message
             ** \param src the binary blob to be converted
             ** \param length length of binary blob
             ** \return serialized blob
             **/
            static Message bytesToMessage(const unsigned char *src, unsigned long length);
            
            /** \brief convert a Message to a binary blob
             ** \param src serialized blob
             ** \param bytes \a *bytes will be set to start of binary blob
             ** \param length \a *length will be set to length of binary blob
             ** \param copy false = \a *bytes will point into src.data; true = new memory is allocated and must be deleted by the user
             ** \return nothing
             **/
            static void messageToBytes(Message src, unsigned char **bytes, unsigned long *length, bool copy);
            
            /** \brief convert a 32 bit number to its 4 byte big endian base 256 encoding
             ** \param src a 32 bit unsigned integer
             ** \param dst pointer into at least 4 bytes
             ** \return nothing
             **/
            static void longToBytes(unsigned long src, unsigned char *dst);

            /** \brief convert a number 4 byte big endian base 256 encoding to its 32 bit value
             ** \param src pointer into \a length bytes
             ** \param length length of \a src; must be >= 4
             ** \return value of first 4 bytes
             **/
            static unsigned long bytesToLong(const unsigned char *src, unsigned long length);
    };
}

#endif
