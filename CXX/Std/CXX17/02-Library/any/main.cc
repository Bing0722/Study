#include <any>
#include <iostream>

// 使用 any_cast<T>() 类型不匹配会抛出异常 建议使用 try-catch

int main(int argc, char *argv[]) {
  std::any s = 2;
  // 提取 T 类型的值
  int a = std::any_cast<int>(s);
  std::cout << "a: " << a << std::endl;

  s = std::string("11111");
  std::string b = std::any_cast<std::string>(s);
  std::cout << "b: " << b << std::endl;

  s = 3.14;
  // 判断类型
  if (s.type() == typeid(double)) {
    std::cout << "a contains a double." << std::endl;
  }

  if (double *p = std::any_cast<double>(&s)) {
    std::cout << "value: " << *p << std::endl;
  } else {
    std::cout << "type mismatch" << std::endl;
  }
  return 0;
}
