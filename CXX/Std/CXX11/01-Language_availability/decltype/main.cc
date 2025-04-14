#include <iostream>
#include <type_traits>

// 返回值后置类型语法
// decltype 需要知道 变量的定义
template <typename T, typename U> auto add2(T x, U y) -> decltype(x + y) {
  return x + y;
}

int main(int argc, char *argv[]) {
  auto x = 1;
  auto y = 2;
  decltype(x + y) z;
  if (std::is_same<decltype(x), int>::value) {
    std::cout << "type x == int" << std::endl;
  }
  if (std::is_same<decltype(x), float>::value) {
    std::cout << "type x == float" << std::endl;
  }
  if (std::is_same<decltype(x), decltype(z)>::value) {
    std::cout << "type x == type z" << std::endl;
  }
  auto n = add2(1, 'c');
  std::cout << n << std::endl;
  return 0;
}
