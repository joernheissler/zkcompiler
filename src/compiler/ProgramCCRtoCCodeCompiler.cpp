#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "compiler/ProgramCCRtoCCodeCompiler.hpp"

#include <algorithm>
#include <map>
#include <cassert>
#include "bignum/bignum.hpp"
#include "element/element.hpp"
#include "util/errorhandling.hpp"
#include "CodeManagement/ccr/impl/CommentCCR.hpp"
#include "CodeManagement/ccr/impl/IfBranchCallCCR.hpp"
#include "CodeManagement/ccr/impl/ProgramCCR.hpp"
#include "CodeManagement/exec/AExplicitCSrcInstCaster.hpp"
#include "CodeManagement/misc/stream/impl/StringStream.hpp"
#include "compiler/CCodeIdentifiers.hpp"

using namespace ZKCompiler;
using namespace CodeManagement;

namespace
{
    // In dynamic-memory-mode the variables are NOT freed when error occur -- use only for debugging!
    const bool g_dynamicMemory = false;
}

ProgramCCRtoCCodeCompiler::IdentifiersMap ProgramCCRtoCCodeCompiler::_ccrIdentifiersMap;
bool ProgramCCRtoCCodeCompiler::_ccrIdentsMapInited = false;

ProgramCCRtoCCodeCompiler::ProgramCCRtoCCodeCompiler() : _pHeaderStream(NULL), _pSourceStream(NULL)
{
}

ProgramCCRtoCCodeCompiler::~ProgramCCRtoCCodeCompiler()
{
    assert(_pHeaderStream == NULL);
    assert(_pSourceStream == NULL);
}

void ProgramCCRtoCCodeCompiler::compile(const ProgramCCR& rProgram, AStream* pSourceStream, AStream* pHeaderStream, const char* pIncludeHeader)
{
    assert(pHeaderStream != NULL || pSourceStream != NULL);
    assert(_pHeaderStream == NULL);
    assert(_pSourceStream == NULL);
    assert(curLineIndentCount() == 0);
    assert(_argsSizeMap.empty());
    assert(_instrsToImplement.empty());
    assert(_varIdentsMap.empty());
    _pHeaderStream = pHeaderStream;
    _pSourceStream = pSourceStream;
    setCodeStream(_pSourceStream);

    if (isShowDebugInfo())
    {
        indentLineOut() << "/* begin c-source-code of program \"" << rProgram.getIdentifier() << "\" */" << endLine();
        indentLineOutHeader() << "/* begin c-header-code of program \"" << rProgram.getIdentifier() << "\" */" << endLine();
    }

    // Output head of the program.
    if (pIncludeHeader != NULL)
        indentLineOut() << "#include \"" << pIncludeHeader << "\"" << endLine(2);

    indentLineOutHeader() << "#ifndef ZK_" << rProgram.getIdentifier() << "_H" << endLine();
    indentLineOutHeader() << endLine();
    indentLineOutHeader() << "#include <gmp.h>" << endLine();
    indentLineOutHeader() << endLine();
    indentLineOutHeader() << "typedef int " << CCodeIdentifiers::_typeInt << ";" << endLine();
    indentLineOutHeader() << "typedef unsigned int " << CCodeIdentifiers::_typeUInt << ";" << endLine();
    indentLineOutHeader() << "typedef long " << CCodeIdentifiers::_typeLong << ";" << endLine();
    indentLineOutHeader() << "typedef unsigned long " << CCodeIdentifiers::_typeULong << ";" << endLine();
    indentLineOutHeader() << "typedef const char* " << CCodeIdentifiers::_typePCChar << ";" << endLine();
    indentLineOutHeader() << "typedef unsigned int " << CCodeIdentifiers::_typeBool << ";" << endLine();
    indentLineOutHeader() << "typedef unsigned int " << CCodeIdentifiers::_typeRelation << ";" << endLine();
    indentLineOutHeader() << endLine();
    indentLineOutHeader() << "#define zk_" << false <<  " 0" << endLine();
    indentLineOutHeader() << "#define zk_" << true << " 1" << endLine();
    indentLineOutHeader() << endLine();

    // Output body of the program.
    indentLineOutHeader() << "/* ZK-protocol functions. */" << endLine();
    if (handleOwnScopeVars(rProgram, true))
        indentLineOut() << endLine();

    for (const AExecutableCCR* pNext = rProgram.getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
    {
        pNext->accept(*this, NULL);
        indentLineOut() << endLine();
    }
    indentLineOutHeader() << endLine();

    if (!_argsSizeMap.empty())
    {   // Output size constants in header file.
        indentLineOutHeader() << "/* Constants with sizes of argument arrays for ZK-protocol functions. */" << endLine();
        for (ArgsSizeMapConstIter_t iter = _argsSizeMap.begin(); iter != _argsSizeMap.end(); ++iter)
        {
            assert(iter->second > 0);
            indentLineOutHeader() << "#define " << CCodeIdentifiers::_constPrefixArgSize << iter->first << " "
                << (unsigned long)iter->second << endLine();
        }
        indentLineOutHeader() << endLine();
    }

    if (!_instrsToImplement.empty())
    {   // Output instructions to implement in header file.
        indentLineOutHeader() << "/* Following functions have to be implemented by user. */" << endLine();
        for (InstrCallCCRsConstIter_t iter = _instrsToImplement.begin(); iter != _instrsToImplement.end(); ++iter)
        {
            assert(iter->second != NULL);
            const AInstructionCallCCR& rCCR = *iter->second;
            const AFunctionCallCCR* rCCRAsFunc = dynamic_cast<const AFunctionCallCCR*>(&rCCR);

            size_t outVarNum = rCCR.getOutputVariablesNumber();
            const size_t inVarNum = rCCR.getInputVariablesNumber();

            indentLineOutHeader() << "/* For more details see also ZKCompiler::" << rCCR.getInstructionIdentifier() << "(). */" << endLine();
            indentLineOutHeader() << "extern ";

            // Output return type.
            if (rCCRAsFunc != NULL && rCCRAsFunc->hasReturnVariable())
            {
                outHeader() << mapCCRIdent(rCCR.getOutputVariable(rCCRAsFunc->getReturnVariableIndex()).getTypeIdentifier()) << " ";
                --outVarNum;
            }
            else
            {
                assert(dynamic_cast<const AProcedureCallCCR*>(&rCCR) != NULL);
                outHeader() << "void ";
            }

            // Output instruction identifier.
            const size_t allVarNum = outVarNum + inVarNum;
            outHeader() << mapCCRIdent(rCCR.getInstructionIdentifier()) << "(";

            // Output output arguments.
            for (size_t i = 0; i < outVarNum; ++i)
            {
                std::string ident = mapCCRIdent(rCCR.getOutputVariable(i).getTypeIdentifier());
                outHeader() << ident;
                if (ident != "mpz_t")
                    // Give all output arguments as pointers except of mpz_t!
                    outHeader() << "*";
                if (i + 1 < allVarNum)
                    outHeader() << ", ";
            }

            // Output input arguments.
            for (size_t i = 0; i < inVarNum; ++i)
            {
                std::string ident = mapCCRIdent(rCCR.getInputVariable(i).getTypeIdentifier());
                // Give all input arguments as copy. Because mpz_t is an array, make it const!
                if (ident == "mpz_t")
                    outHeader() << "const ";
                outHeader() << ident;
                if (i + 1 < inVarNum)
                    outHeader() << ", ";
            }

            if (dynamic_cast<const CMR::handle_error*>(&rCCR) != NULL)
                // Add arguments for file name and line.
                outHeader() << ", " << CCodeIdentifiers::_typePCChar << " /*__FILE__*/, " << CCodeIdentifiers::_typeInt << " /*__LINE__*/);" << endLine();
            else
                outHeader() << ");" << endLine();
        }
        indentLineOutHeader() << endLine();
    }

    indentLineOutHeader() << "#endif" << endLine();

    if (isShowDebugInfo())
    {
        indentLineOut() << "/* end c-source-code of program \"" << rProgram.getIdentifier() << "\" */" << endLine();
        indentLineOutHeader() << "/* end c-header-code of program \"" << rProgram.getIdentifier() << "\" */" << endLine();
    }

    clearLineIndent();

    _varIdentsMap.clear();
    _instrsToImplement.clear();
    _argsSizeMap.clear();
    setCodeStream(NULL);
    _pHeaderStream = NULL;
    _pSourceStream = NULL;
}

void ProgramCCRtoCCodeCompiler::visit(const CommentCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    indentLineOut() << "/* ";
    const char* pText = rCCR.getText().c_str();
    for (size_t i = 0; pText[i] != '\0'; ++i)
    {
        if (pText[i] == '\n')
        {
            out() << endLine();
            indentLineOut() << (pText[i + 1] != '\0' ? " * " : "");
        }
        else
        {
            out() << pText[i];
        }
    }
    out() << " */" << endLine();
}

void ProgramCCRtoCCodeCompiler::visit(const ProgramCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    // Head.
    indentLineOut() << CCodeIdentifiers::_typeBool << " " << rCCR.getIdentifier() << "(";
    indentLineOutHeader() << CCodeIdentifiers::_typeBool << " " << rCCR.getIdentifier() << "(";

    bool arguments = false;
    if (!rCCR.getOutputVariables().empty())
        arguments = handleSubProgramArguments(rCCR.getOutputVariables(), true);

    if (!rCCR.getInputVariables().empty())
    {
        if (arguments)
        {
            out() << ", ";
            outHeader() << ", ";
        }
        arguments |= handleSubProgramArguments(rCCR.getInputVariables(), false);
    }

    out() << ")" << endLine();
    outHeader() << ");" << endLine();

    // Body.
    indentLineOut() << "{" << endLine();
    increaseLineIndent();

    if (handleOwnScopeVars(rCCR))
        indentLineOut() << endLine();

    for (const AExecutableCCR* pNext = rCCR.getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
        pNext->accept(*this, pArgs);

    indentLineOut() << endLine();
    indentLineOut() << "return zk_" << true << ";" << endLine();

    decreaseLineIndent();
    indentLineOut() << "}" << endLine();
}

void ProgramCCRtoCCodeCompiler::visit(const AProcedureCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    indentLineOut() << mapCCRIdent(rCCR.getInstructionIdentifier()) << "(";

    const size_t outVarNum = rCCR.getOutputVariablesNumber();
    const size_t inVarNum = rCCR.getInputVariablesNumber();
    const size_t allVarNum = outVarNum + inVarNum;

    for (size_t i = 0; i < outVarNum; ++i)
    {
        out() << mapVarIdent(rCCR.getOutputVariable(i));
        if (i + 1 < allVarNum)
            out() << ", ";
    }

    for (size_t i = 0; i < inVarNum; ++i)
    {
        out() << mapVarIdent(rCCR.getInputVariable(i));
        if (i + 1 < inVarNum)
            out() << ", ";
    }

    if (dynamic_cast<const CMR::handle_error*>(&rCCR) != NULL)
    {
        _instrsToImplement[rCCR.getInstructionIdentifier()] = &rCCR;   // Error handling has to be implemented by user...
        out() << ", __FILE__, __LINE__);" << endLine();
        indentLineOut() << "return zk_" << false << ";" << endLine();
    }
    else
    {
        out() << ");" << endLine();
        if (std::string(rCCR.getInstructionIdentifier()).find("::") != std::string::npos)
        {   // All static member functions of classes have to be implemented by user (for example member functions of Random)...
            if (_instrsToImplement.find(rCCR.getInstructionIdentifier()) == _instrsToImplement.end())
                _instrsToImplement[rCCR.getInstructionIdentifier()] = &rCCR;
        }
    }
}

void ProgramCCRtoCCodeCompiler::visit(const AFunctionCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    size_t outVarNum = rCCR.getOutputVariablesNumber();
    const size_t inVarNum = rCCR.getInputVariablesNumber();

    indentLineOut();

    if (rCCR.hasReturnVariable())
    {
        out() << mapVarIdent(rCCR.getOutputVariable(rCCR.getReturnVariableIndex())) << " = ";
        --outVarNum;
    }

    const size_t allVarNum = outVarNum + inVarNum;

    if (dynamic_cast<const AExplicitCSrcInstCaster*>(rCCR.getReturnSrcInstCaster()) != NULL)
        out() << "(" << mapCCRIdent(rCCR.getReturnSrcInstCaster()->getToTypeIdentifier()) << ")";
    out() << mapCCRIdent(rCCR.getInstructionIdentifier()) << "(";

    for (size_t i = 0; i < outVarNum; ++i)
    {
        out() << mapVarIdent(rCCR.getOutputVariable(i));
        if (i + 1 < allVarNum)
            out() << ", ";
    }

    for (size_t i = 0; i < inVarNum; ++i)
    {
        out() << mapVarIdent(rCCR.getInputVariable(i));
        if (i + 1 < inVarNum)
            out() << ", ";
    }

    out() << ");" << endLine();

    if (std::string(rCCR.getInstructionIdentifier()).find("::") != std::string::npos)
    {   // All static member functions of classes have to be implemented by user (for example member functions of Random)...
        if (rCCR.hasReturnVariable() || _instrsToImplement.find(rCCR.getInstructionIdentifier()) == _instrsToImplement.end())
            // We don't want to override function calls with used return values!
            // Else we can't get the type information of the return value.
            _instrsToImplement[rCCR.getInstructionIdentifier()] = &rCCR;
    }
}

void ProgramCCRtoCCodeCompiler::visit(const AOperatorCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    size_t outVarNum = rCCR.getOutputVariablesNumber();
    const size_t inVarNum = rCCR.getInputVariablesNumber();

    indentLineOut() << "";

    if (rCCR.hasReturnVariable())
    {
        out() << mapVarIdent(rCCR.getOutputVariable(rCCR.getReturnVariableIndex())) << " = ";
        --outVarNum;
    }

    assert(outVarNum + inVarNum == 1 || outVarNum + inVarNum == 2);

    if (dynamic_cast<const AExplicitCSrcInstCaster*>(rCCR.getReturnSrcInstCaster()) != NULL)
        out() << "(" << rCCR.getReturnSrcInstCaster()->getToTypeIdentifier() << ")";

    if (outVarNum == 0 && inVarNum == 1)
    {   // Unary.
        out() << rCCR.getOperatorIdentifier() << mapVarIdent(rCCR.getInputVariable(0));
    }
    else if (outVarNum == 0 && inVarNum == 2)
    {   // Binary.
        out() << mapVarIdent(rCCR.getInputVariable(0)) << " " << rCCR.getOperatorIdentifier() << " " << mapVarIdent(rCCR.getInputVariable(1));
    }
    else if (outVarNum == 1 && inVarNum == 1)
    {   // Binary.
        out() << mapVarIdent(rCCR.getOutputVariable(0)) << " " << rCCR.getOperatorIdentifier() << " " << mapVarIdent(rCCR.getInputVariable(0));
    }
    else if (outVarNum == 1 && inVarNum == 0)
    {   // Increment/decrement.
        if (rCCR.getOperatorEnum() == o_prefixIncrement || rCCR.getOperatorEnum() == o_prefixDecrement)
            out() << rCCR.getOperatorIdentifier() << mapVarIdent(rCCR.getOutputVariable(0));
        else
        {
            assert(rCCR.getOperatorEnum() == o_suffixIncrement || rCCR.getOperatorEnum() == o_suffixDecrement);
            out() << mapVarIdent(rCCR.getOutputVariable(0)) << rCCR.getOperatorIdentifier();
        }
    }
    else
    {   // Unknown.
        ZK_HANDLE_ERROR("Unknown operator!");
    }

    out() << ";" << endLine();
}

void ProgramCCRtoCCodeCompiler::visit(const AConstructorCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    const AVariableCCR& rThisVar = rCCR.getThisVariable();

    if (g_dynamicMemory)
    {
        indentLineOut() << mapVarIdent(&rThisVar) << " = (" << rThisVar.getTypeIdentifier()
            << "*)malloc(sizeof(" << rThisVar.getTypeIdentifier() << "));" << endLine();
    }
    if (rThisVar.getInitConstant() != NULL)
    {
        if (dynamic_cast<const CMR::zk_bool_t*>(&rThisVar) != NULL)
            indentLineOut() << mapVarIdent(rThisVar) << " = zk_" << *(zk_bool_t*)rThisVar.getInitConstant();
        else if (dynamic_cast<const CMR::zk_int_t*>(&rThisVar) != NULL)
            indentLineOut() << mapVarIdent(rThisVar) << " = " << *(zk_int_t*)rThisVar.getInitConstant();
        else if (dynamic_cast<const CMR::zk_uint_t*>(&rThisVar) != NULL)
            indentLineOut() << mapVarIdent(rThisVar) << " = " << *(zk_uint_t*)rThisVar.getInitConstant();
        else if (dynamic_cast<const CMR::zk_long_t*>(&rThisVar) != NULL)
            indentLineOut() << mapVarIdent(rThisVar) << " = " << *(zk_long_t*)rThisVar.getInitConstant() << "l";
        else if (dynamic_cast<const CMR::zk_ulong_t*>(&rThisVar) != NULL)
            indentLineOut() << mapVarIdent(rThisVar) << " = " << *(zk_ulong_t*)rThisVar.getInitConstant() << "ul";
        else if (dynamic_cast<const CMR::zk_pcchar_t*>(&rThisVar) != NULL)
            indentLineOut() << mapVarIdent(rThisVar) << " = " << "\"" << *(zk_pcchar_t*)rThisVar.getInitConstant() << "\"";
        else if (dynamic_cast<const CMR::bnz_t*>(&rThisVar) != NULL)
        {
            const int base = 10;
            indentLineOut() << mapCCRIdent(CMR::bnz_init_set_str::spec_getInstructionIdentifier()) << "("
                << mapVarIdent(rThisVar) << ", \"" << bnToStr(*(bnz_t*)rThisVar.getInitConstant(), base) << "\", " << base << ")";
        }
        else if (dynamic_cast<const CMR::Relation*>(&rThisVar) != NULL)
        {
            indentLineOut() << mapVarIdent(rThisVar) << " = ";
            switch (*(Relation*)rThisVar.getInitConstant())
            {
            case R_ID:
                out() << R_ID << "/*R_ID*/";
                break;
            case R_EQ:
                out() << R_EQ << "/*R_EQ*/";
                break;
            case R_UN:
                out() << R_UN << "/*R_UN*/";
                break;
            case R_NE:
                out() << R_NE << "/*R_NE*/";
                break;
            case R_LT:
                out() << R_LT << "/*R_LT*/";
                break;
            case R_LE:
                out() << R_LE << "/*R_LE*/";
                break;
            case R_GT:
                out() << R_GT << "/*R_GT*/";
                break;
            case R_GE:
                out() << R_GE << "/*R_GE*/";
                break;
            case R_LG:
                out() << R_LG << "/*R_LG*/";
                break;
            default:
                ZK_HANDLE_ERROR((std::string("Not implemented: output of a constant constructor! [") +
                    rThisVar.getDebugInfo().toString() + "]").c_str());
            };
        }
        else
            ZK_HANDLE_ERROR((std::string("Not implemented: output of a constant constructor! [") +
                rThisVar.getDebugInfo().toString() + "]").c_str());

        out() << ";" << endLine();
    }
}

void ProgramCCRtoCCodeCompiler::visit(const ADestructorCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    const AVariableCCR& rThisVar = rCCR.getThisVariable();

    if (g_dynamicMemory)
    {
        indentLineOut() << "free(" << mapVarIdent(&rThisVar) << ");" << endLine();
    }
    if (rThisVar.getInitConstant() != NULL)
    {
        if (dynamic_cast<const CMR::bnz_t*>(&rThisVar) != NULL)
        {
            indentLineOut() << mapCCRIdent(CMR::bnz_clear::spec_getInstructionIdentifier()) << "("
                << mapVarIdent(rThisVar) << ");" << endLine();
        }
        else if (dynamic_cast<const CMR::zk_bool_t*>(&rThisVar) != NULL ||
                dynamic_cast<const CMR::zk_int_t*>(&rThisVar) != NULL ||
                dynamic_cast<const CMR::zk_uint_t*>(&rThisVar) != NULL ||
                dynamic_cast<const CMR::zk_long_t*>(&rThisVar) != NULL ||
                dynamic_cast<const CMR::zk_ulong_t*>(&rThisVar) != NULL ||
                dynamic_cast<const CMR::zk_pcchar_t*>(&rThisVar) != NULL ||
                dynamic_cast<const CMR::Relation*>(&rThisVar) != NULL)
        {
            // Nothing to do... just check it here, so we don't forget it for new types!
        }
        else
            ZK_HANDLE_ERROR((std::string("Not implemented: output of a constant destructor! [") +
                rThisVar.getDebugInfo().toString() + "]").c_str());
    }
}

void ProgramCCRtoCCodeCompiler::visit(const ACopyConstructorCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    visit(static_cast<const AConstructorCallCCR&>(rCCR));

    const AVariableCCR& rThisVar = rCCR.getThisVariable();
    const AVariableCCR& rToCopyVar = rCCR.getToCopyVariable();

    indentLineOut() << mapVarIdent(rThisVar) << " = ";
    if (dynamic_cast<const CMR::zk_bool_t*>(&rThisVar) != NULL)
        // There is no boolean type in c! Therefore for avoiding signed/unsigned warnings we just cast...
        out() << "(" << CCodeIdentifiers::_typeBool << ")";
    if (dynamic_cast<const AExplicitCSrcInstCaster*>(rCCR.getToCopySrcInstCaster()) != NULL)
        out() << "(" << mapCCRIdent(rCCR.getToCopySrcInstCaster()->getToTypeIdentifier()) << ")";
    out() << mapVarIdent(rToCopyVar) << ";" << endLine();
}

void ProgramCCRtoCCodeCompiler::visit(const ACopyAssignmentCallCCR& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    const AVariableCCR& rThisVar = rCCR.getThisVariable();
    const AVariableCCR& rRHSVar = rCCR.getRHSVariable();

    indentLineOut() << mapVarIdent(rThisVar) << " = ";
    if (dynamic_cast<const CMR::zk_bool_t*>(&rThisVar) != NULL)
        // There is no boolean type in c! Therefore for avoiding signed/unsigned warnings we just cast...
        out() << "(" << CCodeIdentifiers::_typeBool << ")";
    if (dynamic_cast<const AExplicitCSrcInstCaster*>(rCCR.getRHSSrcInstCaster()) != NULL)
        out() << "(" << mapCCRIdent(rCCR.getRHSSrcInstCaster()->getToTypeIdentifier()) << ")";
    out() << mapVarIdent(rRHSVar) << ";" << endLine();
}

void ProgramCCRtoCCodeCompiler::visit(const IfBranchCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    if (isShowDebugInfo())
        indentLineOut() << "/* " << rCCR.getDebugInfo() << " */" << endLine();

    const AVariableCCR& rCondVar = rCCR.getConditionVariable();
    const ScopeBlockCCR& rPreBlock = rCCR.getPreConditionBlock();
    const ScopeBlockCCR& rPostBlock = rCCR.getPostConditionBlock();
    const ScopeBlockCCR& rTrueBlock = rCCR.getTrueBlock();
    const ScopeBlockCCR* pFalseBlock = rCCR.getFalseBlock();

    assert(rCondVar.getConstructorCRR() != NULL);
    const ADestructorCallCCR& rCondVarDestr = *rCondVar.getDestructorCRR();
    assert(rCondVar.getConstructorCRR() == rPreBlock.getLastCallCCR());
    assert(&rCondVarDestr == rPostBlock.getFirstCallCCR());

    // Begin the if-branch.
    indentLineOut() << "{" << endLine();
    increaseLineIndent();

    // Write variables declarations.
    bool varsDeclHead = false;
    varsDeclHead |= handleOwnScopeVars(rCCR);
    varsDeclHead |= handleOwnScopeVars(rPreBlock);
    varsDeclHead |= handleOwnScopeVars(rPostBlock);
    if (varsDeclHead)
        indentLineOut() << endLine();

    // Write the pre-condition-block.
    for (const AExecutableCCR* pNext = rPreBlock.getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
        pNext->accept(*this, pArgs);

    // Write the post-condition-block without the destructor of the condition variable.
    for (const AExecutableCCR* pNext = rCondVarDestr.getNextCCR(); pNext != NULL; pNext = pNext->getNextCCR())
        pNext->accept(*this, pArgs);

    // Write the condition and the true-block.
    indentLineOut() << "if (" << mapVarIdent(rCondVar) << ")" << endLine();
    indentLineOut() << "{" << endLine();
    increaseLineIndent();
    if (handleOwnScopeVars(rTrueBlock))
        indentLineOut() << endLine();
    for (const AExecutableCCR* pNext = rTrueBlock.getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
        pNext->accept(*this, pArgs);
    decreaseLineIndent();
    indentLineOut() << "}" << endLine();

    if (pFalseBlock != NULL)
    {   // Write the false-block.
        indentLineOut() << "else" << endLine();
        indentLineOut() << "{" << endLine();
        increaseLineIndent();
        if (handleOwnScopeVars(*pFalseBlock))
            indentLineOut() << endLine();
        for (const AExecutableCCR* pNext = pFalseBlock->getFirstCallCCR(); pNext != NULL; pNext = pNext->getNextCCR())
            pNext->accept(*this, pArgs);
        decreaseLineIndent();
        indentLineOut() << "}" << endLine();
    }

    // Write the destructor of the condition variable.
    rCondVarDestr.accept(*this, pArgs);

    // End the if-branch.
    decreaseLineIndent();
    indentLineOut() << "}" << endLine();
}

std::string ProgramCCRtoCCodeCompiler::mapVarIdent(const AVariableCCR& rVar, bool global)
{

    if (_varIdentsMap.find(rVar.getVariableId()) == _varIdentsMap.end())
    {
        if (!rVar.isDefaultVarIdent())
            _varIdentsMap[rVar.getVariableId()] = rVar.getVariableIdentifier();
        else
        {
            StringStream ident;
            ident << (global ? "g_" : "");

            if (dynamic_cast<const CMR::zk_bool_t*>(&rVar) != NULL)
                ident << "b";
            else if (dynamic_cast<const CMR::zk_int_t*>(&rVar) != NULL)
                ident << "i";
            else if (dynamic_cast<const CMR::zk_uint_t*>(&rVar) != NULL)
                ident << "ui";
            else if (dynamic_cast<const CMR::zk_long_t*>(&rVar) != NULL)
                ident << "l";
            else if (dynamic_cast<const CMR::zk_ulong_t*>(&rVar) != NULL)
                ident << "ul";
            else if (dynamic_cast<const CMR::zk_pcchar_t*>(&rVar) != NULL)
                ident << "pcc";
            else if (dynamic_cast<const CMR::bnz_t*>(&rVar) != NULL)
                ident << "mpz";
            else if (dynamic_cast<const CMR::Relation*>(&rVar) != NULL)
                ident << "rel";
            else
                ZK_HANDLE_ERROR((std::string("Not implemented: output of a type prefix! [") +
                    rVar.getDebugInfo().toString() + "]").c_str());

            ident << "Var" << (unsigned long)(_varIdentsMap.size() + 1);
            _varIdentsMap[rVar.getVariableId()] = ident.toString();
        }
    }

    return std::string((g_dynamicMemory ? "*" : "")) + _varIdentsMap[rVar.getVariableId()];
}

std::string ProgramCCRtoCCodeCompiler::mapVarIdent(const AVariableCCR* pVar)
{
    assert(g_dynamicMemory);

    if (pVar == NULL)
        return "NULL";

    mapVarIdent(*pVar); // Just create new mapping, if not created yet...

    if (!pVar->isDefaultVarIdent())
        return std::string("&") + _varIdentsMap[pVar->getVariableId()];

    return _varIdentsMap[pVar->getVariableId()];
}

bool ProgramCCRtoCCodeCompiler::handleSubProgramArguments(const ProgramCCR::Variables_t& rArguments, bool output)
{
    typedef std::map<const std::string, std::string> TypeIdentsMap_t;
    ArgsSizeMap_t varIdents;
    TypeIdentsMap_t typeIdents;

    // Prepare identifiers and their size.
    for (ProgramCCR::VariablesConstIter_t iter = rArguments.begin(); iter != rArguments.end(); ++iter)
    {
        assert(*iter != NULL);
        const AVariableCCR& rVar = **iter;
        std::string identifier;
        size_t index;

        // TODO: integrity checks...

        if (getVariableAsArray(rVar, &identifier, &index))
            varIdents[identifier] = std::max(varIdents[identifier], index + 1);
        else
        {
            if (output)
                ZK_HANDLE_ERROR("All output arguments of programs have to be arrays!");
            identifier = rVar.getVariableIdentifier();
            varIdents[identifier] = 0;
        }

        typeIdents[identifier] = rVar.getTypeIdentifier();
    }

    // Output arguments.
    for (ArgsSizeMapConstIter_t iter = varIdents.begin(); iter != varIdents.end();)
    {
        const std::string& rVarIdent = iter->first;
        size_t size = iter->second;

        if (!output && (size > 0 || mapCCRIdent(typeIdents[rVarIdent]) == "mpz_t"))
        {   // const modifier for input arrays or input mpz_t variables.
            out() << "const ";
            outHeader() << "const ";
        }

        out() << mapCCRIdent(typeIdents[rVarIdent]) << " " << rVarIdent;
        outHeader() << mapCCRIdent(typeIdents[rVarIdent]) << " " << rVarIdent;
        if (size > 0)
        {
            _argsSizeMap[rVarIdent] = size; // For constants in header file...
            out() << "[" << (unsigned long)size << "]";
            outHeader() << "[" << (unsigned long)size << "]";
        }

        if (++iter == varIdents.end())
            break;

        out() << ", ";
        outHeader() << ", ";
    }

    return !varIdents.empty();
}

bool ProgramCCRtoCCodeCompiler::handleOwnScopeVars(const ScopeBlockCCR& rCCR, bool global)
{
    std::vector<const AVariableCCR*> vars;
    vars.reserve(rCCR.getOwnVarsNumber());
    rCCR.getOwnVariables(vars);

    for (std::vector<const AVariableCCR*>::iterator iter = vars.begin(); iter != vars.end(); ++iter)
    {
        assert(*iter != NULL);
        const AVariableCCR& rVar = **iter;

        if (!rCCR.isVarUsedAsOutOrInput(rVar))
        {
            if (isShowDebugInfo())
                indentLineOut() << "/* " << rVar.getDebugInfo() << " */" << endLine();
            indentLineOut() << (global ? "static " : "") <<
                mapCCRIdent(rVar.getTypeIdentifier()) << " " << mapVarIdent(rVar, global) << ";" << endLine();
        }
    }

    return !vars.empty();
}

void ProgramCCRtoCCodeCompiler::initCCRIdentifiersMap()
{
    assert(!_ccrIdentsMapInited);

    _ccrIdentifiersMap[CMR::zk_int_t::spec_getTypeIdentifier()] = CCodeIdentifiers::_typeInt;
    _ccrIdentifiersMap[CMR::zk_uint_t::spec_getTypeIdentifier()] = CCodeIdentifiers::_typeUInt;
    _ccrIdentifiersMap[CMR::zk_long_t::spec_getTypeIdentifier()] = CCodeIdentifiers::_typeLong;
    _ccrIdentifiersMap[CMR::zk_ulong_t::spec_getTypeIdentifier()] = CCodeIdentifiers::_typeULong;
    _ccrIdentifiersMap[CMR::zk_pcchar_t::spec_getTypeIdentifier()] = CCodeIdentifiers::_typePCChar;
    _ccrIdentifiersMap[CMR::zk_bool_t::spec_getTypeIdentifier()] = CCodeIdentifiers::_typeBool;
    _ccrIdentifiersMap[CMR::Relation::spec_getTypeIdentifier()] = CCodeIdentifiers::_typeRelation;

    _ccrIdentifiersMap["handle_error"] = CCodeIdentifiers::_funcHandleError;

    _ccrIdentsMapInited = true;
}

std::string ProgramCCRtoCCodeCompiler::mapCCRIdent(const std::string& rIdent)
{
    if (!_ccrIdentsMapInited)
        initCCRIdentifiersMap();

    // Search for predefined mapping.
    ProgramCCRtoCCodeCompiler::IdentsMapConstIter iter = _ccrIdentifiersMap.find(rIdent);
    if (iter != _ccrIdentifiersMap.end())
        return iter->second;

    // Map 'bnz_' to 'mpz_'.
    std::string mappedIdent;
    if (rIdent.length() > 4 &&
            rIdent[0] == 'b' && rIdent[1] == 'n' && rIdent[2] == 'z' && rIdent[3] == '_')
        return "mpz_" + rIdent.substr(4);

    // Map '<class>::<mamber>' to 'zk_<class>_<mamber>'
    size_t pos = rIdent.find("::");
    if (pos != std::string::npos)
    {
        assert(rIdent.find("::", pos + 2) == std::string::npos);
        return "zk_" + rIdent.substr(0, pos) + "_" + rIdent.substr(pos + 2);
    }

    // No mapping.
    return rIdent;
}

bool ProgramCCRtoCCodeCompiler::getVariableAsArray(const AVariableCCR& rVariable, std::string* pIdentifier, size_t* pIndex)
{
    // The identifiers of arguments can be in array format: varIdent[index].
    const std::string& rVarIdent = rVariable.getVariableIdentifier();
    const size_t length = rVarIdent.length();
    if (length < 4 || rVarIdent[length - 1] != ']')
        return false;

    size_t from;
    for (from = length - 3; rVarIdent[from] != '['; --from)
    {
        if (from == 0)
            ZK_HANDLE_ERROR(std::string("Wrong variable identifier format: " + rVarIdent).c_str());
    }
    assert(from > 1);
    assert(from + 2 < length);

    if (pIndex != NULL)
        *pIndex = ::atoi(rVarIdent.substr(from + 1, length - from - 2).c_str());

    if (pIdentifier != NULL)
        *pIdentifier = rVarIdent.substr(0, from);

    return true;
}

#endif
