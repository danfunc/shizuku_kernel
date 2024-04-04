#ifndef SHIZUKU_KERNEL
#define SHIZUKU_KERNEL

#include <shizuku/kernel/config.hpp>
#include <shizuku/kernel/cpu_manager.hpp>

namespace shizuku {
namespace types {
class kernel {
private:
  shizuku::types::memory_manager memory_manager;
  cpu_manager cpu_managers[];

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