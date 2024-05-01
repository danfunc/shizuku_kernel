#ifndef SHIZUKU_KERNEL_CPU_MANAGER_TASK
#define SHIZUKU_KERNEL_CPU_MANAGER_TASK
#include <shizuku/kernel/config.hpp>
#include <shizuku/kernel/thread.hpp>

namespace shizuku {
namespace types {
struct task {
  std::weak_ptr<shizuku::types::thread> thread;
  size_t remain_time;
  task(std::weak_ptr<shizuku::types::thread> thread, size_t time) {
    thread = thread;
    remain_time = time;
  }
};
} // namespace types
} // namespace shizuku

#endif // SHIZUKU_KERNEL_CPU_MANAGER_TASK