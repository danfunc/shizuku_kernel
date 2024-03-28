cmake_minimum_required(VERSION 3.28)

# prelaod_toolchain
include(toolchains/preload_toolchain.cmake)

project(shizuku_kernel C CXX ASM)

# declere targets
add_library(shizuku_kernel_core)
add_executable(shizuku_kernel)
target_link_libraries(shizuku_kernel_core PUBLIC shizuku_kernel_config)
target_link_libraries(shizuku_kernel PRIVATE shizuku_kernel_core)

# afterload_toolchain
include(toolchains/afterload_toolchain.cmake)

add_subdirectory(config)
add_subdirectory(src)
