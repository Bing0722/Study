#include <functional>
#include <iostream>

using foo = void(int);   // 定义别名
void functional(foo f) { // foo 退化为指针形式
  f(1);                  // 通过函数指针调用函数
}

int foo1(int value) { return value; }

int main(int argc, char *argv[]) {
  auto f = [](int value) { std::cout << value << std::endl; };
  functional(f);
  f(1);

  // std::function 包装了一个返回值为 int, 参数为 int 的函数
  std::function<int(int)> func = foo1;

  int important = 10;
  std::function<int(int)> func2 = [&](int value) {
    return 1 + value + important;
  };

  std::cout << func(10) << std::endl;
  std::cout << func2(10) << std::endl;

  return 0;
}
