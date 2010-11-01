#include <climits>
#include <cstring>
#include "util/convert.hpp"
#include "util/errorhandling.hpp"

#define MSG_LENGTH_SIZE 4u

namespace ZKCompiler {
    Message Convert::mpztToMessage(bnz_t *src, unsigned int u)
    {
        Message msg;
        size_t total_length = MSG_LENGTH_SIZE;

        for(unsigned int i = 0; i < u; i++) {
            size_t length = MSG_LENGTH_SIZE + 1 + (bnz_sizeinbase(src[i], 2) + 7) / 8;
            if(length > ULONG_MAX - total_length) ZK_HANDLE_ERROR("message too large");
            total_length += length;
        }

        msg.data = new unsigned char[total_length];
        if(!msg.data) ZK_HANDLE_ERROR("oom");

        unsigned char *p = msg.data + MSG_LENGTH_SIZE;

        for(unsigned int i = 0; i < u; i++) {
            size_t length;
            bnz_export(p + MSG_LENGTH_SIZE + 1, &length, 1, 1, 1, CHAR_BIT - 8, src[i]);
            length += MSG_LENGTH_SIZE + 1;
            longToBytes((unsigned long)length, p);
            p[MSG_LENGTH_SIZE] = (unsigned char) ((bnz_sgn(src[i]) < 0) ? 1 : 0);
            p += length;
        }

        longToBytes((unsigned long)(p - msg.data), msg.data);
        msg.length = (unsigned long)(p - msg.data);

        return msg;
    }

    void Convert::messageToMpzt(Message src, bnz_t *dst, unsigned int u)
    {
        if(src.length != bytesToLong(src.data, src.length)) ZK_HANDLE_ERROR("ERROR: message size mismatch!");

        unsigned char *p = src.data + MSG_LENGTH_SIZE;

        for(unsigned int i = 0; i < u; ++i) {
            unsigned long length = bytesToLong(p, (unsigned long)(src.length - (p - src.data)));
            if(length < MSG_LENGTH_SIZE + 1) ZK_HANDLE_ERROR("ERROR: bad message size!");
            bnz_import(dst[i], length - MSG_LENGTH_SIZE - 1, 1, 1, 1, CHAR_BIT - 8, p + MSG_LENGTH_SIZE + 1);
            switch(p[MSG_LENGTH_SIZE]) {
                case 0: break;
                case 1: bnz_neg(dst[i], dst[i]); break;
                default: ZK_HANDLE_ERROR("first byte must be 0 or 1"); break;
            }

            p += length;
        }

        if(src.data + src.length != p) ZK_HANDLE_ERROR("ERROR: message too long!");
    }

    Message Convert::mpztToMessage(const bnz_t& src)
    {
        Message msg;
        size_t length;
        unsigned long total_length;

        total_length = MSG_LENGTH_SIZE + 1 + ((unsigned long)bnz_sizeinbase(src, 2) + 7) / 8;
        msg.data = new unsigned char[total_length];
        if(!msg.data) ZK_HANDLE_ERROR("oom");
        bnz_export(msg.data + MSG_LENGTH_SIZE + 1, &length, 1, 1, 1, CHAR_BIT - 8, src);
        length += MSG_LENGTH_SIZE + 1;
        longToBytes((unsigned long)length, msg.data);
        msg.data[MSG_LENGTH_SIZE] = (unsigned char) ((bnz_sgn(src) < 0) ? 1 : 0);
        msg.length = (unsigned long)length;

        return msg;
    }

    void Convert::messageToMpzt(Message src, bnz_t& dst)
    {
        if(src.length != bytesToLong(src.data, src.length) || src.length < MSG_LENGTH_SIZE + 1) ZK_HANDLE_ERROR("ERROR: bad message size!");

        bnz_import(dst, src.length - MSG_LENGTH_SIZE - 1, 1, 1, 1, CHAR_BIT - 8, src.data + MSG_LENGTH_SIZE + 1);
        switch(src.data[MSG_LENGTH_SIZE]) {
            case 0: break;
            case 1: bnz_neg(dst, dst); break;
            default: ZK_HANDLE_ERROR("first byte must be 0 or 1"); break;
        }
    }

    Message Convert::messagesToMessage(Message *src, unsigned int u)
    {
        Message msg;

        unsigned long total_length = MSG_LENGTH_SIZE;

        for(unsigned int i = 0; i < u; i++) {
            if(src[i].length > ULONG_MAX - total_length) ZK_HANDLE_ERROR("message too large");
            total_length += src[i].length;
        }

        msg.length = total_length;
        msg.data = new unsigned char[total_length];
        if(!msg.data) ZK_HANDLE_ERROR("oom");

        longToBytes(total_length, msg.data);

        unsigned char *p = msg.data + MSG_LENGTH_SIZE;

        for(unsigned int i = 0; i < u; i++) {
            memcpy(p, src[i].data, src[i].length);
            p += src[i].length;
        }

        return msg;
    }

    void Convert::messageToMessages(Message src, Message *dst, unsigned int u, bool copy)
    {
        if(src.length != bytesToLong(src.data, src.length)) ZK_HANDLE_ERROR("ERROR: message size mismatch!");

        unsigned char *p = src.data + MSG_LENGTH_SIZE;
        unsigned long length = 0;

        for(unsigned int i = 0; i < u; i++)
        {
            length = bytesToLong(p, (unsigned long)(src.length - (p - src.data)));
            if(length > src.length - (p - src.data)) ZK_HANDLE_ERROR("ERROR: message too short!");

            dst[i].length = length;

            if(copy) {
                dst[i].data = new unsigned char[length];
                if(!dst[i].data) {
                    for(unsigned int j = 0; j < i; ++j) delete[] dst[j].data;
                    ZK_HANDLE_ERROR("oom");
                }
                memcpy(dst[i].data, p, length);
            } else {
                dst[i].data = p;
            }
            p += length;
        }

        if(src.data + src.length != p) ZK_HANDLE_ERROR("ERROR: message too long!");
    }

    Message Convert::bytesToMessage(const unsigned char *src, unsigned long length)
    {
        struct Message msg;

        msg.length = length + MSG_LENGTH_SIZE;
        msg.data = new unsigned char[msg.length];
        if(!msg.data) ZK_HANDLE_ERROR("oom");
        longToBytes(msg.length, msg.data);
        memcpy(msg.data + MSG_LENGTH_SIZE, src, length);

        return msg;
    }

    void Convert::messageToBytes(Message src, unsigned char **bytes, unsigned long *length, bool copy)
    {
        if(src.length != bytesToLong(src.data, src.length)) ZK_HANDLE_ERROR("ERROR: message size mismatch!");

        *length = src.length - MSG_LENGTH_SIZE;
        if(copy) {
            *bytes = new unsigned char[*length];
            if(!*bytes) ZK_HANDLE_ERROR("oom");
            memcpy(*bytes, src.data + MSG_LENGTH_SIZE, *length);
        } else {
            *bytes = src.data + MSG_LENGTH_SIZE;
        }
    }

    void Convert::longToBytes(unsigned long src, unsigned char *dst)
    {
        for(size_t i = 0; i < MSG_LENGTH_SIZE; i++) {
            dst[MSG_LENGTH_SIZE - i - 1] = (unsigned char)(src & 0xff);
            src >>= 8;
        }
    }

    unsigned long Convert::bytesToLong(const unsigned char *src, unsigned long length)
    {
        if(length < MSG_LENGTH_SIZE) ZK_HANDLE_ERROR("message too short!");

        unsigned long val = 0;
        for(size_t i = 0; i < MSG_LENGTH_SIZE; i++) {
            val = (val << 8) | (src[i] & 0xff);
        }
        return val;
    }
}
