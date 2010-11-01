#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#ifndef ZK_A_CCR_TO_CODE_COMPILER_HPP
#define ZK_A_CCR_TO_CODE_COMPILER_HPP

#include <cassert>
#include <string>
#include "CodeManagement/ccr/ACCRVisitor.hpp"
#include "CodeManagement/misc/stream/impl/NullStream.hpp"

namespace ZKCompiler
{

    class ACCRtoCodeCompiler : protected CodeManagement::ACCRVisitor
    {
    protected:
        ACCRtoCodeCompiler();

    public:
        ~ACCRtoCodeCompiler();

    public:
        bool isShowDebugInfo();
        void setShowDebugInfo(bool show = true);
        void setIndentString(const std::string& rIndent = "    ");
        void setEndLineString(const std::string& rEndLine = "\n");

    protected:
        void setCodeStream(CodeManagement::AStream* pStream);
        CodeManagement::AStream& out();
        CodeManagement::AStream& out(CodeManagement::AStream* pTempStream);
        CodeManagement::AStream& indentLineOut();
        CodeManagement::AStream& indentLineOut(CodeManagement::AStream* pTempStream);
        void clearLineIndent();
        void increaseLineIndent();
        void decreaseLineIndent();
        size_t curLineIndentCount() const;
        std::string indent() const;
        std::string lineIndent() const;
        std::string endLine() const;
        std::string endLine(size_t number) const;

    private:
        bool _showDebugInfo;
        CodeManagement::AStream* _pCodeStream;
        std::string _endLineString;
        std::string _indentString;
        std::string _curLineIndentString;
    };


    inline bool ACCRtoCodeCompiler::isShowDebugInfo()
    {
        return _showDebugInfo;
    }

    inline void ACCRtoCodeCompiler::setShowDebugInfo(bool show)
    {
        _showDebugInfo = show;
    }

    inline void ACCRtoCodeCompiler::setIndentString(const std::string& rIndent)
    {
        _indentString = rIndent;
    }

    inline void ACCRtoCodeCompiler::setEndLineString(const std::string& rEndLine)
    {
        _endLineString = rEndLine;
    }

    inline void ACCRtoCodeCompiler::setCodeStream(CodeManagement::AStream* pStream)
    {
        _pCodeStream = pStream;
    }

    inline CodeManagement::AStream& ACCRtoCodeCompiler::out()
    {
        if (_pCodeStream != NULL)
            return *_pCodeStream;
        return CodeManagement::NullStream::log;
    }

    inline CodeManagement::AStream& ACCRtoCodeCompiler::out(CodeManagement::AStream* pTempStream)
    {
        if (pTempStream != NULL)
            return *pTempStream;
        return CodeManagement::NullStream::log;
    }

    inline CodeManagement::AStream& ACCRtoCodeCompiler::indentLineOut()
    {
        return out() << _curLineIndentString;
    }

    inline CodeManagement::AStream& ACCRtoCodeCompiler::indentLineOut(CodeManagement::AStream* pTempStream)
    {
        return out(pTempStream) << _curLineIndentString;
    }

    inline void ACCRtoCodeCompiler::clearLineIndent()
    {
        _curLineIndentString = "";
    }

    inline void ACCRtoCodeCompiler::increaseLineIndent()
    {
        _curLineIndentString += indent();
    }

    inline void ACCRtoCodeCompiler::decreaseLineIndent()
    {
        assert(_curLineIndentString.length() >= _indentString.length());
        _curLineIndentString.resize(_curLineIndentString.length() - _indentString.length());
    }

    inline size_t ACCRtoCodeCompiler::curLineIndentCount() const
    {
        return _curLineIndentString.length() / _indentString.length();
    }

    inline std::string ACCRtoCodeCompiler::indent() const
    {
        return _indentString;
    }

    inline std::string ACCRtoCodeCompiler::lineIndent() const
    {
        return _curLineIndentString;
    }

    inline std::string ACCRtoCodeCompiler::endLine() const
    {
        return _endLineString;
    }

}

#endif

#endif
