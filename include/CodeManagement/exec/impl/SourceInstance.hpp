#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_SOURCE_INSTANCE_HPP
#define CM_SOURCE_INSTANCE_HPP

#include <cassert>
#include <cstddef>
#include "exec/ASourceInstanceCaster.hpp"
#include "misc/debug/impl/Exception.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // Kein Namespace im Typ-Namen -> im Namespace des Typs aufrufen!
    // Typen nur bestehend aus einzelnem Wort -> typedefs verwenden!
    // Keine expliziten eingebauten Typen -> typedefs verwenden!
    #define CMD_INSTANCES_HANDLING(type, contructorFunc, destructorFunc) \
            template<> inline U::type* SourceInstance<U::type>::spec_constructor()\
                { return (contructorFunc)(); }\
            template<> inline void SourceInstance<U::type>::spec_destructor(Source_t* pThis)\
                { (destructorFunc)(pThis); }
#else
    #define CMD_INSTANCES_HANDLING(type, contructorFunc, destructorFunc)
#endif

namespace CodeManagement
{

    template<typename TSourceType>
    class SourceInstance
    {
    public:
        typedef TSourceType Source_t;
        typedef SourceInstance<TSourceType> This_t;

    public:
        SourceInstance() : _pSourceInstance(NULL)
        {
        }
        ~SourceInstance()
        {
            assert(!isConstructed());
        }

    protected:
        SourceInstance(const SourceInstance& rToCopy) : _pSourceInstance(rToCopy._pSourceInstance)
        {
        }
        SourceInstance& operator=(const SourceInstance& rRHS)
        {
            _pSourceInstance = rRHS._pSourceInstance;
            return *this;
        }

    public:
        bool isConstructed() const
        {
            return _pSourceInstance != NULL;
        }
        void executeConstructor()
        {
            assert(!isConstructed());
            _pSourceInstance = spec_constructor();
        }
        void executeDestructor()
        {
            assert(isConstructed());
            spec_destructor(_pSourceInstance);
            _pSourceInstance = NULL;
        }
        Source_t& get()
        {
            assert(isConstructed());
            return *_pSourceInstance;
        }
        const Source_t& get() const
        {
            assert(isConstructed());
            return *_pSourceInstance;
        }
        bool getBool() const
        {
            return spec_getBool(*this);
        }

    public:
        static Source_t* spec_constructor()
        {
            return new Source_t();
        }
        static void spec_destructor(Source_t* pThis)
        {
            assert(pThis != NULL);
            delete pThis;
        }
        static bool spec_getBool(const This_t& rThis)
        {   // This method is only implemented for type bool! For other types castings have to be performed.
            (void)rThis;
            throw CM_CREATE_EXCEPTION("Source instance is not of type bool! "
                "A(n explicit) cast to bool has to be performed first." /*" [" + rThis.getDebugInfo().toString() + "]"*/);
        }

    protected:
        Source_t* _pSourceInstance;

        // The following methods can't be members of this class, because they are not defined for all source types.
        // As not-member template methods they will be specialized only for those types they are really called for.
        template<typename TFriendSourceType>
        friend void SourceInstance_executeCopyConstructor(SourceInstance<TFriendSourceType>& rThis, const TFriendSourceType& rToCopy);
        template<typename TFriendSourceType>
        friend void SourceInstance_executeCopyConstructor(SourceInstance<TFriendSourceType>& rThis, const void* pToCopy, const ASourceInstanceCaster& rSrcInstCaster);
        template<typename TFriendSourceType>
        friend void SourceInstance_executeCopyAssignment(SourceInstance<TFriendSourceType>& rThis, const TFriendSourceType& rRHS);
        template<typename TFriendSourceType>
        friend void SourceInstance_executeCopyAssignment(SourceInstance<TFriendSourceType>& rThis, const void* pRHS, const ASourceInstanceCaster& rSrcInstCaster);
    };

    template<> inline bool SourceInstance<bool>::spec_getBool(const SourceInstance<bool>& rThis)
    {   // This method is only implemented for type bool! For other types castings have to be performed.
        assert(rThis.isConstructed());
        return *rThis._pSourceInstance;
    }

    template<typename TSourceType>
    static void SourceInstance_executeCopyConstructor(SourceInstance<TSourceType>& rThis, const TSourceType& rToCopy)
    {
        assert(!rThis.isConstructed());
        rThis._pSourceInstance = new TSourceType(rToCopy);
    }

    template<typename TSourceType>
    void SourceInstance_executeCopyConstructor(SourceInstance<TSourceType>& rThis, const void* pToCopy, const ASourceInstanceCaster& rSrcInstCaster)
    {
        assert(pToCopy != NULL);
        // Create a casted instance and copy it.
        TSourceType* pCastedToCopy = rThis.spec_constructor();
        rSrcInstCaster.cast(pCastedToCopy, pToCopy);
        SourceInstance_executeCopyConstructor(rThis, *pCastedToCopy);
        rThis.spec_destructor(pCastedToCopy);
    }

    template<typename TSourceType>
    void SourceInstance_executeCopyAssignment(SourceInstance<TSourceType>& rThis, const TSourceType& rRHS)
    {
        assert(rThis.isConstructed());
        *rThis._pSourceInstance = rRHS;
    }

    template<typename TSourceType>
    void SourceInstance_executeCopyAssignment(SourceInstance<TSourceType>& rThis, const void* pRHS, const ASourceInstanceCaster& rSrcInstCaster)
    {
        assert(pRHS != NULL);
        // Create a casted instance and copy-assign to it.
        TSourceType* pCastedRHS = rThis.spec_constructor();
        rSrcInstCaster.cast(pCastedRHS, pRHS);
        SourceInstance_executeCopyAssignment(rThis, *pCastedRHS);
        rThis.spec_destructor(pCastedRHS);
    }

}

#endif

#endif
