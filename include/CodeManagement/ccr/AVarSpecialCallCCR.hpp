#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_VAR_SPECIAL_CALL_CCR_HPP
#define CM_A_VAR_SPECIAL_CALL_CCR_HPP

#include "ccr/AExecutableCCR.hpp"

namespace CodeManagement
{

    class AVarSpecialCallCCR : public AExecutableCCR
    {
    public:
        typedef AExecutableCCR Base_t;
        typedef Base_t::Variables_t Variables_t;
        typedef Base_t::VariablesIter_t VariablesIter_t;
        typedef Base_t::VariablesConstIter_t VariablesConstIter_t;

    public:
        AVarSpecialCallCCR(const DebugInfo& rDebugInfo);

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);

    public:
        // We don't know, weather "this" is output or input, so override bindVariablesGeneric().
        virtual bool bindVariablesGeneric(Variables_t* pOutputVariables, Variables_t* pInputVariables, bool expandVarsScopes) = 0;
        const AVariableCCR& getThisVariable() const;

    protected:
        AVariableCCR* _pThisVariable;
    };

}

#endif

#endif
