# The name of our project is "ZKCompiler". CMakeLists files in this project can
# refer to the root source directory of the project as ${ZKCompiler_SOURCE_DIR} and
# to the root binary directory of the project as ${ZKCompiler_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8)
project (ZKCompiler)
set(CMAKE_PROJECT_VERSION "0.1")

# Use GMP as bignum library
set(USED_BIGNUM_LIB "GMP")

# optional gcov support for linux
option(GCOV "Build with gcov support" off)

# optional MPIR support for linux
option(MPIR "Build with MPIR support" off)

# enable code collecting for compiling
option(COMPILER "Build for compiling zk-protocols" off)

# testing for windows x64 build
IF (${CMAKE_GENERATOR} MATCHES "Win64")
    set(WIN64 on)
ENDIF ()

# Use Doxygen for documentation (-> CMake module from http://tobias.rautenkranz.ch/cmake/doxygen/)
option(DOXYGEN "Generate Doxygen documentation" off)
# switch Doxygen support automatically on for non-windows build
IF (NOT WIN32 AND NOT WIN64)
  SET(DOXYGEN on)
ENDIF ()
IF (DOXYGEN)
    set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    include(UseDoxygen OPTIONAL)
ENDIF (DOXYGEN)

# Setup compiler options
IF (MSVC)
    # switch Visual Studio multi-processor compilation on
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} /MP")

#    # statically link to the C/C++ runtime, we don't want to get nasty DLL errors
#    # C
#    if (${CMAKE_C_FLAGS_DEBUG} MATCHES "/MDd")
#      STRING(REGEX REPLACE "/MDd" "/MTd" CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
#    else ()
#      set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} /MTd")
#    endif ()
#    if (${CMAKE_C_FLAGS_RELEASE} MATCHES "/MD")
#      STRING(REGEX REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
#    else ()
#      set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /MT")
#    endif ()
#    # C++
#    if (${CMAKE_CXX_FLAGS_DEBUG} MATCHES "/MDd")
#      STRING(REGEX REPLACE "/MDd" "/MTd" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
#    else ()
#      set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
#    endif ()
#    if (${CMAKE_CXX_FLAGS_RELEASE} MATCHES "/MD")
#      STRING(REGEX REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
#    else ()
#      set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
#    endif ()
ELSE (MSVC)
    # usually linux builds
    set(GCC_WARNINGS "-Wall -Wextra -pedantic -Wconversion -Wshadow -Wformat=2 -Winit-self -Wswitch-enum -Wlogical-op")
    IF (GCOV)
        # compile with extra stuff for gcov (-> for determining coverage)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -O0 -ggdb3 ${GCC_WARNINGS} -g -W -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual -Wwrite-strings -fprofile-arcs -ftest-coverage")
        set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -std=c89 -O0 -ggdb3 ${GCC_WARNINGS} -g -W -fprofile-arcs -ftest-coverage")
        set(CMAKE_LD_FLAGS  "${CMAKE_LD_FLAGS} -fprofile-arcs -ftest-coverage")
    ELSE ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -O0 -ggdb3 ${GCC_WARNINGS}")
        set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -std=c89   -O0 -ggdb3 ${GCC_WARNINGS}")
        set(CMAKE_LD_FLAGS  "${CMAKE_LD_FLAGS}")
    ENDIF (GCOV)
ENDIF (MSVC)


# Setup compiler option
IF (COMPILER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCM_ENABLE_CODE_COLLECTING")
ENDIF (COMPILER)

# Specify available build types, relevant for windows builds
SET (BUILD_TYPES Debug Release MinSizeRel RelWithDebInfo)

# Setup path to selected bignum library
IF (${USED_BIGNUM_LIB} MATCHES "GMP")
    # set up GMP as bignum library
    set (BIGNUM_IMPL bignum_gmp.cpp)
    
    IF (WIN64)
    	FIND_PATH(BIGNUM_INCLUDES gmp.h
                  ${PROJECT_SOURCE_DIR}/extern/MPIR/win64/include)
    
        FIND_LIBRARY(BIGNUM_LIBRARY
                     NAMES mpir "libmpirx64-2.1.1.dll"
                     PATHS ${PROJECT_SOURCE_DIR}/extern/MPIR/win64/lib)
        set(BIGNUM_LIBRARY_DLL ${PROJECT_SOURCE_DIR}/extern/MPIR/win64/lib/libmpirx64-2.1.1.dll.dll)
    ELSEIF (WIN32)
    	FIND_PATH(BIGNUM_INCLUDES gmp.h
                  ${PROJECT_SOURCE_DIR}/extern/MPIR/win32/include)
        FIND_LIBRARY(BIGNUM_LIBRARY
                     NAMES mpir "libmpir-2.1.1.dll"
                     PATHS ${PROJECT_SOURCE_DIR}/extern/MPIR/win32/lib)
        set(BIGNUM_LIBRARY_DLL ${PROJECT_SOURCE_DIR}/extern/MPIR/win32/lib/libmpir-2.1.1.dll.dll)
    ELSE (WIN64)
        # usually linux builds
    	FIND_PATH(BIGNUM_INCLUDES gmp.h
                  /usr/local/include)
        IF (MPIR)
            FIND_LIBRARY(BIGNUM_LIBRARY
                         mpir
                         /usr/local/lib)
        ELSE (MPIR)
            FIND_LIBRARY(BIGNUM_LIBRARY
                         gmp
                         /usr/local/lib)
        ENDIF (MPIR)
    ENDIF (WIN64)
ENDIF (${USED_BIGNUM_LIB} MATCHES "GMP")

# Copy DLL files to executable output directory (in windows)
macro (DLL_COPY_TO_BINARY_DIR target)
    IF (WIN32 OR WIN64)
        # copy the target library DLL in each build directory
        foreach(bt ${BUILD_TYPES})
            FILE(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${bt})
            ADD_CUSTOM_COMMAND(TARGET ${target} POST_BUILD
                               COMMAND ${CMAKE_COMMAND} -E copy
                               ARGS ${BIGNUM_LIBRARY_DLL} ${PROJECT_BINARY_DIR}/bin/${bt}/)
        endforeach(bt)
    ENDIF (WIN32 OR WIN64)
endmacro (DLL_COPY_TO_BINARY_DIR)

# Setup include directories
set(ZKCompiler_INCLUDE_DIR "${ZKCompiler_SOURCE_DIR}/include")

# Setup output Directories
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all Libraries")
# Setup the Executable output Directory
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Single Directory for all Executables.")

find_package(BISON)

ENABLE_TESTING()
# including the standard Dart testing module
INCLUDE(CTest)

# Recurse into the "src" subdirectory. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (src)
