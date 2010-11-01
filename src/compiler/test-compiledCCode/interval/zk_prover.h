/* begin c-header-code of program "prover" */
#ifndef ZK_prover_H

#include <gmp.h>

typedef int zk_int;
typedef unsigned int zk_uint;
typedef long zk_long;
typedef unsigned long zk_ulong;
typedef const char* zk_pcchar;
typedef unsigned int zk_bool;
typedef unsigned int zk_relation;

#define zk_false 0
#define zk_true 1

/* ZK-protocol functions. */
zk_bool zk_Prover_init(const mpz_t vAux_gi[1], const mpz_t vPublicCommitment_x[27], const mpz_t vSecret_w[42]);
zk_bool zk_Prover_p1(mpz_t vCommitment[27]);
zk_bool zk_Prover_p2(mpz_t vResponse[42], const mpz_t vChallenge[1]);
zk_bool zk_Prover_free();

/* Constants with sizes of argument arrays for ZK-protocol functions. */
#define zk_argSize_vAux_gi 1
#define zk_argSize_vChallenge 1
#define zk_argSize_vCommitment 27
#define zk_argSize_vPublicCommitment_x 27
#define zk_argSize_vResponse 42
#define zk_argSize_vSecret_w 42

/* Following functions have to be implemented by user. */
/* For more details see also ZKCompiler::Random::irange(). */
extern void zk_Random_irange(mpz_t, const mpz_t, const mpz_t);
/* For more details see also ZKCompiler::handle_error(). */
extern void zk_handle_error(zk_pcchar, zk_pcchar, zk_int, zk_pcchar /*__FILE__*/, zk_int /*__LINE__*/);

#endif
/* end c-header-code of program "prover" */
