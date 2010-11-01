#include <iomanip>
#include <cstring>
#include <stdio.h>

#include "bignum/bignum.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"

using namespace ZKCompiler;
using namespace std;

int main()
{
    const unsigned char expected_result[] =
        "\x00\x00\x00\x99\x00\x00\x00\x12\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72\x6c\x64"
        "\x21\x0a\x00\x00\x00\x14\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d"
        "\x0e\x0f\x00\x00\x00\x6f\x1c\x68\x74\x81\x6e\x96\x80\xc8\xec\x7c\xcf\x96\xe7\x3c"
        "\x8a\xcd\x9f\x1c\xa2\x94\x87\xe1\xa8\x92\x89\x48\x83\x1a\xdb\x2f\x64\x67\x33\x5c"
        "\xea\xdc\xef\x56\x9b\x53\xc5\xf8\x44\xbc\xc0\xf5\x31\x8c\x71\x91\xf6\x94\x93\x4f"
        "\x0c\xc6\xa2\x6e\xf6\xcd\x05\x10\x5d\x78\xac\x82\x85\x5f\x79\x34\xac\xd8\x36\x39"
        "\xfd\x4b\x5c\xbf\x6b\x01\x13\xdb\x88\x5d\xb6\x5b\xfa\x4d\x9d\x34\xd7\x4b\x3c\xc7"
        "\xa9\xe1\xac\x1d\xb5\x04\xc6\x31\xd6\x35\xde\x3f\x3e";
    int ret = 0;

    Message test_in[] = {
        { (unsigned char *)
          "\x00\x00\x00\x12\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72\x6c\x64\x21\x0a", 18 },

        { (unsigned char *)
          "\x00\x00\x00\x14\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f", 20 },

        { (unsigned char *)
          "\x00\x00\x00\x6f\x1c\x68\x74\x81\x6e\x96\x80\xc8\xec\x7c\xcf\x96\xe7\x3c\x8a\xcd"
          "\x9f\x1c\xa2\x94\x87\xe1\xa8\x92\x89\x48\x83\x1a\xdb\x2f\x64\x67\x33\x5c\xea\xdc"
          "\xef\x56\x9b\x53\xc5\xf8\x44\xbc\xc0\xf5\x31\x8c\x71\x91\xf6\x94\x93\x4f\x0c\xc6"
          "\xa2\x6e\xf6\xcd\x05\x10\x5d\x78\xac\x82\x85\x5f\x79\x34\xac\xd8\x36\x39\xfd\x4b"
          "\x5c\xbf\x6b\x01\x13\xdb\x88\x5d\xb6\x5b\xfa\x4d\x9d\x34\xd7\x4b\x3c\xc7\xa9\xe1"
          "\xac\x1d\xb5\x04\xc6\x31\xd6\x35\xde\x3f\x3e", 111 }
    };

    Message test_out0[3], test_out1[3];

    for(unsigned j = 0; j < 3; ++j) printHex(test_in[j], "  in_0\0  in_1\0  in_2" + 7 * j);
    printf("\n");

    Message msg = Convert::messagesToMessage(test_in, 3);
    printHex(msg, "   msg");
    printf("\n");

    Convert::messageToMessages(msg, test_out0, 3, 0);
    Convert::messageToMessages(msg, test_out1, 3, 1);
    
    for(unsigned j = 0; j < 3; ++j) printHex(test_out0[j], "out0_0\0out0_1\0out0_2" + 7 * j);
    printf("\n");

    for(unsigned j = 0; j < 3; ++j) printHex(test_out1[j], "out1_0\0out1_1\0out1_2" + 7 * j);
    printf("\n");
    
    for(unsigned j = 0; j < 3; ++j) {
        if(test_out0[j].length != test_in[j].length) ret |= 1;
        else if(memcmp(test_out0[j].data, test_in[j].data, test_in[j].length)) ret |= 2;
        if(test_out1[j].length != test_in[j].length) ret |= 4;
        else if(memcmp(test_out1[j].data, test_in[j].data, test_in[j].length)) ret |= 8;
    }

    if(msg.length != sizeof expected_result - 1) {
        ret |= 16;
    } else {
        if(memcmp(expected_result, msg.data, msg.length)) ret |= 32;
    }
    
    delete[] msg.data;
    delete[] test_out1[0].data;
    delete[] test_out1[1].data;
    delete[] test_out1[2].data;

    return ret;
}
