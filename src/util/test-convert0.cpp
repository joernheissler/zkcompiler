#include <iomanip>
#include <cstring>

#include "bignum/bignum.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"

using namespace ZKCompiler;
using namespace std;

#define N 3

int main(void)
{    
    const unsigned char expected_result[] =
        "\x00\x00\x00\x7d\x00\x00\x00\x23\x00\x12\x04\x90\xb4\x83\x99\x6b\x61\xfd\x87\xdf"
        "\x7f\x27\x31\xc5\x43\x7b\x03\x54\xb7\x98\x58\x39\x57\xa3\xe2\xf7\x56\x1b\x91\x00"
        "\x00\x00\x29\x01\x02\x5a\xaf\x48\xeb\x22\xfe\x56\x08\x69\xfd\xee\xe6\xee\x27\xe5"
        "\xb8\x20\xf4\x27\xf9\x7d\x2a\xc3\x27\x8d\xf3\x83\xe0\x30\xe9\xde\xd8\xbf\x1f\xa2"
        "\x00\x00\x00\x2d\x00\x10\xe9\x29\xbe\x34\x87\xd8\x31\x7e\x1c\x53\xcb\xe6\x13\xab"
        "\x84\xe9\x48\xf9\xc9\x23\x31\x89\x18\x5b\x80\xcd\x28\xd4\x06\x91\x48\x20\x42\x58"
        "\x9c\x62\xd5\x54\x73";

    int ret = 0;

    bnz_t convert_test_in[N], convert_test_out[N];

    for(unsigned i = 0; i < N; ++i) {
        bnz_init(convert_test_in[i]);
        bnz_init(convert_test_out[i]);
    }
    
    // Set test numbers
    bnz_set_str(convert_test_in[0], "124354513258076015803579854613213264681262197216277498791573156714126225", 0);
    bnz_set_str(convert_test_in[1], "-4573503245858170450938759013513975639457938175638576489579757689101810156105830965154", 0);
    bnz_set_str(convert_test_in[2], "141098574362985764523948576325432523151240945325325253151664364109835719587912686908745870300275", 0);
    
    // Print test numbers
    for(unsigned i = 0; i < N; ++i) printf(" in_%d = %s\n", i, bnToStr(convert_test_in[i]).c_str());
    printf("\n");

    // Convert to char message
    Message msg = Convert::mpztToMessage(convert_test_in, N);
    printHex(msg, "  msg");
    printf("\n");
    
    // Convert message to numbers
    Convert::messageToMpzt(msg, convert_test_out, N);
    
    // Print converted numbers
    for(unsigned i = 0; i < N; ++i) printf("out_%d = %s\n", i, bnToStr(convert_test_out[i]).c_str());

    // Check equality
    for(unsigned i = 0; i < N; ++i) {
        if(bnz_cmp(convert_test_in[i], convert_test_out[i])) ret |= 1;
    }
    if(msg.length != sizeof expected_result - 1) {
        ret |= 2;
    } else {
        if(memcmp(expected_result, msg.data, msg.length)) ret |= 4;
    }

    delete[] msg.data;
    for(unsigned i = 0; i < N; ++i) {
        bnz_clear(convert_test_in[i]);
        bnz_clear(convert_test_out[i]);
    }

    return ret;
}
