#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_VARIABLE_HPP
#define CM_A_VARIABLE_HPP

#include <memory>
#include "misc/debug/impl/DebugInfo.hpp"

#define CMD_CODE_DEFINITIONS_BLOCK \
    namespace CodeManagement\
    {\
        namespace U /* namespace with User's definitions */\
        {\
            namespace V { } /* namespace for user's Variable types */\
            namespace I { } /* namespace for user's Instruction types */\
            namespace O { } /* namespace for user's Operator types */\
            namespace R { } /* namespace for user's collected code Representative types */\
        }\
    }\
    /* make namespaces with user's definitions accessible for user */\
    namespace CMV { using namespace CodeManagement::U::V; }\
    namespace CMI { using namespace CodeManagement::U::I; }\
    namespace CMO { using namespace CodeManagement::U::O; }\
    namespace CMR { using namespace CodeManagement::U::R; }\
    /* begin user definitions */\
    namespace CodeManagement

#define CMD_CODE_DEFINITIONS_BLOCK_EX(projectNamespace) \
    namespace CodeManagement\
    {\
        namespace U /* namespace with User's definitions */\
        {\
            using namespace projectNamespace;\
            namespace V { } /* namespace for user's Variable types */\
            namespace I { } /* namespace for user's Instruction types */\
            namespace O { } /* namespace for user's Operator types */\
            namespace R { } /* namespace for user's collected code Representative types */\
        }\
    }\
    namespace projectNamespace\
    {\
        /* make namespaces with user's definitions accessible for user */\
        namespace CMV { using namespace CodeManagement::U::V; }\
        namespace CMI { using namespace CodeManagement::U::I; }\
        namespace CMO { using namespace CodeManagement::U::O; }\
        namespace CMR { using namespace CodeManagement::U::R; }\
    }\
    /* begin user definitions */\
    namespace CodeManagement

#define CMO_USING_OPERATORS using namespace CMO

#ifdef CM_ENABLE_CODE_COLLECTING
    #define CMV(variableDefinition) CMV::variableDefinition(CM_CREATE_DEBUG_INFO(#variableDefinition))
    #define CMV_CONSTRUCT(variable) variable(CM_CREATE_DEBUG_INFO(#variable))
    #define CMV_OUT(variable) ((variable).getSourceInstance(CM_CREATE_DEBUG_INFO("CMV_OUT(" #variable ")")))
    // TODO: rewrite to template function?
    #define CMV_NEW_ARRAY(variablePtr, variableType, size) \
        {   const size_t CM__size = (size);\
            variablePtr = std::allocator<CMV::variableType>().allocate(CM__size); /* allocate memory without call the constructors */\
            for(size_t CM__i = 0; CM__i < CM__size; ++CM__i)\
                new(&variablePtr[CM__i])CMV(variableType); /* call the constructor without allocating memory */\
        } (void)0
    // TODO: rewrite to template function?
    #define CMV_DELETE_ARRAY(variablePtr, variableType, size) \
        {   const size_t CM__size = (size);\
            for(size_t CM__i = 0; CM__i < CM__size; ++CM__i)\
                std::allocator<CMV::variableType>().destroy(&variablePtr[CM__i]); /* call the destructor without deallocating memory */\
            std::allocator<CMV::variableType>().deallocate(variablePtr, CM__size); /* deallocate memory without call the destructors */\
        } (void)0
#else
    #define CMV(variableDefinition) variableDefinition
    #define CMV_CONSTRUCT(variable) variable()
    #define CMV_OUT(variable) (variable)
    // TODO: rewrite to template function?
    #define CMV_NEW_ARRAY(variablePtr, variableType, size) { variablePtr = new CMV::variableType[(size)]; } (void)0
    // TODO: rewrite to template function?
    #define CMV_DELETE_ARRAY(variablePtr, variableType, size)  { delete[] variablePtr; } (void)0
#endif

namespace CodeManagement
{

    class AVariableInstance;
    class AVariableCCR;

    class AVariable
    {
    public:
        typedef long unsigned int variableId_t;

    protected:
        AVariable(const DebugInfo& rDebugInfo);
        AVariable(const AVariable& rToCopy);

    public:
        virtual ~AVariable();

    private:
        AVariable& operator=(const AVariable&);

    public:
        variableId_t getVariableId() const;
        const DebugInfo& getDebugInfo() const;

    protected:
        bool wasCopied() const;
        void setDebugInfo(const DebugInfo& rDebugInfo);

    public:
        virtual const void* getInitConstant() const = 0;
        virtual AVariableCCR* createNewCCR() const = 0;

    private:
        static variableId_t generateNewId();

    private:
        mutable bool _wasCopied;
        const variableId_t _id;
        DebugInfo _debugInfo;

    private:
        static variableId_t _lastId;
    };

}

#endif

#endif
