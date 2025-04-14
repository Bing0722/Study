#include <bit>
#include <cstdint>
#include <iostream>

int main(int argc, char *argv[]) {
  uint32_t x = 42;
  std::cout << "has_single_bit(判断是否为2 的幂数): " << std::has_single_bit(x)
            << std::endl;
  std::cout << "bit_ceil(返回最接近x 的2 的幂): " << std::bit_ceil(x)
            << std::endl;
  std::cout << "bit_floor: " << std::bit_floor(x) << std::endl;
  std::cout << "bit_width(计算表示x 至少需要多少个bit):" << std::bit_width(x)
            << std::endl;
  std::cout << "countl_zero" << std::countl_zero(x) << std::endl;
  std::cout << "popcount: " << std::popcount(x) << std::endl;

  return 0;
}
