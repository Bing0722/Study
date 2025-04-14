#include <iostream>

/**
 * c++17
 *
 * 一元左折叠
 * (... op pack)
 *
 * 一元右折叠
 * (pack op ...)
 *
 * 二元左折叠
 * (init op ... op pack)
 *
 * 二元右折叠
 * (pack op ... op init)
 *
 */

template <typename... Args> void print(Args... args) {
  (std::cout << ... << args) << std::endl; // 一元左折叠
}

template <typename... Args> auto sum(Args... args) {
  return (0 + ... + args); // 二元左折叠
}

template <typename... Args> std::string concat(Args... args) {
  return (args + ... + std::string("END")); // 二元右折叠
}

int main(int argc, char *argv[]) {
  std::cout << sum(1, 2, 3, 4, 5) << std::endl;
  std::cout << sum() << std::endl;

  print("111");
  print();

  std::cout << concat("A", "B", "C") << std::endl;

  return 0;
}
