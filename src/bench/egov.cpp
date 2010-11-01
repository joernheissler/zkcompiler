#ifdef _MSC_VER
  // windows builds
  #define NOMINMAX // switch off min()/max() macros
  #include <windows.h> 
#else
  #include <unistd.h>
  #include <iostream>
  #include <sys/time.h>
#endif
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdarg>
#include "hash/hash.hpp"
#include "hash/sha1.hpp"
#include "random/random.hpp"
#include "util/foursquares.hpp"
#include "util/zkprint.hpp"
#include "parser/parser.hpp"

CM_INIT_CODE_MANAGER;

#define bn2str(bn) (bnToStr((bn)).c_str())

using namespace ZKCompiler;
using namespace std;

// 1024 bit RSA security
#define l_x 1024
#define l_n 1024
#define l_E 404
#define l_e 60
#define l   60
#define l_w 16

// 2048 bit RSA security
//#define l_x 2048
//#define l_n 2048
//#define l_E 404
//#define l_e 60
//#define l   60
//#define l_w 16

// FIX ME: funktioniert nicht mehr fuer grosse M und N
#define M 1
#define N 1
#define RL 2

#define MAX_TIMESTAMP 4200000 // one month
#define TESTS 20
#define RUNS 10


//#define WORST_CASE
//#define AVERAGE

typedef struct sPubParam
  {
  bnz_t a;
  bnz_t b;
  bnz_t d;
  bnz_t f1;
  bnz_t f2;
  bnz_t g;
  bnz_t h;
  bnz_t h_1;
  bnz_t h_2;
  bnz_t ghat;
  bnz_t hhat;
  bnz_t gbar;
  bnz_t hbar;
  bnz_t ybar_1;
  bnz_t ybar_2;
  bnz_t ybar_3;
  bnz_t rbar;
  bnz_t n;
  bnz_t n2;
  bnz_t Cert[M];
  bnz_t iRole[N];
  bnz_t ubar;
  bnz_t ebar;
  bnz_t vbar;
  bnz_t hhk;
  } pubParam;

typedef struct sRPrivParam
  {
  bnz_t p;
  bnz_t q;
  bnz_t phi;
  } RPrivParam;

typedef struct sUPrivParam
  {
  bnz_t x;
  bnz_t r_1;
  } UPrivParam;

typedef struct sOPrivParam
  {
  bnz_t xbar_1;
  bnz_t xbar_2;
  bnz_t xbar_3;
  } OPrivParam;

typedef struct sCert {
    bnz_t s, e, v, q, mhat, u[N], TS_max;
} Cert;

typedef struct sRLWitness {
    bnz_t mhatprime;
    bnz_t uprime_1;
    bnz_t uprime_2;
    bnz_t rhat_2;
    bnz_t rhat_4;
    bnz_t z_1;
    bnz_t Cuprime_1;
    bnz_t Cuprime_2;
} RLWitness;

typedef struct sRLWitnesses {
    bnz_t Cmhat;
    bnz_t rhat_3;
    RLWitness rlwitness[RL];
} RLWitnesses;

typedef struct sTimestamp {
  #ifdef _MSC_VER
    // windows builds
    LONGLONG g_Frequency, g_CurentCount;
  #else
    timeval begin;
  #endif
} Timestamp;

typedef struct sTimeCounter {
  double requestU;
  double requestR;
  double activatingU;
  double activatingG;
  double opening;
} TimeCounter;

// Global public parameters
void pubParamInit(pubParam* pubparam)
  {
  bnz_init(pubparam->a);
  bnz_init(pubparam->b);
  bnz_init(pubparam->d);
  bnz_init(pubparam->f1);
  bnz_init(pubparam->f2);
  bnz_init(pubparam->g);
  bnz_init(pubparam->h);
  bnz_init(pubparam->h_1);
  bnz_init(pubparam->h_2);
  bnz_init(pubparam->ghat);
  bnz_init(pubparam->hhat);
  bnz_init(pubparam->gbar);
  bnz_init(pubparam->hbar);
  bnz_init(pubparam->ybar_1);
  bnz_init(pubparam->ybar_2);
  bnz_init(pubparam->ybar_3);
  bnz_init(pubparam->rbar);
  bnz_init(pubparam->n);
  bnz_init(pubparam->n2);
  for (int i=0; i < M; i++)
    bnz_init(pubparam->Cert[i]);
  for (int i=0; i < N; i++)
    bnz_init(pubparam->iRole[i]);
  bnz_init(pubparam->ubar);
  bnz_init(pubparam->ebar);
  bnz_init(pubparam->vbar);
  bnz_init(pubparam->hhk);
  }

void pubParamClear(pubParam* pubparam)
  {
  bnz_clear(pubparam->a);
  bnz_clear(pubparam->b);
  bnz_clear(pubparam->d);
  bnz_clear(pubparam->f1);
  bnz_clear(pubparam->f2);
  bnz_clear(pubparam->g);
  bnz_clear(pubparam->h);
  bnz_clear(pubparam->h_1);
  bnz_clear(pubparam->h_2);
  bnz_clear(pubparam->ghat);
  bnz_clear(pubparam->hhat);
  bnz_clear(pubparam->gbar);
  bnz_clear(pubparam->hbar);
  bnz_clear(pubparam->ybar_1);
  bnz_clear(pubparam->ybar_2);
  bnz_clear(pubparam->ybar_3);
  bnz_clear(pubparam->rbar);
  bnz_clear(pubparam->n);
  bnz_clear(pubparam->n2);
  for (int i=0; i < M; i++)
    bnz_clear(pubparam->Cert[i]);
  for (int i=0; i < N; i++)
    bnz_clear(pubparam->iRole[i]);
  bnz_clear(pubparam->ubar);
  bnz_clear(pubparam->ebar);
  bnz_clear(pubparam->vbar);
  bnz_clear(pubparam->hhk);
  }
// Global public parameters


// R parameters
void RprivparamInit(RPrivParam* rprivparam)
  {
  bnz_init(rprivparam->p);
  bnz_init(rprivparam->q);
  bnz_init(rprivparam->phi);
  }

void RprivparamClear(RPrivParam* rprivparam)
  {
  bnz_clear(rprivparam->p);
  bnz_clear(rprivparam->q);
  bnz_clear(rprivparam->phi);
  }
// R parameters

// U parameters
void UPrivParamInit(UPrivParam* uprivparam)
  {
  bnz_init(uprivparam->x);
  bnz_init(uprivparam->r_1);
  }

void UPrivParamClear(UPrivParam* uprivparam)
  {
  bnz_clear(uprivparam->x);
  bnz_clear(uprivparam->r_1);
  }
// U parameters

// O parameters
void OPrivParamInit(OPrivParam* oprivparam)
  {
  bnz_init(oprivparam->xbar_1);
  bnz_init(oprivparam->xbar_2);
  bnz_init(oprivparam->xbar_3);
  }

void OPrivParamClear(OPrivParam* oprivparam)
  {
  bnz_clear(oprivparam->xbar_1);
  bnz_clear(oprivparam->xbar_2);
  bnz_clear(oprivparam->xbar_3);
  }
// O parameters

// ZKCert
void CertInit(Cert *cert)
{
    bnz_init(cert->s);
    bnz_init(cert->e);
    bnz_init(cert->v);
    bnz_init(cert->q);
    bnz_init(cert->mhat);
    for(int i = 0; i < N; i++)
        bnz_init(cert->u[i]);
    bnz_init(cert->TS_max);
}

void CertClear(Cert *cert)
{
    bnz_clear(cert->s);
    bnz_clear(cert->e);
    bnz_clear(cert->v);
    bnz_clear(cert->q);
    bnz_clear(cert->mhat);
    for(int i = 0; i < N; i++)
        bnz_clear(cert->u[i]);
    bnz_clear(cert->TS_max);
}
// ZKCert

// witness for revocation list
void RLWitnessInit(RLWitness *w)
{
    bnz_init(w->mhatprime);
    bnz_init(w->uprime_1);
    bnz_init(w->uprime_2);
    bnz_init(w->rhat_2);
    bnz_init(w->rhat_4);
    bnz_init(w->z_1);
    bnz_init(w->Cuprime_1);
    bnz_init(w->Cuprime_2);
}

void RLWitnessClear(RLWitness *w)
{
    bnz_clear(w->mhatprime);
    bnz_clear(w->uprime_1);
    bnz_clear(w->uprime_2);
    bnz_clear(w->rhat_2);
    bnz_clear(w->rhat_4);
    bnz_clear(w->z_1);
    bnz_clear(w->Cuprime_1);
    bnz_clear(w->Cuprime_2);
}
// witness for revocation list

// revocation list
void RLWitnessesInit(RLWitnesses *rl)
{
    bnz_init(rl->Cmhat);
    bnz_init(rl->rhat_3);
    for (int i=0; i < RL; i++)
        RLWitnessInit(&(rl->rlwitness[i]));
}

void RLWitnessesClear(RLWitnesses *rl)
{
    bnz_clear(rl->Cmhat);
    bnz_clear(rl->rhat_3);
    for (int i=0; i < RL; i++)
        RLWitnessClear(&(rl->rlwitness[i]));
}
// revocation list


void TimeCounterInit(TimeCounter *timecnt)
{
  timecnt->requestU    = 0;
  timecnt->requestR    = 0;
  timecnt->activatingU = 0;
  timecnt->activatingG = 0;
  timecnt->opening     = 0;
}


void Timestamp_begin(Timestamp *t)
{
  #ifdef _MSC_VER
    // windows builds
    if (!QueryPerformanceFrequency((LARGE_INTEGER*)&t->g_Frequency))
      printf("Performance Counter not available!");

    QueryPerformanceCounter((LARGE_INTEGER*)&t->g_CurentCount); 
  #else
    if (gettimeofday(&t->begin,(struct timezone *)0)) {
      fprintf(stderr, "can not get time\n");
    }
  #endif
}

double Timestamp_end(Timestamp *t)
{
  double dTimeDiff = 0;
  #ifdef _MSC_VER
    // windows builds
    LONGLONG g_LastCount;
    QueryPerformanceCounter((LARGE_INTEGER*)&g_LastCount);

    dTimeDiff = (((double)(g_LastCount - t->g_CurentCount))/((double)t->g_Frequency)); 
  #else
    timeval end;
    long seconds, useconds;
    if (gettimeofday(&end,(struct timezone *)0)) {
      fprintf(stderr, "can not get time\n");
    }
    seconds = end.tv_sec - t->begin.tv_sec;
    useconds = end.tv_usec - t->begin.tv_usec;
    if(useconds < 0) {
      useconds += 1000000;
      seconds--;
    }   

    dTimeDiff = (double)seconds + (((double)useconds)/1000000.0);
  #endif
  return dTimeDiff/TESTS; 
}

/* FIXME: it's possible that a generated QR has not maximum order and that two generators are identical */
void genQR(bnz_t* qr, bnz_t* n)
{
    bool found = false;
    bnz_t result;
    bnz_init(result);

    while(!found)
    {
        // find random element 
        Random::posrange(*qr, *n);

        bnz_gcd(result, *qr, *n);
        if (bnz_cmp_ui(result, 1) == 0)
        {
            bnz_powm_ui(*qr, *qr, 2, *n);
            found = true;
        }
        else
            printf("NOT FOUND\n");
    }

    bnz_clear(result);
}


int genPubParam(pubParam* pubparam, RPrivParam* rprivparam, OPrivParam* oprivparam)
  {
  // 512 bit safe primes
  unsigned char p_char[] = {0xb9,0x4c,0x09,0x6b,0x6f,0x2f,0x4a,0xae,0x81,0xb3,0xe1,0xe5,0x86,0x44,0x82,0xf2,0xff,
	                        0xa8,0x14,0x03,0x73,0x3e,0x24,0xb4,0x7d,0x1e,0x24,0x4e,0x3a,0xc1,0x01,0x89,0x70,0x4f,
							0xcb,0x4d,0x40,0xf7,0xd8,0xbe,0xd3,0x6c,0x2d,0x77,0xf3,0x90,0xc9,0x98,0x8a,0x42,0x69,
							0x08,0xfa,0x84,0xf7,0xd3,0x98,0xe9,0x74,0xcb,0x48,0x1a,0x33,0xfb};
  unsigned char q_char[] = {0xa7,0xcf,0x6d,0xc1,0x0a,0x83,0xd9,0x06,0x8d,0x37,0x0a,0x1e,0x13,0x44,0x06,0x83,0x43,
	                        0xbf,0x3b,0x0a,0x96,0x32,0x4c,0x85,0x96,0xd8,0xe3,0xa0,0x63,0x8e,0xb5,0x88,0x3b,0x73,
							0x2e,0x1e,0xaa,0x5e,0xe5,0xc7,0x88,0x9b,0x26,0xa1,0x9d,0x07,0xc5,0xb5,0x92,0xe7,0x30,
							0x9d,0x59,0xe7,0x62,0x3d,0x07,0x50,0x58,0x9d,0xdf,0x86,0x56,0x43};
/*
  // 1024 bit safe primes
  unsigned char p_char[] = {0xd2,0x60,0x20,0xf7,0x38,0xa4,0xb0,0x9d,0x99,0xab,0x70,0xf6,0x95,0xe7,0xc1,0x15,0xd5,
	                        0x40,0xea,0x24,0x10,0x47,0x40,0x71,0xc5,0x9a,0x3b,0xdf,0x36,0x32,0x9d,0x03,0x55,0x00,
							0x96,0x58,0xbb,0x32,0x61,0x6e,0x94,0x83,0x6e,0xb1,0x2e,0x7d,0x93,0xee,0xe6,0xca,0x97,
							0xbb,0x68,0xff,0x17,0xa4,0x73,0xdd,0x9c,0x33,0xa4,0x7c,0x0b,0x6a,0x55,0x68,0xd5,0x92,
							0x73,0x41,0xc3,0x2a,0x72,0x0a,0xf5,0x67,0x35,0x82,0x80,0x9d,0xa9,0x6d,0x95,0xf0,0xec,
							0x34,0x48,0x0d,0x6c,0x85,0xba,0x4d,0xcc,0x9b,0x57,0x06,0x45,0x4a,0xde,0x2b,0xb3,0x3c,
							0xb6,0x6a,0x6c,0x24,0x76,0xd9,0x9c,0x49,0x52,0x90,0x6d,0x10,0x44,0x60,0x27,0xf0,0xe7,
							0xe2,0x6d,0x35,0xb1,0xde,0x5a,0xe8,0x6a,0x77};
  unsigned char q_char[] = {0xd1,0xf6,0x2d,0xe1,0xfe,0x13,0xca,0x19,0xcb,0x35,0x57,0xf4,0xe9,0x91,0x72,0x50,0xfb,
	                        0x32,0xba,0xb9,0x26,0xd8,0xa6,0x2b,0xae,0xb3,0x8e,0x44,0x57,0xcd,0x96,0xcc,0xc2,0x1f,
							0xb0,0xa4,0xf6,0x5f,0x68,0xac,0x60,0x3c,0x27,0x88,0xd1,0xae,0x8e,0xcd,0xbc,0xa2,0xed,
							0x91,0xb3,0x8d,0xc8,0x6a,0x76,0xfc,0x9a,0xa8,0x04,0x32,0xce,0xe8,0xf6,0x9d,0xcd,0xbf,
							0xe9,0x26,0x5d,0xec,0xea,0xb8,0x05,0x6a,0x0a,0xec,0x75,0xff,0x63,0x79,0xbc,0x20,0xac,
							0x39,0x12,0xdb,0xea,0x23,0x7f,0x4c,0x37,0xc5,0x72,0x9f,0xae,0x0c,0xdc,0xcf,0x5c,0x12,
							0x35,0x91,0x9c,0x98,0xde,0x1f,0xd0,0x95,0xa5,0xb8,0xbc,0x5d,0x0a,0x65,0x82,0xce,0xf8,
							0xa8,0xa2,0xaf,0x70,0x7a,0xf0,0xcb,0x22,0xfb};
*/
/*
  // generate n
  Random::sbits(rprivparam->p, l_n/2);
  zkprintf("p:\n%Zx\n\n", rprivparam->p);

  Random::sbits(rprivparam->q, l_n/2);
  zkprintf("q:\n%Zx\n\n", rprivparam->q);
*/

  bnz_import(rprivparam->p, sizeof p_char, 1, 1, 0, 0, p_char);
  bnz_import(rprivparam->q, sizeof q_char, 1, 1, 0, 0, q_char);
  #ifdef _DEBUG
    printf("p:\n%s\n\n", bn2str(rprivparam->p));
    printf("q:\n%s\n\n", bn2str(rprivparam->q));
  #endif

  bnz_mul(pubparam->n, rprivparam->p, rprivparam->q);
  #ifdef _DEBUG
    printf("n:\n%s\n\n", bn2str(pubparam->n));
  #endif

  bnz_mul(pubparam->n2, pubparam->n, pubparam->n);
  #ifdef _DEBUG
    printf("n^2:\n%s\n\n", bn2str(pubparam->n2));
  #endif

  {   // determine phi = (p-1)(q-1)/4
      bnz_t temp;
      bnz_init(temp);

      bnz_tdiv_q_2exp(temp           , rprivparam->p, 1);
      bnz_tdiv_q_2exp(rprivparam->phi, rprivparam->q, 1);
      bnz_mul(rprivparam->phi, rprivparam->phi, temp);

      bnz_clear(temp);
  }

  genQR(&pubparam->a, &pubparam->n);
  genQR(&pubparam->b, &pubparam->n);
  genQR(&pubparam->d, &pubparam->n);
  genQR(&pubparam->f1, &pubparam->n);
  genQR(&pubparam->f2, &pubparam->n);
  genQR(&pubparam->g, &pubparam->n);
  genQR(&pubparam->h, &pubparam->n);
  genQR(&pubparam->h_1, &pubparam->n);
  genQR(&pubparam->h_2, &pubparam->n);
  genQR(&pubparam->ghat, &pubparam->n);
  genQR(&pubparam->hhat, &pubparam->n);

  // gbar = (gbarprime)^2n
  bnz_t gbarprime;
  bnz_init(gbarprime);
  genQR(&gbarprime, &pubparam->n2);
  bnz_powm_ui(pubparam->gbar, gbarprime, 2, pubparam->n2);
  bnz_powm(pubparam->gbar, pubparam->gbar, pubparam->n, pubparam->n2);

  // determine O's secret keys
  bnz_t tmp;
  bnz_init(tmp);
  bnz_tdiv_q_2exp(tmp, pubparam->n2, 2);
  bnz_sub_ui(tmp, tmp, 1);
  Random::posrange(oprivparam->xbar_1, tmp);
  Random::posrange(oprivparam->xbar_2, tmp);
  Random::posrange(oprivparam->xbar_3, tmp);
  bnz_clear(tmp);

  // determine O's public keys
  bnz_powm(pubparam->ybar_1, pubparam->gbar, oprivparam->xbar_1, pubparam->n2);
  bnz_powm(pubparam->ybar_2, pubparam->gbar, oprivparam->xbar_2, pubparam->n2);
  bnz_powm(pubparam->ybar_3, pubparam->gbar, oprivparam->xbar_3, pubparam->n2);
  bnz_add_ui(pubparam->hbar, pubparam->n, 1);
  bnz_mod(pubparam->hbar, pubparam->hbar, pubparam->n2);

  bnz_set_ui(pubparam->hhk, 1);

  bnz_clear(gbarprime);

  for (int i=0; i < M; i++)
    Random::pbits(pubparam->Cert[i], l);
  for (int i=0; i < N; i++)
    Random::pbits(pubparam->iRole[i], l);
// FIXME
//  bnz_set_ui(pubparam->iRole[0], 1);

  #ifdef _DEBUG
    printf("a:\n%s\n\n", bn2str(pubparam->a));
    printf("b:\n%s\n\n", bn2str(pubparam->b));
    printf("d:\n%s\n\n", bn2str(pubparam->d));
    printf("f1:\n%s\n\n", bn2str(pubparam->f1));
    printf("f2:\n%s\n\n", bn2str(pubparam->f2));
    printf("g:\n%s\n\n", bn2str(pubparam->g));
    printf("h:\n%s\n\n", bn2str(pubparam->h));
    printf("h_1:\n%s\n\n", bn2str(pubparam->h_1));
    printf("h_2:\n%s\n\n", bn2str(pubparam->h_2));
    printf("ghat:\n%s\n\n", bn2str(pubparam->ghat));
    printf("hhat:\n%s\n\n", bn2str(pubparam->hhat));
    printf("gbar:\n%s\n\n", bn2str(pubparam->gbar));
    printf("hbar:\n%s\n\n", bn2str(pubparam->hbar));
    printf("ybar_1:\n%s\n\n", bn2str(pubparam->ybar_1));
    printf("ybar_2:\n%s\n\n", bn2str(pubparam->ybar_2));
    printf("ybar_3:\n%s\n\n", bn2str(pubparam->ybar_3));
    for (int i=0; i < M; i++)
      printf("Cert[%i]:\n%s\n\n", i, bn2str(pubparam->Cert[i]));
    for (int i=0; i < N; i++)
      printf("iRole[%i]:\n%s\n\n", i, bn2str(pubparam->iRole[i]));
  #endif
  return(0);
  }


void genUPrivParam(UPrivParam *priv, pubParam *pub, bnz_t *C_x_1)
{
    // Commitment for x
#ifdef WORST_CASE
    bnz_setbit(priv->x, l_x + 1);
    bnz_sub_ui(priv->x, priv->x, 1);
    bnz_setbit(priv->r_1, l_n + 1);
    bnz_sub_ui(priv->r_1, priv->r_1, 1);
#elif defined(AVERAGE)
    bnz_setbit(priv->x, l_x/2 + 1);
    bnz_sub_ui(priv->x, priv->x, 1);
    bnz_setbit(priv->r_1, l_n/2 + 1);
    bnz_sub_ui(priv->r_1, priv->r_1, 1);
#else
    Random::bits(priv->x, l_x);
    Random::bits(priv->r_1, l_n);
#endif

    bnz_t temp;
    bnz_init(temp);

    // C_x_1 = a^x * b^r_1 mod n
    bnz_powm(temp, pub->b, priv->r_1, pub->n);
    bnz_powm(*C_x_1, pub->a, priv->x, pub->n);
    bnz_mul(*C_x_1, temp, *C_x_1);
    bnz_mod(*C_x_1, *C_x_1, pub->n);

    bnz_clear(temp);
#ifdef _DEBUG
    printf("C_x_1 = a^x * b^r_1 mod n:\n%s\n\n", bn2str(*C_x_1));
#endif
}

void Sign(RPrivParam *priv, pubParam *pub, bnz_t *r_prime, bnz_t *mbar, Cert *cert, bnz_t *C_x_1)
{
    bnz_t q, mhat, E, temp1, temp2;
    bnz_init(q);
    bnz_init(mhat);
    bnz_init(E);
    bnz_init(temp1);
    bnz_init(temp2);

    bnz_set_ui(cert->TS_max, MAX_TIMESTAMP);

    // choose identifier mbar
    Random::posrange(*mbar, pub->n);

    // accumulator
    bnz_set_ui(mhat, 1);
    for (int i=0; i < M; i++)
        bnz_mul(mhat, mhat, pub->Cert[i]);
    for (int i=0; i < N; i++)
        bnz_mul(mhat, mhat, pub->iRole[i]);
//    bnz_mod(mhat, mhat, pub->n);

    bnz_powm(q, pub->g, mhat, pub->n);
#ifdef _DEBUG
    printf("q:\n%s\n\n", bn2str(q));
#endif

    // Commitment for x
#ifdef WORST_CASE
    bnz_setbit(*r_prime, l_n + 1);
    bnz_sub_ui(*r_prime, *r_prime, 1);
#elif defined(AVERAGE)
    bnz_setbit(*r_prime, l_n/2 + 1);
    bnz_sub_ui(*r_prime, *r_prime, 1);
#else
    Random::bits(*r_prime, l_n);
#endif

    Random::pbits(cert->e, l_e);

    // E = 2^{l_E} + e
    bnz_ui_pow_ui(E, 2, l_E);
    bnz_add(E, E, cert->e);

    // invert E
    bnz_invert(E, E, priv->phi);

    // v = (C_{x_1} b^{r_prime} d g^mhat f1^{LT} h^mbar)^{1/E} mod n
    bnz_powm(temp1, pub->b, *r_prime, pub->n);
    bnz_powm(temp2, pub->f1, cert->TS_max, pub->n);
	bnz_powm(cert->v, pub->h, *mbar, pub->n);
    bnz_mul(cert->v, cert->v, temp2);
    bnz_mul(cert->v, cert->v, q);
    bnz_mul(cert->v, cert->v, pub->d);
    bnz_mul(cert->v, cert->v, temp1);
    bnz_mul(cert->v, cert->v, *C_x_1);
    bnz_mod(cert->v, cert->v, pub->n);
    bnz_powm(cert->v, cert->v, E, pub->n);
#ifdef _DEBUG
    printf("v = (C_{x_1} b^{r_prime} d g^mhat f1^{LT} h^mbar)^{1/E} mod n:\n%s\n\n", bn2str(cert->v));
#endif

    bnz_clear(q);
    bnz_clear(mhat);
    bnz_clear(E);
    bnz_clear(temp1);
    bnz_clear(temp2);
}

void Finish(Cert *cert, pubParam *pub, UPrivParam *priv, bnz_t *r_prime, bnz_t *mbar)
{
    bnz_t mhat, result1, result2, E, temp1, temp2, temp3;
    bnz_init(result1);
    bnz_init(result2);
    bnz_init(E);
    bnz_init(temp1);
    bnz_init(temp2);
    bnz_init(temp3);

    // accumulator
    bnz_set_ui(cert->mhat, 1);
    for (int i=0; i < M; i++)
        bnz_mul(cert->mhat, cert->mhat, pub->Cert[i]);
    for (int i=0; i < N; i++)
        bnz_mul(cert->mhat, cert->mhat, pub->iRole[i]);
    //bnz_mod(cert->mhat, cert->mhat, pub->n);

    bnz_powm(cert->q, pub->g, cert->mhat, pub->n);
#ifdef _DEBUG
    printf("q:\n%s\n\n", bn2str(cert->q));
#endif

    // s = r_1 + r_prime
    bnz_add(cert->s, priv->r_1, *r_prime);
#ifdef _DEBUG
    printf("s = r_1 + r_prime:\n%s\n\n", bn2str(cert->s));
#endif

    bnz_ui_pow_ui(E, 2, l_E);
    bnz_add(E, E, cert->e);

    // verifying certificate
    bnz_powm(result1, cert->v, E, pub->n);
#ifdef _DEBUG
    printf("result1:\n%s\n\n", bn2str(result1));
#endif
    bnz_powm(temp1, pub->a, priv->x, pub->n);
    bnz_powm(temp2, pub->b, cert->s, pub->n);
    bnz_powm(temp3, pub->f1, cert->TS_max, pub->n);
    bnz_powm(result2, pub->h, *mbar, pub->n);
    bnz_mul(result2, result2, temp3);
    bnz_mul(result2, result2, cert->q);
    bnz_mul(result2, result2, pub->d);
    bnz_mul(result2, result2, temp2);
    bnz_mul(result2, result2, temp1);
    bnz_mod(result2, result2, pub->n);
#ifdef _DEBUG
    printf("result2:\n%s\n\n", bn2str(result2));
    printf("result1 %s result2\n\n", bnz_cmp(result1, result2) ? "!=" : "==");
#endif

    // calculating u[i]
    //for (int i=0; i < N; i++)  {
    //    bnz_set_ui(temp1, 1);
    //    for (int j=0; j < N; j++)
    //        if (i != j)
    //            bnz_mul(temp1, temp1, pub->iRole[i]);
    //    bnz_powm(cert->u[i], pub->g, temp1, pub->n);
    //}
	bnz_set_ui(temp1, 1);
    for (int i=0; i < M; i++)  {
        bnz_mul(temp1, temp1, pub->Cert[i]);
    }

	for (int i=0; i < N; i++)  {
        bnz_set(cert->u[i], temp1);
        for (int j=0; j < N; j++)
            if (i != j)  {
                bnz_mul(cert->u[i], cert->u[i], pub->iRole[j]);
			}
        bnz_powm(cert->u[i], pub->g, cert->u[i], pub->n);
	}
    
#ifdef _DEBUG
    printf("pub->iRole[0]:\n%s\n\n", bn2str(pub->iRole[0]));
    printf("cert->u[0]:\n%s\n\n", bn2str(cert->u[0]));
	bnz_powm(temp1, cert->u[0], pub->iRole[0], pub->n);
    printf("Accu1:\n%s\n\n", bn2str(temp1));
	printf("Accu2:\n%s\n\n", bn2str(cert->q));
#endif

	bnz_clear(result1);
    bnz_clear(result2);
    bnz_clear(E);
    bnz_clear(temp1);
    bnz_clear(temp2);
    bnz_clear(temp3);
}

Parser *initParser(const char *file, pubParam *pub, Cert */*cert*/, RLWitnesses *rl)
{
    try {
        Parser *p = Parser::fromFile(file);
        p->getVar("a")->set(CMV_IN(pub->a));
        p->getVar("b")->set(CMV_IN(pub->b));
        p->getVar("d")->set(CMV_IN(pub->d));
        p->getVar("f1")->set(CMV_IN(pub->f1));
        p->getVar("f2")->set(CMV_IN(pub->f2));
        p->getVar("g")->set(CMV_IN(pub->g));
        p->getVar("h")->set(CMV_IN(pub->h));
        p->getVar("h_1")->set(CMV_IN(pub->h_1));
        p->getVar("h_2")->set(CMV_IN(pub->h_2));
        p->getVar("ghat")->set(CMV_IN(pub->ghat));
        p->getVar("hhat")->set(CMV_IN(pub->hhat));
        p->getVar("gbar")->set(CMV_IN(pub->gbar));
        p->getVar("hbar")->set(CMV_IN(pub->hbar));
        p->getVar("ybar_1")->set(CMV_IN(pub->ybar_1));
        p->getVar("ybar_2")->set(CMV_IN(pub->ybar_2));
        p->getVar("ybar_3")->set(CMV_IN(pub->ybar_3));
        p->getVar("hhk")->set(CMV_IN(pub->hhk));

		p->getVar("mhat_i")->set(CMV_IN(pub->iRole[0]));

        p->getVar("Cmhat")->set(CMV_IN(rl->Cmhat));
        p->getVar("mhatprime1")->set(CMV_IN(rl->rlwitness[0].mhatprime));
        p->getVar("mhatprime2")->set(CMV_IN(rl->rlwitness[1].mhatprime));

        bnz_t tmp;
		bnz_init(tmp);
		bnz_set_ui(tmp, 2);
        p->getVar("two")->set(CMV_IN(tmp));
		bnz_clear(tmp);
        return p;
    } catch(const char *msg) {
        printf("Exception: %s\n", msg);
        throw;
    }
}

void initProver(Parser *p, pubParam *pub, UPrivParam *priv, Cert *cert, bnz_t *mbar, bnz_t *Cv, bnz_t *TS_cur, bnz_t *Cui, RLWitnesses *rl)
{
    bnz_t r_2;
	bnz_t rhat_1;
	bnz_t sbar;
    bnz_t varSigma;
    bnz_t tmp;
    bnz_t squares[4];

    bnz_init(r_2);
    bnz_init(rhat_1);
    bnz_init(sbar);
    bnz_init(varSigma);
    bnz_init(tmp);
    for(int i = 0; i < 4; ++i) bnz_init(squares[i]);
    
    /* Cv = v * b^r2 */
    Random::bits(r_2, l_n/2);
    bnz_powm(*Cv, pub->b, r_2, pub->n);
    bnz_mul(*Cv, *Cv, cert->v);
    bnz_mod(*Cv, *Cv, pub->n);
    p->getVar("Cv")->set(CMV_IN(*Cv));

    bnz_ui_pow_ui(varSigma, 2, l_E);
    bnz_add(varSigma, varSigma, cert->e);
    bnz_mul(varSigma, varSigma, r_2);
    bnz_add(varSigma, varSigma, cert->s);

    Element *w = p->getVar("w");
    w->getSub(0)->set(CMV_IN(cert->TS_max));
    w->getSub(1)->set(CMV_IN(cert->e));
    w->getSub(2)->set(CMV_IN(priv->x));
    w->getSub(3)->set(CMV_IN(varSigma));
    w->getSub(4)->set(CMV_IN(cert->mhat));
    w->getSub(5)->set(CMV_IN(*mbar));

	Element *intr = w->getSub(6);

    bnz_sub(tmp, cert->TS_max, *TS_cur);
    foursquares(squares[0], squares[1], squares[2], squares[3], tmp);
  
    for(unsigned i = 0; i < 4; ++i) {
        intr->getSub(i)->getSub(1)->set(CMV_IN(squares[i]));
        intr->getSub(i)->getSub(0)->cast(intr->getSub(i)->getSub(1));
        intr->getSub(i)->getSub(0)->pow(intr->getSub(i)->getSub(0), CMV_IN(squares[i]));
        intr->getSub(i)->getSub(2)->random();
        intr->getSub(i)->getSub(3)->cast(intr->getSub(i)->getSub(1));
        intr->getSub(i)->getSub(3)->pow(intr->getSub(i)->getSub(3), intr->getSub(i)->getSub(2));
    }
    intr->getSub(4)->random();

    /* C_{u_i} = u_i * h_1^rhat_1 */
    Random::bits(rhat_1, l_n/2);
    bnz_powm(*Cui, pub->h_1, rhat_1, pub->n);
	bnz_mul(*Cui, *Cui, cert->u[0]);
    bnz_mod(*Cui, *Cui, pub->n);

    w->getSub(7)->set(CMV_IN(rhat_1));
    w->getSub(8)->set(CMV_IN(rl->rhat_3));

    w->getSub(9)->set(CMV_IN(pub->rbar));

    // non-mem proof 1
    w->getSub(10)->set(CMV_IN(rl->rlwitness[0].uprime_1));
    w->getSub(11)->set(CMV_IN(rl->rlwitness[0].rhat_2));
    w->getSub(12)->set(CMV_IN(rl->rhat_3));
    w->getSub(13)->set(CMV_IN(rl->rlwitness[0].rhat_4));
    w->getSub(14)->set(CMV_IN(rl->rlwitness[0].z_1));
    // nuhat = rhat_3 uprime_1
    bnz_mul(tmp, rl->rhat_3, rl->rlwitness[0].uprime_1);
    w->getSub(15)->set(CMV_IN(tmp));


    // non-mem proof 2
    w->getSub(16)->set(CMV_IN(rl->rlwitness[1].uprime_1));
    w->getSub(17)->set(CMV_IN(rl->rlwitness[1].rhat_2));
    w->getSub(18)->set(CMV_IN(rl->rhat_3));
    w->getSub(19)->set(CMV_IN(rl->rlwitness[1].rhat_4));
    w->getSub(20)->set(CMV_IN(rl->rlwitness[1].z_1));

    // nuhat = rhat_3 uprime_1
    bnz_mul(tmp, rl->rhat_3, rl->rlwitness[1].uprime_1);
    w->getSub(21)->set(CMV_IN(tmp));



	Element *x = p->getVar("x");

    // x[0] = d^-1 * Cv^(2^(L_E))
    bnz_ui_pow_ui(tmp, 2, l_E);
    x->getSub(0)->pow(p->getVar("Cv"), CMV_IN(tmp));
    x->getSub(0)->iop(x->getSub(0), p->getVar("d"));

    Element *f1 = p->getVar("f1");
    Element *f2 = p->getVar("f2");

    Element *tmp3 = p->getElement("H");
    tmp3->pow(f2, intr->getSub(4));

    x->getSub(1)->pow(f1, CMV_IN(cert->TS_max));
    x->getSub(1)->op(x->getSub(1), tmp3);

    x->getSub(2)->ipow(f1, CMV_IN(*TS_cur));
    x->getSub(2)->op(x->getSub(2), x->getSub(1));
  
    Element *xint = x->getSub(3);
    for(unsigned i = 0; i < 4; ++i) {
        // x0[i] = f1 ^ wi * f2 ^ pi
        xint->getSub(i)->getSub(0)->pow(f1, intr->getSub(i)->getSub(1));
        tmp3->pow(f2, intr->getSub(i)->getSub(2));
        xint->getSub(i)->getSub(0)->op(xint->getSub(i)->getSub(0), tmp3);

        // x1[i] = 1
        xint->getSub(i)->getSub(1)->identity();
    }

    // C_{u_i}^{\hat{m}_i}
	bnz_powm(tmp, *Cui, pub->iRole[0], pub->n);
    x->getSub(4)->set(CMV_IN(tmp));

	// ubar^2
	bnz_powm_ui(tmp, pub->ubar, 2, pub->n2);
    x->getSub(5)->set(CMV_IN(tmp));

	// ebar^2
	bnz_powm_ui(tmp, pub->ebar, 2, pub->n2);
    x->getSub(6)->set(CMV_IN(tmp));

	// vbar^2
	bnz_powm_ui(tmp, pub->vbar, 2, pub->n2);
    x->getSub(7)->set(CMV_IN(tmp));

	// Cmhat
    x->getSub(8)->set(CMV_IN(rl->Cmhat));

    // 1
    // Cuprime_2LS
	bnz_powm(tmp, rl->rlwitness[0].Cuprime_2, rl->rlwitness[0].mhatprime, pub->n);
	bnz_mul(tmp, tmp, pub->g);
	bnz_mod(tmp, tmp, pub->n);
    x->getSub(9)->set(CMV_IN(tmp));
    // Cuprime_1
    x->getSub(10)->set(CMV_IN(rl->rlwitness[0].Cuprime_1));
    // 1
    x->getSub(11)->identity();

    // 2
    // Cuprime_2LS
	bnz_powm(tmp, rl->rlwitness[1].Cuprime_2, rl->rlwitness[1].mhatprime, pub->n);
	bnz_mul(tmp, tmp, pub->g);
	bnz_mod(tmp, tmp, pub->n);
    x->getSub(12)->set(CMV_IN(tmp));
    // Cuprime_1
    x->getSub(13)->set(CMV_IN(rl->rlwitness[1].Cuprime_1));
    // 1
    x->getSub(14)->identity();

    delete tmp3;

    bnz_clear(r_2);
    bnz_clear(rhat_1);
    bnz_clear(sbar);
    bnz_clear(varSigma);
    bnz_clear(tmp);
    for(int i = 0; i < 4; ++i) bnz_clear(squares[i]);
}

void initVerifier(Parser *p, bnz_t *Cv, bnz_t *TS_cur, Element *proverx)
{
    bnz_t tmp;
    bnz_init(tmp);
    Message msg;

    Element *x = p->getVar("x");
    
    p->getVar("Cv")->set(CMV_IN(*Cv));

//	p->getVar("Cmhat")->set(CMV_IN(*Cmhat));
    
    bnz_ui_pow_ui(tmp, 2, l_E);
    x->getSub(0)->pow(p->getVar("Cv"), CMV_IN(tmp));
    x->getSub(0)->iop(x->getSub(0), p->getVar("d"));

    msg = proverx->getSub(1)->get();
    x->getSub(1)->set(msg);
    delete[] msg.data;

    x->getSub(2)->ipow(p->getVar("f1"), CMV_IN(*TS_cur));
    x->getSub(2)->op(x->getSub(2), x->getSub(1));
    
    for(unsigned i = 0; i < 4; ++i) {
        msg = proverx->getSub(3)->getSub(i)->getSub(0)->get();
        x->getSub(3)->getSub(i)->getSub(0)->set(msg);
        delete[] msg.data;
        x->getSub(3)->getSub(i)->getSub(1)->identity();
    }

    msg = proverx->getSub(4)->get();
    x->getSub(4)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(5)->get();
    x->getSub(5)->set(msg);
    delete[] msg.data;

	msg = proverx->getSub(6)->get();
    x->getSub(6)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(7)->get();
    x->getSub(7)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(8)->get();
    x->getSub(8)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(9)->get();
    x->getSub(9)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(10)->get();
    x->getSub(10)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(11)->get();
    x->getSub(11)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(12)->get();
    x->getSub(12)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(13)->get();
    x->getSub(13)->set(msg);
    delete[] msg.data;

    msg = proverx->getSub(14)->get();
    x->getSub(14)->set(msg);
    delete[] msg.data;

	bnz_clear(tmp);
}

void exteuclid(bnz_t *X, bnz_t *Y, bnz_t *a, bnz_t *b)  {
    bnz_t tmp;
    bnz_init(tmp);

    bnz_invert(*X, *a, *b);
    bnz_set_ui(*Y, 1);
    bnz_mul(tmp, *a, *X);
    bnz_sub(*Y, *Y, tmp);

    bnz_divexact(*Y, *Y, *b);

    bnz_clear(tmp);
}

void getNonMemWitness(bnz_t* uprime_1, bnz_t *uprime_2, pubParam *pub, Cert *cert, bnz_t *mhatprime)  {
    bnz_t uhatprime_1, bhatprime, khat, result1, result2;
    bnz_init(uhatprime_1);
    bnz_init(bhatprime);
    bnz_init(khat);
    bnz_init(result1);
    bnz_init(result2);

    exteuclid(&uhatprime_1, &bhatprime, &cert->mhat, mhatprime);
    bnz_mul(result1, uhatprime_1, cert->mhat);
    bnz_mul(result2, bhatprime, *mhatprime);
    bnz_add(result1, result1, result2);
#ifdef _DEBUG
    printf("result1 (ggt):\n%s\n\n", bn2str(result1));
#endif
    // khat
    bnz_setbit(khat, l);
    bnz_sub_ui(khat, khat, 1);
    bnz_sub(khat, khat, uhatprime_1);
    bnz_tdiv_q(khat, khat, *mhatprime);

    // uprime_1
    bnz_mul(*uprime_1, khat, *mhatprime);
    bnz_add(*uprime_1, *uprime_1, uhatprime_1);

    // uprime_2
    bnz_mul(*uprime_2, khat, cert->mhat);
    bnz_sub(*uprime_2, *uprime_2, bhatprime);
    bnz_powm(*uprime_2, pub->g, *uprime_2, pub->n);

    // verification
    bnz_powm(result1, cert->q, *uprime_1, pub->n);
    bnz_powm(result2, *uprime_2, *mhatprime, pub->n);
    bnz_mul(result2, result2, pub->g);
    bnz_mod(result2, result2, pub->n);
#ifdef _DEBUG
    printf("result1 (non-mem witness):\n%s\n\n", bn2str(result1));
    printf("result2 (non-mem witness):\n%s\n\n", bn2str(result2));
    printf("result1 %s result2\n\n", bnz_cmp(result1, result2) ? "!=" : "==");
#endif

    bnz_clear(uhatprime_1);
    bnz_clear(bhatprime);
    bnz_clear(khat);
    bnz_clear(result1);
    bnz_clear(result2);
}

int main(int argc, char *argv[])
  {
  if(argc != 2) {
      printf("I need my .zk file as parameter!\n");
      return 1;
  }

  bnz_t TS_cur;
  bnz_init(TS_cur);

FILE* log;
log=fopen("log.txt","w");

if(log==NULL)
//fehler beim oeffnen
return -1;

  TimeCounter timecnt[RUNS];
  Timestamp timestamp;
  for (int i=0; i < RUNS; i++)
    TimeCounterInit(&timecnt[i]);

  for (int run=0; run < RUNS; run++)  {

#ifdef WORST_CASE
    bnz_set_ui(TS_cur, MAX_TIMESTAMP-6);
  #elif defined(AVERAGE)
    bnz_set_ui(TS_cur, MAX_TIMESTAMP/2);
  #else
//    Random::posrange(TS_cur, cert.TS_max);
    bnz_set_ui(TS_cur, run*20000);
  #endif

  for (int steps=0; steps < TESTS; steps++)  {

  Random::init();

  Hash *h;


  pubParam pubparam;
  RPrivParam rprivparam;
  UPrivParam uprivparam;
  OPrivParam oprivparam;
  Cert cert;

  RLWitnesses rl;
  RLWitnessesInit(&rl);

  bnz_t C_x_1, r_prime, mbar, Cv, Cui, tmp;

  pubParamInit(&pubparam);
  RprivparamInit(&rprivparam);
  UPrivParamInit(&uprivparam);
  OPrivParamInit(&oprivparam);
  CertInit(&cert);
  bnz_init(C_x_1);
  bnz_init(r_prime);
  bnz_init(mbar);
  bnz_init(Cv);
  bnz_init(Cui);
  bnz_init(tmp);
  
  genPubParam(&pubparam, &rprivparam, &oprivparam);

  // Requesting new iRole ZKC (U), PART I
  Timestamp_begin(&timestamp);
  genUPrivParam(&uprivparam, &pubparam, &C_x_1);
  timecnt[run].requestU =+ Timestamp_end(&timestamp);

  // Requesting new iRole ZKC (R)
  Timestamp_begin(&timestamp);
  Sign(&rprivparam, &pubparam, &r_prime, &mbar, &cert, &C_x_1);
  timecnt[run].requestR =+ Timestamp_end(&timestamp);

  // Requesting new iRole ZKC (U), PART II
  Timestamp_begin(&timestamp);
  Finish(&cert, &pubparam, &uprivparam, &r_prime, &mbar);
  timecnt[run].requestU =+ Timestamp_end(&timestamp);


  // Signing
  Timestamp_begin(&timestamp);

  // Verifiable Encryption
  // calculate (u,e,v)
  Random::bits(pubparam.rbar, l_n/4 - 1);
  bnz_powm(pubparam.ubar, pubparam.gbar, pubparam.rbar, pubparam.n2);

  bnz_powm(tmp, pubparam.ybar_1, pubparam.rbar, pubparam.n2);
  bnz_powm(pubparam.ebar, pubparam.hbar, mbar, pubparam.n2);
  bnz_mul(pubparam.ebar, pubparam.ebar, tmp);
  bnz_mod(pubparam.ebar, pubparam.ebar, pubparam.n2);

  bnz_powm(pubparam.vbar, pubparam.ybar_3, pubparam.hhk, pubparam.n2);
  bnz_mul(pubparam.vbar, pubparam.ybar_2, pubparam.vbar);
  bnz_powm(pubparam.vbar, pubparam.vbar, pubparam.rbar, pubparam.n2);


  // non-membership proofs
  Random::bits(rl.rhat_3, l_n + l);

  // C_mhat = ghat^mhat hhat^rhat_3
  bnz_powm(rl.Cmhat, pubparam.hhat, rl.rhat_3, pubparam.n);
  bnz_powm(tmp, pubparam.ghat, cert.mhat, pubparam.n);
  bnz_mul(rl.Cmhat, rl.Cmhat, tmp);
  bnz_mod(rl.Cmhat, rl.Cmhat, pubparam.n);
    
  for (int i=0; i < RL; i++)  {
      Random::pbits(rl.rlwitness[i].mhatprime, l);
      getNonMemWitness(&rl.rlwitness[i].uprime_1, &rl.rlwitness[i].uprime_2, &pubparam, &cert, &rl.rlwitness[i].mhatprime);

      // C_uprime_1 = ghat^uprime_1 hhat^rhat_4
      Random::bits(rl.rlwitness[i].rhat_4, l_n + l);
      bnz_powm(rl.rlwitness[i].Cuprime_1, pubparam.hhat, rl.rlwitness[i].rhat_4, pubparam.n);
	  bnz_powm(tmp, pubparam.ghat, rl.rlwitness[i].uprime_1, pubparam.n);
      bnz_mul(rl.rlwitness[i].Cuprime_1, rl.rlwitness[i].Cuprime_1, tmp);
      bnz_mod(rl.rlwitness[i].Cuprime_1, rl.rlwitness[i].Cuprime_1, pubparam.n);

#ifdef _DEBUG
    printf("C_uprime_1:\n%s\n\n", bn2str(rl.rlwitness[i].Cuprime_1));
    printf("rl.rlwitness[i].rhat_4:\n%s\n\n", bn2str(rl.rlwitness[i].rhat_4));
#endif

      // C_uprime_2 = uprime_2 h_2^rhat_2
      Random::bits(rl.rlwitness[i].rhat_2, l_n/2);
      bnz_powm(rl.rlwitness[i].Cuprime_2, pubparam.h_2, rl.rlwitness[i].rhat_2, pubparam.n);
      bnz_mul(rl.rlwitness[i].Cuprime_2, rl.rlwitness[i].Cuprime_2, rl.rlwitness[i].uprime_2);
      bnz_mod(rl.rlwitness[i].Cuprime_2, rl.rlwitness[i].Cuprime_2, pubparam.n);

      // z_1 = mhat uprime_1
      bnz_mul(rl.rlwitness[i].z_1, cert.mhat, rl.rlwitness[i].uprime_1);
  }

  try {
      Parser *prover   = initParser(argv[1], &pubparam, &cert, &rl);
      initProver(prover, &pubparam, &uprivparam, &cert, &mbar, &Cv, &TS_cur, &Cui, &rl);
	  Sigma *sigp = prover->getSigma("sigma");

      /* prover creates a hash function object */
      h = new SHA1();
      Message sig;
      /* prover creates a signature */
      sig = sigp->sign(h);

	  timecnt[run].activatingU =+ Timestamp_end(&timestamp);

      delete h;

      /* verifier creates a hash function object */
      h = new SHA1();
      // Verifying
      Timestamp_begin(&timestamp);

      Parser *verifier = initParser(argv[1], &pubparam, &cert, &rl);
      initVerifier(verifier, &Cv, &TS_cur, prover->getVar("x"));
      Sigma *sigv = verifier->getSigma("sigma");

      /* verifier verifies the signature */
      printf("V: %d\n", sigv->verify(h, sig));
   	  timecnt[run].activatingG =+ Timestamp_end(&timestamp);

	  delete[] sig.data;

      delete sigp;
      delete sigv;
      delete prover;
      delete verifier;
  } catch(const char *err) {
      printf("Exception: %s\n", err);
      throw;
  }

  // opening (u,e,v)
  bnz_t result1, result2;
  bnz_init(result1);
  bnz_init(result2);

  // Opening
  Timestamp_begin(&timestamp);
  // ubar^{2(xbar_2 + \mathcal{H}_{\text{\texttt{hk}}}(ubar,ebar)xbar_3)} = vbar^2
  bnz_mul(result1, pubparam.hhk, oprivparam.xbar_3);
  bnz_add(result1, oprivparam.xbar_2, result1);
  bnz_mul_2exp(result1, result1, 1);
  bnz_powm(result1, pubparam.ubar, result1, pubparam.n2);

  bnz_powm_ui(result2, pubparam.vbar, 2, pubparam.n2);

#ifdef _DEBUG
    printf("result1:\n%s\n\n", bn2str(result1));
    printf("result2:\n%s\n\n", bn2str(result2));
    printf("result1 %s result2\n\n", bnz_cmp(result1, result2) ? "!=" : "==");
#endif

  bnz_powm(tmp, pubparam.hbar, mbar, pubparam.n2);
  bnz_powm(result1, pubparam.ubar, oprivparam.xbar_1, pubparam.n2);
  bnz_mul(result1, result1, tmp);
  bnz_mod(result1, result1, pubparam.n2);

  bnz_set(result2, pubparam.ebar);

#ifdef _DEBUG
    printf("result1:\n%s\n\n", bn2str(result1));
    printf("result2:\n%s\n\n", bn2str(result2));
    printf("result1 %s result2\n\n", bnz_cmp(result1, result2) ? "!=" : "==");
#endif

  timecnt[run].opening =+ Timestamp_end(&timestamp);

  bnz_clear(result1);
  bnz_clear(result2);
  bnz_clear(tmp);


  delete h;

  pubParamClear(&pubparam);
  RprivparamClear(&rprivparam);
  UPrivParamClear(&uprivparam);
  OPrivParamClear(&oprivparam);
  CertClear(&cert);
  RLWitnessesClear(&rl);
  bnz_clear(C_x_1);
  bnz_clear(r_prime);
  bnz_clear(mbar);
  bnz_clear(Cv);
  bnz_clear(Cui);
  
  Random::free();
}
  printf("Requesting iRole ZKC (U)   : %f seconds\n", timecnt[run].requestU/TESTS);
  printf("Requesting iRole ZKC (R)   : %f seconds\n", timecnt[run].requestR/TESTS);
  printf("Activating an iRole ZKC (U): %f seconds\n", timecnt[run].activatingU/TESTS);
  printf("Activating an iRole ZKC (G): %f seconds\n", timecnt[run].activatingG/TESTS);
  printf("Opening: %f seconds\n", timecnt[run].opening/TESTS);

}

for (int i=0; i < RUNS; i++)
  fprintf(log, "(%i, %f) ", i, timecnt[i].requestU/TESTS);
fprintf(log, "\n");

for (int i=0; i < RUNS; i++)
  fprintf(log, "(%i, %f) ", i, timecnt[i].requestR/TESTS);
fprintf(log, "\n");

for (int i=0; i < RUNS; i++)
  fprintf(log, "(%i, %f) ", i, timecnt[i].activatingU/TESTS);
fprintf(log, "\n");

for (int i=0; i < RUNS; i++)
  fprintf(log, "(%i, %f) ", i, timecnt[i].activatingG/TESTS);
fprintf(log, "\n");

fclose(log);
bnz_clear(TS_cur);

  int i;               /* Ein ganzzahliger Datentyp */
   printf("Bitte geben Sie eine Zahl ein : ");
   scanf("%d",&i);      /* Wartet auf die Eingabe */

  return 0;
  }
