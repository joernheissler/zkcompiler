#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_ZK_FILE_TO_PROGRAM_CCR_COMPILER_HPP
#define ZK_ZK_FILE_TO_PROGRAM_CCR_COMPILER_HPP

#include "AZKProtocol.hpp"
#include "CodeManagement/core/impl/CodeCollector.hpp"
#include "CodeManagement/misc/stream/impl/StringStream.hpp"
#include "parser/parser.hpp"

namespace ZKCompiler
{

    class ZKFileToProgramCCRCompiler : public AZKProtocol
    {
    public:
        ZKFileToProgramCCRCompiler(const char* pZKFileName, const char* pIdentSigma, bool interactive = true);
        ZKFileToProgramCCRCompiler(const AZKProtocol& rToCopy);
        virtual ~ZKFileToProgramCCRCompiler();

    public:
        void compileProver(CodeManagement::CodeCollector& rCC);
        void compileVerifier(CodeManagement::CodeCollector& rCC);

    protected:
        virtual void proverInit(CodeManagement::CodeCollector& rCC, Parser*& rpParser, Sigma*& rpSigma);
        virtual void proverP1(CodeManagement::CodeCollector& rCC, Sigma& rSigma);
        virtual void proverP2(CodeManagement::CodeCollector& rCC, Sigma& rSigma);
        virtual void proverFree(CodeManagement::CodeCollector& rCC, Parser& rParser, Sigma& rSigma);
        virtual void verifierInit(CodeManagement::CodeCollector& rCC, Parser*& rpParser, Sigma*& rpSigma);
        virtual void verifierC(CodeManagement::CodeCollector& rCC, Sigma& rSigma);
        virtual void verifierV(CodeManagement::CodeCollector& rCC, Sigma& rSigma);
        virtual void verifierFree(CodeManagement::CodeCollector& rCC, Parser& rParser, Sigma& rSigma);

    protected:
        template<class TVariable>
        void addOutputVariables(CodeManagement::CodeCollector& rCC, const char* pIdent, TVariable vVars[], size_t size)
        {
            for (size_t i = 0; i < size; ++i)
            {
                CodeManagement::StringStream varIdent;
                varIdent << pIdent << "[" << (unsigned long)i << "]";
                rCC.addOutputVariable(vVars[i], varIdent.toString());
            }
        }
        template<class TVariable>
        void addInputVariables(CodeManagement::CodeCollector& rCC, const char* pIdent, TVariable vVars[], size_t size)
        {
            for (size_t i = 0; i < size; ++i)
            {
                CodeManagement::StringStream varIdent;
                varIdent << pIdent << "[" << (unsigned long)i << "]";
                rCC.addInputVariable(vVars[i], varIdent.toString());
            }
        }
    };

}

#endif

#endif
