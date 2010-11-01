include_directories (${ZKCompiler_INCLUDE_DIR}) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_library (compiler
    ACCRtoCodeCompiler.cpp ${ZKCompiler_INCLUDE_DIR}/compiler/ACCRtoCodeCompiler.hpp
    AZKProtocol.cpp ${ZKCompiler_INCLUDE_DIR}/compiler/AZKProtocol.hpp
    CCodeIdentifiers.cpp ${ZKCompiler_INCLUDE_DIR}/compiler/CCodeIdentifiers.hpp
    ProgramCCRtoCCodeCompiler.cpp ${ZKCompiler_INCLUDE_DIR}/compiler/ProgramCCRtoCCodeCompiler.hpp
    ZKFileToProgramCCRCompiler.cpp ${ZKCompiler_INCLUDE_DIR}/compiler/ZKFileToProgramCCRCompiler.hpp
    ZKProgramCCRTester.cpp ${ZKCompiler_INCLUDE_DIR}/compiler/ZKProgramCCRTester.hpp
)

target_link_libraries (compiler CodeManagement random bignum)

IF (COMPILER)
    # These tests compile c-code, that is written to the tests in test-compiledCCode.
    # FIXME: The tests in test-compiledCCode have to use actual code, that is output of the following tests.
    # Currently the compiled c-code will be tested only in the next run of the test-suite,
    # so we have to run the testuite once then rebuild with new compiled c-code and after that run the test-suite once again... ugly!

    # phi
    include_directories (${ZKCompiler_SOURCE_DIR}/include) 
    add_executable(test-compile-phi test-compile-phi.cpp)
    add_test (test-compile-phi ${PROJECT_BINARY_DIR}/bin/test-compile-phi ${ZKCompiler_SOURCE_DIR}/src/parser/test-parserPhi.zk ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode/phi)
    DLL_COPY_TO_BINARY_DIR(test-compile-phi)
    target_link_libraries(test-compile-phi compiler CodeManagement parser zkparser sigma hom element group util hash bignum)
    
    # and
    include_directories (${ZKCompiler_SOURCE_DIR}/include) 
    add_executable(test-compile-and test-compile-and.cpp)
    add_test (test-compile-and ${PROJECT_BINARY_DIR}/bin/test-compile-and ${ZKCompiler_SOURCE_DIR}/src/parser/test-parserAnd.zk ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode/and)
    DLL_COPY_TO_BINARY_DIR(test-compile-and)
    target_link_libraries(test-compile-and compiler CodeManagement parser zkparser sigma hom element group util hash bignum)

    # interval
    include_directories (${ZKCompiler_SOURCE_DIR}/include)
    add_executable(test-compile-interval test-compile-interval.cpp)
    add_test (test-compile-interval ${PROJECT_BINARY_DIR}/bin/test-compile-interval ${ZKCompiler_SOURCE_DIR}/src/parser/test-parserIntervall.zk ${ZKCompiler_SOURCE_DIR}/src/compiler/test-compiledCCode/interval)
    DLL_COPY_TO_BINARY_DIR(test-compile-interval)
    target_link_libraries(test-compile-interval compiler CodeManagement parser zkparser sigma hom element group util hash bignum)    
ENDIF (COMPILER)

# Tests for compiled c-code
# We add these tests also in non-compiler mode -- just for fun!
add_subdirectory(test-compiledCCode)
