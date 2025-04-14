#include <iostream>
#include <utility>

// 编译器的整数序列
template <std::size_t... Ints> void print(std::index_sequence<Ints...>) {
  ((std::cout << Ints << " "), ...); // ... 是c++17
}

int main(int argc, char *argv[]) {
  auto s = std::make_index_sequence<5>{};
  print(s);

  return 0;
}
