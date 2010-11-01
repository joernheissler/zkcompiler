#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_VARIABLE_CCR_HPP
#define CM_A_VARIABLE_CCR_HPP

#include <list>
#include "ccr/ACollectedCodeRepr.hpp"
#include "misc/debug/impl/DebugInfo.hpp"

namespace CodeManagement
{
    class ACCRVisitor;
    class AConstructorCallCCR;
    class ACopyAssignmentCallCCR;
    class ACopyConstructorCallCCR;
    class ADestructorCallCCR;
    class AExecutableCCR;
    class AVariableInstance;
    class ScopeBlockCCR;
    class ASourceInstanceCaster;

    class AVariableCCR : public ACollectedCodeRepr
    {
    public:
        typedef ACollectedCodeRepr Base_t;
        typedef long unsigned int variableId_t;
        typedef std::list<AExecutableCCR*> ExecutableCallCCRs_t;
        typedef ExecutableCallCCRs_t::iterator ExecutableCallCCRsIter_t;
        typedef ExecutableCallCCRs_t::const_iterator ExecutableCallCCRsConstIter_t;

    protected:
        AVariableCCR(variableId_t id, const DebugInfo& rDebugInfo);

    public:
        virtual ~AVariableCCR();

    public:
        variableId_t getVariableId() const;
        void setVariableIdentifier(const std::string& rIdentifier);
        const std::string& getVariableIdentifier() const;
        std::string getDefaultVarIdent() const;
        bool isDefaultVarIdent() const;
        AConstructorCallCCR* getConstructorCRR();
        const AConstructorCallCCR* getConstructorCRR() const;
        ADestructorCallCCR* getDestructorCRR();
        const ADestructorCallCCR* getDestructorCRR() const;
        const ExecutableCallCCRs_t& getOutputExecutableCallCCRs() const;
        const ExecutableCallCCRs_t& getInputExecutableCallCCRs() const;
        bool expandScopeTillVisibleIn(ScopeBlockCCR& rScope);

    private:
        void setConstructorCRR(AConstructorCallCCR* pConstructor);  // Accessible from AConstructorCallCCR.
        void setDestructorCRR(ADestructorCallCCR* pDestructor); // Accessible from ADestructorCallCCR.
        template<class TStructorCallCCR> void setStructorCRR(TStructorCallCCR*& rpDst, TStructorCallCCR* pSrc);
        // Multiple references of variable dependent calls in variable CCRs are allowed!
        // It could happen when, the same variable is passed more then once as argument to an instruction...
        ExecutableCallCCRs_t& getOutputExecutableCallCCRs();  // Accessible from AExecutableCCR.
        // Multiple references of variable dependent calls in variable CCRs are allowed!
        // It could happen when, the same variable is passed more then once as argument to an instruction...
        ExecutableCallCCRs_t& getInputExecutableCallCCRs();  // Accessible from AExecutableCCR.

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool isBulk() const;
        virtual const void* getInitConstant() const = 0;
        virtual const char* getTypeIdentifier() const = 0;
        virtual AVariableInstance* createNewInstance() const = 0;
        virtual AConstructorCallCCR* createNewConstructorCallCCR(const DebugInfo& rDebugInfo) const = 0;
        virtual ADestructorCallCCR* createNewDestructorCallCCR(const DebugInfo& rDebugInfo) const = 0;
        virtual ACopyConstructorCallCCR* createNewCopyConstructorCallCCR(const DebugInfo& rDebugInfo,
            const ASourceInstanceCaster* pToCopySrcInstCaster) const = 0;
        virtual ACopyAssignmentCallCCR* createNewCopyAssignmentCallCCR(const DebugInfo& rDebugInfo,
            const ASourceInstanceCaster* pRHSSrcInstCaster) const = 0;

    private:
        const variableId_t _variableId;
        std::string _variableIdentifier;
        AConstructorCallCCR* _pConstructorCRR;
        ADestructorCallCCR* _pDestructorCRR;
        ExecutableCallCCRs_t _outputExecutableCallCCRs;
        ExecutableCallCCRs_t _inputExecutableCallCCRs;

        friend class ScopeBlockCCR;   // Needed for setting/expanding the scope...
        friend class AExecutableCCR;    // Needed for binding...
        friend class AConstructorCallCCR;   // Needed for binding...
        friend class ADestructorCallCCR;    // Needed for binding...

#ifndef CM_ENABLE_CODE_COLLECTING
    public:
        static const char* spec_getTypeIdentifier() { return ""; }
#endif
    };

}

#endif

#endif
