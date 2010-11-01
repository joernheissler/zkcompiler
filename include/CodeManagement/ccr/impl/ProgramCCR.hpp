#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_PROGRAM_CCR_HPP
#define CM_PROGRAM_CCR_HPP

#include <vector>
#include "ccr/impl/ScopeBlockCCR.hpp"

namespace CodeManagement
{

    class ACCRVisitor;
    class AVariableCCR;

    class ProgramCCR : public ScopeBlockCCR
    {
    public:
        typedef ScopeBlockCCR Base_t;
        typedef std::map<std::string, AVariableInstance*> InstancesMap_t;
        typedef InstancesMap_t::iterator InstsMapIter_t;
        typedef InstancesMap_t::const_iterator InstsMapConstIter_t;

    public:
        ProgramCCR(const std::string& rIdentifier, const DebugInfo& rDebugInfo);
        virtual ~ProgramCCR();

    public:
        virtual void execute(InstancesTable_t& rInstancesTable, void* pRetSrcInstCopy = NULL) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);

    public:
        const std::string& getIdentifier() const;
        const Variables_t& getOutputVariables() const;
        Variables_t& getOutputVariables();
        const Variables_t& getInputVariables() const;
        Variables_t& getInputVariables();
        void call(InstancesTable_t& rInstancesTable, const Variables_t& rOutputVariables, const Variables_t& rInputVariables) const;
        void initInstances(InstancesTable_t& rInstancesTable, InstancesMap_t* pInstancesMap = NULL, bool constructNewInsts = true) const;
//        void freeInstances(InstancesTable_t& rInstancesTable, InstancesMap_t* pInstancesMap = NULL) const;
        void executeCall(InstancesTable_t& rInstancesTable) const;

    protected:
        static void initInstances(const Variables_t& rVariables, InstancesTable_t& rInstancesTable, InstancesMap_t* pInstancesMap, bool constructNewInsts);

    private:
        std::string _identifier;
    };

}

#endif

#endif
