### General Settings ###

cmake_minimum_required(VERSION 3.21 FATAL_ERROR)
project(leetcode VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

### Define Options ###

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

### Compilation Settings

add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE
        "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused;-O2>>"
        "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
        )

target_compile_options(compiler_flags INTERFACE "-fsanitize=undefined")
target_link_options(compiler_flags INTERFACE "-fsanitize=undefined")

### Subdirectories ###

add_subdirectory(external)
add_subdirectory(romanToInteger)
