#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_A_ZK_PROTOCOL_HPP
#define ZK_A_ZK_PROTOCOL_HPP

#include <string>
#include <vector>

namespace ZKCompiler
{

    class AZKProtocol
    {
    public:
        typedef std::vector<std::string> Identifiers_t;
        typedef Identifiers_t::iterator IdentsIter_t;
        typedef Identifiers_t::const_iterator IdentsConstIter_t;

    protected:
        AZKProtocol(const char* pZKFileName, const char* pIdentSigma, bool interactive);
        AZKProtocol(const AZKProtocol& rToCopy);

    public:
        virtual ~AZKProtocol();

    public:
        void copyParameters(const AZKProtocol& rToApply);
        void setZKFileName(const char* pFileName);
        const char* getZKFileName() const;
        void setSigma(const char* pIdent);
        const char* getSigma() const;
        const Identifiers_t& getSecretVars() const;
        Identifiers_t& getSecretVars();
        const Identifiers_t& getPublicCommitmentVars() const;
        Identifiers_t& getPublicCommitmentVars();
        const Identifiers_t& getAuxVars() const;
        Identifiers_t& getAuxVars();
        void setInteractive(bool interactive);
        bool isInteractive() const;

    private:
        std::string _zkFileName;
        std::string _identSigma;
        Identifiers_t _identsVarsSecret;
        Identifiers_t _identsVarsPublicCommitment;
        Identifiers_t _identsVarsAux;
        bool _interactive;
    };

}

#endif

#endif
