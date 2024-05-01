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
class cpu_manager;
class rp2040 {
public:
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
    void *start_stack_pointer, *sp;
    exec_mode mode;
    inline context(shizuku::types::method entry, uintptr_t arg0, uintptr_t arg1,
                   uintptr_t arg2, uintptr_t arg3, void *start_exception_stack,
                   size_t stack_size, exec_mode mode) {};
    inline ~context() {};
  };

private:
  friend cpu_manager;
  static int init();
  static int get_core_num() { return ::get_core_num(); };
  static void auto_exit();
  static __always_inline void pendsv() {
    *(uintptr_t *)(PPB_BASE + M0PLUS_ICSR_OFFSET) |= 1 << 28;
  };
  static std::shared_ptr<context> current_context[SHIZUKU_CPU_CORE_COUNT];
  static void pendSV_handler();
  rp2040(size_t core_num, cpu_manager &manager);
};
} // namespace types
} // namespace shizuku
#endif
