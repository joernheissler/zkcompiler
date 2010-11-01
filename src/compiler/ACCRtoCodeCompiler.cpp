#ifndef DOXYGEN_SHOULD_SKIP_THIS
// TODO: doxygen documentation...

#include "compiler/ACCRtoCodeCompiler.hpp"

using namespace ZKCompiler;
using namespace CodeManagement;

ACCRtoCodeCompiler::ACCRtoCodeCompiler() :
    _showDebugInfo(false), _pCodeStream(NULL)
{
    setIndentString();
    setEndLineString();
}

ACCRtoCodeCompiler::~ACCRtoCodeCompiler()
{
    assert(_pCodeStream == NULL);
}

std::string ACCRtoCodeCompiler::endLine(size_t number) const
{
    std::string endLines = "";
    for (size_t i = 0; i < number; ++i)
        endLines += endLine();
    return endLines;;
}

#endif
