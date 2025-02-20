
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER /usr/bin/clang)

file(GLOB COMMON_SOURCES
    include/vm/*.hpp
    src/*.[ch]pp
    src/heap_mgr/*.[ch]pp
    src/io_mgr/*.[ch]pp
    src/scratch_mgr/*.[ch]pp)

set(POSIX_SOURCES
    include/vm/posix/platform_posix.hpp
    src/posix/platform_posix.cpp
    include/vm/posix/file_posix.hpp
    src/posix/file_posix.cpp
    )

set(APPLE_SOURCES
    ${POSIX_SOURCES}
    )

set(MAC_SOURCES
    ${APPLE_SOURCES}
    include/vm/posix/apple/mac/platform_mac.hpp
    src/posix/apple/mac/platform_mac.cpp
    src/posix/apple/mac/platform_mac_new.cpp
    )

set(IOS_SOURCES
    ${APPLE_SOURCES}
    )

set(MICROSOFT_SOURCES
    )

set(WIN32_SOURCES
    ${MICROSOFT_SOURCES}
    )
    
set(WINARM_SOURCES
    ${MICROSOFT_SOURCES}
    )

if(PLATFORM STREQUAL "mac")
    set(VM_PRIVATE_PLATFORM_CHOICE "MAC")
    set(SOURCES
        ${COMMON_SOURCES}
        ${MAC_SOURCES}
        )
elseif(PLATFORM STREQUAL "win32")
    set(VM_PRIVATE_PLATFORM_CHOICE "WIN32")
    set(SOURCES
        ${COMMON_SOURCES}
        ${WIN32_SOURCES}
        )
elseif(PLATFORM STREQUAL "winarm")
    set(VM_PRIVATE_PLATFORM_CHOICE "WINARM")
    set(SOURCES
        ${COMMON_SOURCES}
        ${WINARM_SOURCES}
        )
elseif(PLATFORM STREQUAL "ios")
    set(VM_PRIVATE_PLATFORM_CHOICE "IOS")
    set(SOURCES
        ${COMMON_SOURCES}
        ${IOS_SOURCES}
        )
elseif(PLATFORM STREQUAL "linux")
    set(VM_PRIVATE_PLATFORM_CHOICE "LINUX")
    set(SOURCES
        ${COMMON_SOURCES}
        ${LINUX_SOURCES}
        )
else()
    message(FATAL_ERROR "must specify PLATFORM mac,win32,winarm,ios,linux")
endif()

configure_file(vm_cmake_config.hpp.in vm/cmake_config.hpp @ONLY)

add_library(virtual_memory STATIC ${SOURCES})

target_include_directories(virtual_memory PUBLIC include)
target_include_directories(virtual_memory PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
