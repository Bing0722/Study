#include <iostream>

// 可以防止重要函数的返回值被意外忽略，比如资源句柄、状态码等
[[nodiscard("未使用的返回值")]] int add(int a, int b) { return a + b; }

// 避免未使用警告
void log(int a, [[maybe_unused]] int b) {
  std::cout << "a: " << a << std::endl;
}

// 告诉编译器，这个函数不会返回，优化时可能会用上。
[[noreturn]] void panic() { throw std::runtime_error("fatal"); }

int main(int argc, char *argv[]) {
  auto x = add(1, 2);

  std::cout << "x: " << x << std::endl;

  return 0;
}
