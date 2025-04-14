#include <iostream>

class Foo {
public:
  Foo() {}
  void print_this_addr_1() { std::cout << "Foo this: " << this << std::endl; }
  void print_this_addr_2() {
    auto f = [this]() { std::cout << "Foo [this]:" << this << std::endl; };
    f();
  }
  void print_this_addr_3() {
    auto f = [=] { std::cout << "Foo [=]: " << this << std::endl; };
    f();
  }
};

int main(int argc, char *argv[]) {
  Foo foo;
  foo.print_this_addr_1();
  foo.print_this_addr_2();
  foo.print_this_addr_3();
  return 0;
}
