#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef CM_DEBUG_INFO_HPP
#define CM_DEBUG_INFO_HPP

#include <string>

#define CM_CREATE_DEBUG_INFO(message) CodeManagement::DebugInfo(message, __FILE__, __LINE__)

namespace CodeManagement
{
    class AStream;

    class DebugInfo
    {
    public:
        DebugInfo(const std::string& rMessage, const std::string& rFileName, int line);
        virtual ~DebugInfo();

    public:
        const std::string& getMessage() const;
        const std::string& getFileName() const;
        int getLine() const;

    public:
        virtual AStream& outStream(AStream& rStream) const;
        std::string toString() const;
        const char* getShortFileName() const;

    public:
        static void setOutStreamShowFileNameAndLine(bool show = true);
        static bool isOutStreamShowFileNameAndLine();
        static void setOutStreamShortFileName(bool shortFileName = true);
        static bool isOutStreamShortFileName();

    protected:
        std::string _message;
        std::string _fileName;
        int _line;

    private:
        static bool _outStreamShowFileNameAndLine;
        static bool _outStreamShortFileName;

    };

    AStream& operator<<(AStream& rStream, const DebugInfo& rDebugInfo);

}

#endif

#endif
