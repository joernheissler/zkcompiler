include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_library (sigma sigma.cpp ${ZKCompiler_INCLUDE_DIR}/sigma/sigma.hpp
                   phi.cpp   ${ZKCompiler_INCLUDE_DIR}/sigma/phi.hpp
                   gsp.cpp   ${ZKCompiler_INCLUDE_DIR}/sigma/gsp.hpp
#                  exp.cpp   ${ZKCompiler_INCLUDE_DIR}/sigma/exp.hpp
                   and.cpp   ${ZKCompiler_INCLUDE_DIR}/sigma/and.hpp
                   or.cpp    ${ZKCompiler_INCLUDE_DIR}/sigma/or.hpp
                   lipmaa.cpp ${ZKCompiler_INCLUDE_DIR}/sigma/lipmaa.hpp
)

## define targets for testing
#set (SIGMA_TARGETS SigmaPhi SigmaGsp SigmaExp SigmaAND SigmaANDgsp SigmaOR SigmaORgsp)
#
## configure each target, copy bignum library to output directory
#foreach(t ${SIGMA_TARGETS})
#	add_executable (test-${t} ${t}-test.cpp)
#	add_test (test-${t} ${PROJECT_BINARY_DIR}/bin/test-${t}) 
#	DLL_COPY_TO_BINARY_DIR(test-${t})
#endforeach(t)
#
#target_link_libraries (test-SigmaPhi element group hom sigma random util hash parser zkparser bignum)
#target_link_libraries (test-SigmaGsp element group hom sigma random util hash parser zkparser bignum)
#target_link_libraries (test-SigmaExp element group hom sigma random util hash parser zkparser bignum)
#target_link_libraries (test-SigmaAND element group hom sigma random util hash parser zkparser bignum)
#target_link_libraries (test-SigmaANDgsp element group hom sigma random util hash parser zkparser bignum)
#target_link_libraries (test-SigmaOR element group hom sigma random util hash parser zkparser bignum)
#target_link_libraries (test-SigmaORgsp element group hom sigma random util hash parser zkparser bignum)
