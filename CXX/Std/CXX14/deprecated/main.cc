#include <iostream>

// 弃用警告
struct [[deprecated("不要使用!")]] A;

struct A {};

int main(int argc, char *argv[]) {
  A a;
  std::cout << "不要使用" << std::endl;
  return 0;
}
