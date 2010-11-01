#include <climits>
#include <cstring>

#include "random/random.hpp"
#include "sigma/sigma.hpp"

#include "sigma/phi.hpp"
#include "sigma/and.hpp"
#include "sigma/or.hpp"
#include "sigma/gsp.hpp"
#include "sigma/lipmaa.hpp"
//#include "sigma/exp.hpp"
#include "util/errorhandling.hpp"

#ifdef CM_ENABLE_CODE_COLLECTING
    // TODO: CM... remove, as soon as not needed...
    #include "CodeManagement/misc/debug/impl/Exception.hpp"
#endif

using namespace ZKCompiler::sigma;
CMO_USING_OPERATORS;

namespace ZKCompiler {
    /* Sigma factory */
    Sigma *Sigma::create(Parser *parser, const char *type, unsigned n, char *const params[])
    {
        if(!strcmp(type, "SigmaPhi")) return new sigma::Phi(parser, n, params);
        if(!strcmp(type, "SigmaGsp")) return new sigma::Gsp(parser, n, params);
//      if(!strcmp(type, "SigmaExp")) return new sigma::Exp(parser, n, params);
        if(!strcmp(type, "SigmaAND")) return new sigma::And(parser, n, params);
#ifndef CM_ENABLE_CODE_COLLECTING
        if(!strcmp(type, "SigmaOR" )) return new sigma::Or (parser, n, params);
#endif
        if(!strcmp(type, "SigmaLipmaa" )) return new sigma::Lipmaa(parser, n, params);

        ZK_HANDLE_ERROR("unknown sigma protocol");
        return NULL;
    }

    Sigma::Sigma() : CMV_CONSTRUCT(cplus),  CMV_CONSTRUCT(c)
    {
        CMI(bnz_init(cplus));
        CMI(bnz_init_set_si(c, CMV_IN(-1l)));
    }

    Sigma::~Sigma()
    {
        CMI(bnz_clear(cplus));
        CMI(bnz_clear(c));
    }

    CMV::zk_bool_t Sigma::V()
    {
        return V(true);
    }

    void Sigma::genChallenge()
    {
        CMV(bnz_t c_);
        CMM_IF(!CMI(bnz_cmp_ui(cplus, CMV_IN(0ul))))
            ZK_CMI_HANDLE_ERROR_CMV_IN("cplus not set");
        CMM_ENDIF
        CMI(bnz_init(c_));

        CMI(Random::range0(c_, cplus));

        setChallenge(c_);
        CMI(bnz_clear(c_));
    }

    void Sigma::setChallenge(const CMV::bnz_t& c_)
    {
        CMM_IF(CMI(bnz_cmp(c_, cplus)) >= CMV_IN(0))
            ZK_CMI_HANDLE_ERROR_CMV_IN("c must be smaller than cplus");
        CMM_ENDIF
        CMM_IF(CMI(bnz_cmp_ui(c_, CMV_IN(0ul))) < CMV_IN(0))
            ZK_CMI_HANDLE_ERROR_CMV_IN("c must not be negative");
        CMM_ENDIF
        CMI(bnz_set(c, c_));
    }

    void Sigma::setChallenge(Message msg)
    {
        if (!CMM_IS_EXECUTING)
            ZK_HANDLE_ERROR("Sigma::setChallenge(Message) is not allowed to be called in not executed code regions when code is collecting!");
        CMM_COMMENT("WARNING: Sigma::setChallenge(Message) called in compiler mode!\n"
            "You CAN NOT collect the structure Message currently! Use it only for testing.\n"
            "If you want to collect code, the getter/setter with CMV::bnz_t-types...");
        bnz_t c_;
        bnz_init(c_);
        Convert::messageToMpzt(msg, c_);
        setChallenge(CMV_IN(c_));
        bnz_clear(c_);
    }

    void Sigma::getChallenge(CMV::bnz_t& c_)
    {
        CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0))
            ZK_CMI_HANDLE_ERROR_CMV_IN("challenge not set");
        CMM_ENDIF
        CMI(bnz_set(c_, c));
    }

    const CMV::bnz_t& Sigma::getChallenge() const
    {
        CMM_IF(CMI(bnz_cmp_ui(c, CMV_IN(0ul))) < CMV_IN(0))
            ZK_CMI_HANDLE_ERROR_CMV_IN("challenge not set");
        CMM_ENDIF
        return c;
    }

    Message Sigma::getChallenge()
    {
        if (!CMM_IS_EXECUTING)
            ZK_HANDLE_ERROR("Message Sigma::getChallenge() is not allowed to be called in not executed code regions when code is collecting!");
        CMM_COMMENT("WARNING: Message Sigma::getChallenge() called in compiler mode!\n"
            "You CAN NOT collect the structure Message currently! Use it only for testing.\n"
            "If you want to collect code, use the getter/setter with CMV::bnz_t-types...");
        if (bnz_cmp_ui(CMV_OUT(c), 0) < 0)
            ZK_HANDLE_ERROR("challenge not set");
        return Convert::mpztToMessage(CMV_OUT(c));
    }

    void Sigma::getCommitment(CMV::bnz_t vDst[], unsigned n) const
    {
        CMV::bnz_t const** ppDst = new CMV::bnz_t const*[n];
        getCommitmentPtrs(ppDst, n);
        for (unsigned i = 0; i < n; ++i)
            CMI(bnz_set(vDst[i], *ppDst[i]));
        delete[] ppDst;
    }

    void Sigma::getResponse(CMV::bnz_t vDst[], unsigned n) const
    {
        CMV::bnz_t const** ppDst = new CMV::bnz_t const*[n];
        getResponsePtrs(ppDst, n);
        for (unsigned i = 0; i < n; ++i)
            CMI(bnz_set(vDst[i], *ppDst[i]));
        delete[] ppDst;
    }

    void Sigma::getCPlus(CMV::bnz_t& cplus_)
    {
        CMI(bnz_set(cplus_, cplus));
    }

    void Sigma::setCPlus(const CMV::bnz_t& cplus_)
    {
        CMM_IF(CMI(bnz_cmp_ui(cplus_, CMV_IN(0ul))) < CMV_IN(0))
            ZK_CMI_HANDLE_ERROR_CMV_IN("cplus must not be negative");
        CMM_ENDIF
        CMI(bnz_set(cplus, cplus_));
    }

    void Sigma::setAuxCommitment(Message msg)
    {
        /* check if message is zero sized */
        Convert::messageToMpzt(msg, 0, 0);
    }

    Message Sigma::getAuxCommitment()
    {
        /* return zero sized message */
        return Convert::mpztToMessage(0, 0);
    }

    void Sigma::setCommitment(const CMV::bnz_t vSrc[], unsigned n)
    {
        CMV::bnz_t const** ppSrc = new CMV::bnz_t const*[n];
        for (unsigned i = 0; i < n; ++i)
            ppSrc[i] = &vSrc[i];
        setCommitment(ppSrc, n);
        delete[] ppSrc;
    }

    void Sigma::setResponse(const CMV::bnz_t vSrc[], unsigned n)
    {
        CMV::bnz_t const** ppSrc = new CMV::bnz_t const*[n];
        for (unsigned i = 0; i < n; ++i)
            ppSrc[i] = &vSrc[i];
        setResponse(ppSrc, n);
        delete[] ppSrc;
    }

    Message Sigma::sign(Hash *h)
    {
#ifdef CM_ENABLE_CODE_COLLECTING
            // TODO: CM...
            throw CM_CREATE_EXCEPTION("Not implemented yet for CM: Message Sigma::sign(Hash *h)");
            (void)h;
#else
        Message msg[3], m;
        bnz_t ch;

        bnz_init(ch);

        /* set cplus to size of hash output */
        bnz_ui_pow_ui(ch, 2, h->getSize() * 8u);
        setCPlus(ch);

        /* call signer's P1 function */
        P1();

        /* set m = (x, r) */
        msg[0] = getPublic();
        msg[1] = getCommitment();
        m = Convert::messagesToMessage(msg, 2);

        /* compute H(x, r) */
        h->reset();
        h->update((void *)m.data, m.length, 0);

        /* clean up */
        delete[] m.data;
        delete[] msg[0].data;
        delete[] msg[1].data;

        /* set ch = H(x, r) */
        bnz_import(ch, h->getSize(), 1, 1, 1, CHAR_BIT - 8, h->final());

        /* set challenge ch and call signer's P2 function */
        setChallenge(ch);
        P2();

        /* set m = (t, c, s) */
        msg[0] = getAuxCommitment();
        msg[1] = Convert::mpztToMessage(ch);
        msg[2] = getResponse();
        m = Convert::messagesToMessage(msg, 3);

        /* clean up */
        delete[] msg[0].data;
        delete[] msg[1].data;
        delete[] msg[2].data;
        bnz_clear(ch);

        /* return (c, s) */
        return m;
#endif
    }

    bool Sigma::verify(Hash *h, Message sig)
    {
#ifdef CM_ENABLE_CODE_COLLECTING
            // TODO: CM...
            throw CM_CREATE_EXCEPTION("Not implemented yet for CM: bool Sigma::verify(Hash *h, Message sig)");
            (void)h;
            (void)sig;
#else
        bool ret;
        Message msg[3], m;
        bnz_t ch, c2;

        bnz_init(ch);
        bnz_init(c2);

        /* set cplus to size of hash output */
        bnz_ui_pow_ui(ch, 2, h->getSize() * 8u);
        setCPlus(ch);

        /* msg = (c, s) */
        Convert::messageToMessages(sig, msg, 3, 0);
        Convert::messageToMpzt(msg[1], ch);

        /* set verifier's (t, c, s), verify that s is okay and call r = R(c, s) */
        setAuxCommitment(msg[0]);
        setChallenge(ch);
        setResponse(msg[2]);
        if(V(false) == false) {
            ret = false;
            goto out;
        }
        R();

        /* set m = (x, r) */
        msg[0] = getPublic();
        msg[1] = getCommitment();
        m = Convert::messagesToMessage(msg, 2);

        /* compute H(x, r) */
        h->reset();
        h->update((void *)m.data, m.length, 0);

        /* clean up */
        delete[] m.data;
        delete[] msg[0].data;
        delete[] msg[1].data;

        /* set c2 = H(x, r) */
        bnz_import(c2, h->getSize(), 1, 1, 1, CHAR_BIT - 8, h->final());

        /* verify if ch == c2 */
        if(!bnz_cmp(ch, c2)) {
            ret = true;
        } else {
            ret = false;
        }

out:    /* clean up */
        bnz_clear(ch);
        bnz_clear(c2);

        /* return true iff signature was correct */
        return ret;
#endif
    }
}
