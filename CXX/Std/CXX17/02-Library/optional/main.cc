#include <iostream>
#include <optional>

std::optional<int> find_id(bool ok) {
  if (ok) {
    return 42;
  }
  return std::nullopt;
}

int main(int argc, char *argv[]) {
  auto n = find_id(false);
  if (n.has_value()) {
    std::cout << "值存在 :" << n.value() << std::endl;
  } else {
    std::cout << "值不存在" << std::endl;
  }

  std::optional<int> v1;
  if (v1) {
    std::cout << "value: " << *v1 << std::endl;
  } else {
    std::cout << "没有值" << std::endl;
  }

  v1 = 42;

  if (v1) {
    std::cout << "value: " << *v1 << std::endl;
  } else {
    std::cout << "没有值" << std::endl;
  }

  v1 = std::nullopt; // 清楚值 变为空

  return 0;
}
