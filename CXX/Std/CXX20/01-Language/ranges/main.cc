#include <iostream>
#include <ranges>
#include <vector>

int main(int argc, char *argv[]) {
  // filter 过滤元素 transform 元素映射
  auto v2 = std::views::iota(1, 10) |
            std::views::filter([](auto x) { return x % 2 == 0; }) |
            std::views::transform([](auto x) { return x; });

  for (const auto x : v2) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  // drop 跳过前几个元素 take 截取前几个元素
  std::vector<int> v3{10, 20, 30, 40, 50};
  auto sub = v3 | std::views::drop(1) | std::views::take(3);

  for (const auto x : sub) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
