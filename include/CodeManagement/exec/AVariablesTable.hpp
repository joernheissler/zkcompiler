#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_VARIABLES_TABLE_HPP
#define CM_A_VARIABLES_TABLE_HPP

#include <cassert>
#include <map>

namespace CodeManagement
{

    class AVariablesTable
    {
    public:
        typedef long unsigned int variableId_t;
        typedef std::map<variableId_t, void*> Map_t;
        typedef Map_t::iterator MapIter_t;
        typedef Map_t::const_iterator MapConstIter_t;

    protected:
        AVariablesTable();

    public:
        virtual ~AVariablesTable();

    protected:
        void addNewVariable(variableId_t id, void* pVariable);
        void* removeVariable(variableId_t id, bool destroy);
        virtual void destroyVariable(void* pVariable) const = 0;

    public:
        size_t getVariablesNumber() const;
        const void* getVariable(variableId_t id) const;
        void* getVariable(variableId_t id);
        void clear(bool destroy);

    protected:
        Map_t _map;
    };

}

#endif

#endif
