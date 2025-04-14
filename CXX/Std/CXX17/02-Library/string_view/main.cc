#include <iostream>
#include <string_view>

// std::string_view 是一个只读字符串的视图
// 它不拥有数据本身，只记录字符串的起始地址和长度。

int main(int argc, char *argv[]) {
  // 构造
  std::string_view sv1 = "abc"; // 字面量
  std::string str = "hello";
  std::string_view sv2 = str;           // 从 std::string
  std::string_view sv3 = str.data();    // 从 C 风格的字符串
  std::string_view sv4{str.c_str(), 3}; // 从部分字符串

  std::cout << "sv1 size: " << sv1.size() << " data: " << sv1.data()
            << std::endl;
  std::cout << "sv2 size: " << sv2.size() << " data: " << sv2.data()
            << std::endl;
  std::cout << "sv3 size: " << sv3.size() << " data: " << sv3.data()
            << std::endl;
  std::cout << "sv4 size: " << sv4.size() << " data: " << sv4.data()
            << std::endl;

  std::string_view sv;
  {
    std::string str = "hello";
    sv = str;
  } // ⚠️ str 已销毁，sv 指向无效内存！
  std::cout << sv << '\n'; // ❌ 未定义行为

  return 0;
}
