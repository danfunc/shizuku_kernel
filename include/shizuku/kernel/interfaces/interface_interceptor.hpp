#ifndef SHIZUKU_KERNEL_INTERFACE_INTERCEPTOR
#define SHIZUKU_KERNEL_INTERFACE_INTERCEPTOR
#include <concepts>
namespace shizuku {
namespace types {
template <typename INTERFACE_CLASS, typename INHERITANCE_CLASS>
requires std::derived_from<INHERITANCE_CLASS, INTERFACE_CLASS>
struct INTERFACE_INTERCEPTOR final : INHERITANCE_CLASS {
};
} // namespace types

} // namespace shizuku

#endif // SHIZUKU_KERNEL_INTERFACE_INTERCEPTOR