
include(GoogleTest)

macro(standard_build)

    ## Library Build

    get_filename_component(LibraryName ${CMAKE_CURRENT_SOURCE_DIR} NAME)    
    
    message(CHECK_START "Loading ${LibraryName}...")

    file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
    foreach(SOURCE_FILE ${SOURCE_FILES})
        message("   Adding source file: ${SOURCE_FILE}")
    endforeach()
    add_library(${LibraryName} SHARED ${SOURCE_FILES})

    target_link_libraries(${LibraryName} PRIVATE compiler_flags)
    target_include_directories(${LibraryName} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src> $<INSTALL_INTERFACE:include>)
    string(TOUPPER ${LibraryName} UpperLibraryName)
    target_compile_definitions(${LibraryName} PRIVATE "EXPORTING_${UpperLibraryName}")

    set_property(TARGET ${LibraryName} PROPERTY CXX_INCLUDE_WHAT_YOU_USE ${iwyu_path})

 
    ## Documentation Build

    set(DocName "${LibraryName}_docs")
    
    doxygen_add_docs(${DocName} ${SOURCE_FILES})
        
    ## Test Build

    set(TestName "${LibraryName}_test")
    
    file(GLOB_RECURSE TEST_SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/*.h)
    foreach(SOURCE_FILE ${TEST_SOURCE_FILES})
        message("   Adding test source file: ${SOURCE_FILE}")
    endforeach()
    add_executable(${TestName} ${TEST_SOURCE_FILES})

    target_link_libraries(${TestName} PRIVATE compiler_flags)
    target_link_libraries(${TestName} PUBLIC ${LibraryName})
    target_link_libraries(${TestName} PUBLIC gtest)
    target_link_libraries(${TestName} PUBLIC gmock)
    target_link_libraries(${TestName} PUBLIC gtest_main)

    gtest_discover_tests(${TestName} XML_OUTPUT_DIR report EXTRA_ARGS --gtest_catch_exceptions=0)
    message(CHECK_PASS "done.")

    set(LibraryName ${LibraryName} PARENT_SCOPE)

    ## Benchmark Build

    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bench)
        set(BenchName "${LibraryName}_bench")
        file(GLOB_RECURSE BENCH_SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/bench/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/bench/*.h)
        add_executable(${BenchName} ${BENCH_SOURCE_FILES})
        target_link_libraries(${BenchName} PUBLIC ${LibraryName})
        target_link_libraries(${BenchName} PRIVATE benchmark::benchmark_main)
    endif()

endmacro()

list( APPEND skip_directories cmake-* )
list( APPEND skip_directories cmake )

macro(subdir_list result curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)
    set(dirlist "")
    foreach(child ${children})
        if(IS_DIRECTORY ${curdir}/${child})
            set(skip OFF)
            if(child MATCHES "^\\..*")
                set(skip ON)
            endif()
            foreach(skip_dir ${skip_directories})
                if(child MATCHES ${skip_dir})
                    set(skip ON)
                endif()
            endforeach()
            if(NOT skip)
                LIST(APPEND dirlist ${child})
            endif()
        endif()
    endforeach()
    set(${result} ${dirlist})
endmacro()
