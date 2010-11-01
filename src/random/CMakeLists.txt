include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 

IF (WIN32)
	add_library (random random.cpp seedWIN.c   ${ZKCompiler_INCLUDE_DIR}/random/random.hpp ${ZKCompiler_INCLUDE_DIR}/random/random_seed.h)
ELSE (WIN32)
	add_library (random random.cpp seedLinux.c ${ZKCompiler_INCLUDE_DIR}/random/random.hpp ${ZKCompiler_INCLUDE_DIR}/random/random_seed.h)
ENDIF (WIN32)

target_link_libraries (random bignum util)

add_executable (test-random test-random.cpp)
add_test (test-random ${PROJECT_BINARY_DIR}/bin/test-random)
DLL_COPY_TO_BINARY_DIR(test-random)
target_link_libraries (test-random random bignum)
