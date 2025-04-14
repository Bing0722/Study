#include <iostream>

template <typename T, typename U> struct A {
  T t;
  U u;
};

// 别名模板
template <typename T> using B = A<T, int>;

// 变量模板
template <class T> constexpr T pi = T(3.1415926535897932385L);

int main() {
  B<double> b;
  b.t = 10;
  b.u = 20;
  std::cout << b.t << std::endl;
  std::cout << b.u << std::endl;

  std::cout << pi<int> << std::endl;    // 3
  std::cout << pi<double> << std::endl; // 3.14159
  return 0;
}
