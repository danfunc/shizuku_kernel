#ifndef SHIZUKU_KERNEL_CPU_MANAGER
#define SHIZUKU_KERNEL_CPU_MANAGER

#include <shizuku/kernel/config.hpp>
#include <shizuku/kernel/thread.hpp>

namespace shizuku {
namespace types {
class kernel;
struct thread;
class cpu_manager {
  struct task {
    std::weak_ptr<shizuku::types::thread> thread;
    size_t remain_time;
    task(std::weak_ptr<shizuku::types::thread> thread, size_t time) {
      thread = thread;
      remain_time = time;
    }
  };
  cpu_driver driver;
  friend cpu_driver;
  friend kernel;
  static std::shared_ptr<thread_context> schedule();
  static task current_tasks[SHIZUKU_CPU_CORE_COUNT];

public:
  void init();
};
} // namespace types
} // namespace shizuku

#endif // SHIZUKU_KERNEL_CPU_MANAGER