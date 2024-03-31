#ifndef SHIZUKU_KERNEL_PICO_SDK_SUPPORT_RP2040
#define SHIZUKU_KERNEL_PICO_SDK_SUPPORT_RP2040
#include <cstdint>
#include <hardware/exception.h>
#include <shizuku/kernel/cpu_driver_interface.hpp>
#include <shizuku/kernel/interface_interceptor.hpp>
#include <shizuku/kernel/method.hpp>
namespace shizuku {
namespace types {
struct rp2040;
struct rp2040 : public cpu_driver_interface {
public:
  int init() override;
  int get_core_num() override;
  struct context {
    struct exception_stack {
      uint32_t r0, r1, r2, r3;
      size_t r12;
      void *lr, *pc;
      uint32_t xPSR;
    };
    exception_stack stack;
    uint32_t r4, r5, r6, r7, r8, r9, r10, r11;
    void *sp;
    inline context() {};
    inline context(shizuku::types::method entry, uintptr_t arg0, uintptr_t arg1,
                   uintptr_t arg2, uintptr_t arg3) {

    };
  };
};
} // namespace types
} // namespace shizuku
#endif
