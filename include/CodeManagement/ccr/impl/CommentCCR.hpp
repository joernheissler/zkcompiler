#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CMM_COMMENT_CCR_HPP
#define CMM_COMMENT_CCR_HPP

#include "ccr/AExecutableCCR.hpp"

namespace CodeManagement
{

    class ACCRVisitor;

    class CommentCCR : public AExecutableCCR
    {
    public:
        typedef AExecutableCCR Base_t;
        typedef VariablesTable<AVariableInstance> InstancesTable_t;

    public:
        CommentCCR(const std::string& rText, const DebugInfo& rDebugInfo);

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);

    public:
        const std::string& getText() const;

    private:
        std::string _text;
    };

}

#endif

#endif
