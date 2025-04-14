#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<int> vec{1, 2, 3, 4, 5};

  for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << std::endl;
  }

  for (auto &element : vec) {
    element += 1;
  }

  for (auto element : vec) {
    std::cout << element << std::endl;
  }

  return 0;
}
