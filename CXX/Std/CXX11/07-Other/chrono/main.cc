#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[]) {
  auto time = std::chrono::system_clock::now();
  std::cout << time.time_since_epoch().count() << std::endl;
  std::time_t now_c = std::chrono::system_clock::to_time_t(time);
  std::tm now_tm;
  localtime_r(&now_c, &now_tm);

  std::cout << "Current local time: "
            << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << std::endl;

  return 0;
}
