#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_COPYABLE_VARIABLE_INSTANCE_HPP
#define CM_COPYABLE_VARIABLE_INSTANCE_HPP

#include <cassert>
#include <cstddef>
#include "exec/impl/VariableInstance.hpp"

namespace CodeManagement
{

    template<typename TSourceType>
    class CopyableVariableInstance : public VariableInstance<TSourceType>
    {
    public:
        typedef TSourceType Source_t;
        typedef VariableInstance<Source_t> Base_t;
        typedef ConstSourceInstance<Source_t> ConstSourceInstance_t;

    public:
        CopyableVariableInstance(const DebugInfo& rDebugInfo) :
            Base_t(rDebugInfo)
        {
        }
        CopyableVariableInstance(const DebugInfo& rDebugInfo, const ConstSourceInstance_t& rInitConstant) :
            Base_t(rDebugInfo, rInitConstant)
        {
        }
        virtual ~CopyableVariableInstance()
        {
        }

    private:
        CopyableVariableInstance(const CopyableVariableInstance& rToCopy) : Base_t()
        {
            throw CM_CREATE_EXCEPTION("Illegal call to copy-constructor!");
        }
        CopyableVariableInstance& operator=(const CopyableVariableInstance& rRHS)
        {
            throw CM_CREATE_EXCEPTION("Illegal call to copy-assignment!");
            return *this;
        }

    public:
        virtual void executeCopyConstructor(const void* pToCopy, const ASourceInstanceCaster* pSrcInstCaster)
        {
            assert(pToCopy != NULL);
            assert(!this->_sourceInstance.isConstructed());
            if (pSrcInstCaster != NULL)
                SourceInstance_executeCopyConstructor(this->_sourceInstance, pToCopy, *pSrcInstCaster);
            else
                SourceInstance_executeCopyConstructor(this->_sourceInstance, *(const Source_t*)pToCopy);
        }
        virtual void executeCopyAssignment(const void* pRHS, const ASourceInstanceCaster* pSrcInstCaster)
        {
            assert(pRHS != NULL);
            assert(this->_sourceInstance.isConstructed());
            if (pSrcInstCaster != NULL)
                SourceInstance_executeCopyAssignment(this->_sourceInstance, pRHS, *pSrcInstCaster);
            else
                SourceInstance_executeCopyAssignment(this->_sourceInstance, *(const Source_t*)pRHS);
        }
    };
}

#endif

#endif
