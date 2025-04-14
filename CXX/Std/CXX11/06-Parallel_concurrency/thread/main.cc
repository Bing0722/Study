#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

int v = 1;

void critical_section(int changeV) {
  static std::mutex mtx;
  // std::lock_guard<std::mutex> lock(mtx);
  // 尽量使用这个 可以任意位置调用 lock和unlock
  std::unique_lock<std::mutex> lock(mtx);

  v = changeV;
}

int main(int argc, char *argv[]) {
  std::thread t1([] { std::cout << "Hello, World!" << std::endl; });

  std::cout << "thread id: " << t1.get_id() << std::endl;
  t1.join();

  std::thread t2(critical_section, 3), t3(critical_section, 4);
  t2.join();
  t3.join();

  std::queue<int> produced_nums;
  std::mutex mtx;
  std::condition_variable cv;
  bool notified = false; // 通知信号

  // 生产者
  auto producer = [&]() {
    for (int i = 0;; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(900));
      std::unique_lock<std::mutex> lock(mtx);
      std::cout << "producing " << i << std::endl;
      produced_nums.push(i);
      notified = true;
      cv.notify_all(); // 此处也可以使用 notify_one
    }
  };
  // 消费者
  auto consumer = [&]() {
    while (true) {
      std::unique_lock<std::mutex> lock(mtx);
      // while (!notified) { // 避免虚假唤醒
      //   cv.wait(lock);
      // }
      // 返回 false 释放锁并等待 返回true 加锁并离开
      cv.wait(lock, [&notified] { return !notified; });
      // 短暂取消锁，使得生产者有机会在消费者消费空前继续生产
      lock.unlock();
      // 消费者慢于生产者
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      lock.lock();
      while (!produced_nums.empty()) {
        std::cout << "consuming " << produced_nums.front() << std::endl;
        produced_nums.pop();
      }
      notified = false;
    }
  };

  // 分别在不同的线程中运行
  std::thread p(producer);
  std::thread cs[2];
  for (int i = 0; i < 2; ++i) {
    cs[i] = std::thread(consumer);
  }
  p.join();
  for (int i = 0; i < 2; ++i) {
    cs[i].join();
  }
  return 0;
}
