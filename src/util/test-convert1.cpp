#include <iomanip>
#include <cstring>

#include "bignum/bignum.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"

using namespace ZKCompiler;
using namespace std;

int main()
{
    const unsigned char expected_result[] =
        "\x00\x00\x00\x2d\x01\x0d\xa8\xc2\x53\x82\x95\x5a\x30\xff\x3d\x09\x5a\x18\x98\x33"
        "\x3f\xaf\x56\x94\xf8\x94\x03\xbf\x6f\x8f\x5d\x7d\x89\x31\x39\x45\x06\x20\x46\x02"
        "\x54\xe9\x84\x52\x2c";
    int ret = 0;
    bnz_t test_in, test_out;
    
    bnz_init_set_str(test_in, "-113968384964967814893826047181110955234577063840514762245011778314723598972234519694980539503148", 0);
    bnz_init(test_out);

    printf(" in = %s\n\n", bnToStr(test_in).c_str());

    Message msg = Convert::mpztToMessage(test_in);
    printHex(msg, "msg");
    printf("\n");

    Convert::messageToMpzt(msg, test_out);
    printf("out = %s\n", bnToStr(test_out).c_str());
    if(bnz_cmp(test_in, test_out)) ret |= 1;
    if(msg.length != sizeof expected_result - 1) {
        ret |= 2;
    } else {
        if(memcmp(expected_result, msg.data, msg.length)) ret |= 4;
    }
    delete[] msg.data;
    bnz_clear(test_in);
    bnz_clear(test_out);

    return ret;
}
