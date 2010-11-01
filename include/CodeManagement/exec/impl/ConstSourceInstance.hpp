#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_CONST_SOURCE_INSTANCE_HPP
#define CM_CONST_SOURCE_INSTANCE_HPP

#include "exec/impl/SourceInstance.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // Kein Namespace im Typ-Namen -> im Namespace des Typs aufrufen!
    // Typen nur bestehend aus einzelnem Wort -> typedefs verwenden!
    // Keine expliziten eingebauten Typen -> typedefs verwenden!
    #define CMD_CONST_INSTANCES_HANDLING(type, contructorFunc, destructorFunc) \
            template<> inline U::type* ConstSourceInstance<U::type>::spec_constConstructor(const Source_t& rInitConstant)\
                { return (contructorFunc)(rInitConstant); }\
            template<> inline void ConstSourceInstance<U::type>::spec_constDestructor(Source_t* pThis)\
                { (destructorFunc)(pThis); }
#else
    #define CMD_CONST_INSTANCES_HANDLING(type, contructorFunc, destructorFunc)
#endif

namespace CodeManagement
{

    template<typename TSourceType>
    class ConstSourceInstance : private SourceInstance<TSourceType>
    {
    public:
        typedef TSourceType Source_t;
        typedef SourceInstance<Source_t> Base_t;
        typedef ConstSourceInstance<Source_t> This_t;

    public:
        ConstSourceInstance(const Source_t& rInitConstant) : _pReferencesCounter(new size_t(0))
        {
            assert(!this->isConstructed());
            this->_pSourceInstance = this->spec_constConstructor(rInitConstant);
            addReference();
        }
        ~ConstSourceInstance()
        {
            freeReference();
        }
        ConstSourceInstance(const ConstSourceInstance& rToCopy) :
            Base_t(rToCopy), _pReferencesCounter(rToCopy._pReferencesCounter)
        {
            addReference();
        }
        ConstSourceInstance& operator=(const ConstSourceInstance& rRHS)
        {
            freeReference();
            Base_t::operator=(rRHS);
            _pReferencesCounter = rRHS._pReferencesCounter;
            return *this;
        }

    public:
        Source_t& get()
        {
            return Base_t::get();
        }
        const Source_t& get() const
        {
            return Base_t::get();
        }
        bool getBool() const
        {
            return Base_t::getBool();
        }

    private:
        void addReference()
        {
            assert(_pReferencesCounter != NULL);
            ++(*_pReferencesCounter);
        }
        void freeReference()
        {
            assert(this->isConstructed());
            assert(_pReferencesCounter != NULL);
            assert(*_pReferencesCounter > 0);
            if (--(*_pReferencesCounter) == 0)
            {   // This was the last reference to the constant.
                this->spec_constDestructor(this->_pSourceInstance);
                delete _pReferencesCounter;
            }
            this->_pSourceInstance = NULL;
        }

    public:
        static Source_t* spec_constConstructor(const Source_t& rInitConstant)
        {
            // If here a compilation error occurs then you can use your own constructor/destructor for constant source instances.
            // You specify them with macros that are defined on the top of this file.
            return new Source_t(rInitConstant);
        }
        static void spec_constDestructor(Source_t* pThis)
        {
            spec_destructor(pThis);
        }

    private:
        size_t* _pReferencesCounter;
    };
}

#endif

#endif
