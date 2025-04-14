#include <iostream>
#include <type_traits>
#include <vector>

std::vector<int> foo() {
  std::vector<int> temp = {1, 2, 3, 4};
  return temp; // 将亡值 (xvalue )
}

void reference(std::string &str) { std::cout << "左值" << std::endl; }

void reference(std::string &&str) { std::cout << "右值" << std::endl; }

int main(int argc, char *argv[]) {
  // "01234" 是左值
  const char (&left)[6] = "01234";
  // 断言正确
  static_assert(std::is_same<decltype("01234"), const char (&)[6]>::value, "");

  std::vector<int> v = foo(); // 触发移动语义

  std::string lv1 = "string,"; // rv1 左值
  // std::string &&r1 = rv1; // 非法
  std::string &&rv1 = std::move(lv1); // 合法， move将左值转化为右值
  std::cout << rv1 << std::endl;      // string,

  const std::string &lv2 = lv1 + lv1; // 合法, 常量左值能延长临时变量的生命周期
  // lv2 += "Test"; // 常量引用无法修改
  std::cout << lv2 << std::endl; // string,string,

  std::string &&rv2 = lv1 + lv2; // 右值引用延长临时变量的生命周期
  rv2 += "Test";                 // 非常量接受修改
  std::cout << rv2 << std::endl;

  reference(rv2); // 左值

  return 0;
}
