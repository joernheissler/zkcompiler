#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_VARIABLE_INSTANCE_HPP
#define CM_A_VARIABLE_INSTANCE_HPP

#include "misc/debug/impl/DebugInfo.hpp"

namespace CodeManagement
{
    class ASourceInstanceCaster;

    class AVariableInstance
    {
    protected:
        AVariableInstance(const DebugInfo& rDebugInfo);

    public:
        virtual ~AVariableInstance();

    private:
        AVariableInstance(const AVariableInstance&);
        AVariableInstance& operator=(const AVariableInstance&);

    public:
        const DebugInfo& getDebugInfo() const;
        virtual bool isConstant() const = 0;
        virtual const void* getConstSourceInstance() const = 0;
        virtual void* getSourceInstance() = 0;
        virtual bool getSourceInstanceBool() const = 0;
        virtual void executeConstructor() = 0;
        virtual void executeDestructor() = 0;
        virtual void executeCopyConstructor(const void* pToCopy, const ASourceInstanceCaster* pSrcInstCaster) = 0;
        virtual void executeCopyAssignment(const void* pRHS, const ASourceInstanceCaster* pSrcInstCaster) = 0;

    private:
        DebugInfo _debugInfo;
    };

}

#endif

#endif
