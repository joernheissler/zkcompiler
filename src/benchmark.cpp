#ifdef _MSC_VER
  // windows builds
  #define NOMINMAX // switch off min()/max() macros
  #include <windows.h> 
#else
  #include <unistd.h>
  #include <cstring>
  #include <sys/time.h>
#endif

#include <iomanip>
#include <stdio.h>

#include "parser/parser.hpp"
#include "util/convert.hpp"
#include "util/zkprint.hpp"
#include "random/random.hpp"
#include "hash/sha1.hpp"

using namespace std;
using namespace ZKCompiler;

CM_INIT_CODE_MANAGER;

bool noninter(Sigma *p, Sigma *v)
{
    Message sig;
    Hash *h;
    bool ret;

    /* prover creates a hash function object */
    h = new SHA1();
    /* prover creates a signature */
    sig = p->sign(h);
    delete h;

    /* verifier creates a hash function object */
    h = new SHA1();
    /* verifier verifies the signature */
    ret = v->verify(h, sig);
    delete h;

    /* delete signature */
    delete[] sig.data;

    return ret;
}

bool inter(Sigma *p, Sigma *v)
{
    Message msg;
    bool ret;

    if(p->simulationNeeded()) {
        printf("simulationNeeded==true but should be false\n");
        ret = false;
        goto out;
    }
    
    /* prover calls P1 */
    p->P1();
    
    /* transmit commitment from prover to verifier */
    msg = p->getCommitment();
    v->setCommitment(msg);
    delete[] msg.data;

    /* verifier generates challenge */
    v->genChallenge();

    /* transmit challenge from verifier to prover */
    msg = v->getChallenge();
    p->setChallenge(msg);
    delete[] msg.data;

    /* prover calls P2 */
    p->P2();

    /* transmit response from prover to verifier */
    msg = p->getResponse();
    v->setResponse(msg);
    delete[] msg.data;

    /* verifier calls V */
    ret = CMV_OUT(v->V());
out:
    delete p;
    delete v;
    return ret;
}

struct witness { const char *w, *x, *h; };

void rnd(Parser *p, struct witness *w, unsigned long k)
{
    for(unsigned i = 0; i < 3; ++i) {
        if(i == 2 || k == 2 || i == k) {
            /* choose random witnesses */
            p->getVar(w[i].w)->random();
            
            /* calculate public value */
            p->map(w[i].x, w[i].h, w[i].w);
        } else {
            /* choose random public value */
            p->getVar(w[i].x)->random();
        }
    }
}


int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("I need the .zk file as parameter!\n");
        return 13;
    }
    try {
        Random::init();
        Message msg;
        
        /* initialize prover */
        Parser *prover  = Parser::fromFile(argv[1]);
        
        /* initialize verifier */
        Parser *verifier = Parser::fromFile(argv[1]);

        struct witness wx[] = { {"w0a","x0a","phi0a"}, {"w0b","x0b","phi0b"}, {"w0c","x0c","phi0c"},
                                {"w1a","x1a","phi1a"}, {"w1b","x1b","phi1b"}, {"w1c","x1c","phi1c"},
                                {"w2a","x2a","phi1a"}, {"w2b","x2b","phi1b"}, {"w2c","x2c","phi1c"},
                                {0, 0, 0} };
        bnz_t r;
        bnz_init(r);
        
        /* generate random witnesses and calculate public values.
         * Or, generate a random public value without witness */
        bnz_set_ui(r, 3);
        Random::range0(r, r);
        rnd(prover, wx + 0, bnz_get_ui(r));
        
        bnz_set_ui(r, 3);
        Random::range0(r, r);
        rnd(prover, wx + 3, bnz_get_ui(r));
        
        bnz_set_ui(r, 3);
        Random::range0(r, r);
        rnd(prover, wx + 6, bnz_get_ui(r));
        
        for(int i = 0; i < 9; ++i) {
            /* transmit public value to verifier */
            msg = prover->getVar(wx[i].x)->get();
            verifier->getVar(wx[i].x)->set(msg);
            delete[] msg.data;
        }


        #ifdef _MSC_VER
            // windows builds
            LONGLONG g_Frequency, g_CurentCount, g_LastCount;

			if (!QueryPerformanceFrequency((LARGE_INTEGER*)&g_Frequency))
              printf("Performance Counter not available!");

            printf("Starting benchmark...\n");

			QueryPerformanceCounter((LARGE_INTEGER*)&g_CurentCount); 
        #else
            timeval begin, end;
            long seconds, useconds;
            
            printf("Starting benchmark...\n");

			if (gettimeofday(&begin,(struct timezone *)0)) {
                fprintf(stderr, "can not get time\n");
            }
        #endif

        for (int i=0; i < 500; i++) {
            if(!inter(prover->getSigma("s0x"), verifier->getSigma("s0x"))) { printf("fail\n"); return 100; }
            if(!noninter(prover->getSigma("s0x"), verifier->getSigma("s0x"))) { printf("fail\n"); return 100; }
            if(!inter(prover->getSigma("s0y"), verifier->getSigma("s0y"))) { printf("fail\n"); return 100; }
            if(!noninter(prover->getSigma("s0y"), verifier->getSigma("s0y"))) { printf("fail\n"); return 100; }
            if(!inter(prover->getSigma("s1x"), verifier->getSigma("s1x"))) { printf("fail\n"); return 100; }
            if(!noninter(prover->getSigma("s1x"), verifier->getSigma("s1x"))) { printf("fail\n"); return 100; }
            if(!inter(prover->getSigma("s1y"), verifier->getSigma("s1y"))) { printf("fail\n"); return 100; }
            if(!noninter(prover->getSigma("s1y"), verifier->getSigma("s1y"))) { printf("fail\n"); return 100; }
         }

        #ifdef _MSC_VER
            // windows builds
            QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount);

            double dTimeDiff = (((double)(g_LastCount-g_CurentCount))/((double)g_Frequency)); 

            printf("Time: %f seconds\n", dTimeDiff); 
        #else
            if (gettimeofday(&end,(struct timezone *)0)) {
                fprintf(stderr, "can not get time\n");
            }
            seconds = end.tv_sec - begin.tv_sec;
            useconds = end.tv_usec - begin.tv_usec;
            if(useconds < 0) {
                useconds += 1000000;
                seconds--;
            }   

            printf("Time: %d seconds and %d useconds\n", (unsigned int)seconds, (unsigned int)useconds);
        #endif

        delete verifier;
        delete prover;
        Random::free();
    } catch(char const *p) {
        printf("Exception: %s\n", p);
        return 13;
    }

    return 0;
}
