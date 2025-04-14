#include <concepts>
#include <iostream>
#include <type_traits>

// 模板约束

// 旧方式：SFINAE + enable_if
template <typename T>
[[nodiscard("unused return value")]] std::enable_if_t<std::is_integral_v<T>, T>
increment(T value) {
  return value + 1;
}

// C++20 Concepts
template <std::integral T> T increment_cxx20(T value) { return value + 1; }

// requires 约束表达式 与上面等价
template <typename T>
  requires std::integral<T>
T add_one(T value) {
  return value + 1;
}

// 自定义 concepts
// 可以对两个 T 类型的值执行 a + b
// 且结果类型是 T 本身
template <typename T>
concept Addable = requires(T a, T b) {
  { a + b } -> std::same_as<T>;
};

int main(int argc, char *argv[]) {
  auto x = increment(2);
  std::cout << "x: " << x << std::endl;

  return 0;
}
