#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_VARIABLE_HPP
#define CM_VARIABLE_HPP

#include <cassert>
#include "core/impl/CodeManager.hpp"
#include "ccr/impl/VariableCCR.hpp"
#include "ccw/AVariable.hpp"
#include "misc/debug/impl/DebugInfo.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // Kein Namespace im Typ-Namen -> im Namespace des Typs aufrufen!
    // Typen nur bestehend aus einzelnem Wort -> typedefs verwenden!
    // Keine expliziten eingebauten Typen -> typedefs verwenden!
    #define CMD_TYPE(type) \
        namespace U {\
            namespace V { typedef Variable<type> type; }\
            namespace R { typedef VariableCCR<type> type; } }\
        template<> inline const char* VariableCCR<U::type>::spec_getTypeIdentifier() { return #type; }
    #define CMV_IN(value) CodeManagement::getFromSourceVariableFactory((value)).create(CM_CREATE_DEBUG_INFO("CMV_IN(" #value ")"))
#else
    #define CMD_TYPE(type) \
        namespace U {\
            namespace V { typedef type type; }\
            namespace R { typedef AVariableCCR type; } }
    #define CMV_IN(value) (value)
#endif

namespace CodeManagement
{

    template<typename TSourceType>
    struct Specific_FromSourceVariableFactory;

    template<typename TSourceType>
    class Variable : public AVariable
    {
    public:
        typedef TSourceType Source_t;
        typedef Variable This_t;
        typedef ConstSourceInstance<Source_t> ConstSourceInstance_t;
        typedef VariableCCR<Source_t> CCR_t;
        typedef ConstructorCallCCR<Source_t> ConstructorCallCCR_t;
        typedef DestructorCallCCR<Source_t> DestructorCallCCR_t;
        typedef CopyConstructorCallCCR<Source_t> CopyConstructorCallCCR_t;
        typedef CopyAssignmentCallCCR<Source_t> CopyAssignmentCallCCR_t;

    public:
        explicit Variable(const DebugInfo& rDebugInfo, bool callManager = true) :
            AVariable(rDebugInfo), _pConstInitSrcInst(NULL)
        {
            if (callManager)
                // Call it here only when the complete class instance has been constructed,
                // i.e. derived classes' constructors have to call it on their own!
                CodeManager::getManager().onCallVariableConstructor(*this);
        }
        virtual ~Variable()
        {
            if (wasCopied())
                // This is just a "forgotten" copied variable. Do nothing.
                // The copy will care about the instance.
                return;

            // Do not call from derived classes' destructors!
            CodeManager::getManager().onCallVariableDestructor(*this);

            if (_pConstInitSrcInst != NULL)
                delete _pConstInitSrcInst;
        }

    protected:
        Variable(const DebugInfo& rDebugInfo, const ConstSourceInstance_t& rInitConstant, bool callManager) :
            AVariable(rDebugInfo), _pConstInitSrcInst(new ConstSourceInstance_t(rInitConstant))
        {
            if (callManager)
                // Call it here only when the complete class instance has been constructed,
                // i.e. derived classes' constructors have to call it on their own!
                CodeManager::getManager().onCallVariableConstructor(*this);
        }

    private:
        Variable(const This_t& rToCopy) :
            AVariable(rToCopy), _pConstInitSrcInst(rToCopy._pConstInitSrcInst)
        {
            // This could only be called from Specific_FromSourceVariableFactory::create().
            // We don't tell the manager, let this copy be the original and "forget" the true original.
            assert(!wasCopied());
            assert(rToCopy.wasCopied());
        }
        This_t& operator=(const This_t& /*rRHS*/)
        {
            throw CM_CREATE_EXCEPTION("Illegal call to copy-assignment!");
            return *this;
        }

    public:
        virtual const void* getInitConstant() const
        {
            return _pConstInitSrcInst != NULL ? &_pConstInitSrcInst->get() : NULL;
        }
        virtual AVariableCCR* createNewCCR() const
        {
            if (_pConstInitSrcInst != NULL)
                return new CCR_t(getVariableId(), getDebugInfo(), *_pConstInitSrcInst);
            return new CCR_t(getVariableId(), getDebugInfo());
        }
        const Source_t& getSourceInstance(const DebugInfo& rDebugInfo) const
        {
            const Source_t* pSrcInst = (const Source_t*)CodeManager::getManager().getVariableSourceInstance(*this);
            if (pSrcInst == NULL)
                throw CM_CREATE_EXCEPTION("Tried to access a not existing instance! "
                    "Maybe you are in a not executed if-branch. Use CM_ON_EXECUTION to check it! [" + rDebugInfo.toString() + "]");
            return *pSrcInst;
        }

    protected:
        const ConstSourceInstance_t* const _pConstInitSrcInst;

        friend struct Specific_FromSourceVariableFactory<Source_t>;  // Needed for copying the variable.
    };

    template<typename TSourceType>
    struct Specific_FromSourceVariableFactory
    {
        Specific_FromSourceVariableFactory(const TSourceType& rSource) : _constant(rSource)
        {
        }
        Variable<TSourceType> create(const DebugInfo& rDebugInfo)
        {
            // Could call the private copy constructor.
            return Variable<TSourceType>(rDebugInfo, _constant, true);
        }
        ConstSourceInstance<TSourceType> _constant;
    };

    template<typename TSourceType>
    Specific_FromSourceVariableFactory<TSourceType> getFromSourceVariableFactory(const TSourceType& rInit)
    {
        return Specific_FromSourceVariableFactory<TSourceType>(rInit);
    }
}

#endif

#endif
