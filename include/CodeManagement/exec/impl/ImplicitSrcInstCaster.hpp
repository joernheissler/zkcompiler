#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_IMPLICIT_SRC_INST_CASTER_HPP
#define CM_IMPLICIT_SRC_INST_CASTER_HPP

#include "ccr/impl/VariableCCR.hpp"
#include "exec/AImplicitSrcInstCaster.hpp"

namespace CodeManagement
{
    template<typename TToSourceType, typename TFromSourceType>
    class ImplicitSrcInstCaster : public AImplicitSrcInstCaster
    {
    public:
        typedef TToSourceType ToSource_t;
        typedef TFromSourceType FromSource_t;
        typedef ImplicitSrcInstCaster<ToSource_t, FromSource_t> This_t;

    public:
        virtual This_t* createNewCopy() const
        {
            return new This_t(*this);
        }
        virtual void cast(void* pSrcInst, const void* pSrcInstToCast) const
        {
            // The following code performs type checking at compilation time for implicit castings.
            *(ToSource_t*)pSrcInst = *(FromSource_t*)pSrcInstToCast;
        }
        virtual const char* getToTypeIdentifier() const
        {
            return VariableCCR<ToSource_t>::spec_getTypeIdentifier();
        }
        virtual const char* getFromTypeIdentifier() const
        {
            return VariableCCR<FromSource_t>::spec_getTypeIdentifier();
        }
    };
}

#endif

#endif
