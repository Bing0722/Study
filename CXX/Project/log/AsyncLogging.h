#ifndef _ASYNC_LOGGING_H
#define _ASYNC_LOGGING_H

#include "Condition.h"
#include "CountDownLatch.h"
#include "LogStream.h"
#include "MutexLock.h"
#include "Thread.h"
#include "noncopyable.h"
#include <memory>
#include <string>
#include <vector>

class AsyncLogging : public NonCopyable {
public:
  AsyncLogging(const std::string &basename, int flushInterval = 2);
  ~AsyncLogging() {
    if (running_) {
      stop();
    }
  }

  void append(const char *logline, size_t len);

  void start() {
    running_ = true;
    thread_.start();
    latch_.wait(); // 等待线程准备完毕
  }

  void stop() {
    running_ = false;
    cond_.notify();
    thread_.join();
  }

private:
  void threadFunc();

  typedef FixBuffer<kLargeBuffer> Buffer;
  typedef std::shared_ptr<Buffer> BufferPtr;
  typedef std::vector<BufferPtr> BufferVector;

  const int flushInterval_;
  bool running_;
  std::string basename_;
  Thread thread_;
  MutexLock mutex_;
  Condition cond_;
  BufferPtr currentBuffer_;
  BufferPtr nextBuffer_;
  BufferVector buffers_;
  CountDownLatch latch_;
};

#endif // _ASYNC_LOGGING_H
