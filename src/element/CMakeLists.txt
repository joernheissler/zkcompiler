include_directories (${ZKCompiler_INCLUDE_DIR}) 
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
add_library (element
    element.cpp ${ZKCompiler_INCLUDE_DIR}/element/element.hpp
    atomic.cpp  ${ZKCompiler_INCLUDE_DIR}/element/atomic.hpp
    tuple.cpp   ${ZKCompiler_INCLUDE_DIR}/element/tuple.hpp
)

target_link_libraries (element util hom)
