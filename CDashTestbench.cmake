# Options:
# operating system (linux / windows)
# nightly -> set submission mode to nightly, if not set -> continuous build
# update -> update svn
# memcheck -> valgrind
# coverage -> gcov (compile mit gcov=on)

# Linux
# - Unix Makefiles, memcheck, coverage, CMake Settings
# - Unix Makefiles, Release
# - Android

# Windows
# - Visual Studio 2005, Win32, CMake Settings
# - Visual Studio 2005, Win32, Release
# - Visual Studio 2005, Win64, CMake Settings
# - Visual Studio 2005, Win64, Release

# - Visual Studio 2008, Win32, CMake Settings
# - Visual Studio 2008, Win32, Release
# - Visual Studio 2008, Win64, CMake Settings
# - Visual Studio 2008, Win64, Release

# - Visual Studio 2010, Win32, CMake Settings
# - Visual Studio 2010, Win32, Release
# - Visual Studio 2010, Win64, CMake Settings
# - Visual Studio 2010, Win64, Release

# operating system
IF(${CTEST_SCRIPT_ARG} MATCHES "linux")
  set(OPERATING_SYSTEM "Linux")
ELSEIF(${CTEST_SCRIPT_ARG} MATCHES "windows")
  set(OPERATING_SYSTEM "Windows")
ELSE ()
MESSAGE(FATAL_ERROR "Specify operating system (linux / windows)!")
ENDIF ()

# submission mode
set(SUBMISSION_MODE "Continuous")
IF(${CTEST_SCRIPT_ARG} MATCHES "nightly")
  set(SUBMISSION_MODE "Nightly")
ENDIF ()

# update the source directory
set(UPDATE_SVN FALSE)
IF(${CTEST_SCRIPT_ARG} MATCHES "update")
  set(UPDATE_SVN TRUE)
ENDIF ()

# memory check
set(BUILD_WITH_MEMCHECK FALSE)
IF(${CTEST_SCRIPT_ARG} MATCHES "memcheck")
  set(BUILD_WITH_MEMCHECK TRUE)
ENDIF ()

# determine coverage
set(BUILD_WITH_COVERAGE FALSE)
IF(${CTEST_SCRIPT_ARG} MATCHES "coverage")
  set(BUILD_WITH_COVERAGE TRUE)
ENDIF ()

# which generator
IF(${CTEST_SCRIPT_ARG} MATCHES "Unix Makefiles")
  set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
  set(BUILD_STRING "gcc-default")
ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "Visual Studio 8 2005 Win64")
  set(CTEST_CMAKE_GENERATOR "Visual Studio 8 2005 Win64")
  set(BUILD_STRING "vs2005-x64")
ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "Visual Studio 8 2005")
  set(CTEST_CMAKE_GENERATOR "Visual Studio 8 2005")
  set(BUILD_STRING "vs2005-x86")

ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "Visual Studio 9 2008 Win64")
  set(CTEST_CMAKE_GENERATOR "Visual Studio 9 2008 Win64")
  set(BUILD_STRING "vs2008-x64")
ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "Visual Studio 9 2008")
  set(CTEST_CMAKE_GENERATOR "Visual Studio 9 2008")
  set(BUILD_STRING "vs2008-x86")

ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "Visual Studio 10 Win64")
  set(CTEST_CMAKE_GENERATOR "Visual Studio 10 Win64")
  set(BUILD_STRING "vs2010-x64")
ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "Visual Studio 10")
  set(CTEST_CMAKE_GENERATOR "Visual Studio 10")
  set(BUILD_STRING "vs2010-x86")
ENDIF ()

# build type
IF(${CTEST_SCRIPT_ARG} MATCHES "debug")
  set(CTEST_CMAKE_BUILD_TYPE "Debug")
ELSEIF (${CTEST_SCRIPT_ARG} MATCHES "release")
  set(CTEST_CMAKE_BUILD_TYPE "Release")
ENDIF ()



# source and binary directories on disk
set(CTEST_SOURCE_DIRECTORY "${CTEST_SCRIPT_DIRECTORY}")
set(CTEST_BINARY_DIRECTORY "${CTEST_SOURCE_DIRECTORY}/build")

# CTest should wipe the binary tree before running
set(CTEST_START_WITH_EMPTY_BINARY_DIRECTORY TRUE)
#FILE(REMOVE_RECURSE ${CTEST_BINARY_DIRECTORY})

# maximum number of warnings
set(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_WARNINGS 2000)
set(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_ERRORS   2000)

# which CTest command to use for running the dashboard
set(CTEST_COMMAND "\"${CTEST_EXECUTABLE_NAME}\"")

# what cmake command to use for configuring this dashboard
set(CTEST_CMAKE_COMMAND "\"${CMAKE_EXECUTABLE_NAME}\"")



# this is the initial cache to use for the binary tree, be careful to escape
# any quotes inside of this string if you use it
#SET (CTEST_INITIAL_CACHE "
#     CMAKE_GENERATOR:INTERNAL=Unix Makefiles
#     BUILDNAME:STRING=Linux-x64
#     ")

set(CTEST_SITE "${OPERATING_SYSTEM}TestVM")

set(CTEST_BUILD_NAME "${OPERATING_SYSTEM}")
IF(BUILD_STRING)
  set(CTEST_BUILD_NAME "${CTEST_BUILD_NAME}-${BUILD_STRING}")
ELSE ()
  set(CTEST_BUILD_NAME "${CTEST_BUILD_NAME}-default")
ENDIF ()

IF(CTEST_CMAKE_BUILD_TYPE)
  set(CTEST_BUILD_NAME "${CTEST_BUILD_NAME}-${CTEST_CMAKE_BUILD_TYPE}")
ELSE ()
  set(CTEST_BUILD_NAME "${CTEST_BUILD_NAME}-default")
ENDIF ()


ctest_start(${SUBMISSION_MODE})

#tell cmake to use svn to update
find_program(CTEST_SVN_COMMAND NAMES svn)
set(CTEST_SVN_CHECKOUT "svn co https://winserver/svn/main/ZKCompiler/trunk ${CTEST_SOURCE_DIRECTORY}")
set(CTEST_UPDATE_COMMAND "${CTEST_SVN_COMMAND}")
SET($ENV{LC_MESSAGES}    "en_EN" )
ctest_update(SOURCE "${CTEST_SOURCE_DIRECTORY}")

set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
set(CTEST_CONFIGURE_COMMAND "${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE:STRING=${CTEST_BUILD_CONFIGURATION}" -DCOMPILER=on)
set(CTEST_CONFIGURE_COMMAND "${CTEST_CONFIGURE_COMMAND} \"-G${CTEST_CMAKE_GENERATOR}\"")
if (BUILD_WITH_COVERAGE)
  set(CTEST_CONFIGURE_COMMAND "${CTEST_CONFIGURE_COMMAND} \"-DGCOV=on\"")
endif ()
set(CTEST_CONFIGURE_COMMAND "${CTEST_CONFIGURE_COMMAND} \"${CTEST_SOURCE_DIRECTORY}\"")
ctest_configure(BUILD "${CTEST_BINARY_DIRECTORY}")

ctest_build(BUILD "${CTEST_BINARY_DIRECTORY}")

ctest_test(BUILD "${CTEST_BINARY_DIRECTORY}")

find_program(CTEST_COVERAGE_COMMAND NAMES gcov)
if (BUILD_WITH_COVERAGE AND CTEST_COVERAGE_COMMAND)
  ctest_coverage(BUILD "${CTEST_BINARY_DIRECTORY}")
endif ()

find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
if (BUILD_WITH_MEMCHECK AND CTEST_MEMORYCHECK_COMMAND)
  ctest_memcheck()
endif ()
ctest_submit()

