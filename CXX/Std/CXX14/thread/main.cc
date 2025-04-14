#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <vector>

// c++14 新增的共享互斥锁  带超时能力
std::shared_timed_mutex rw_mutex;
int shared_data = 0;

void reader(int id) {
  // 获取共享锁，允许多个 reader 同时读
  std::shared_lock<std::shared_timed_mutex> lock(rw_mutex);
  std::cout << "Reader " << id << " sees: " << shared_data << "\n";
}

void writer() {
  // 获取独占锁，阻塞其他读写线程
  std::unique_lock<std::shared_timed_mutex> lock(rw_mutex);
  ++shared_data;
  std::cout << "Writer updated data to: " << shared_data << "\n";
}

int main() {
  std::vector<std::thread> threads;

  threads.emplace_back(writer); // 一个写线程

  for (int i = 0; i < 5; ++i) {
    threads.emplace_back(reader, i); // 多个读线程
  }

  for (auto &t : threads) {
    t.join();
  }

  return 0;
}
