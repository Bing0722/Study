#include <future>
#include <iostream>
#include <thread>

int calculate_sum(int a, int b) {
  std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
  return a + b;
}

void perform_task(std::promise<std::string> promise) {
  try {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    promise.set_value("Task completed successfully!");
  } catch (...) {
    promise.set_exception(std::current_exception());
  }
}

int main(int argc, char *argv[]) {
  // 将一个返回值为7的 lambda 表达式封装到 task 中
  // std::packaged_task 的模板参数为要封装函数的类型
  std::packaged_task<int()> task([] { return 7; });

  // 获得 task 的future
  std::future<int> result = task.get_future();

  std::thread(std::move(task)).detach(); // 在一个线程中执行 task
  std::cout << "waitting..";
  result.wait(); // 在此设置屏障，阻塞到future的完成

  std::cout << "done!" << std::endl
            << "future result is " << result.get() << std::endl;

  // async
  std::cout << "Starting asynchronous calculation..." << std::endl;
  std::future<int> result_future =
      std::async(std::launch::async, calculate_sum, 5, 10);

  std::cout << "Doing other work..." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));

  std::cout << "Waiting for result..." << std::endl;
  int sum = result_future.get(); // 阻塞直到结果可用，并获取结果

  std::cout << "Sum is: " << sum << std::endl;

  // promise
  std::promise<std::string> task_promise;
  std::future<std::string> task_future = task_promise.get_future();

  std::thread t(perform_task, std::move(task_promise)); // 注意移动 promise

  std::cout << "Waiting for task to complete..." << std::endl;
  try {
    std::string result = task_future.get();
    std::cout << "Result: " << result << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  t.join();
  return 0;
}
