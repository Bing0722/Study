#include <iostream>
#include <vector>

class Foo {
public:
  int value_a;
  int value_b;
  Foo(int a, int b) : value_a(a), value_b(b) {}
};

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    for (std::initializer_list<int>::iterator it = list.begin();
         it != list.end(); ++it)
      vec.push_back(*it);
  }
};

int main(int argc, char *argv[]) {
  // before C++11
  int arr[3] = {1, 2, 3};
  Foo foo(1, 2);
  std::vector<int> vec = {1, 2, 3, 4, 5};

  std::cout << "arr[0]: " << arr[0] << std::endl;
  std::cout << "foo: " << foo.value_a << ", " << foo.value_b << std::endl;

  std::cout << "Foo: ";
  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  // after C++11 可以使用 {} 进行构造
  Foo foo2{1, 2};
  MagicFoo magicFoo{1, 2, 3, 4, 5};

  std::cout << "foo2: " << foo2.value_a << ", " << foo2.value_b << std::endl;

  std::cout << "magicFoo: ";
  for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;

  return 0;
}
