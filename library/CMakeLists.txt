
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/clang)

file(GLOB SOURCES
    include/mylib/*.hpp
    src/*.[ch]pp)

add_library(mylib STATIC ${SOURCES})

configure_file(mylib_cmake_config.hpp.in mylib/cmake_config.hpp @ONLY)

target_include_directories(mylib PUBLIC include)
target_include_directories(mylib PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
