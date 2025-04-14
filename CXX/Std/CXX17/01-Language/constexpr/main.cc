#include <iostream>

// 扩展constexpr使用范围，可用于if语句中，也可用于lambda表达式中。
template <bool ok> constexpr void foo() {
  // 在编译期进行判断，if和else语句不生成代码
  if constexpr (ok == true) {
    // 当ok为true时，下面的else块不生成汇编代码
    std::cout << "ok" << std::endl;
  } else {
    // 当ok为false时，上面的if块不生成汇编代码
    std::cout << "not ok" << std::endl;
  }
}

int main(int argc, char *argv[]) {
  // 输出ok，并且汇编代码中只有std::cout << "ok" << std::endl;这一句
  foo<true>();
  // 输出not ok，并且汇编代码中只有std::cout << "not ok" << std::endl;这一句
  foo<false>();
  return 0;
}
