#include <shizuku/kernel/cpu_manager.hpp>

using namespace shizuku::types;

cpu_manager::cpu_manager(size_t core_num)
    : core_num{core_num}, driver{core_num, *this} {

      };