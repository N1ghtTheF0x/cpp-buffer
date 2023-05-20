cmake_minimum_required(VERSION 3.22)

set(NTF_PROJECT_NAME "template") # Name of program (Use this for linking)
set(NTF_TYPE "LIB") # LIB: Compile a library, EXE: Compile a executable. NOTICE: when EXE then the main.cpp will be included
set(NTF_MAJOR_VERSION 1) # Major version of program
set(NTF_MINOR_VERSION 0) # Minor version of program
set(NTF_PATCH_VERSION 0) # Patch version of program
set(NTF_TWEAK_VERSION 0) # Tweak version of program
set(NTF_WINDOWS_USE_WIN32 TRUE) # Use WIN32 for Windows (only when target is windows!)

# full version string
set(NTF_VERSION ${NTF_MAJOR_VERSION}.${NTF_MINOR_VERSION}.${NTF_PATCH_VERSION}.${NTF_TWEAK_VERSION})
# appended to project name and output
set(NTF_PREFIX "ntf")

project(${NTF_PROJECT_NAME} VERSION ${NTF_VERSION} DESCRIPTION "description goes here" HOMEPAGE_URL "https://github.com/N1ghtTheF0x/"  LANGUAGES CXX C)

# Output compiled programs to lib/bin folders in the current working directory
# https://stackoverflow.com/a/6595001
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# https://stackoverflow.com/a/58988164
foreach( OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES} )
    string( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
    set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_CURRENT_SOURCE_DIR}/lib )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_CURRENT_SOURCE_DIR}/lib )
    set( CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_CURRENT_SOURCE_DIR}/bin )
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )
# set C/C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
# collect all the sources of the program
file(GLOB_RECURSE NTF_SOURCES source/*.cpp source/*.c)

if(WIN32 AND NTF_WINDOWS_USE_WIN32)
    set(NTF_USE_WIN32 WIN32) # Use Win32 with executable. This disables Console!
endif()

if(NTF_TYPE STREQUAL "LIB")
    add_library(${NTF_PROJECT_NAME} ${NTF_SOURCES})
elseif(NTF_TYPE STREQUAL "EXE")
    add_executable(${NTF_PROJECT_NAME} ${NTF_USE_WIN32} main.cpp ${NTF_SOURCES})
else()
    message(FATAL_ERROR "Unknown program type: ${NTF_TYPE}")
endif()
# output will be: <prefix>-<version>-<name>
if(NTF_PREFIX STREQUAL "")
    set_target_properties(${NTF_PROJECT_NAME} PROPERTIES PREFIX ${NTF_VERSION}-)
else()
    set_target_properties(${NTF_PROJECT_NAME} PROPERTIES PREFIX ${NTF_PREFIX}-${NTF_VERSION}-)
endif()

if(UNIX) # when on linux, put the arch type as suffix
    set_target_properties(${NTF_PROJECT_NAME} PROPERTIES SUFFIX .${CMAKE_SYSTEM_PROCESSOR})
endif()

# 3rd-Party includes here...

# add_subdirectory(...) or find_package(...)
# target_link_libraries(${NTF_PROJECT_NAME} PRIVATE ...)
# target_include_directories(${NTF_PROJECT_NAME} PRIVATE ...)

# include local include folder
target_include_directories(${NTF_PROJECT_NAME} PRIVATE include)
# Preprocessor definitions: Windows, Linux and other OS names
target_compile_definitions(${NTF_PROJECT_NAME} PRIVATE ${CMAKE_SYSTEM_NAME})