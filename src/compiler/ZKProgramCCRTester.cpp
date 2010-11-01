#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "compiler/ZKProgramCCRTester.hpp"

#include <cstdio>
#include "compiler/CCodeIdentifiers.hpp"

using namespace ZKCompiler;
using namespace CodeManagement;

ZKProgramCCRTester::ZKProgramCCRTester(const char* pZKFileName, const char* pIdentSigma, bool interactive) :
    AZKProtocol(pZKFileName, pIdentSigma, interactive)
{
}

ZKProgramCCRTester::ZKProgramCCRTester(const AZKProtocol& rToCopy) : AZKProtocol(rToCopy)
{
}

ZKProgramCCRTester::~ZKProgramCCRTester()
{
}

bool ZKProgramCCRTester::test(Parser& rProverParser, Parser& rVerifierParser,
        const ProgramCCR& rProverProg, const ProgramCCR& rVerifierProg)
{
    if (!isInteractive())
        ZK_HANDLE_ERROR("Testing of non-interactive protocols not implemented yet!");

    // Init protocol...
    ProgramCCR::InstancesTable_t instancesTable;

    Sigma* pProverSigma = NULL;
    {   // Prover and verifier must not know anything about each other at initialization!
        printf("Init prover...\n");
        ProgramCCR::InstancesMap_t initInstsMap;
        proverInit(rProverProg, instancesTable, initInstsMap, rProverParser, pProverSigma);
        assert(pProverSigma != NULL);
        destructInstancesInMap(initInstsMap);
    }

    Sigma* pVerifierSigma = NULL;
    {   // Prover and verifier must not know anything about each other at initialization!
        printf("Init verifier...\n");
        ProgramCCR::InstancesMap_t initInstsMap;
        verifierInit(rVerifierProg, instancesTable, initInstsMap, rVerifierParser, pVerifierSigma);
        assert(pVerifierSigma != NULL);
        destructInstancesInMap(initInstsMap);
    }

    // Execute protocol...
    printf("Execute...\n");
    ProgramCCR::InstancesMap_t instancesMap;
    proverP1(rProverProg, instancesTable, instancesMap, *pProverSigma);
    verifierC(rVerifierProg, instancesTable, instancesMap, *pVerifierSigma);
    proverP2(rProverProg, instancesTable, instancesMap, *pProverSigma);
    bool verification = verifierV(rVerifierProg, instancesTable, instancesMap, *pVerifierSigma);

    // Free protocol...
    printf("Free prover and verifier...\n");
    proverFree(rProverProg, instancesTable, instancesMap, rProverParser, *pProverSigma);
    verifierFree(rVerifierProg, instancesTable, instancesMap, rVerifierParser, *pVerifierSigma);
    destructInstancesInMap(instancesMap);

    return verification;
}

void ZKProgramCCRTester::destructInstancesInMap(ProgramCCR::InstancesMap_t& rInstancesMap)
{
    for (ProgramCCR::InstsMapIter_t iter = rInstancesMap.begin(); iter != rInstancesMap.end(); ++iter)
    {
        assert(iter->second != NULL);
        iter->second->executeDestructor();
    }
}

void ZKProgramCCRTester::getElementNumbers(const Element& rElement, bnz_t* vpDst[], unsigned int size) const
{
    CMV::bnz_t const** ppDstPtrs = new CMV::bnz_t const*[size];
    rElement.getPtrs(ppDstPtrs, size);
    for (unsigned i = 0; i < size; ++i)
        bnz_set(*vpDst[i], CMV_OUT(*ppDstPtrs[i]));
    delete[] ppDstPtrs;
}

void ZKProgramCCRTester::getElementNumbers(const Element& rElement, bnz_t vDst[], unsigned int size) const
{
    bnz_t** ppDst = new bnz_t*[size];
    for (unsigned i = 0; i < size; ++i)
        ppDst[i] = &vDst[i];
    getElementNumbers(rElement, ppDst, size);
    delete[] ppDst;
}

void ZKProgramCCRTester::initBNZsInPtrsArray(bnz_t* vpBNZs[], unsigned int size) const
{
    for (unsigned i = 0; i < size; ++i)
        bnz_init(*vpBNZs[i]);
}

void ZKProgramCCRTester::initBNZsInArray(bnz_t vBNZs[], unsigned int size) const
{
    for (unsigned i = 0; i < size; ++i)
        bnz_init(vBNZs[i]);
}

void ZKProgramCCRTester::clearBNZsInPtrsArray(bnz_t* vpBNZs[], unsigned int size) const
{
    for (unsigned i = 0; i < size; ++i)
        bnz_clear(*vpBNZs[i]);
}

void ZKProgramCCRTester::clearBNZsInArray(bnz_t vBNZs[], unsigned int size) const
{
    for (unsigned i = 0; i < size; ++i)
        bnz_clear(vBNZs[i]);
}

void ZKProgramCCRTester::printBNZsInPtrsArray(const char* pIdent, bnz_t* vpBNZs[], unsigned int size) const
{
    printf("vStr_%s[] = {", pIdent);
    for (unsigned i = 0; i < size; ++i)
        printf("\"%s\"%s", bnToStr(*vpBNZs[i], 10).c_str(), i + 1 == size ? "}\n" : ", ");
}

void ZKProgramCCRTester::initArguments(unsigned*& rpSize, bnz_t***& rpppArg, ProgramCCR::InstancesMap_t& rInstancesMap,
    Parser& rParser, const Identifiers_t& rIdents, const char* pIdentPrefix, bool print) const
{
    assert(rpSize == NULL);
    assert(rpppArg == NULL);
    if (!rIdents.empty())
    {
        rpSize = new unsigned[rIdents.size()];
        rpppArg = new bnz_t**[rIdents.size()];
        for (size_t i = 0; i < rIdents.size(); ++i)
        {
            rpSize[i] = rParser.getVar(rIdents[i].c_str())->getSize();
            rpppArg[i] = new bnz_t*[rpSize[i]];
            std::string ident = std::string(pIdentPrefix) + rIdents[i];
            getInstances(rInstancesMap, ident.c_str(), rpppArg[i], rpSize[i]);
            initBNZsInPtrsArray(rpppArg[i], rpSize[i]);
            getElementNumbers(*rParser.getVar(rIdents[i].c_str()), rpppArg[i], rpSize[i]);
            if (print)
                printBNZsInPtrsArray(ident.c_str(), rpppArg[i], rpSize[i]);
        }
    }
}

void ZKProgramCCRTester::clearArguments(unsigned* pSize, bnz_t*** pppArg, const Identifiers_t& rIdents) const
{
    if (!rIdents.empty())
    {
        for (size_t i = 0; i < getSecretVars().size(); ++i)
        {
            clearBNZsInPtrsArray(pppArg[i], pSize[i]);
            delete[] pppArg[i];
        }
        delete[] pSize;
        delete[] pppArg;
    }
}

void ZKProgramCCRTester::proverInit(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& rInstancesMap, Parser& rParser, Sigma*& rpSigma)
{
    assert(rpSigma == NULL);
    rpSigma = rParser.getSigma(getSigma());
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_proverInit);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->initInstances(rInstancesTable, &rInstancesMap);

    unsigned* pSecretSize = NULL;
    unsigned* pAuxSize = NULL;
    unsigned* pPublicCommitmentSize = NULL;
    bnz_t*** pppSecret = NULL;
    bnz_t*** pppPublicCommitment = NULL;
    bnz_t*** pppAux = NULL;
    initArguments(pSecretSize, pppSecret, rInstancesMap, rParser, getSecretVars(), CCodeIdentifiers::_argPrefixSecret);
    initArguments(pPublicCommitmentSize, pppPublicCommitment, rInstancesMap, rParser,
        getPublicCommitmentVars(), CCodeIdentifiers::_argPrefixPublicCommitment);
    initArguments(pAuxSize, pppAux, rInstancesMap, rParser, getAuxVars(), CCodeIdentifiers::_argPrefixAux);

    // Execute initialization...
    pSubProgCCR->executeCall(rInstancesTable);

    clearArguments(pSecretSize, pppSecret, getSecretVars());
    clearArguments(pPublicCommitmentSize, pppPublicCommitment, getPublicCommitmentVars());
    clearArguments(pAuxSize, pppAux, getAuxVars());
}

void ZKProgramCCRTester::proverP1(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma)
{
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_proverP1);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->initInstances(rInstancesTable, &rInstancesMap);

    const unsigned commitmentSize = rSigma.getCommitmentSize();
    bnz_t** ppCommitment = new bnz_t*[commitmentSize];
    getInstances(rInstancesMap, CCodeIdentifiers::_argCommitment, ppCommitment, commitmentSize);

    initBNZsInPtrsArray(ppCommitment, commitmentSize);
    pSubProgCCR->executeCall(rInstancesTable);
    // Verifier is going to clear the BNZs of commitment...

    printBNZsInPtrsArray(CCodeIdentifiers::_argCommitment, ppCommitment, commitmentSize);
    delete[] ppCommitment;
}

void ZKProgramCCRTester::proverP2(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma)
{
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_proverP2);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->initInstances(rInstancesTable, &rInstancesMap);

    const unsigned responseSize = rSigma.getResponseSize();
    const unsigned challengeSize = 1;
    bnz_t** ppResponse = new bnz_t*[responseSize];
    bnz_t** ppChallenge = new bnz_t*[challengeSize];
    getInstances(rInstancesMap, CCodeIdentifiers::_argResponse, ppResponse, responseSize);
    getInstances(rInstancesMap, CCodeIdentifiers::_argChallenge, ppChallenge, challengeSize);

    initBNZsInPtrsArray(ppResponse, responseSize);
    pSubProgCCR->executeCall(rInstancesTable);
    clearBNZsInPtrsArray(ppChallenge, challengeSize);
    // Verifier is going to clear the BNZs of response...

    printBNZsInPtrsArray(CCodeIdentifiers::_argResponse, ppResponse, responseSize);
    delete[] ppResponse;
    delete[] ppChallenge;
}

void ZKProgramCCRTester::proverFree(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& /*rInstancesMap*/, Parser& /*rParser*/, Sigma& rSigma)
{
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_proverFree);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->executeCall(rInstancesTable);
    delete &rSigma;
}

void ZKProgramCCRTester::verifierInit(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& rInstancesMap, Parser& rParser, Sigma*& rpSigma)
{
    assert(rpSigma == NULL);
    rpSigma = rParser.getSigma(getSigma());
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_verifierInit);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->initInstances(rInstancesTable, &rInstancesMap);

    unsigned* pAuxSize = NULL;
    unsigned* pPublicCommitmentSize = NULL;
    bnz_t*** pppPublicCommitment = NULL;
    bnz_t*** pppAux = NULL;
    initArguments(pPublicCommitmentSize, pppPublicCommitment, rInstancesMap, rParser,
        getPublicCommitmentVars(), CCodeIdentifiers::_argPrefixPublicCommitment);
    initArguments(pAuxSize, pppAux, rInstancesMap, rParser, getAuxVars(), CCodeIdentifiers::_argPrefixAux);

    // Execute initialization...
    pSubProgCCR->executeCall(rInstancesTable);

    clearArguments(pPublicCommitmentSize, pppPublicCommitment, getPublicCommitmentVars());
    clearArguments(pAuxSize, pppAux, getAuxVars());
}

void ZKProgramCCRTester::verifierC(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma)
{
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_verifierC);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->initInstances(rInstancesTable, &rInstancesMap);

    const unsigned challengeSize = 1;
    const unsigned commitmentSize = rSigma.getCommitmentSize();
    bnz_t** ppChallenge = new bnz_t*[challengeSize];
    bnz_t** ppCommitment = new bnz_t*[commitmentSize];
    getInstances(rInstancesMap, CCodeIdentifiers::_argChallenge, ppChallenge, challengeSize);
    getInstances(rInstancesMap, CCodeIdentifiers::_argCommitment, ppCommitment, commitmentSize);

    initBNZsInPtrsArray(ppChallenge, challengeSize);
    pSubProgCCR->executeCall(rInstancesTable);
    clearBNZsInPtrsArray(ppCommitment, commitmentSize);
    // Prover is going to clear the BNZs of challenge...

    printBNZsInPtrsArray(CCodeIdentifiers::_argChallenge, ppChallenge, challengeSize);
    delete[] ppChallenge;
    delete[] ppCommitment;
}

bool ZKProgramCCRTester::verifierV(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& rInstancesMap, Sigma& rSigma)
{
    if (!isInteractive())
        ZK_HANDLE_ERROR("Compilation of non-interactive protocols not implemented yet!");

    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_verifierV);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->initInstances(rInstancesTable, &rInstancesMap);

    const unsigned verificationSize = 1;
    const unsigned responseSize = rSigma.getResponseSize();
    zk_bool_t** ppVerification = new zk_bool_t*[verificationSize];
    bnz_t** ppResponse = new bnz_t*[responseSize];
    getInstances(rInstancesMap, CCodeIdentifiers::_argVerification, ppVerification, verificationSize);
    getInstances(rInstancesMap, CCodeIdentifiers::_argResponse, ppResponse, responseSize);

    *ppVerification[0] = false;
    pSubProgCCR->executeCall(rInstancesTable);
    clearBNZsInPtrsArray(ppResponse, responseSize);

    printf("%s[] = {%s}\n", CCodeIdentifiers::_argVerification, *ppVerification[0] ? "true" : "false");
    bool ret = *ppVerification[0];
    delete[] ppVerification;
    delete[] ppResponse;

    return ret;
}

void ZKProgramCCRTester::verifierFree(const ProgramCCR& rProgCCR, ProgramCCR::InstancesTable_t& rInstancesTable, ProgramCCR::InstancesMap_t& /*rInstancesMap*/, Parser& /*rParser*/, Sigma& rSigma)
{
    const ProgramCCR* pSubProgCCR = rProgCCR.getProgram(CCodeIdentifiers::_verifierFree);
    assert(pSubProgCCR != NULL);
    pSubProgCCR->executeCall(rInstancesTable);
    delete &rSigma;
}

#endif
