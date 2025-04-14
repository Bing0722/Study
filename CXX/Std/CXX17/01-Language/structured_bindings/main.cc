#include <iostream>
#include <map>

// 解构 pair tuple map等

int main(int argc, char *argv[]) {
  std::map<int, std::string> map{{1, "a"}, {2, "b"}, {3, "c"}, {4, "d"}};

  // 结构化解构
  for (const auto &[index, value] : map) {
    std::cout << "index: " << index << ", valude: " << value << std::endl;
  }

  return 0;
}
