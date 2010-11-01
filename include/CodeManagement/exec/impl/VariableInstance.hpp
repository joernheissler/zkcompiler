#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_VARIABLE_INSTANCE_HPP
#define CM_VARIABLE_INSTANCE_HPP

#include <cassert>
#include <cstddef>
#include "exec/AVariableInstance.hpp"
#include "exec/impl/ConstSourceInstance.hpp"
#include "misc/debug/impl/Exception.hpp"

namespace CodeManagement
{

    template<typename TSourceType>
    class VariableInstance : public AVariableInstance
    {
    public:
        typedef TSourceType Source_t;
        typedef SourceInstance<Source_t> SourceInstance_t;
        typedef ConstSourceInstance<Source_t> ConstSourceInstance_t;

    public:
        explicit VariableInstance(const DebugInfo& rDebugInfo) :
            AVariableInstance(rDebugInfo), _pConstInitSrcInst(NULL)
        {
        }
        VariableInstance(const DebugInfo& rDebugInfo, const ConstSourceInstance_t& rInitConstant) :
            AVariableInstance(rDebugInfo), _pConstInitSrcInst(new ConstSourceInstance_t(rInitConstant))
        {
        }
        virtual ~VariableInstance()
        {
            // The manager should have been freed the source instance.
            // When this assert fails, it could be that the collected code has memory leaks!
            assert(!_sourceInstance.isConstructed());
            if (_pConstInitSrcInst != NULL)
                delete _pConstInitSrcInst;
        }

    private:
        VariableInstance(const VariableInstance& /*rToCopy*/)
        {
            throw CM_CREATE_EXCEPTION("Illegal call to copy-constructor!");
        }
        VariableInstance& operator=(const VariableInstance& /*rRHS*/)
        {
            throw CM_CREATE_EXCEPTION("Illegal call to copy-assignment!");
            return *this;
        }

    public:
        virtual bool isConstant() const
        {
            return _pConstInitSrcInst != NULL;
        }
        virtual const void* getConstSourceInstance() const
        {
            if (isConstant())
            {
                assert(!_sourceInstance.isConstructed());
                return &_pConstInitSrcInst->get();
            }
            return _sourceInstance.isConstructed() ? (Source_t*)&_sourceInstance.get() : NULL;
        }
        virtual void* getSourceInstance()
        {
            assert(!isConstant());
            return _sourceInstance.isConstructed() ? (Source_t*)&_sourceInstance.get() : NULL;
        }
        virtual bool getSourceInstanceBool() const
        {
            if (isConstant())
            {
                assert(!_sourceInstance.isConstructed());
                return _pConstInitSrcInst->getBool();
            }
            return _sourceInstance.getBool();
        }
        virtual void executeConstructor()
        {
            assert(!isConstant());
            _sourceInstance.executeConstructor();
        }
        virtual void executeDestructor()
        {
            assert(!isConstant());
            _sourceInstance.executeDestructor();
        }
        virtual void executeCopyConstructor(const void* /*pToCopy*/, const ASourceInstanceCaster* /*pSrcInstCaster*/)
        {
            // forbid call by name
            throw CM_CREATE_EXCEPTION("Illegal operation of a non-copyable instance!");
        }
        virtual void executeCopyAssignment(const void* /*pRHS*/, const ASourceInstanceCaster* /*pSrcInstCaster*/)
        {
            // forbid assignment
            throw CM_CREATE_EXCEPTION("Illegal operation of a non-copyable instance!");
        }

    protected:
        SourceInstance_t _sourceInstance;

    private:
        const ConstSourceInstance_t* const _pConstInitSrcInst;
    };

}

#endif

#endif
