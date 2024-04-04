#ifndef SHIZUKU_KERNEL_METHOD
#define SHIZUKU_KERNEL_METHOD
#include <stdint.h>
namespace shizuku {
namespace types {
using method = void (*)(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
}
} // namespace shizuku
#endif // SHIZUKU_KERNEL_METHOD