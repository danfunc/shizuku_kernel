#ifndef SHIZUKU_KERNEL_CPU_DRIVER_TEMPLATE
#define SHIZUKU_KERNEL_CPU_DRIVER_TEMPLATE
#include <shizuku/operation_result.hpp>
namespace shizuku {
namespace types {
struct thread;

struct cpu_driver_interface {
public:
  virtual int init() = 0;
};
} // namespace types
} // namespace shizuku
#endif // SHIZUKU_KERNEL_CPU_DRIVER_TEMPLATE