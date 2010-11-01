#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_COPYABLE_VARIABLE_CCR_HPP
#define CM_COPYABLE_VARIABLE_CCR_HPP

#include <cassert>
#include "ccr/impl/VariableCCR.hpp"
#include "exec/impl/CopyableVariableInstance.hpp"

namespace CodeManagement
{

    template<typename TSourceType>
    class CopyableVariableCCR : public VariableCCR<TSourceType>
    {
    public:
        typedef TSourceType Source_t;
        typedef VariableCCR<Source_t> Base_t;
        typedef SourceInstance<Source_t> SourceInstance_t;
        typedef ConstSourceInstance<Source_t> ConstSourceInstance_t;
        typedef AVariableCCR::variableId_t variableId_t;
        typedef CopyableVariableCCR This_t;
        typedef CopyableVariableInstance<Source_t> Instance_t;
        typedef ConstructorCallCCR<Source_t> ConstructorCallCCR_t;
        typedef DestructorCallCCR<Source_t> DestructorCallCCR_t;
        typedef CopyConstructorCallCCR<Source_t> CopyConstructorCallCCR_t;
        typedef CopyAssignmentCallCCR<Source_t> CopyAssignmentCallCCR_t;

    public:
        CopyableVariableCCR(variableId_t id, const DebugInfo& rDebugInfo) :
            Base_t(id, rDebugInfo)
        {
        }
        CopyableVariableCCR(variableId_t id, const DebugInfo& rDebugInfo, const ConstSourceInstance_t& rInitConstant) :
            Base_t(id, rDebugInfo, rInitConstant)
        {
        }
        virtual ~CopyableVariableCCR()
        {
        }

    private:
        CopyableVariableCCR(const This_t& rToCopy) : Base_t()
        {
            assert(false);
        }
        This_t& operator=(const This_t& rRHS)
        {
            assert(false);
            return *this;
        }

    public:
        virtual AVariableInstance* createNewInstance() const
        {
            if (this->_pConstInitSrcInst != NULL)
                return new Instance_t(this->getDebugInfo(), *this->_pConstInitSrcInst);
            return new Instance_t(this->getDebugInfo());
        }
        virtual AConstructorCallCCR* createNewConstructorCallCCR(const DebugInfo& rDebugInfo) const
        {
            return new ConstructorCallCCR_t(rDebugInfo);
        }
        virtual ACopyConstructorCallCCR* createNewCopyConstructorCallCCR(const DebugInfo& rDebugInfo,
            const ASourceInstanceCaster* pToCopySrcInstCaster) const
        {
            return new CopyConstructorCallCCR_t(rDebugInfo, pToCopySrcInstCaster);
        }
        virtual ACopyAssignmentCallCCR* createNewCopyAssignmentCallCCR(const DebugInfo& rDebugInfo,
            const ASourceInstanceCaster* pRHSSrcInstCaster) const
        {
            return new CopyAssignmentCallCCR_t(rDebugInfo, pRHSSrcInstCaster);
        }
    };

}

#endif

#endif
