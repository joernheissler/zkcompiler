include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_library (hom hom.cpp ${ZKCompiler_INCLUDE_DIR}/hom/hom.hpp)

add_executable (test-hom test-hom.cpp)
add_test (test-hom ${PROJECT_BINARY_DIR}/bin/test-hom)
DLL_COPY_TO_BINARY_DIR(test-hom)
target_link_libraries (test-hom parser zkparser sigma hom element group util hash bignum CodeManagement)

add_executable (test-hom2 test-hom2.cpp)
add_test (test-hom2 ${PROJECT_BINARY_DIR}/bin/test-hom2)
DLL_COPY_TO_BINARY_DIR(test-hom2)
target_link_libraries (test-hom2 parser zkparser sigma hom element group util hash bignum CodeManagement)

