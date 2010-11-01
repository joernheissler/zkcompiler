#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_ZK_PROGRAM_CCR_TESTER_HPP
#define ZK_ZK_PROGRAM_CCR_TESTER_HPP

#include "AZKProtocol.hpp"
#include "bignum/bignum.hpp"
#include "CodeManagement/ccr/impl/ProgramCCR.hpp"
#include "CodeManagement/misc/stream/impl/StringStream.hpp"
#include "parser/parser.hpp"
#include "util/errorhandling.hpp"

namespace ZKCompiler
{

    class ZKProgramCCRTester : public AZKProtocol
    {
    public:
        ZKProgramCCRTester(const char* pZKFileName, const char* pIdentSigma, bool interactive = true);
        ZKProgramCCRTester(const AZKProtocol& rToCopy);
        virtual ~ZKProgramCCRTester();

    public:
        bool test(Parser& rProverParser, Parser& rVerifierParser, const CodeManagement::ProgramCCR& rProverProg, const CodeManagement::ProgramCCR& rVerifierProg);

    protected:
        virtual void proverInit(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Parser& rParser, Sigma*& rpSigma);
        virtual void proverP1(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma);
        virtual void proverP2(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma);
        virtual void proverFree(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Parser& rParser, Sigma& rSigma);
        virtual void verifierInit(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Parser& rParser, Sigma*& rpSigma);
        virtual void verifierC(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma);
        virtual bool verifierV(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma);
        virtual void verifierFree(const CodeManagement::ProgramCCR& rProgCCR, CodeManagement::ProgramCCR::InstancesTable_t& rInstancesTable, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, Parser& rParser, Sigma& rSigma);

    protected:
        void destructInstancesInMap(CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap);
        void getElementNumbers(const Element& rElement, bnz_t* vpDst[], unsigned int size) const;
        void getElementNumbers(const Element& rElement, bnz_t vDst[], unsigned int size) const;
        void initBNZsInPtrsArray(bnz_t* vpBNZs[], unsigned int size) const;
        void initBNZsInArray(bnz_t vBNZs[], unsigned int size) const;
        void clearBNZsInPtrsArray(bnz_t* vpBNZs[], unsigned int size) const;
        void clearBNZsInArray(bnz_t vBNZs[], unsigned int size) const;
        void printBNZsInPtrsArray(const char* pIdent, bnz_t* vpBNZs[], unsigned int size) const;
        void initArguments(unsigned*& rpSize, bnz_t***& rpppArg, CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap,
            Parser& rParser, const Identifiers_t& rIdents, const char* pIdentPrefix, bool print = true) const;
        void clearArguments(unsigned* pSize, bnz_t*** pppArg, const Identifiers_t& rIdents) const;
        template<typename TSourceType>
        void getInstances(CodeManagement::ProgramCCR::InstancesMap_t& rInstancesMap, const char* pIdent, TSourceType* vpInsts[], unsigned size) const
        {
            for (unsigned i = 0; i < size; ++i)
            {
                CodeManagement::StringStream varIdent;
                varIdent << pIdent << "[" << i << "]";
                CodeManagement::ProgramCCR::InstsMapIter_t iter = rInstancesMap.find(varIdent.toCString());
                if (iter == rInstancesMap.end())
                    ZK_HANDLE_ERROR("Instance not found!");
                vpInsts[i] = (TSourceType*)iter->second->getSourceInstance();
            }

            // Check weather there are more instances with the same identifier in rInstancesMap.
            // Looking for the next element of array should be enough...
            CodeManagement::StringStream varIdent;
            varIdent << pIdent << "[" << size << "]";
            if (rInstancesMap.find(varIdent.toCString()) != rInstancesMap.end())
                ZK_HANDLE_ERROR("Not all instances read!");
        }
    };

}

#endif

#endif
