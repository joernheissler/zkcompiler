#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_A_COLLECTED_CODE_REPR_HPP
#define CM_A_COLLECTED_CODE_REPR_HPP

#include "misc/debug/impl/DebugInfo.hpp"

namespace CodeManagement
{

    class ACCRVisitor;
    class ACCRVisitorArgs;
    class ScopeBlockCCR;

    class ACollectedCodeRepr
    {
    public:
        ACollectedCodeRepr(const DebugInfo& rDebugInfo);
        virtual ~ACollectedCodeRepr();

    public:
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs) const;
        virtual void accept(ACCRVisitor& rVisitor, ACCRVisitorArgs* pArgs);
        virtual bool isBulk() const = 0;

    public:
        const DebugInfo& getDebugInfo() const;
        ScopeBlockCCR* getParentScopeBlockCCR();
        const ScopeBlockCCR* getParentScopeBlockCCR() const;

    private:
        void setParentScopeBlockCCR(ScopeBlockCCR* pScopeBlock);

    private:
        DebugInfo _debugInfo;
        ScopeBlockCCR* _pParentScopeBlockCCR;

        friend class ScopeBlockCCR; // Needed to set parent scope block.
        friend class AExecutableCCR; // Needed to set parent scope block.
    };

}

#endif

#endif
