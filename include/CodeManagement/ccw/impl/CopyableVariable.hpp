#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_COPYABLE_VARIABLE_HPP
#define CM_COPYABLE_VARIABLE_HPP

#include "ccr/impl/CopyableVariableCCR.hpp"
#include "ccw/AInstruction.hpp"
#include "ccw/impl/Variable.hpp"
#include "exec/impl/ExplicitCSrcInstCaster.hpp"
#include "exec/impl/ImplicitSrcInstCaster.hpp"
#include "misc/debug/impl/DebugInfo.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // Kein Namespace im Typ-Namen -> im Namespace des Typs aufrufen!
    // Typen nur bestehend aus einzelnem Wort -> typedefs verwenden!
    // Keine expliziten eingebauten Typen -> typedefs verwenden!
    #define CMD_COPYABLE_TYPE(type) \
        namespace U {\
            typedef type type;\
            namespace V { typedef CopyableVariable<type> type; }\
            namespace R { typedef CopyableVariableCCR<type> type; } }\
        template<> inline const char* VariableCCR<U::type>::spec_getTypeIdentifier() { return #type; }\
        template<> struct Specific_FromSourceVariableFactory<U::type> {\
            ConstSourceInstance<U::type> _constant;\
            Specific_FromSourceVariableFactory(const U::type& rSource) : _constant(rSource) { }\
            CopyableVariable<U::type> create(const DebugInfo& rDebugInfo) { return CopyableVariable<U::type>(rDebugInfo, _constant); } };
    #define CMV_CCAST(type, variable) ((variable).explicitCCast< type >(CM_CREATE_DEBUG_INFO("CMV_CCAST(" #type ", " #variable ")")))
#else
    #define CMD_COPYABLE_TYPE(type) \
        namespace U {\
            namespace V { typedef type type; }\
            namespace R { typedef AVariableCCR type; } }
    #define CMV_CCAST(type, variable) ((type)(variable))
#endif

namespace CodeManagement
{

    template<typename TSourceType>
    class CopyableVariable : public Variable<TSourceType>
    {
    public:
        typedef TSourceType Source_t;
        typedef Variable<Source_t> Base_t;
        typedef CopyableVariable This_t;
        typedef SourceInstance<Source_t> SourceInstance_t;
        typedef ConstSourceInstance<Source_t> ConstSourceInstance_t;
        typedef CopyableVariableCCR<Source_t> CCR_t;
        typedef ConstructorCallCCR<Source_t> ConstructorCallCCR_t;
        typedef DestructorCallCCR<Source_t> DestructorCallCCR_t;
        typedef CopyConstructorCallCCR<Source_t> CopyConstructorCallCCR_t;
        typedef CopyAssignmentCallCCR<Source_t> CopyAssignmentCallCCR_t;

    public:
        explicit CopyableVariable(const DebugInfo& rDebugInfo) :
            Base_t(rDebugInfo, false)
        {
            CodeManager::getManager().onCallVariableConstructor(*this);
        }
        CopyableVariable(const CopyableVariable& rToCopy) :
            Base_t(CM_CREATE_DEBUG_INFO("implicit copy of [" + rToCopy.getDebugInfo().toString() + "]"), false)
        {
            CodeManager::getManager().onCallVariableCopyConstructor(*this, rToCopy, NULL);
        }
        CopyableVariable& operator=(const CopyableVariable& rRHS)
        {
            CodeManager::getManager().onCallVariableCopyAssignment(*this, rRHS, NULL);
            return *this;
        }

    public:
        template<typename TSourceTypeToCopy>
        explicit CopyableVariable(const CopyableVariable<TSourceTypeToCopy>& rToCopy,
                const DebugInfo& rDebugInfo = CM_CREATE_DEBUG_INFO("")) :
            Base_t(rDebugInfo.getMessage() == "" ?
                CM_CREATE_DEBUG_INFO("ic-copy of [" + rToCopy.getDebugInfo().toString() + "]") : rDebugInfo, false)
        {   // If TSourceTypeToCopy is the same as Source_t an pForceCopyDebugInfo is not explicitly specified, then the
            // copy-constructor will be called, but in some cases not!
            // If pForceCopyDebugInfo is specified explicitly specified then this constructor is called in all cases!
            ImplicitSrcInstCaster<Source_t, TSourceTypeToCopy> toCopySrcInstCaster;
            CodeManager::getManager().onCallVariableCopyConstructor(*this, rToCopy, &toCopySrcInstCaster);
        }
        template<typename TSourceTypeRHS>
        This_t& operator=(const CopyableVariable<TSourceTypeRHS>& rRHS)
        {
            ImplicitSrcInstCaster<Source_t, TSourceTypeRHS> rhsSrcInstCaster;
            CodeManager::getManager().onCallVariableCopyAssignment(*this, rRHS, &rhsSrcInstCaster);
            return *this;
        }
        template<typename TSrcTypeCasted>
        CopyableVariable<TSrcTypeCasted> explicitCCast(const DebugInfo& rDebugInfo) const
        {
            return CopyableVariable<TSrcTypeCasted>(rDebugInfo, *this);
        }

    public:
        virtual AVariableCCR* createNewCCR() const
        {
            if (this->_pConstInitSrcInst != NULL)
                return new CCR_t(this->getVariableId(), this->getDebugInfo(), *this->_pConstInitSrcInst);
            return new CCR_t(this->getVariableId(), this->getDebugInfo());
        }

    private:
        CopyableVariable(const DebugInfo& rDebugInfo, const ConstSourceInstance_t& rInitConstant) :
            Base_t(rDebugInfo, rInitConstant, false)
        {
            CodeManager::getManager().onCallVariableConstructor(*this);
        }
        template<typename TSourceTypeToCopy>
        CopyableVariable(const DebugInfo& rDebugInfo, const CopyableVariable<TSourceTypeToCopy>& rToCopy) :
            Base_t(rDebugInfo, false)
        {
            ExplicitCSrcInstCaster<Source_t, TSourceTypeToCopy> toCopySrcInstCaster;
            CodeManager::getManager().onCallVariableCopyConstructor(*this, rToCopy, &toCopySrcInstCaster);
        }

        template<typename TSourceTypeFrien>
        friend class CopyableVariable;  // Needed for explicit casting...
        friend struct Specific_FromSourceVariableFactory<Source_t>;  // Needed for copying the variable.
    };
}

#endif

#endif
