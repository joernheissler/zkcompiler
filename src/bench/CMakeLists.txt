# benchmark
include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_executable (egov egov.cpp)
DLL_COPY_TO_BINARY_DIR(egov)
target_link_libraries (egov parser zkparser sigma hom element group util hash bignum)
