#include <iostream>

template <typename T, typename U, int value> class SuckType {
public:
  T a;
  T b;
  SuckType() : a(value), b(value) {}
};

// template <typename U>
// typedef SuckType<std::vector<int>, U, 1> NewType; // 不合法

// c++11
template <typename T> using NewType = SuckType<int, T, 1>; // 合法

// template <typename T, typename U> auto add(T x, U y) -> decltype(x + y) {
//   return x + y;
// }

// c++11 提供了指定模板默认参数
template <typename T = int, typename U = int>
auto add(T x, U y) -> decltype(x + y) {
  return x + y;
}

// 计算变长模板参数的长度
template <typename... Ts> void magic(Ts... args) {
  std::cout << sizeof...(args) << std::endl;
}

template <typename... Args> void printf(const std::string &str, Args... args);

// c++11
template <typename T0> void printf1(T0 value) {
  std::cout << value << std::endl;
}

template <typename T, typename... Ts> void printf1(T value, Ts... args) {
  std::cout << value << std::endl;
  printf1(args...);
}

// c++17
template <typename T, typename... Ts> void printf2(T value, Ts... args) {
  std::cout << value << std::endl;
  if constexpr (sizeof...(args) > 0) {
    printf2(args...);
  }
}

int main(int argc, char *argv[]) {
  magic();
  magic(1);
  magic(1, "");

  printf1(1);
  printf1("");
  printf1(1, "s", 2.6);

  printf2(1);
  printf2(1, 2, 3, 4);
  return 0;
}
