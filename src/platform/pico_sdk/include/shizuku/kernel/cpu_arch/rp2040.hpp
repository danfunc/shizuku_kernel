#ifndef SHIZUKU_KERNEL_PICO_SDK_SUPPORT_RP2040
#define SHIZUKU_KERNEL_PICO_SDK_SUPPORT_RP2040
#include <cstdint>
#include <hardware/exception.h>
#include <shizuku/kernel/interfaces/cpu_driver_interface.hpp>
#include <shizuku/kernel/interfaces/interface_interceptor.hpp>
#include <shizuku/kernel/method.hpp>
#include <stdlib.h>
namespace shizuku {
namespace types {
struct rp2040;
struct rp2040 : public cpu_driver_interface {
public:
  int init() override;
  int get_core_num() override;
  static void auto_exit();
  struct context {
    struct exception_stack {
      uint32_t r0, r1, r2, r3, r12;
      void *lr, *pc;
      uint32_t xPSR;
    };
    enum struct exc_return : uintptr_t {
      handler_MSP = 0xFFFFFFF1,
      thread_MSP = 0xFFFFFFF9,
      thread_PSP = 0xFFFFFFFD,
    };
    using exec_mode = exc_return;
    exception_stack *sp;
    exec_mode mode;
    uint32_t r4, r5, r6, r7, r8, r9, r10, r11;
    inline context(shizuku::types::method entry, uintptr_t arg0, uintptr_t arg1,
                   uintptr_t arg2, uintptr_t arg3, void *start_sp,
                   size_t stack_size, exec_mode mode) {
      start_sp = (void *)((uintptr_t)start_sp & ~0xfL);
      sp = ((exception_stack *)start_sp - 2);
      sp->pc = (void *)entry;
      sp->r0 = arg0;
      sp->r1 = arg1;
      sp->r2 = arg2;
      sp->r3 = arg3;
      sp->lr = (void *)auto_exit;
      r4 = 0;
      r5 = 0;
      r6 = 0;
      r7 = 0;
      r8 = 0;
      r9 = 0;
      r10 = 0;
      r11 = 0;
      this->mode = mode;
    };
  };
};
} // namespace types
} // namespace shizuku
#endif
