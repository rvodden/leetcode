include(FetchContent)

set_property(
    DIRECTORY
    APPEND
    PROPERTY COMPILE_OPTIONS -Wno-everything
)

### Google Test ###

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
        DOWNLOAD_EXTRACT_TIMESTAMP false
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ### Google Benchmark ###

FetchContent_Declare(
        googlebenchmark
        URL https://github.com/google/benchmark/archive/b0d5adfacdfde5122ce421d5eddd217e46425fa2.zip
        DOWNLOAD_EXTRACT_TIMESTAMP false
)

FetchContent_MakeAvailable(googlebenchmark)
