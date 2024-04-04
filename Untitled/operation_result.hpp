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

template <typename T> struct operation_result {
  error_code result;
  T &returned_value;
  operation_result(T &return_value) {
    result = error_code::success;
    returned_value = return_value;
  }
  operation_result(error_code result) { this->result = result; }
  operation_result(error_code result, T &return_value) {
    this->result = result;
    this->returned_value = return_value;
  }
};
template <typename T>
requires std::integral<T>
struct operation_result<T> {
  error_code result;
  T value;
};

} // namespace types

} // namespace shizuku

#endif // SHIZUKU_OPERATION_RESULT