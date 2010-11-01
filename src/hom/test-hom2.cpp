#include "parser/parser.hpp"
#include "util/zkprint.hpp"

CM_INIT_CODE_MANAGER;

using namespace ZKCompiler;
using namespace std;

#define INPUT "G0 = Z_add_n(509);"                  \
              "G = (G0, G0);"                       \
              "H = Z_mul_n(1019, qr);"              \
              "H: g = 749, h = 821;"                \
              "phi [ G -> H ] = g ^ $.0 + h ^ $.1;" \
              "phi2 [ G0 -> H ] = phi([$,$]);"

int main(void)
{
    //CodeManagement::CodeCollector codeCollector;
    //CodeManagement::DefaultCodeManager::getManager().addCodeCollector(codeCollector);

    int ret = 0;
    Parser *p = Parser::fromString(INPUT);
    Hom *phi = p->getHom("phi2");
    Element *w = phi->getSrcElement();
    Element *x = phi->getDstElement();

    const char *i[] = { "123" };
    CMV::zk_pcchar_t* pInitStrings;
    CMV_NEW_ARRAY(pInitStrings, zk_pcchar_t, 1);
    for(unsigned j = 0; j < 1; ++j)
        pInitStrings[j] = CMV_IN((zk_pcchar_t)i[j]);
    w->set(pInitStrings, 1);
    CMV_DELETE_ARRAY(pInitStrings, zk_pcchar_t, 1);

    printf("Phi2-Mapping BEGIN\n");
    x->map(phi, w);
    printf("Phi2-Mapping END\n");

    CMV(bnz_t tmp);
    CMI(bnz_init(tmp));
    x->get(tmp);
    printf("749^123 * 821^123 = %s (mod 1019)\n", bnToStr(CMV_OUT(tmp)).c_str());
    if(bnz_cmp_ui(CMV_OUT(tmp), 501)) ret = 1;
    CMI(bnz_clear(tmp));

    delete w;
    delete x;
    delete p;

    return ret;
}
