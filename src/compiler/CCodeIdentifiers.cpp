#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "compiler/CCodeIdentifiers.hpp"

using namespace ZKCompiler;

const char* CCodeIdentifiers::_funcHandleError = "zk_handle_error";

const char* CCodeIdentifiers::_typeInt      = "zk_int";
const char* CCodeIdentifiers::_typeUInt     = "zk_uint";
const char* CCodeIdentifiers::_typeLong     = "zk_long";
const char* CCodeIdentifiers::_typeULong    = "zk_ulong";
const char* CCodeIdentifiers::_typePCChar   = "zk_pcchar";
const char* CCodeIdentifiers::_typeBool     = "zk_bool";
const char* CCodeIdentifiers::_typeRelation = "zk_relation";

const char* CCodeIdentifiers::_constPrefixArgSize = "zk_argSize_";

const char* CCodeIdentifiers::_proverInit =     "zk_Prover_init";
const char* CCodeIdentifiers::_proverP1 =       "zk_Prover_p1";
const char* CCodeIdentifiers::_proverP2 =       "zk_Prover_p2";
const char* CCodeIdentifiers::_proverFree =     "zk_Prover_free";

const char* CCodeIdentifiers::_verifierInit =   "zk_Verifier_init";
const char* CCodeIdentifiers::_verifierC =      "zk_Verifier_c";
const char* CCodeIdentifiers::_verifierV =      "zk_Verifier_v";
const char* CCodeIdentifiers::_verifierFree =   "zk_Verifier_free";

const char* CCodeIdentifiers::_argCommitment =      "vCommitment";
const char* CCodeIdentifiers::_argChallenge =       "vChallenge";
const char* CCodeIdentifiers::_argResponse =        "vResponse";
const char* CCodeIdentifiers::_argVerification =    "vVerification";

const char* CCodeIdentifiers::_argPrefixSecret =            "vSecret_";
const char* CCodeIdentifiers::_argPrefixPublicCommitment =  "vPublicCommitment_";
const char* CCodeIdentifiers::_argPrefixAux =               "vAux_";

#endif
