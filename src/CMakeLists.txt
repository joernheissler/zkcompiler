set(CodeManagement_INCLUDE_DIR ${ZKCompiler_INCLUDE_DIR}/CodeManagement)
add_subdirectory (CodeManagement)

add_subdirectory (bignum)
add_subdirectory (element)
add_subdirectory (group)
add_subdirectory (hash)
add_subdirectory (hom)
add_subdirectory (parser)
add_subdirectory (random)
add_subdirectory (sigma)
add_subdirectory (util)
add_subdirectory (zkparser)
add_subdirectory (compiler)
add_subdirectory (bench)


# generate static and dynamic libraries for the zero-knowledge compiler
#add_library(zkcompiler SHARED)
#add_library(zkcompiler-static STATIC)

#set_target_properties(zkcompiler-static PROPERTIES OUTPUT_NAME "zkcompiler")
#set_target_properties(zkcompiler-static PROPERTIES PREFIX "lib")

#target_link_libraries (zkcompiler element group hash hom parser random sigma util zkparser bignum)
#target_link_libraries (zkcompiler-static element group hash hom parser random sigma util zkparser bignum)


# benchmark
include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_executable (benchmark benchmark.cpp)
DLL_COPY_TO_BINARY_DIR(benchmark)
target_link_libraries (benchmark parser zkparser sigma hom element group util hash bignum)
