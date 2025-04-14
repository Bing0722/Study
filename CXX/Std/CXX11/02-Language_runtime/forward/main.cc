#include <iostream>

void reference(int &v) { std::cout << "左值" << std::endl; }
void reference(int &&v) { std::cout << "右值" << std::endl; }

template <typename T> void pass(T &&v) {
  std::cout << "普通传参: ";
  reference(v);
}

void reference_1(int &v) { std::cout << "左值引用" << std::endl; }
void reference_1(int &&v) { std::cout << "右值引用" << std::endl; }

template <typename T> void pass_1(T &&v) {
  std::cout << "              普通传参:";
  reference_1(v);
  std::cout << "         std::move传参:";
  reference_1(std::move(v));
  std::cout << "      std::forward传参:";
  reference_1(std::forward<T>(v));
  std::cout << "  static_cast<T&&>传参:";
  reference_1(static_cast<T &&>(v));
}

int main(int argc, char *argv[]) {
  std::cout << "传递右值" << std::endl;
  pass(1);

  std::cout << "传递左值" << std::endl;
  int l = 1;
  pass(l);

  std::cout << "===========传递右值==========" << std::endl;
  pass_1(1);

  std::cout << "===========传递左值==========" << std::endl;
  int l_1 = 1;
  pass_1(l_1);

  return 0;
}
