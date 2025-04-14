#include <filesystem>
#include <iostream>

/**
 *
 * std::filesystem::path	                        表示路径（文件或目录）
 * std::filesystem::directory_entry	              表示目录中的文件项
 * std::filesystem::directory_iterator	          用于遍历目录
 * std::filesystem::recursive_directory_iterator	递归遍历目录
 *
 */

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  for (const auto &p : fs::directory_iterator("../")) {
    std::cout << p.path() << std::endl;
  }

  if (fs::exists("text.txt")) {
    std::cout << "没有 text.txt 文件" << std::endl;
  } else {
    std::cout << "有 text.txt 文件" << std::endl;
  }

  if (fs::is_regular_file("file.txt")) {
    std::cout << "file.txt 不是一个文件" << std::endl;
  } else {
    std::cout << "file.txt 是一个文件" << std::endl;
  }

  if (fs::is_directory("folder/")) {
    std::cout << "folder是一个目录" << std::endl;
  } else {
    std::cout << "folder 不是一个目录" << std::endl;
  }

  auto size = fs::file_size("Makefile");
  std::cout << "Makefile size: " << size << std::endl;

  auto time = fs::last_write_time("Makefile");
  std::cout << "Makefile time: " << time.time_since_epoch().count()
            << std::endl;

  fs::path base = "home/Bing";
  // 路径拼接
  fs::path full = base / "Download" / "notes.txt";

  return 0;
}
