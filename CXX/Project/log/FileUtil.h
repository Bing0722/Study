#ifndef _FILE_UTIL_H
#define _FILE_UTIL_H

#include "noncopyable.h"
#include <cstdio>
#include <string>

class AppendFile : public NonCopyable {
public:
  explicit AppendFile(const std::string &filename);
  ~AppendFile();

  // 追加
  void append(const char *logline, const size_t len);
  void flush();

private:
  // 写操作
  size_t write(const char *logline, size_t len);
  FILE *fp_;
  char buffer_[64 * 1024];
};

#endif // _FILE_UTIL_H
