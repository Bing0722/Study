#include <array>
#include <iostream>
#include <vector>

void vec_() {
  std::vector<int> v;
  std::cout << "size: " << v.size() << std::endl;         // size: 0
  std::cout << "capacity: " << v.capacity() << std::endl; // capacity: 0

  // 如下可看出 std::vector 的存储是自动管理的，按需自动扩张
  // 但是如果空间不足，需要重新分配更多内存，而重分配内存通常是性能上有开销的操作
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  std::cout << "size: " << v.size() << std::endl;         // size: 3
  std::cout << "capacity: " << v.capacity() << std::endl; // capacity: 4

  v.push_back(4);
  v.push_back(5);
  std::cout << "size: " << v.size() << std::endl;         // size: 5
  std::cout << "capacity: " << v.capacity() << std::endl; // capacity: 8

  // 如下可看出容器虽然清空了元素，但是被清空元素的内存并没有归还
  v.clear();
  std::cout << "size: " << v.size() << std::endl;         // size: 0
  std::cout << "capacity: " << v.capacity() << std::endl; // capacity: 8

  // 额外内存可通过 shrink_to_fit() 调用返回给系统
  v.shrink_to_fit();
  std::cout << "size: " << v.size() << std::endl;         // size: 0
  std::cout << "capacity: " << v.capacity() << std::endl; // capacity: 0
}

int main(int argc, char *argv[]) {
  // 由于std::vector是自动扩容的，当存入大量的数据后，
  // 并且对容器进行了删除操作，容器并不会自动归还被删除元素相应的内存，
  // 这时候就需要手动运行shrink_to_fit() 释放这部分内
  // vec_();

  // std::array 的优点
  // 如果容器大小是固定的，那么可以优先考虑使用 std::array 容器
  std::array<int, 4> arr = {1, 2, 3};
  std::cout << "size: " << arr.size() << std::endl;

  return 0;
}
