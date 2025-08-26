#include "LogFile.h"
#include "FileUtil.h"
#include "MutexLock.h"

LogFile::LogFile(const std::string &basename, int flushEveryN)
    : basename_(basename), flushEveryN_(flushEveryN), count_(0),
      mutex_(new MutexLock) {

  file_.reset(new AppendFile(basename));
}

LogFile::~LogFile() {}

void LogFile::append(const char *logline, size_t len) {
  MutexLockGuard lock(*mutex_);
  append_unlocked(logline, len);
}

void LogFile::flush() {
  MutexLockGuard lock(*mutex_);
  file_->flush();
}

bool LogFile::rollFile() { return false; }

void LogFile::append_unlocked(const char *logline, size_t len) {
  file_->append(logline, len);
  ++count_;
  if (count_ >= flushEveryN_) {
    count_ = 0;
    file_->flush();
  }
}
