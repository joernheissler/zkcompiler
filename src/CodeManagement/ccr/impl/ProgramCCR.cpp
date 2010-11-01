#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "ccr/impl/ProgramCCR.hpp"

#include "ccr/ACCRVisitor.hpp"
#include "exec/AVariableInstance.hpp"
#include "misc/debug/impl/Exception.hpp"

using namespace CodeManagement;

ProgramCCR::ProgramCCR(const std::string& rIdentifier, const DebugInfo& rDebugInfo) :
    Base_t(rDebugInfo), _identifier(rIdentifier)
{
    assert(_pOutputVariables == NULL);
    _pOutputVariables = new Variables_t();
    assert(_pInputVariables == NULL);
    _pInputVariables = new Variables_t();
}

ProgramCCR::~ProgramCCR()
{
    assert(_pOutputVariables != NULL);
    delete _pOutputVariables;
    _pOutputVariables = NULL;
    assert(_pInputVariables != NULL);
    delete _pInputVariables;
    _pInputVariables = NULL;
}

void ProgramCCR::execute(InstancesTable_t& /*rInstancesTable*/, void* /*pRetSrcInstCopy*/) const
{
    // This is just the implementation of a program, but not a call of the program! So we have nothing to execute here.
}

void ProgramCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const
{
    rVisitor.visit(*this, pArgs);
}

void ProgramCCR::accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs)
{
    rVisitor.visit(*this, pArgs);
}

const std::string& ProgramCCR::getIdentifier() const
{
    return _identifier;
}

const AExecutableCCR::Variables_t& ProgramCCR::getOutputVariables() const
{
    return const_cast<ProgramCCR*>(this)->getOutputVariables();
}

AExecutableCCR::Variables_t& ProgramCCR::getOutputVariables()
{
    assert(_pOutputVariables != NULL);
    return *_pOutputVariables;
}

const AExecutableCCR::Variables_t& ProgramCCR::getInputVariables() const
{
    return const_cast<ProgramCCR*>(this)->getInputVariables();
}

AExecutableCCR::Variables_t& ProgramCCR::getInputVariables()
{
    assert(_pInputVariables != NULL);
    return *_pInputVariables;
}

void ProgramCCR::call(InstancesTable_t& rInstancesTable, const Variables_t& rOutputVariables, const Variables_t& rInputVariables) const
{
    // TODO: implement
    assert(false);
    (void)rInstancesTable;
    (void)rOutputVariables;
    (void)rInputVariables;
}

void ProgramCCR::initInstances(InstancesTable_t& rInstancesTable, InstancesMap_t* pInstancesMap, bool constructNewInsts) const
{
    initInstances(getOutputVariables(), rInstancesTable, pInstancesMap, constructNewInsts);
    initInstances(getInputVariables(), rInstancesTable, pInstancesMap, constructNewInsts);
}

//void ProgramCCR::freeInstances(InstancesTable_t& rInstancesTable, InstancesMap_t* pInstancesMap) const
//{
//
//}

void ProgramCCR::executeCall(InstancesTable_t& rInstancesTable) const
{
    Base_t::execute(rInstancesTable);
}

void ProgramCCR::initInstances(const Variables_t& rVariables, InstancesTable_t& rInstancesTable, InstancesMap_t* pInstancesMap, bool constructNewInsts)
{
    for (VariablesConstIter_t iter = rVariables.begin(); iter != rVariables.end(); ++iter)
    {
        assert(*iter != NULL);
        AVariableInstance* pInstInMap = NULL;
        if (pInstancesMap != NULL)
        {
            assert((*iter)->getVariableIdentifier() != "");
            InstsMapConstIter_t instInMaptIter = pInstancesMap->find((*iter)->getVariableIdentifier());
            if (instInMaptIter != pInstancesMap->end())
            {
                assert(instInMaptIter->second != NULL);
                pInstInMap = instInMaptIter->second;
            }
        }
        if (pInstInMap == NULL)
        {   // Create new instance.
            AVariableInstance* pNewInst = (*iter)->createNewInstance();
            assert(pNewInst != NULL);
            rInstancesTable.addNewVariable((*iter)->getVariableId(), *pNewInst);
            if (constructNewInsts)
                pNewInst->executeConstructor();
            if (pInstancesMap != NULL)
                (*pInstancesMap)[(*iter)->getVariableIdentifier()] = pNewInst;
        }
        else
        {   // Create new reference to an existing instance.
            rInstancesTable.addNewVariable((*iter)->getVariableId(), *pInstInMap);
        }
    }
}

#endif
