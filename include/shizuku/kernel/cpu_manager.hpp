#ifndef SHIZUKU_KERNEL_CPU_MANAGER
#define SHIZUKU_KERNEL_CPU_MANAGER

#include <shizuku/kernel/config.hpp>
#include <shizuku/kernel/cpu_manager/task.hpp>
#include <shizuku/kernel/thread.hpp>

namespace shizuku {
namespace types {
class kernel;
struct thread;
class cpu_manager {
  const cpu_driver driver;
  const size_t core_num;
  friend cpu_driver;
  friend kernel;
  static std::shared_ptr<thread_context> schedule();
  cpu_manager(size_t core_num);
};
} // namespace types
} // namespace shizuku

#endif // SHIZUKU_KERNEL_CPU_MANAGER