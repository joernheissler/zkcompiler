#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_VARIABLE_CCR_HPP
#define CM_VARIABLE_CCR_HPP

#include <cassert>
#include "ccr/AVariableCCR.hpp"
#include "ccr/impl/ConstructorCallCCR.hpp"
#include "ccr/impl/CopyConstructorCallCCR.hpp"
#include "ccr/impl/CopyAssignmentCallCCR.hpp"
#include "ccr/impl/DestructorCallCCR.hpp"
#include "exec/impl/ConstSourceInstance.hpp"
#include "exec/impl/VariableInstance.hpp"
#include "misc/debug/impl/Exception.hpp"

namespace CodeManagement
{

    template<typename TSourceType>
    class VariableCCR : public AVariableCCR
    {
    public:
        typedef TSourceType Source_t;
        typedef AVariableCCR Base_t;
        typedef ConstSourceInstance<Source_t> ConstSourceInstance_t;
        typedef Base_t::variableId_t variableId_t;
        typedef VariableCCR This_t;
        typedef VariableInstance<Source_t> Instance_t;
        typedef ConstructorCallCCR<Source_t> ConstructorCallCCR_t;
        typedef DestructorCallCCR<Source_t> DestructorCallCCR_t;

    public:
        VariableCCR(variableId_t id, const DebugInfo& rDebugInfo) :
            Base_t(id, rDebugInfo), _pConstInitSrcInst(NULL)
        {
        }
        VariableCCR(variableId_t id, const DebugInfo& rDebugInfo, const ConstSourceInstance_t& rInitConstant) :
            Base_t(id, rDebugInfo), _pConstInitSrcInst(new ConstSourceInstance_t(rInitConstant))
        {
        }
        virtual ~VariableCCR()
        {
            if (_pConstInitSrcInst != NULL)
                delete _pConstInitSrcInst;
        }

    private:
        VariableCCR(const This_t& rToCopy) : AVariableCCR()
        {
            assert(false);
        }
        This_t& operator=(const This_t& rRHS)
        {
            assert(false);
            return *this;
        }

    public:
        virtual const char* getTypeIdentifier() const
        {
            return spec_getTypeIdentifier();
        }
        virtual const void* getInitConstant() const
        {
            return _pConstInitSrcInst != NULL ? &_pConstInitSrcInst->get() : NULL;
        }
        virtual AVariableInstance* createNewInstance() const
        {
            if (_pConstInitSrcInst != NULL)
                return new Instance_t(getDebugInfo(), *_pConstInitSrcInst);
            return new Instance_t(getDebugInfo());
        }
        virtual AConstructorCallCCR* createNewConstructorCallCCR(const DebugInfo& rDebugInfo) const
        {
            return new ConstructorCallCCR_t(rDebugInfo);
        }
        virtual ADestructorCallCCR* createNewDestructorCallCCR(const DebugInfo& rDebugInfo) const
        {
            return new DestructorCallCCR_t(rDebugInfo);
        }
        virtual ACopyConstructorCallCCR* createNewCopyConstructorCallCCR(const DebugInfo& rDebugInfo,
            const ASourceInstanceCaster* /*pToCopySrcInstCaster*/) const
        {
            // forbid call by name
            throw CM_CREATE_EXCEPTION("Illegal operation of a non-copyable variable! [" + rDebugInfo.toString() + "]");
        }
        virtual ACopyAssignmentCallCCR* createNewCopyAssignmentCallCCR(const DebugInfo& rDebugInfo,
            const ASourceInstanceCaster* /*pRHSSrcInstCaster*/) const
        {
            // forbid assignment
            throw CM_CREATE_EXCEPTION("Illegal operation of a non-copyable variable! [" + rDebugInfo.toString() + "]");
        }

    protected:
        const ConstSourceInstance_t* const _pConstInitSrcInst;

    public:
        static const char* spec_getTypeIdentifier();
    };

}

#endif

#endif
