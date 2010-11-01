#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_FILE_STREAM_HPP
#define CM_FILE_STREAM_HPP

#include <cstdio>
#include "misc/stream/AStream.hpp"

namespace CodeManagement
{

    class FileStream : public AStream
    {
    public:
        explicit FileStream(const char* pFileName = NULL);
        virtual ~FileStream();

    public:
        void open(const char* pFileName);
        void close();
        bool isOpen() const;

    public:
        virtual AStream& operator<<(bool b);
        virtual AStream& operator<<(char c);
        virtual AStream& operator<<(int d);
        virtual AStream& operator<<(unsigned u);
        virtual AStream& operator<<(long ld);
        virtual AStream& operator<<(unsigned long lu);
        virtual AStream& operator<<(const char* pStr);
        virtual AStream& operator<<(const std::string& rStr);

    private:
        FILE* _pFile;
    };

}

#endif

#endif
