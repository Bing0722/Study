#include <iostream>

// 扩展static_assert用法，静态断言的显示文本可选。
int main(int argc, char *argv[]) {
  static_assert(true, "");
  // static_assert(false);
  return 0;
}
