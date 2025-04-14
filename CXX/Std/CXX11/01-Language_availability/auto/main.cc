#include <initializer_list>
#include <iostream>
#include <vector>

class MagicFoo {
public:
  std::vector<int> vec;
  MagicFoo(std::initializer_list<int> list) {
    // auto 关键字进行类型推导
    for (auto it = list.begin(); it != list.end(); ++it) {
      vec.push_back(*it);
    }
  }
};

int main(int argc, char *argv[]) {
  MagicFoo magicFoo = {1, 2, 3, 4, 5};

  std::cout << "magicFoo: ";
  for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
    std::cout << *it << ", ";
  }
  std::cout << std::endl;
  return 0;
}
