#include <iostream>
#define LEN 10

int len_foo() {
  int i = 2;
  return i;
}

constexpr int len_foo_constexpr() { return 5; }

constexpr int fibonacci(const int n) {
  return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

// 数组定义时不能使用变量作为数组的长度, 必须使用一个编译时常量表达式
int main(int argc, char *argv[]) {
  char arr_1[10];
  char arr_2[LEN];

  int len = 10;
  // char arr_3[len]; //  非法

  const int len_2 = len + 1;
  constexpr int len_2_constexpr = 1 + 2 + 3;
  // char arr_4[len_2]; // 非法
  char arr_5[len_2_constexpr];

  // char arr_6[len_foo() + 5]; // 非法
  char arr_7[len_foo_constexpr() + 1];

  std::cout << fibonacci(10) << std::endl;
  std::cout << fibonacci(10) << std::endl;

  return 0;
}
