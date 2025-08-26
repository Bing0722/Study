#include "FileUtil.h"
#include <cstdio>
#include <unistd.h>

AppendFile::AppendFile(const std::string &filename)
    : fp_(fopen(filename.c_str(), "ae")) {

  // 用于为给定的文件流 设置指定的缓冲区 用于控制缓冲区和管理生命周期
  setbuffer(fp_, buffer_, sizeof buffer_);
}

AppendFile::~AppendFile() { fclose(fp_); }

void AppendFile::append(const char *logline, const size_t len) {
  size_t n = this->write(logline, len);
  size_t remain = len - n;
  while (remain > 0) {
    size_t x = this->write(logline + n, remain);
    if (x == 0) {
      int err = ferror(fp_);
      if (err) {
        fprintf(stderr, "AppendFile::append() failed! \n");
      }
      break;
    }
    n += x;
    remain = len - n;
  }
}

void AppendFile::flush() {
  // 作用是强制将输出缓冲区中的内容写入到实际的文件或设备
  fflush(fp_);
}

size_t AppendFile::write(const char *logline, size_t len) {
  // 在多线程环境下进行高效且无锁的文件写入操作
  // 前提是 要保证他的操作是安全的 同步的
  return fwrite_unlocked(logline, 1, len, fp_);
}
