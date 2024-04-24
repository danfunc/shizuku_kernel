#ifdef SHIZUKU_CONFIGURED_BY_CMAKE // error squiggle disable in template
#ifndef SHIZUKU_KERNEL_CONFIG
#define SHIZUKU_KERNEL_CONFIG
#include "shizuku/kernel/cpu_arch/${SHIZUKU_CPU_ARCH}.hpp"
#include "shizuku/kernel/interfaces/cpu_driver_interface.hpp"
#include "shizuku/kernel/interfaces/interface_interceptor.hpp"
#include "shizuku/kernel/interfaces/memory_manager_interface.hpp"
#include "shizuku/kernel/platform/${SHIZUKU_PLATFORM}.hpp"
namespace shizuku {
namespace types {
using cpu_driver = ${SHIZUKU_CPU_ARCH};
using thread_context = cpu_driver::context;

} // namespace types
} // namespace shizuku
#endif // SHIZUKU_KERNEL_CONFIG
#endif