#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "compiler/AZKProtocol.hpp"

using namespace ZKCompiler;

AZKProtocol::AZKProtocol(const char* pZKFileName, const char* pIdentSigma, bool interactive) :
    _zkFileName(pZKFileName), _identSigma(pIdentSigma), _interactive(interactive)
{
}

AZKProtocol::AZKProtocol(const AZKProtocol& rToCopy)
{
    copyParameters(rToCopy);
}

AZKProtocol::~AZKProtocol()
{
}

void AZKProtocol::copyParameters(const AZKProtocol& rToApply)
{
    setZKFileName(rToApply.getZKFileName());
    setSigma(rToApply.getSigma());
    getSecretVars() = rToApply.getSecretVars();
    getPublicCommitmentVars() = rToApply.getPublicCommitmentVars();
    getAuxVars() = rToApply.getAuxVars();
    setInteractive(rToApply.isInteractive());
}

void AZKProtocol::setZKFileName(const char* pFileName)
{
    _zkFileName = pFileName;
}

const char* AZKProtocol::getZKFileName() const
{
    return _zkFileName.c_str();
}

void AZKProtocol::setSigma(const char* pIdent)
{
    _identSigma = pIdent;
}

const char* AZKProtocol::getSigma() const
{
    return _identSigma.c_str();
}

const AZKProtocol::Identifiers_t& AZKProtocol::getSecretVars() const
{
    return _identsVarsSecret;
}

AZKProtocol::Identifiers_t& AZKProtocol::getSecretVars()
{
    return _identsVarsSecret;
}

const AZKProtocol::Identifiers_t& AZKProtocol::getPublicCommitmentVars() const
{
    return _identsVarsPublicCommitment;
}

AZKProtocol::Identifiers_t& AZKProtocol::getPublicCommitmentVars()
{
    return _identsVarsPublicCommitment;
}

const AZKProtocol::Identifiers_t& AZKProtocol::getAuxVars() const
{
    return _identsVarsAux;
}

AZKProtocol::Identifiers_t& AZKProtocol::getAuxVars()
{
    return _identsVarsAux;
}

void AZKProtocol::setInteractive(bool interactive)
{
    _interactive = interactive;
}

bool AZKProtocol::isInteractive() const
{
    return _interactive;
}

#endif
