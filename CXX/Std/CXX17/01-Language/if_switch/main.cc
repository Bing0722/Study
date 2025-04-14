#include <iostream>
#include <map>
#include <utility>

int main(int argc, char *argv[]) {
  // c++17 之前
  std::map<int, std::string> c = {{1, "a"}};
  {
    // res 作用域在这个大括号内
    auto res = c.insert(std::make_pair(2, "b"));
    if (!res.second) {
      std::cout << "key 1 exist" << std::endl;
    } else {
      std::cout << "insert success, value: " << res.first->second << std::endl;
    }
  }

  // c++17 可以直接在 if 语句中进行初始化
  // res 的作用域在if 结束
  if (auto res = c.insert(std::make_pair(3, "c")); !res.second) {
    std::cout << "key 1 exist" << std::endl;
  } else {
    std::cout << "insert success, value: " << res.first->second << std::endl;
  }

  return 0;
}
