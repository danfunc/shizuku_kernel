cmake_minimum_required(VERSION 3.28)

# prelaod_toolchain
include(toolchains/preload_toolchain.cmake)
set(CMAKE_CXX_STANDARD 20)
project(shizuku_kernel C CXX ASM)
# declere targets
add_library(shizuku_kernel_core)
add_library(shizuku_kernel_core_templates INTERFACE)
add_executable(shizuku_kernel)
target_link_libraries(shizuku_kernel_core PUBLIC shizuku_kernel_config
                                                 shizuku_kernel_core_templates)
target_link_libraries(shizuku_kernel PRIVATE shizuku_kernel_core)

target_include_directories(
  shizuku_kernel_core
  PUBLIC
  interface)
target_include_directories(
  shizuku_kernel_core_templates
  INTERFACE include
  INTERFACE
  interface)

# afterload_toolchain
include(toolchains/afterload_toolchain.cmake)

add_subdirectory(config)
add_subdirectory(src)
