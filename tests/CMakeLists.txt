
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

# Enable testing
enable_testing()

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)

FetchContent_MakeAvailable(googletest)

target_include_directories(virtual_memory PUBLIC include)

file(GLOB SOURCES
    src/*.[ch]pp
    )
    
add_executable(virtual_memory_test ${SOURCES})

target_link_libraries(virtual_memory_test virtual_memory gtest_main)
