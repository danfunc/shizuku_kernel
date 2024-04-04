add_library(shizuku_kernel_pico_sdk_support OBJECT)
target_include_directories(shizuku_kernel_pico_sdk_support PUBLIC include)
if(NOT (CMAKE_BUILD_TYPE STREQUAL "Debug"))
  target_precompile_headers(
    shizuku_kernel_pico_sdk_support
    PRIVATE
    $<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/shizuku/kernel/platform/pico_sdk.hpp>
  )
endif()

target_link_libraries(shizuku_kernel_pico_sdk_support
                      PUBLIC pico_stdlib pico_multicore hardware_exception )
target_link_libraries(shizuku_kernel_core
                      PUBLIC shizuku_kernel_pico_sdk_support)
target_link_libraries(
  shizuku_kernel_pico_sdk_support
  PUBLIC shizuku_kernel_config
  PRIVATE shizuku_kernel_core_templates)
add_subdirectory(main)
add_subdirectory(rp2040)
