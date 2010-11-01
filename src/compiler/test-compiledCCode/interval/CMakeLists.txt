# interval
include_directories (${ZKCompiler_SOURCE_DIR}/include ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode/interval)
include_directories (${BIGNUM_INCLUDES})
add_executable(test-compiledCCode-interval test-compiledCCode-interval.cpp zk_prover.c zk_verifier.c ../ZKCCodeTester.cpp)
add_test (test-compiledCCode-interval ${PROJECT_BINARY_DIR}/bin/test-compiledCCode-interval)
DLL_COPY_TO_BINARY_DIR(test-compiledCCode-interval)
target_link_libraries(test-compiledCCode-interval random bignum)
