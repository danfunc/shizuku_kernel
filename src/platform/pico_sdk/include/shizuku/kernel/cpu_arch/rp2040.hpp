#ifndef SHIZUKU_KERNEL_PICO_SDK_SUPPORT_RP2040
#define SHIZUKU_KERNEL_PICO_SDK_SUPPORT_RP2040
#include <bit>
#include <cstdint>
#include <hardware/exception.h>
#include <memory>
#include <pico/multicore.h>
#include <pico/platform.h>
#include <pico/stdlib.h>
#include <shizuku/kernel/interfaces/cpu_driver_interface.hpp>
#include <shizuku/kernel/interfaces/interface_interceptor.hpp>
#include <shizuku/kernel/method.hpp>
#include <stdlib.h>
namespace shizuku {
namespace types {
struct rp2040 {
public:
  static int init();
  static int get_core_num() { return ::get_core_num(); };
  static void auto_exit();
  struct context {
    struct exception_stack {
      uint32_t r0, r1, r2, r3, r12;
      void (*lr)(), (*pc)();
      uint32_t xPSR;
    };
    enum struct exc_return : uintptr_t {
      handler_MSP = 0xFFFFFFF1,
      thread_MSP = 0xFFFFFFF9,
      thread_PSP = 0xFFFFFFFD,
    };
    using exec_mode = exc_return;
    exception_stack exception_stack;
    void *start_stack_pointer, *sp;
    exec_mode mode;
    uint32_t r4, r5, r6, r7, r8, r9, r10, r11, stack_size;
    inline context(shizuku::types::method entry, uintptr_t arg0, uintptr_t arg1,
                   uintptr_t arg2, uintptr_t arg3, void *start_exception_stack,
                   size_t stack_size, exec_mode mode) {
      start_exception_stack =
          (void *)((uintptr_t)start_exception_stack & ~0xfL);
      exception_stack.pc = (void (*)())entry;
      exception_stack.r0 = arg0;
      exception_stack.r1 = arg1;
      exception_stack.r2 = arg2;
      exception_stack.r3 = arg3;
      exception_stack.lr = auto_exit;
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
    inline ~context() {};
  };
  static __always_inline void pendsv() {
    *(uintptr_t *)(PPB_BASE + M0PLUS_ICSR_OFFSET) |= 1 << 28;
  };
  static std::shared_ptr<context> current_context[SHIZUKU_CPU_CORE_COUNT];

private:
  static void pendSV_handler();
};
} // namespace types
} // namespace shizuku
#endif
