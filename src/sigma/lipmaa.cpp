#include "sigma/lipmaa.hpp"
#include "util/errorhandling.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    namespace sigma {

        Lipmaa::Lipmaa(Parser */*p*/, unsigned int n, char *const /*params*/[])
        {
            if (n != 6) ZK_HANDLE_ERROR("ERROR: Invalid number of parameters!");
        }

        Lipmaa::~Lipmaa()
        {
        }

        void Lipmaa::P1()
        {
        }

        void Lipmaa::P2()
        {
        }

        CMV::zk_bool_t Lipmaa::V(bool /*interactive*/)
        {
            return CMV_IN(false);
        }
                
        void Lipmaa::S()
        {
        }

        void Lipmaa::R()
        {
        }

        bool Lipmaa::simulationNeeded()
        {
            return false;
        }

        Message Lipmaa::getCommitment()
        {
        return Convert::mpztToMessage(0, 0);
        }

        Message Lipmaa::getResponse()
        {
        return Convert::mpztToMessage(0, 0);
        }

        Message Lipmaa::getPublic()
        {
        return Convert::mpztToMessage(0, 0);
        }

        Message Lipmaa::getAuxCommitment()
        {
        return Convert::mpztToMessage(0, 0);
        }

        void Lipmaa::setCommitment(Message /*msg*/)
        {
        }

        void Lipmaa::setResponse(Message /*msg*/)
        {
        }

        void Lipmaa::setAuxCommitment(Message /*msg*/)
        {
        }
        
        /* FIXME */
        unsigned Lipmaa::getCommitmentSize() const
        {
            return 0;
        }
        void Lipmaa::getCommitmentPtrs(const CMV::bnz_t* /*vpDst*/[], unsigned /*n*/) const {}
        void Lipmaa::setCommitment(const CMV::bnz_t* /*vpSrc*/[], unsigned /*n*/) {}
        unsigned Lipmaa::getResponseSize() const
        {
            return 0;
        }
        void Lipmaa::getResponsePtrs(const CMV::bnz_t* /*vpDst*/[], unsigned /*n*/) const {}
        void Lipmaa::setResponse(const CMV::bnz_t* /*vpSrc*/[], unsigned /*n*/) {}
    }
}

