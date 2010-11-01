include_directories (${ZKCompiler_SOURCE_DIR}/include)
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
set (inc ${ZKCompiler_INCLUDE_DIR}/util)
add_library (util basictypes.cpp convert.cpp errorhandling.cpp foursquares.cpp zkprint.cpp
    ${inc}/basictypes.hpp ${inc}/convert.hpp ${inc}/errorhandling.hpp ${inc}/foursquares.hpp ${inc}/zkprint.hpp)

foreach (t test-convert0 test-convert1 test-convert2 test-foursquares)
    add_executable (${t} ${t}.cpp)
    add_test (${t} ${PROJECT_BINARY_DIR}/bin/${t})
    DLL_COPY_TO_BINARY_DIR(${t})
    target_link_libraries (${t} util random bignum)
endforeach(t)
