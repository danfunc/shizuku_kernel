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
  asm volatile("mov %0, r4" : "=r"(r4));
  current_context[get_core_num()]->r4 = r4;
  asm volatile("mov %0, r5" : "=r"(r5));
  current_context[get_core_num()]->r5 = r5;
  asm volatile("mov %0, r6" : "=r"(r6));
  current_context[get_core_num()]->r6 = r6;
  asm volatile("mov %0, r7" : "=r"(r7));
  current_context[get_core_num()]->r7 = r7;
  asm volatile("mov %0, r8" : "=r"(r8));
  current_context[get_core_num()]->r8 = r8;
  asm volatile("mov %0, r9" : "=r"(r9));
  current_context[get_core_num()]->r9 = r9;
  asm volatile("mov %0, r10" : "=r"(r10));
  current_context[get_core_num()]->r10 = r10;
  asm volatile("mov %0, r11" : "=r"(r11));
  current_context[get_core_num()]->r11 = r11;
  asm volatile("mrs %0, MSP" : "=r"(sp));
  current_context[get_core_num()]->sp = sp;
  asm volatile("mov %0, lr" : "=r"(lr));
  current_context[get_core_num()]->mode = lr;
  current_context[get_core_num()] = cpu_manager::schedule();
  r4 = current_context[get_core_num()]->r4;
  asm volatile("mov r4, %0" : : "r"(r4));
  r5 = current_context[get_core_num()]->r5;
  asm volatile("mov r5, %0" : : "r"(r5));
  r6 = current_context[get_core_num()]->r6;
  asm volatile("mov r6, %0" : : "r"(r6));
  r7 = current_context[get_core_num()]->r7;
  asm volatile("mov r7, %0" : : "r"(r7));
  r8 = current_context[get_core_num()]->r8;
  asm volatile("mov r8, %0" : : "r"(r8));
  r9 = current_context[get_core_num()]->r9;
  asm volatile("mov r9, %0" : : "r"(r9));
  r10 = current_context[get_core_num()]->r10;
  asm volatile("mov r10, %0" : : "r"(r10));
  r11 = current_context[get_core_num()]->r11;
  asm volatile("mov r11, %0" : : "r"(r11));
  sp = current_context[get_core_num()]->sp;
  asm volatile("msr MSP, %0" : : "r"(sp));
  lr = current_context[get_core_num()]->mode;
  asm volatile("mov lr, %0" : : "r"(lr));
  return;
}
void rp2040::auto_exit() {}