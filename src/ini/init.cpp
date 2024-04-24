#include <shizuku/kernel/kernel.hpp>

using namespace shizuku::types;

void kernel::init() {
  for (size_t i = 0; i < SHIZUKU_CPU_CORE_COUNT; i++) {
    cpu_managers[i].init();
  }
};