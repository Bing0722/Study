#include <iostream>
#include <memory>
#include <utility>

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Foo {
  Foo() { std::cout << "Foo::Foo()" << std::endl; }
  ~Foo() { std::cout << "Foo::~Foo()" << std::endl; }
  void foo() { std::cout << "Foo::foo()" << std::endl; }
};

void f(const Foo &) { std::cout << "f(const Foo&)" << std::endl; }

int main(int argc, char *argv[]) {
  std::unique_ptr<Foo> p1(make_unique<Foo>());
  // p1 不为空 输出
  if (p1) {
    p1->foo();
  }

  {
    std::unique_ptr<Foo> p2(std::move(p1));
    // p2 不为空 输出
    f(*p2);
    if (p2) {
      p2->foo();
    }
    // p1 为空 无输出
    if (p1) {
      p1->foo();
    }

    p1 = std::move(p2);
    // p2 为空 无输出
    if (p2) {
      p2->foo();
    }
    std::cout << "p2 被销毁" << std::endl;
  }
  // p1 不为空 输出
  if (p1) {
    p1->foo();
  }
  return 0;
}
