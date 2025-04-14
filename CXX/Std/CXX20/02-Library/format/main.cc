#include <format>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string s1 = std::format("Hello, {}", "World");
  std::cout << s1 << std::endl;

  // 格式化
  int n = 42;
  std::cout << std::format("{:04}", n) << std::endl; // 0042
  std::cout << std::format("{:#x}", n) << std::endl; // 0x2a
  std::cout << std::format("{:b}", n) << std::endl;  // 101010（二进制）
  std::cout << std::format("{:+}", n) << std::endl;  // +42

  double pi = 3.1415926;
  std::cout << std::format("{:.2f}", pi) << std::endl;   // 3.14
  std::cout << std::format("{:10.2f}", pi) << std::endl; // "      3.14"
  std::cout << std::format("{:e}", pi) << std::endl; // 科学计数法：3.141593e+00

  std::cout << std::format("{:*>8}", 42) << std::endl; // "******42"
  std::cout << std::format("{:_<8}", 42) << std::endl; // "42______"
  std::cout << std::format("{:.^8}", 42) << std::endl; // "..42...."
  return 0;
}
