#include <iostream>

// c++14 放宽了 constexpr 的限制 可以在constexpr 中使用局部变量

// constexpr int factorial(int n) { // C++14 和 C++11均可
//    return n <= 1 ? 1 : (n * factorial(n - 1));
// }

constexpr int factorial(int n) { // C++11中不可，C++14中可以
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += i;
  }
  return ret;
}

// constexpr int func(bool flag) { // C++14 和 C++11均可
//    return 0;
// }

constexpr int func(bool flag) { // C++11中不可，C++14中可以
  if (flag)
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[]) {

  std::cout << factorial(10) << std::endl;
  std::cout << func(true) << std::endl;

  return 0;
}
