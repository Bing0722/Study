#include <iostream>
#include <memory>

struct A;
struct B;

struct A {
  std::shared_ptr<B> pointer;

  ~A() { std::cout << "A delete" << std::endl; }
};

struct B {
  std::shared_ptr<A> pointer;
  ~B() { std::cout << "B deldete" << std::endl; }
};

struct C;
struct D;

struct C {
  std::shared_ptr<D> pointer;
  ~C() { std::cout << "C delete" << std::endl; }
  void print() { std::cout << "A" << std::endl; }
};

struct D {
  std::weak_ptr<C> pointer; // 改成 weak_ptr
  ~D() { std::cout << "D delete" << std::endl; }
  void printA() {
    if (!pointer.expired()) { // 监视 shared_ptr 的生命周期
      auto ptr = pointer.lock();
      ptr->print();
    }
  }
};

int main(int argc, char *argv[]) {
  // 循环引用 内存泄漏
  // auto aptr = std::make_shared<A>();
  // auto bptr = std::make_shared<B>();
  // aptr->pointer = bptr;
  // bptr->pointer = aptr;

  // 正确的使用
  auto aptr = std::make_shared<C>();
  auto bptr = std::make_shared<D>();
  aptr->pointer = bptr;
  bptr->pointer = aptr;
  aptr->print();
  bptr->printA();

  return 0;
}
