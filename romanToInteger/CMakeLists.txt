include(GoogleTest)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
add_library(roman ${SOURCE_FILES})

target_link_libraries(roman PRIVATE compiler_flags)
target_include_directories(roman INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src> $<INSTALL_INTERFACE:include>)
target_compile_definitions(roman PRIVATE "EXPORTING_ROMAN")

install(TARGETS roman DESTINATION lib EXPORT roman_targets)
install(FILES src/solution.h DESTINATION include)

enable_testing()

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/*.h)
add_executable(roman_test ${SOURCE_FILES})

target_link_libraries(roman_test PRIVATE compiler_flags)
target_link_libraries(roman_test PUBLIC roman)
target_link_libraries(roman_test PUBLIC gtest_main)
target_link_libraries(roman_test PUBLIC gmock_main)

gtest_discover_tests(roman_test XML_OUTPUT_DIR report EXTRA_ARGS --gtest_catch_exceptions=0)
