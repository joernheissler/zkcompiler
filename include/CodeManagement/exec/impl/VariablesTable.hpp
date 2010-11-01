#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_VARIABLES_TABLE_HPP
#define CM_VARIABLES_TABLE_HPP

#include <cassert>
#include <map>
#include "exec/AVariablesTable.hpp"

namespace CodeManagement
{

    template <class TVariableType>
    class VariablesTable : public AVariablesTable
    {
    public:
        typedef long unsigned int variableId_t;
        typedef TVariableType Variable_t;
        typedef VariablesTable This_t;

    protected:
        typedef AVariablesTable::Map_t Map_t;
        typedef AVariablesTable::MapIter_t MapIter_t;
        typedef AVariablesTable::MapConstIter_t MapConstIter_t;

    public:
        virtual ~VariablesTable()
        {
            clear(true);
        }

    protected:
        virtual void destroyVariable(void* pVariable) const
        {
            assert(pVariable != NULL);
            delete static_cast<Variable_t*>(pVariable);
        }

    public:
        void addNewVariable(variableId_t id, Variable_t& rVariable)
        {
            AVariablesTable::addNewVariable(id, &rVariable);
        }
        Variable_t* removeVariable(variableId_t id, bool destroy)
        {
            return static_cast<Variable_t*>(AVariablesTable::removeVariable(id, destroy));
        }
        const Variable_t* getVariable(variableId_t id) const
        {
            return static_cast<const Variable_t*>(AVariablesTable::getVariable(id));
        }
        Variable_t* getVariable(variableId_t id)
        {
            return static_cast<Variable_t*>(AVariablesTable::getVariable(id));
        }
        template<class TDstContainer> void getAllVariables(TDstContainer& rDst) const
        {
            for (MapConstIter_t iter = _map.begin(); iter != _map.end(); ++iter)
            {
                assert(iter->second != NULL);
                rDst.push_back(static_cast<const Variable_t*>(iter->second));
            }
        }
        template<class TDstContainer> void getAllVariables(TDstContainer& rDst)
        {
            for (MapIter_t iter = _map.begin(); iter != _map.end(); ++iter)
            {
                assert(iter->second != NULL);
                rDst.push_back(static_cast<Variable_t*>(iter->second));
            }
        }
        template<class TDstContainer, class TSrcContainerIterator>
        void getVariables(TDstContainer& rDst, const TSrcContainerIterator& rSrcBegin, const TSrcContainerIterator rSrcEnd)
        {
            for (TSrcContainerIterator iter = rSrcBegin; iter != rSrcEnd; ++iter)
            {
                assert(*iter != NULL);
                rDst.push_back(getVariable((*iter)->getVariableId()));
            }
        }
    };

}

#endif

#endif
