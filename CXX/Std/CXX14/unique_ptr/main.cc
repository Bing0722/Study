#include <iostream>
#include <memory>

// c++14新增 std::make_unique<>()

struct Foo {
public:
  Foo() {}
  void foo() { std::cout << "Foo::foo()" << std::endl; }
};

int main(int argc, char *argv[]) {
  // c++14新增 std::make_unique<>()
  auto ptr = std::make_unique<Foo>();

  {
    auto ptr2 = std::move(ptr);
    ptr2->foo();
  }
  if (ptr) {
    ptr->foo();
  }

  return 0;
}
