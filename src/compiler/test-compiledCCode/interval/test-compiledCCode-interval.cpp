#include "ZKCCodeTester.hpp"

using namespace ZKCompiler;

bool initZKProver(const char* vStr_vSecret_w[], const char* vStr_vPublicCommitment_x[], const char* vStr_vAux_gi[])
{
    bool noErrors = false;

    mpz_t* pSecret_w;
    mpz_t* pPublicCommitment_x;
    mpz_t* pAux_gi;
    ZKCCodeTester::initMPZsArray(pSecret_w, zk_argSize_vSecret_w, vStr_vSecret_w);
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, vStr_vPublicCommitment_x);
    ZKCCodeTester::initMPZsArray(pAux_gi, zk_argSize_vAux_gi, vStr_vAux_gi);
    ZKCCodeTester::printMPZsArray(pSecret_w, zk_argSize_vSecret_w, "vSecret_w");
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, "vPublicCommitment_x");
    ZKCCodeTester::printMPZsArray(pAux_gi, zk_argSize_vAux_gi, "vAux_gi");
    noErrors = zk_Prover_init(pAux_gi, pPublicCommitment_x, pSecret_w);
    ZKCCodeTester::clearMPZsArray(pSecret_w, zk_argSize_vSecret_w);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x);
    ZKCCodeTester::clearMPZsArray(pAux_gi, zk_argSize_vAux_gi);

    return noErrors;
}

bool initZKVerifier(const char* vStr_vPublicCommitment_x[], const char* vStr_vAux_gi[])
{
    bool noErrors = false;

    mpz_t* pPublicCommitment_x;
    mpz_t* vAux_gi;
    ZKCCodeTester::initMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, vStr_vPublicCommitment_x);
    ZKCCodeTester::initMPZsArray(vAux_gi, zk_argSize_vAux_gi, vStr_vAux_gi);
    ZKCCodeTester::printMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x, "vPublicCommitment_x");
    ZKCCodeTester::printMPZsArray(vAux_gi, zk_argSize_vAux_gi, "vAux_gi");
    noErrors = zk_Verifier_init(vAux_gi, pPublicCommitment_x);
    ZKCCodeTester::clearMPZsArray(pPublicCommitment_x, zk_argSize_vPublicCommitment_x);
    ZKCCodeTester::clearMPZsArray(vAux_gi, zk_argSize_vAux_gi);

    return noErrors;
}

#define TEST_CHECK(msg, expVer, retVal) \
    {\
        printf("%s\n", (msg));\
        if ((retVal) && (expVer) == verification)\
        {\
            printf("OK\n");\
        }\
        else\
        {\
            printf("FAIL\n");\
            ret = 1;\
        }\
    } (void)0

int main()
{
    int ret = 0;
    zk_bool verification = false;

    const char* vStr_vSecret_w[] = {"31337", "302667701153485116200754826965601415717063735350", "134", "11", "106", "32", "17956", "121", "11236", "1024", "199", "28", "151", "74", "39601", "784", "22801", "5476", "322617790106899219473393688190920273630013617549", "770614353695147006271629978813987956327220983463", "775104383371852209688715122091264835560667666080", "1002596263129652524636769794751047531484081700024", "893532666594733839771739386549118113359369854338", "-647199429029991954112447776999949624370227902615", "-1402411313154858447840579319862791136513450911463", "-351219453672374825681473788677529903270536688791", "-765732025378398873675501930300280919354547679583", "429957373575414360700422230579863337300747741665", "-318396712003239426115783902414165173762499457969", "-603151430117190225626146054469732412326441266335", "1049798976333709080122138157969295286368069098636", "1181683896422082956336047678536360608777919616593", "-1443937145900809026270187091584386851257802384158", "1019758443983393903082405207922181114458139039107", "-42337251207729761569663014831034198553062454897228", "-9123957319676609023100377543953817143969658720708", "-83563475950571192674844382261536863705944223515943", "-32434299873821255614058107220711050910761151089559", "153430472026635084941547022287725198237923057335653", "-10857122563689519143275774777699812835643017150027", "46633966366588344317213182172954554386879615769161", "45652964272655470599417213238682379626614792747897"};
    const char* vStr_wrong_vSecret_w[] = {"31337", "141861416335847213250909269826823152583240628944", "56", "1", "128", "104", "3136", "1", "16384", "10816", "11", "50", "235", "104", "121", "2500", "55225", "10816", "-369252137315806131632401951529930812997437084103", "-1120156378482065889284787430814913116180642559534", "-1214214398854602485554090016116178313691158351956", "899182338790147800060779815259278413692867861471", "744528777514194204903722232615685553208855276170", "-927076537599997390374161279186068909266396633470", "507995415284940031572289902578619646508002796157", "1279557737573635167803793629294756465400000744590", "803082929816195352388539827778842431374859691730", "1072470165787716741253784005847386710655721248483", "-584393188792568009582884607974816033208018933311", "-155834863528487784412083036061680007668979730320", "-464282900128970685445683365064905173295062910568", "79553176370934516924207236685922385508079610890", "-606982827706078932380874861360060941191512234848", "-681697545326792786665778550738834720552979799497", "21422648467199337576318231518291811081065331985938", "193079840882068498910626151628844206914245926064", "155927438468674058182495811965449443798976271846525", "-92235405496601736038517307157670198558658256848394", "-9298195128107119561719621470632171918418519519598", "-53543955113014902545764993055683413147277982813260", "136725416538547403319597008012721706862692937093237", "15525128261635936792190857199675886077020912153783"};
    const char* vStr_vPublicCommitment_x[] = {"14638", "1867460", "466231", "2110732", "1323237", "1576717", "2671351", "127334", "2783085", "1290269", "2431120", "545035", "1203949", "345352", "1128618", "1127379", "2368781", "2792604", "881104", "127334", "2783085", "1290269", "2431120", "1127379", "2368781", "2792604", "881104"};
    const char* vStr_vAux_gi[] = {"1518264"};

    Random::init();
    TEST_CHECK(">>> posive test <<<", true,
            initZKProver(vStr_vSecret_w, vStr_vPublicCommitment_x, vStr_vAux_gi) &&
            initZKVerifier(vStr_vPublicCommitment_x, vStr_vAux_gi) &&
            ZKCCodeTester::test(&verification));
    TEST_CHECK(">>> negative test <<<", false,
            initZKProver(vStr_wrong_vSecret_w, vStr_vPublicCommitment_x, vStr_vAux_gi) &&
            initZKVerifier(vStr_vPublicCommitment_x, vStr_vAux_gi) &&
            ZKCCodeTester::test(&verification));
    Random::free();

    return ret;
}
