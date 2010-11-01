#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_SOURCE_INSTANCE_CASTER_HPP
#define CM_A_SOURCE_INSTANCE_CASTER_HPP

namespace CodeManagement
{
    class ASourceInstanceCaster
    {
    public:
        virtual ASourceInstanceCaster* createNewCopy() const = 0;
        virtual void cast(void* pSrcInst, const void* pSrcInstToCast) const = 0;
        virtual const char* getToTypeIdentifier() const = 0;
        virtual const char* getFromTypeIdentifier() const = 0;
    };
}

#endif

#endif
