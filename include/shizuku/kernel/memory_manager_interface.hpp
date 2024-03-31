#ifndef SHIZUKU_MEMORY_MANAGER_INTERFACE
#define SHIZUKU_MEMORY_MANAGER_INTERFACE
#include <shizuku/operation_result.hpp>
namespace shizuku {
namespace types {
class memory_manager_interface {
public:
  virtual void init() = 0;
};

} // namespace types

} // namespace shizuku
#endif // SHIZUKU_MEMORY_MANAGER_INTERFACE