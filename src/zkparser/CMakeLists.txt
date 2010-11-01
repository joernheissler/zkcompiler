include_directories (${ZKCompiler_SOURCE_DIR}/include)
include_directories (${CMAKE_CURRENT_BINARY_DIR})

BISON_TARGET(ZKParserGrammar zkparser_grammar.y ${CMAKE_CURRENT_BINARY_DIR}/zkparser_grammar.c COMPILE_FLAGS "-p zk")

add_library (zkparser zkparser.c ${ZKCompiler_INCLUDE_DIR}/zkparser/zkparser.h)
SET_SOURCE_FILES_PROPERTIES(zkparser.c OBJECT_DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/zkparser_grammar.c)
