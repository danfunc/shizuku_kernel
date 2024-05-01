#include <shizuku/kernel/config.hpp>
#include <shizuku/kernel/kernel.hpp>

using namespace shizuku::types;

int rp2040::init() {
  exception_set_exclusive_handler(PENDSV_EXCEPTION, pendSV_handler);
  return 0;
};
void rp2040::pendSV_handler() {
  void *sp;
  rp2040::context::exc_return lr;
  uint32_t r4, r5, r6, r7, r8, r9, r10, r11;
  return;
}
void rp2040::auto_exit() {}