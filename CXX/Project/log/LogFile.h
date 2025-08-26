#ifndef _LOG_FILE_H
#define _LOG_FILE_H

#include "FileUtil.h"
#include "MutexLock.h"
#include "noncopyable.h"
#include <memory>
#include <string>

class LogFile : NonCopyable {
public:
  LogFile(const std::string &basename, int flushEveryN = 1024);
  ~LogFile();

  void append(const char *logline, size_t len);
  void flush();
  bool rollFile();

private:
  void append_unlocked(const char *logline, size_t len);

  const std::string basename_;
  const int flushEveryN_;

  int count_;
  std::unique_ptr<MutexLock> mutex_;
  std::unique_ptr<AppendFile> file_;
};

#endif // _LOG_FILE_H
