#ifndef SHIZUKU_KERNEL_PICO_SDK_PLATFORM
#define SHIZUKU_KERNEL_PICO_SDK_PLATFORM

#include <map>
#include <memory>
#include <shizuku/kernel/memory_manager_interface.hpp>
#include <stdio.h>
#include <stdlib.h>

namespace shizuku {
namespace types {
class pico_sdk_memory_manager : public memory_manager_interface {
public:
  void init() override;
};
} // namespace types
} // namespace shizuku
#endif // SHIZUKU_KERNEL_PICO_SDK_PLATFORM