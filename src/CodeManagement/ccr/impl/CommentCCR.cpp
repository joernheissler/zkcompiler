#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/impl/CommentCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "misc/stream/impl/Logger.hpp"

using namespace CodeManagement;

CommentCCR::CommentCCR(const std::string& rText, const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _text(rText)
{
}

void CommentCCR::execute(InstancesTable_t& /*rInstancesTable*/, void* /*pRetSrcInstCopy*/) const
{
    Logger::log << getText() << "\n";
}

void CommentCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void CommentCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

const std::string& CommentCCR::getText() const
{
    return _text;
}

#endif
