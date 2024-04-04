#ifndef SHIZUKU_MEMORY_MANAGER_INTERFACE
#define SHIZUKU_MEMORY_MANAGER_INTERFACE
#include <cstdint>
#include <shizuku/operation_result.hpp>
namespace shizuku {
namespace types {
class memory_manager_interface {
public:
  virtual void init() noexcept = 0;
  virtual void *malloc(size_t size) noexcept = 0;
  virtual void free(size_t size) noexcept = 0;
};

} // namespace types

} // namespace shizuku
#endif // SHIZUKU_MEMORY_MANAGER_INTERFACE