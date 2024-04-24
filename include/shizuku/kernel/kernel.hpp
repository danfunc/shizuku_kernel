#ifndef SHIZUKU_KERNEL
#define SHIZUKU_KERNEL

#include <shizuku/kernel/config.hpp>
#include <shizuku/kernel/cpu_manager.hpp>
#include <shizuku/kernel/thread.hpp>

namespace shizuku {
namespace types {
class kernel {
private:
  static cpu_manager cpu_managers[SHIZUKU_CPU_CORE_COUNT];

public:
  void init();
  kernel();
  ~kernel();
};

kernel::kernel() {}

kernel::~kernel() {}

} // namespace types
} // namespace shizuku

#endif // SHIZUKU_KERNEL