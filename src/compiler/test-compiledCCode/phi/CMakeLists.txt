# phi
include_directories (${ZKCompiler_SOURCE_DIR}/include ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode/phi)
include_directories (${BIGNUM_INCLUDES})
add_executable(test-compiledCCode-phi test-compiledCCode-phi.cpp zk_prover.c zk_verifier.c ../ZKCCodeTester.cpp)
add_test (test-compiledCCode-phi ${PROJECT_BINARY_DIR}/bin/test-compiledCCode-phi)
DLL_COPY_TO_BINARY_DIR(test-compiledCCode-phi)
target_link_libraries(test-compiledCCode-phi random bignum)