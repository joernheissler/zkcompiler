#include "bignum/bignum.hpp"
#include "util/foursquares.hpp"
#include "random/random.hpp"
#include "util/zkprint.hpp"

using namespace ZKCompiler;

int main()
{
    Random::init();

    bnz_t w,w1,w2,w3,w4;
    bnz_init_set_ui(w, 1234567890);
    bnz_init(w1);
    bnz_init(w2);
    bnz_init(w3);
    bnz_init(w4);
    foursquares(w1,w2,w3,w4,w);
    printf("%s =  %s^2 + %s^2 + %s^2 + %s^2\n",
        bnToStr(w).c_str(), bnToStr(w1).c_str(), bnToStr(w2).c_str(), bnToStr(w3).c_str(), bnToStr(w4).c_str());
    bnz_clear(w);
    bnz_clear(w1);
    bnz_clear(w2);
    bnz_clear(w3);
    bnz_clear(w4);
    
    Random::free();

    return 0;
}
