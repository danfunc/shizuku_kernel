add_library(shizuku_kernel_pico_sdk_support OBJECT)
target_link_libraries(shizuku_kernel_pico_sdk_support PRIVATE pico_stdlib
                                                              pico_multicore)
target_link_libraries(shizuku_kernel_core
                      PUBLIC shizuku_kernel_pico_sdk_support)
target_link_libraries(shizuku_kernel_pico_sdk_support
                      PUBLIC shizuku_kernel_config)
add_subdirectory(main)
add_subdirectory(rp2040)
