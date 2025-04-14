#include <iostream>

struct Base {
  int id;
};

struct Derived : Base {
  std::string name;
};

int main(int argc, char *argv[]) {
  Derived d1{1, "bing"}; // c++17允许 c++11 不允许

  std::cout << d1.name << std::endl;

  return 0;
}
