#include <iostream>

// auto 自动推导返回类型 不能产生歧义
// 如果存在多个返回类型 那么需要类型相同

// c++11 不支持 需要 尾随返回类型
// c++14 支持
auto foo(int i) { return i; }

// 同样c++11 不支持
// c++14 支持
template <typename T> auto foo(T i) { return i; }

int main(int argc, char *argv[]) {
  auto x = foo(2);

  std::cout << "auto " << x << std::endl;

  return 0;
}
