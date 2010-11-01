#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_COPY_CONSTRUCTOR_CALL_CCR_HPP
#define CM_COPY_CONSTRUCTOR_CALL_CCR_HPP

#include "ccr/ACopyConstructorCallCCR.hpp"

namespace CodeManagement
{

    template<class TSourceType>
    class CopyConstructorCallCCR : public ACopyConstructorCallCCR
    {
    public:
        typedef TSourceType Source_t;

    public:
        CopyConstructorCallCCR(const DebugInfo& rDebugInfo, const ASourceInstanceCaster* pToCopySrcInstCaster) :
            ACopyConstructorCallCCR(rDebugInfo, pToCopySrcInstCaster)
        {
        }
    };

}

#endif

#endif
