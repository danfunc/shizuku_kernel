#ifndef SHIZUKU_KERNEL_THREAD_HPP
#define SHIZUKU_KERNEL_THREAD_HPP
#include <shizuku/kernel/config.hpp>
namespace shizuku {
namespace types {
struct thread {
  std::shared_ptr<thread_context> context;
};
} // namespace types
} // namespace shizuku
#endif // SHIZUKU_KERNEL_THREAD_HPP