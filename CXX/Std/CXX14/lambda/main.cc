#include <iostream>

int main(int argc, char *argv[]) {
  // c++11 需要指定 lambda中的参数类型
  auto f1 = [](int a) { return a; };
  auto f2 = [](auto a) { return a; };
  std::cout << f1(2) << std::endl;
  std::cout << f2("2") << std::endl;
  return 0;
}
