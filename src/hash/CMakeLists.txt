include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_library (hash hash.cpp sha1.cpp ${ZKCompiler_INCLUDE_DIR}/hash/hash.hpp ${ZKCompiler_INCLUDE_DIR}/hash/sha1.hpp)

add_executable (test-sha1 test-sha1.cpp)
add_test (test-sha1 ${PROJECT_BINARY_DIR}/bin/test-sha1)
target_link_libraries (test-sha1 hash util)
