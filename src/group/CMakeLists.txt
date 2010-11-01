include_directories (${ZKCompiler_SOURCE_DIR}/include) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
set (gi ${ZKCompiler_INCLUDE_DIR}/group)

add_library (group group.cpp   ${gi}/group.hpp
                   z.cpp       ${gi}/z.hpp
                   z_add_n.cpp ${gi}/z_add_n.hpp
                   z_mul_n.cpp ${gi}/z_mul_n.hpp
)
target_link_libraries (group random element util)

set (tests test-group-z test-group-z_add_n test-group-z_mul_n)
foreach(t ${tests})
    add_executable (${t} ${t}.cpp)
    add_test (${t} ${PROJECT_BINARY_DIR}/bin/${t})
    DLL_COPY_TO_BINARY_DIR(${t})
    target_link_libraries (${t} group element bignum util)
endforeach(t)

