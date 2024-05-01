#ifndef SHIZUKU_KERNEL_PICO_SDK_PLATFORM
#define SHIZUKU_KERNEL_PICO_SDK_PLATFORM

#include <map>
#include <memory>
#include <shizuku/kernel/interfaces/memory_manager_interface.hpp>
#include <shizuku/operation_result.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

namespace shizuku {
namespace types {
class pico_sdk_memory_manager : public memory_manager_interface {
public:
  void init() noexcept override;
  void *malloc(size_t size) noexcept override;
  void free(size_t size) noexcept override;
};
} // namespace types
} // namespace shizuku
#endif // SHIZUKU_KERNEL_PICO_SDK_PLATFORM