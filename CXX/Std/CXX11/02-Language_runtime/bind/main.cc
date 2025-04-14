#include <functional>
#include <iostream>

void foo(int a, int b, int c) {
  std::cout << a << " " << b << " " << c << std::endl;
}

struct Foo {
public:
  Foo() {}
  void print_data(int n1, int n2) { std::cout << n1 + n2 << std::endl; }
  int data = 10;
};

int main(int argc, char *argv[]) {
  // std::bind 将对象与参数绑定

  auto f1 = std::bind(foo, std::placeholders::_1, std::placeholders::_2,
                      std::placeholders::_3);

  f1(1, 2, 3);
  foo(1, 2, 3);

  std::function<void(int, int)> f2 =
      std::bind(foo, std::placeholders::_1, std::placeholders::_2, 3);
  f2(1, 2);

  // 绑定指向成员函数指针
  Foo foo3;
  auto f3 = std::bind(&Foo::print_data, &foo3, 40, std::placeholders::_1);
  f3(10);

  // 绑定数据成员指针
  auto f4 = std::bind(&Foo::data, std::placeholders::_1);
  std::cout << f4(foo3) << std::endl;
  return 0;
}
