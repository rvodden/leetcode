### General Settings ###

cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(leetcode VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_MACOSX_RPATH 1)

include(cmake/standard_build.cmake)
enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

### Find Dependencies ###

find_program(iwyu_path NAMES include-what-you-use iwyu REQUIRED)

### Define Options ###

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

### Compilation Settings

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-fdiagnostics-color=always;-O0>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
        )

if (USE_SANITIZER STREQUAL "Address")
    target_compile_options(compiler_flags, "-fsanitize=address")
elseif (USE_SANITIZER STREQUAL "Thread")
    target_compile_options(compiler_flags, "-fsanitize=thread")
elseif (USE_SANITIZER STREQUAL "Leak")
     target_compile_options(compiler_flags, "-fsanitize=leak")
elseif (USE_SANITIZER STREQUAL "Memory")
     target_compile_options(compiler_flags, "-fsanitize=memory")
elseif (USE_SANITIZER STREQUAL "Undefined")
    target_compile_options(compiler_flags, "-fsanitize=undefined")
endif()

### Documentation

find_package(Doxygen REQUIRED dot)

if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    set(DocName "docs")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( ${DocName}
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
endif (DOXYGEN_FOUND)

### Subdirectories ###

subdir_list(SUBDIRS ${MY_CURRENT_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()

### Macros (Move to another file, or maybe even another project?)



