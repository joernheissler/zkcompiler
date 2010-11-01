#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_PROGRAM_CCR_TO_C_CODE_COMPILER_HPP
#define ZK_PROGRAM_CCR_TO_C_CODE_COMPILER_HPP

#include <map>
#include <string>
#include "ACCRtoCodeCompiler.hpp"
#include "CodeManagement/ccr/AVariableCCR.hpp"
#include "CodeManagement/ccr/impl/ProgramCCR.hpp"

namespace CodeManagement
{
    class ScopeBlockCCR;
}

namespace ZKCompiler
{
    class ProgramCCRtoCCodeCompiler : public ACCRtoCodeCompiler
    {
    public:
        typedef std::map<std::string, std::string> IdentifiersMap;
        typedef IdentifiersMap::iterator IdentsMapIter;
        typedef IdentifiersMap::const_iterator IdentsMapConstIter;

    protected:
        typedef std::map<std::string, size_t> ArgsSizeMap_t;
        typedef ArgsSizeMap_t::iterator ArgsSizeMapIter_t;
        typedef ArgsSizeMap_t::const_iterator ArgsSizeMapConstIter_t;
        typedef std::map<std::string, const CodeManagement::AInstructionCallCCR*> InstructionCallCCRs_t;
        typedef InstructionCallCCRs_t::iterator InstrCallCCRsIter_t;
        typedef InstructionCallCCRs_t::const_iterator InstrCallCCRsConstIter_t;
        typedef std::map<CodeManagement::AVariableCCR::variableId_t, std::string> VarIdents_t;
        typedef VarIdents_t::iterator VarIdentsIter_t;
        typedef VarIdents_t::const_iterator VarIdentsConstIter_t;

    public:
        ProgramCCRtoCCodeCompiler();
        virtual ~ProgramCCRtoCCodeCompiler();

    public:
        void compile(const CodeManagement::ProgramCCR& rProgram, CodeManagement::AStream* pSourceStream, CodeManagement::AStream* pHeaderStream, const char* pIncludeHeader);

    protected:
        virtual void visit(const CodeManagement::CommentCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::ProgramCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::AProcedureCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::AFunctionCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::AOperatorCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::AConstructorCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::ADestructorCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::ACopyConstructorCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::ACopyAssignmentCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);
        virtual void visit(const CodeManagement::IfBranchCallCCR& rCCR, CodeManagement::ACCRVisitorArgs* pArgs = NULL);

    protected:
        CodeManagement::AStream& outHeader();
        CodeManagement::AStream& indentLineOutHeader();
        std::string mapVarIdent(const CodeManagement::AVariableCCR& rVar, bool global = false);
        std::string mapVarIdent(const CodeManagement::AVariableCCR* pVar);
        bool handleSubProgramArguments(const CodeManagement::ProgramCCR::Variables_t& rArguments, bool output);
        bool handleOwnScopeVars(const CodeManagement::ScopeBlockCCR& rCCR, bool global = false);

    protected:
        static void initCCRIdentifiersMap();
        static std::string mapCCRIdent(const std::string& rIdent);
        static bool getVariableAsArray(const CodeManagement::AVariableCCR& rVariable, std::string* pIdentifier, size_t* pIndex);

    protected:
        CodeManagement::AStream* _pHeaderStream;
        CodeManagement::AStream* _pSourceStream;
        VarIdents_t _varIdentsMap;
        ArgsSizeMap_t _argsSizeMap;
        InstructionCallCCRs_t _instrsToImplement;

    protected:
        static IdentifiersMap _ccrIdentifiersMap;
        static bool _ccrIdentsMapInited;
    };

    inline CodeManagement::AStream& ProgramCCRtoCCodeCompiler::outHeader()
    {
        return out(_pHeaderStream);
    }

    inline CodeManagement::AStream& ProgramCCRtoCCodeCompiler::indentLineOutHeader()
    {
        return indentLineOut(_pHeaderStream);
    }
}

#endif

#endif
