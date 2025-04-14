#include <iostream>

// c++11 委托构造
class Base {
public:
  int value1;
  int value2;
  Base() { value1 = 1; }
  Base(int value) : Base() { // 委托 Base() 构造函数
    value2 = 2;
  }

  virtual void foo() {}
  virtual void foo(int) {}
};

// c++11 继承构造
struct Subclass : Base {
public:
  using Base::Base; // 继承构造

  void foo() override {}
  void foo(int) final override {}
};

struct Subclass2 : Subclass {
  using Subclass::Subclass;
  void foo() override {}
  // void foo(int) override; // 不允许在重写
};

// c++11 显示拒绝
// 尽量不要在 `private` 中声明 不优雅
class Magic {
public:
  Magic() = default;                        // 显式声明使用编译器生成的构造
  Magic &operator=(const Magic &) = delete; // 显式声明拒绝编译器生成构造
  Magic(int magic_number);
};

// c++11 强类型枚举
enum class new_enum : unsigned int {
  value1,
  value2,
  value3 = 100,
  value4 = 100,
};

int main(int argc, char *argv[]) {

  Base b(2);
  std::cout << b.value1 << std::endl;
  std::cout << b.value2 << std::endl;

  Subclass s(3);

  std::cout << s.value1 << std::endl;
  std::cout << s.value2 << std::endl;

  if (new_enum::value3 == new_enum::value4) {
    // 会输出true
    std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
  }

  return 0;
}
