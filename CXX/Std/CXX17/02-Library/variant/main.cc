#include <iostream>
#include <string>
#include <variant>

int main(int argc, char *argv[]) {
  // 类型安全的联合体 使用 std::get std::visit 来访问这个值
  std::variant<int, double, std::string> v;

  v = 42;
  std::cout << std::get<int>(v) << std::endl;

  v = 3.1;
  std::cout << std::get<double>(v) << std::endl;

  v = "Hello";
  std::cout << std::get<std::string>(v) << std::endl;

  // 根据最后覆盖的类型
  std::visit([](auto &&arg) { std::cout << "value: " << arg << std::endl; }, v);

  return 0;
}
