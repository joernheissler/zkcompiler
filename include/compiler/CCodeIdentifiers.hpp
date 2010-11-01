#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_C_CODE_IDENTIFIERS_HPP
#define ZK_C_CODE_IDENTIFIERS_HPP

namespace ZKCompiler
{

    class CCodeIdentifiers
    {
    public:
        static const char* _funcHandleError;

        static const char* _typeInt;
        static const char* _typeUInt;
        static const char* _typeLong;
        static const char* _typeULong;
        static const char* _typePCChar;
        static const char* _typeBool;
        static const char* _typeRelation;

        static const char* _constPrefixArgSize;

        static const char* _proverInit;
        static const char* _proverP1;
        static const char* _proverP2;
        static const char* _proverFree;

        static const char* _verifierInit;
        static const char* _verifierC;
        static const char* _verifierV;
        static const char* _verifierFree;

        static const char* _argCommitment;
        static const char* _argChallenge;
        static const char* _argResponse;
        static const char* _argVerification;

        static const char* _argPrefixSecret;
        static const char* _argPrefixPublicCommitment;
        static const char* _argPrefixAux;
    };

}

#endif

#endif
