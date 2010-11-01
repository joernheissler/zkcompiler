#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_CCR_VISITOR_HPP
#define CM_A_CCR_VISITOR_HPP

namespace CodeManagement
{

    class ACollectedCodeRepr;
    class AConstructorCallCCR;
    class ACopyAssignmentCallCCR;
    class ACopyConstructorCallCCR;
    class ADestructorCallCCR;
    class AExecutableCCR;
    class AFunctionCallCCR;
    class AInstructionCallCCR;
    class AVarSpecialCallCCR;
    class AOperatorCallCCR;
    class AProcedureCallCCR;
    class AVariableCCR;
    class CommentCCR;
    class IfBranchCallCCR;
    class ProgramCCR;
    class ScopeBlockCCR;

    class ACCRVisitorArgs
    {
    protected:
        ACCRVisitorArgs();
    };

    class ACCRVisitor
    {
    protected:
        ACCRVisitor();

    public:
        virtual ~ACCRVisitor();

    protected:
        virtual void visit(const ACollectedCodeRepr& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(ACollectedCodeRepr& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AVariableCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AVariableCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AExecutableCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AExecutableCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AVarSpecialCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AVarSpecialCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AInstructionCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AInstructionCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const IfBranchCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(IfBranchCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const CommentCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(CommentCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const ScopeBlockCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(ScopeBlockCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const ProgramCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(ProgramCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AProcedureCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AProcedureCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AFunctionCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AFunctionCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AOperatorCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AOperatorCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const AConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(AConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const ADestructorCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(ADestructorCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const ACopyConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(ACopyConstructorCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        virtual void visit(const ACopyAssignmentCallCCR& rCCR, ACCRVisitorArgs* pArgs);
        virtual void visit(ACopyAssignmentCallCCR& rCCR, ACCRVisitorArgs* pArgs);

        friend class ACollectedCodeRepr;
        friend class AConstructorCallCCR;
        friend class ACopyAssignmentCallCCR;
        friend class ACopyConstructorCallCCR;
        friend class ADestructorCallCCR;
        friend class AExecutableCCR;
        friend class AFunctionCallCCR;
        friend class AInstructionCallCCR;
        friend class AVarSpecialCallCCR;
        friend class AOperatorCallCCR;
        friend class AProcedureCallCCR;
        friend class AVariableCCR;
        friend class CommentCCR;
        friend class IfBranchCallCCR;
        friend class ProgramCCR;
        friend class ScopeBlockCCR;
    };

}

#endif

#endif
