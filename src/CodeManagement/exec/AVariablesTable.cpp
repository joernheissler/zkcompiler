#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "exec/AVariablesTable.hpp"

#include "misc/debug/impl/Exception.hpp"
#include "misc/stream/impl/StringStream.hpp"

using namespace CodeManagement;

AVariablesTable::AVariablesTable()
{
}

AVariablesTable::~AVariablesTable()
{
    assert(_map.empty());
}

void AVariablesTable::addNewVariable(variableId_t id, void* pVariable)
{
    assert(pVariable != NULL);

    MapConstIter_t iter = _map.find(id);
    if (iter == _map.end())
        _map[id] = pVariable;
    else
    {
        StringStream msg;
        msg << "Multiple add of variable [" << iter->first << "]!";
        throw CM_CREATE_EXCEPTION(msg.toCString());
    }
}

void* AVariablesTable::removeVariable(variableId_t id, bool destroy)
{
    MapIter_t iter = _map.find(id);
    if (iter != _map.end())
    {
        void* pRemovedVariable = iter->second;
        _map.erase(iter);
        if (destroy)
        {
            destroyVariable(pRemovedVariable);
            pRemovedVariable = NULL;
        }
        return pRemovedVariable;
    }
    else
    {
        StringStream msg;
        msg << "No variable [" << iter->first << "] to remove!";
        throw CM_CREATE_EXCEPTION(msg.toCString());
        return NULL;
    }
}

size_t AVariablesTable::getVariablesNumber() const
{
    return _map.size();
}

const void* AVariablesTable::getVariable(variableId_t id) const
{
    return const_cast<AVariablesTable*>(this)->getVariable(id);
}

void* AVariablesTable::getVariable(variableId_t id)
{
    MapConstIter_t iter = _map.find(id);
    if (iter != _map.end())
    {
        return iter->second;
    }
    else
    {
        return NULL;
    }
}

void AVariablesTable::clear(bool destroy)
{
    if (destroy)
    {   // Note: One variable can be stored more then once!
        std::map<void*, bool> destroyed;
        for (MapIter_t iter = _map.begin(); iter != _map.end(); ++iter)
        {
            assert(iter->second != NULL);
            if (destroyed.find(iter->second) == destroyed.end())
            {
                destroyVariable(iter->second);
                destroyed[iter->second] = true;
            }
        }
    }
    _map.clear();
}

#endif
