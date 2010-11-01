#include "parser/parser.hpp"
#include "util/zkprint.hpp"

CM_INIT_CODE_MANAGER;

using namespace ZKCompiler;
using namespace std;

#define INPUT "G0 = Z_add_n(509);"                  \
              "G = (G0, G0);"                       \
              "H = Z_mul_n(1019, qr);"              \
              "H: g = 749, h = 821;"                \
              "phi [ G -> H ] = g ^ $.0 + h ^ $.1;"

int main(void)
{
    //CodeManagement::CodeCollector codeCollector;
    //CodeManagement::DefaultCodeManager::getManager().addCodeCollector(codeCollector);

    int ret = 0;
    Parser *p = Parser::fromString(INPUT);
    Hom *phi = p->getHom("phi");
    Element *w = phi->getSrcElement();
    Element *x = phi->getDstElement();

    const char *i[] = { "100", "211" };
    CMV::zk_pcchar_t* pInitStrings;
    CMV_NEW_ARRAY(pInitStrings, zk_pcchar_t, 2);
    for(unsigned j = 0; j < 2; ++j)
        pInitStrings[j] = CMV_IN((zk_pcchar_t)i[j]);
    w->set(pInitStrings, 2);
    CMV_DELETE_ARRAY(pInitStrings, zk_pcchar_t, 2);

    printf("Phi-Mapping BEGIN\n");
    x->map(phi, w);
    printf("Phi-Mapping END\n");

    CMV(bnz_t tmp);
    CMI(bnz_init(tmp));
    x->get(tmp);
    printf("749^100 * 821^211 = %s (mod 1019)\n", bnToStr(CMV_OUT(tmp)).c_str());
    if(bnz_cmp_ui(CMV_OUT(tmp), 153)) ret = 1;
    CMI(bnz_clear(tmp));

    delete w;
    delete x;
    delete p;

    return ret;
}
