#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "compiler/ZKFileToProgramCCRCompiler.hpp"

#include "CodeManagement/core/impl/CodeManager.hpp"
#include "CodeManagement/ccr/impl/ProgramCCR.hpp"
#include "compiler/CCodeIdentifiers.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;
using namespace CodeManagement;

ZKFileToProgramCCRCompiler::ZKFileToProgramCCRCompiler(const char* pZKFileName, const char* pIdentSigma, bool interactive) :
    AZKProtocol(pZKFileName, pIdentSigma, interactive)
{
}

ZKFileToProgramCCRCompiler::ZKFileToProgramCCRCompiler(const AZKProtocol& rToCopy) : AZKProtocol(rToCopy)
{
}

ZKFileToProgramCCRCompiler::~ZKFileToProgramCCRCompiler()
{
}

void ZKFileToProgramCCRCompiler::compileProver(CodeCollector& rCC)
{
    if (!isInteractive())
        ZK_HANDLE_ERROR("Compilation of non-interactive protocols not implemented yet!");

    CMM_IF(CMV_IN(false))    // Don't execute any code, just collect!
        Parser* pParser = NULL;
        Sigma* pSigma = NULL;
        proverInit(rCC, pParser, pSigma);
        assert(pParser != NULL);
        assert(pSigma != NULL);
        proverP1(rCC, *pSigma);
        proverP2(rCC, *pSigma);
        proverFree(rCC, *pParser, *pSigma);
    CMM_ENDIF
}

void ZKFileToProgramCCRCompiler::compileVerifier(CodeCollector& rCC)
{
    if (!isInteractive())
        ZK_HANDLE_ERROR("Compilation of non-interactive protocols not implemented yet!");

    CMM_IF(CMV_IN(false))    // Don't execute any code, just collect!
        Parser* pParser = NULL;
        Sigma* pSigma = NULL;
        verifierInit(rCC, pParser, pSigma);
        assert(pParser != NULL);
        assert(pSigma != NULL);
        verifierC(rCC, *pSigma);
        verifierV(rCC, *pSigma);
        verifierFree(rCC, *pParser, *pSigma);
    CMM_ENDIF
}

void ZKFileToProgramCCRCompiler::proverInit(CodeCollector& rCC, Parser*& rpParser, Sigma*& rpSigma)
{
    assert(rpParser == NULL);
    assert(rpSigma == NULL);

    unsigned* pSecretSize = getSecretVars().empty() ? NULL : new unsigned[getSecretVars().size()];
    unsigned* pPublicCommitmentSize = getPublicCommitmentVars().empty() ? NULL : new unsigned[getPublicCommitmentVars().size()];
    unsigned* pAuxSize = getAuxVars().empty() ? NULL : new unsigned[getAuxVars().size()];
    {
        Parser* pAuxParser = Parser::fromFile(getZKFileName());
        for (size_t i = 0; i < getSecretVars().size(); ++i)
            pSecretSize[i] = pAuxParser->getVar(getSecretVars()[i].c_str())->getSize();
        for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
            pPublicCommitmentSize[i] = pAuxParser->getVar(getPublicCommitmentVars()[i].c_str())->getSize();
        for (size_t i = 0; i < getAuxVars().size(); ++i)
            pAuxSize[i] = pAuxParser->getVar(getAuxVars()[i].c_str())->getSize();
        delete pAuxParser;
    }

    CMV::bnz_t** ppSecret = getSecretVars().empty() ? NULL : new CMV::bnz_t*[getSecretVars().size()];
    CMV::bnz_t** ppPublicCommitment = getPublicCommitmentVars().empty() ? NULL : new CMV::bnz_t*[getPublicCommitmentVars().size()];
    CMV::bnz_t** ppAux = getAuxVars().empty() ? NULL : new CMV::bnz_t*[getAuxVars().size()];
    for (size_t i = 0; i < getSecretVars().size(); ++i)
        CMV_NEW_ARRAY(ppSecret[i], bnz_t, pSecretSize[i]);
    for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
        CMV_NEW_ARRAY(ppPublicCommitment[i], bnz_t, pPublicCommitmentSize[i]);
    for (size_t i = 0; i < getAuxVars().size(); ++i)
        CMV_NEW_ARRAY(ppAux[i], bnz_t, pAuxSize[i]);
    rCC.beginSubProgram(CCodeIdentifiers::_proverInit);
    {
        rpParser = Parser::fromFile(getZKFileName());
        for (size_t i = 0; i < getSecretVars().size(); ++i)
        {
            addInputVariables(rCC, (std::string(CCodeIdentifiers::_argPrefixSecret) + getSecretVars()[i]).c_str(),
                ppSecret[i], pSecretSize[i]);
            rpParser->getVar(getSecretVars()[i].c_str())->set(ppSecret[i], pSecretSize[i]);
        }
        for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
        {
            addInputVariables(rCC, (std::string(CCodeIdentifiers::_argPrefixPublicCommitment) + getPublicCommitmentVars()[i]).c_str(),
                ppPublicCommitment[i], pPublicCommitmentSize[i]);
            rpParser->getVar(getPublicCommitmentVars()[i].c_str())->set(ppPublicCommitment[i], pPublicCommitmentSize[i]);
        }
        for (size_t i = 0; i < getAuxVars().size(); ++i)
        {
            addInputVariables(rCC, (std::string(CCodeIdentifiers::_argPrefixAux) + getAuxVars()[i]).c_str(),
                ppAux[i], pAuxSize[i]);
            rpParser->getVar(getAuxVars()[i].c_str())->set(ppAux[i], pAuxSize[i]);
        }
        rpSigma = rpParser->getSigma(getSigma());
    }
    rCC.endSubProgram(CCodeIdentifiers::_proverInit);
    if (!getSecretVars().empty())
    {
        for (size_t i = 0; i < getSecretVars().size(); ++i)
            CMV_DELETE_ARRAY(ppSecret[i], bnz_t, pSecretSize[i]);
        delete[] ppSecret;
        delete[] pSecretSize;
    }
    if (!getPublicCommitmentVars().empty())
    {
        for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
            CMV_DELETE_ARRAY(ppPublicCommitment[i], bnz_t, pPublicCommitmentSize[i]);
        delete[] ppPublicCommitment;
        delete[] pPublicCommitmentSize;
    }
    if (!getAuxVars().empty())
    {
        for (size_t i = 0; i < getAuxVars().size(); ++i)
            CMV_DELETE_ARRAY(ppAux[i], bnz_t, pAuxSize[i]);
        delete[] ppAux;
        delete[] pAuxSize;
    }
}

void ZKFileToProgramCCRCompiler::proverP1(CodeCollector& rCC, Sigma& rSigma)
{
    const unsigned commitmentSize = rSigma.getCommitmentSize();
    CMV::bnz_t* pCommitment;
    CMV_NEW_ARRAY(pCommitment, bnz_t, commitmentSize);
    rCC.beginSubProgram(CCodeIdentifiers::_proverP1);
    {
        addOutputVariables(rCC, CCodeIdentifiers::_argCommitment, pCommitment, commitmentSize);
        rSigma.P1();
        rSigma.getCommitment(pCommitment, commitmentSize);
    }
    rCC.endSubProgram(CCodeIdentifiers::_proverP1);
    CMV_DELETE_ARRAY(pCommitment, bnz_t, commitmentSize);
}

void ZKFileToProgramCCRCompiler::proverP2(CodeCollector& rCC, Sigma& rSigma)
{
    const unsigned challengeSize = 1;
    const unsigned responseSize = rSigma.getResponseSize();
    CMV::bnz_t* pChallenge;
    CMV::bnz_t* pResponse;
    CMV_NEW_ARRAY(pChallenge, bnz_t, challengeSize);
    CMV_NEW_ARRAY(pResponse, bnz_t, responseSize);
    rCC.beginSubProgram(CCodeIdentifiers::_proverP2);
    {
        addOutputVariables(rCC, CCodeIdentifiers::_argResponse, pResponse, responseSize);
        addInputVariables(rCC, CCodeIdentifiers::_argChallenge, pChallenge, challengeSize);
        rSigma.setChallenge(pChallenge[0]);
        rSigma.P2();
        rSigma.getResponse(pResponse, responseSize);
    }
    rCC.endSubProgram(CCodeIdentifiers::_proverP2);
    CMV_DELETE_ARRAY(pResponse, bnz_t, responseSize);
    CMV_DELETE_ARRAY(pChallenge, bnz_t, challengeSize);
}

void ZKFileToProgramCCRCompiler::proverFree(CodeCollector& rCC, Parser& rParser, Sigma& rSigma)
{
    rCC.beginSubProgram(CCodeIdentifiers::_proverFree);
    {
        delete &rSigma;
        delete &rParser;
    }
    rCC.endSubProgram(CCodeIdentifiers::_proverFree);
}

void ZKFileToProgramCCRCompiler::verifierInit(CodeCollector& rCC, Parser*& rpParser, Sigma*& rpSigma)
{
    assert(rpParser == NULL);
    assert(rpSigma == NULL);

    unsigned* pPublicCommitmentSize = getPublicCommitmentVars().empty() ? NULL : new unsigned[getPublicCommitmentVars().size()];
    unsigned* pAuxSize = getAuxVars().empty() ? NULL : new unsigned[getAuxVars().size()];
    {
        Parser* pAuxParser = Parser::fromFile(getZKFileName());
        for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
            pPublicCommitmentSize[i] = pAuxParser->getVar(getPublicCommitmentVars()[i].c_str())->getSize();
        for (size_t i = 0; i < getAuxVars().size(); ++i)
            pAuxSize[i] = pAuxParser->getVar(getAuxVars()[i].c_str())->getSize();
        delete pAuxParser;
    }

    CMV::bnz_t** ppPublicCommitment = getPublicCommitmentVars().empty() ? NULL : new CMV::bnz_t*[getPublicCommitmentVars().size()];
    CMV::bnz_t** ppAux = getAuxVars().empty() ? NULL : new CMV::bnz_t*[getAuxVars().size()];
    for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
        CMV_NEW_ARRAY(ppPublicCommitment[i], bnz_t, pPublicCommitmentSize[i]);
    for (size_t i = 0; i < getAuxVars().size(); ++i)
        CMV_NEW_ARRAY(ppAux[i], bnz_t, pAuxSize[i]);
    rCC.beginSubProgram(CCodeIdentifiers::_verifierInit);
    {
        rpParser = Parser::fromFile(getZKFileName());
        for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
        {
            addInputVariables(rCC, (std::string(CCodeIdentifiers::_argPrefixPublicCommitment) + getPublicCommitmentVars()[i]).c_str(),
                ppPublicCommitment[i], pPublicCommitmentSize[i]);
            rpParser->getVar(getPublicCommitmentVars()[i].c_str())->set(ppPublicCommitment[i], pPublicCommitmentSize[i]);
        }
        for (size_t i = 0; i < getAuxVars().size(); ++i)
        {
            addInputVariables(rCC, (std::string(CCodeIdentifiers::_argPrefixAux) + getAuxVars()[i]).c_str(),
                ppAux[i], pAuxSize[i]);
            rpParser->getVar(getAuxVars()[i].c_str())->set(ppAux[i], pAuxSize[i]);
        }
        rpSigma = rpParser->getSigma(getSigma());
    }
    rCC.endSubProgram(CCodeIdentifiers::_verifierInit);
    if (!getPublicCommitmentVars().empty())
    {
        for (size_t i = 0; i < getPublicCommitmentVars().size(); ++i)
            CMV_DELETE_ARRAY(ppPublicCommitment[i], bnz_t, pPublicCommitmentSize[i]);
        delete[] ppPublicCommitment;
        delete[] pPublicCommitmentSize;
    }
    if (!getAuxVars().empty())
    {
        for (size_t i = 0; i < getAuxVars().size(); ++i)
            CMV_DELETE_ARRAY(ppAux[i], bnz_t, pAuxSize[i]);
        delete[] ppAux;
        delete[] pAuxSize;
    }
}

void ZKFileToProgramCCRCompiler::verifierC(CodeCollector& rCC, Sigma& rSigma)
{
    const unsigned challengeSize = 1;
    const unsigned commitmentSize = rSigma.getCommitmentSize();
    CMV::bnz_t* pChallenge;
    CMV::bnz_t* pCommitment;
    CMV_NEW_ARRAY(pChallenge, bnz_t, challengeSize);
    CMV_NEW_ARRAY(pCommitment, bnz_t, commitmentSize);
    rCC.beginSubProgram(CCodeIdentifiers::_verifierC);
    {
        addOutputVariables(rCC, CCodeIdentifiers::_argChallenge, pChallenge, challengeSize);
        addInputVariables(rCC, CCodeIdentifiers::_argCommitment, pCommitment, commitmentSize);
        rSigma.setCommitment(pCommitment, commitmentSize);
        rSigma.genChallenge();
        rSigma.getChallenge(pChallenge[0]);
    }
    rCC.endSubProgram(CCodeIdentifiers::_verifierC);
    CMV_DELETE_ARRAY(pCommitment, bnz_t, commitmentSize);
    CMV_DELETE_ARRAY(pChallenge, bnz_t, challengeSize);
}

void ZKFileToProgramCCRCompiler::verifierV(CodeCollector& rCC, Sigma& rSigma)
{
    if (!isInteractive())
        ZK_HANDLE_ERROR("Compilation of non-interactive protocols not implemented yet!");

    const unsigned verificationSize = 1;
    const unsigned responseSize = rSigma.getResponseSize();
    CMV::zk_bool_t* pVerification;
    CMV::bnz_t* pResponse;
    CMV_NEW_ARRAY(pVerification, zk_bool_t, verificationSize);
    CMV_NEW_ARRAY(pResponse, bnz_t, responseSize);
    rCC.beginSubProgram(CCodeIdentifiers::_verifierV);
    {
        addOutputVariables(rCC, CCodeIdentifiers::_argVerification, pVerification, verificationSize);
        addInputVariables(rCC, CCodeIdentifiers::_argResponse, pResponse, responseSize);
        rSigma.setResponse(pResponse, responseSize);
        pVerification[0] = rSigma.V();
    }
    rCC.endSubProgram(CCodeIdentifiers::_verifierV);
    CMV_DELETE_ARRAY(pResponse, bnz_t, responseSize);
    CMV_DELETE_ARRAY(pVerification, zk_bool_t, verificationSize);
}

void ZKFileToProgramCCRCompiler::verifierFree(CodeCollector& rCC, Parser& rParser, Sigma& rSigma)
{
    rCC.beginSubProgram(CCodeIdentifiers::_verifierFree);
    {
        delete &rSigma;
        delete &rParser;
    }
    rCC.endSubProgram(CCodeIdentifiers::_verifierFree);
}

#endif
