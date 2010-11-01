#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/ACCRVisitor.hpp"

#include "ccr/AConstructorCallCCR.hpp"
#include "ccr/ACopyAssignmentCallCCR.hpp"
#include "ccr/ACopyConstructorCallCCR.hpp"
#include "ccr/ADestructorCallCCR.hpp"
#include "ccr/AProcedureCallCCR.hpp"
#include "ccr/AFunctionCallCCR.hpp"
#include "ccr/AOperatorCallCCR.hpp"
#include "ccr/impl/CommentCCR.hpp"
#include "ccr/impl/IfBranchCallCCR.hpp"
#include "ccr/impl/ProgramCCR.hpp"
#include "misc/debug/impl/Exception.hpp"

using namespace CodeManagement;

ACCRVisitorArgs::ACCRVisitorArgs()
{
}


ACCRVisitor::ACCRVisitor()
{
}

ACCRVisitor::~ACCRVisitor()
{
}

void ACCRVisitor::visit(const ACollectedCodeRepr& rCCR, ACCRVisitorArgs* /*pArgs*/)
{
    DebugInfo::setOutStreamShowFileNameAndLine(true);
    std::string msg = "Tried to call a not implemented method!";
    msg += " rCCR.getDebugInfo() = [" + rCCR.getDebugInfo().toString() + "]";
    throw CM_CREATE_EXCEPTION(msg);
}

void ACCRVisitor::visit(ACollectedCodeRepr& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const ACollectedCodeRepr&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AVariableCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AVariableCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AVariableCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AVariableCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const CommentCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const CommentCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(CommentCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const CommentCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const ScopeBlockCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const ScopeBlockCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(ScopeBlockCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const ScopeBlockCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const ProgramCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const ProgramCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(ProgramCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const ProgramCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AExecutableCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AExecutableCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AExecutableCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AExecutableCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AProcedureCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AProcedureCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AProcedureCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AProcedureCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AFunctionCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AFunctionCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AFunctionCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AFunctionCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AOperatorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AOperatorCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AOperatorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AOperatorCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AVarSpecialCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AVarSpecialCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AVarSpecialCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AVarSpecialCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AInstructionCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AInstructionCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AInstructionCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AInstructionCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const IfBranchCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const IfBranchCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(IfBranchCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const IfBranchCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const AConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const AConstructorCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(AConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const AConstructorCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const ADestructorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const ADestructorCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(ADestructorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const ADestructorCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const ACopyConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const ACopyConstructorCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(ACopyConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const ACopyConstructorCallCCR&>(rCCR), pArgs);
}

void ACCRVisitor::visit(const ACopyAssignmentCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(static_cast<const ACopyAssignmentCallCCR::Base_t&>(rCCR), pArgs);
}

void ACCRVisitor::visit(ACopyAssignmentCallCCR& rCCR, ACCRVisitorArgs* pArgs)
{
    visit(const_cast<const ACopyAssignmentCallCCR&>(rCCR), pArgs);
}

#endif
