# and
include_directories (${ZKCompiler_SOURCE_DIR}/include ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode/and)
include_directories (${BIGNUM_INCLUDES})
add_executable(test-compiledCCode-and test-compiledCCode-and.cpp zk_prover.c zk_verifier.c ../ZKCCodeTester.cpp)
add_test (test-compiledCCode-and ${PROJECT_BINARY_DIR}/bin/test-compiledCCode-and)
DLL_COPY_TO_BINARY_DIR(test-compiledCCode-and)
target_link_libraries(test-compiledCCode-and random bignum)