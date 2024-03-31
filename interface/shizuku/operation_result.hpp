#ifndef SHIZUKU_OPERATION_RESULT
#define SHIZUKU_OPERATION_RESULT
#include <concepts>
#include <cstdint>

namespace shizuku {
namespace types {
enum struct error_code : intptr_t {
  success = 0,
  noerror = 0,
  lack_of_memory,
};

template <typename T> struct operation_result {};

} // namespace types

} // namespace shizuku

#endif // SHIZUKU_OPERATION_RESULT