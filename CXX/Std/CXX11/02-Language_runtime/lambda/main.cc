#include <iostream>

void lambda_value_capture() {
  int value = 1;
  std::cout << "lambda outer: " << std::addressof(value) << std::endl;
  // 按值捕获
  auto copy_value = [value] {
    std::cout << "lambda inner: " << std::addressof(value) << std::endl;
    return value;
  };

  value = 100;
  auto store_value = copy_value();
  std::cout << "store_value: " << store_value << std::endl;
}

void lambda_reference_capture() {
  int value = 1;
  std::cout << "lambda outer: " << std::addressof(value) << std::endl;
  // 引用捕获
  // 在异步中 防止悬垂指针
  auto copy_value = [&value] {
    std::cout << "lambda inner: " << std::addressof(value) << std::endl;
    return value;
  };

  value = 100;
  auto store_value = copy_value();
  std::cout << "store_value: " << store_value << std::endl;
}

int main(int argc, char *argv[]) {
  lambda_value_capture();
  lambda_reference_capture();
  return 0;
}
