add_library(shizuku_kernel_config INTERFACE)

if(DEFINED ENV{SHIZUKU_PLATFORM} AND NOT SHIZUKU_PLATFORM)
  set(SHIZUKU_PLATFORM $ENV{SHIZUKU_PLATFORM})
endif()

if(DEFINED ENV{SHIZUKU_CPU_ARCH} AND NOT SHIZUKU_CPU_ARCH)
  set(SHIZUKU_CPU_ARCH $ENV{SHIZUKU_CPU_ARCH})
endif()

target_compile_definitions(
  shizuku_kernel_config
  INTERFACE SHIZUKU_CPU_ARCH=${SHIZUKU_CPU_ARCH}
  INTERFACE SHIZUKU_PLATFORM=${SHIZUKU_PLATFORM}
  INTERFACE SHIZUKU_CPU_CORE_COUNT=${SHIZUKU_CPU_CORE_COUNT})
set(SHIZUKU_PLATFORM_VALID
    no
    CACHE BOOL "SHIZUKU_PLATFORM_VALID RESULT" FORCE)
set(SHIZUKU_CPU_VALID
    no
    CACHE BOOL "SHIZUKU_CPU_VALID RESULT" FORCE)
add_subdirectory(platform)
add_subdirectory(cpu_arch)

if(SHIZUKU_PLATFORM_VALID)
  message("SHIZUKU_PLATFORM is ${SHIZUKU_PLATFORM}")
else()
  message(FATAL_ERROR "SHIZUKU_PLATFORM invalid")
endif()
if(SHIZUKU_CPU_ARCH_VALID)
  message("SHIZUKU_CPU_ARCH is ${SHIZUKU_CPU_ARCH}")
else()
  message(FATAL_ERROR "SHIZUKU_CPU_ARCH invalid")
endif()
target_include_directories(shizuku_kernel_config
                           INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/interface)
configure_file(config_template.hpp interface/shizuku/kernel/config.hpp)
target_compile_definitions(shizuku_kernel_config
                           INTERFACE SHIZUKU_CONFIGURED_BY_CMAKE)
