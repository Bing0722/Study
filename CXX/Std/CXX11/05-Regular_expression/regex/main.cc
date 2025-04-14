#include <iostream>
#include <regex>

int main(int argc, char *argv[]) {
  std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};

  std::regex txt_regex("[a-z]+\\.txt");
  for (const auto &fname : fnames) {
    std::cout << fname << ": " << std::regex_match(fname, txt_regex)
              << std::endl;
  }

  std::cout << "" << std::endl;
  return 0;
}
