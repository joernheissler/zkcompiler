include_directories (${ZKCompiler_SOURCE_DIR}/include)
include_directories (${ZKCompiler_SOURCE_DIR}/include/CodeManagement) 
include_directories (${BIGNUM_INCLUDES})
add_library (bignum bignum.cpp ${BIGNUM_IMPL} ${ZKCompiler_INCLUDE_DIR}/bignum/bignum.hpp)
target_link_libraries(bignum ${BIGNUM_LIBRARY} CodeManagement)
#TODO: right linking of CodeManagement! here it is not needed, it's just easier to put it here because everything is depending on bignum...