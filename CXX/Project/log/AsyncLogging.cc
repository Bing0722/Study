#include "AsyncLogging.h"
#include "LogFile.h"
#include <cassert>
#include <iostream>

AsyncLogging::AsyncLogging(const std::string &logFileName, int flushInterval)
    : flushInterval_(flushInterval), running_(false), basename_(logFileName),
      thread_(std::bind(&AsyncLogging::threadFunc, this), "Logging"), mutex_(),
      cond_(mutex_), currentBuffer_(new Buffer), nextBuffer_(new Buffer),
      buffers_(), latch_(1) {

  assert(logFileName.size() > 1);
  currentBuffer_->bzero();
  nextBuffer_->bzero();
  buffers_.reserve(16);
}

void AsyncLogging::append(const char *logline, size_t len) {
  MutexLockGuard lock(mutex_);
  thread_.tid();
  thread_.name();
  if (currentBuffer_->avail() > len) {
    currentBuffer_->append(logline, len);
  } else {
    buffers_.push_back(currentBuffer_);
    currentBuffer_.reset(); // 释放 当前的引用计数
    if (nextBuffer_) {
      currentBuffer_ = std::move(nextBuffer_);
    } else {
      currentBuffer_.reset(new Buffer);
    }
    currentBuffer_->append(logline, len);
    cond_.notify();
  }
}

void AsyncLogging::threadFunc() {
  assert(running_ == true);
  // 通知主线程 开始处理日志
  latch_.countDown();

  LogFile output(basename_);

  BufferPtr newBuffer1(new Buffer);
  BufferPtr newBuffer2(new Buffer);

  newBuffer1->bzero();
  newBuffer2->bzero();
  BufferVector buffersToWrite;
  buffersToWrite.reserve(16);

  while (running_) {
    assert(newBuffer1 && newBuffer1->length() == 0);
    assert(newBuffer2 && newBuffer2->length() == 0);
    assert(buffersToWrite.empty());

    {
      MutexLockGuard lock(mutex_);
      if (buffers_.empty()) {
        cond_.waitForSeconds(flushInterval_);
      }
      buffers_.push_back(currentBuffer_);
      currentBuffer_.reset(); // 释放 当前的引用计数

      // 将newBuffer1 的所有权转移给 currentBuffer_
      currentBuffer_ = std::move(newBuffer1);
      // 交换两个缓冲区
      buffersToWrite.swap(buffers_);
      if (!nextBuffer_) {
        nextBuffer_ = std::move(newBuffer2);
      }
    }

    assert(!buffersToWrite.empty());

    // 限制缓冲区的数量
    if (buffersToWrite.size() > 25) {
      buffersToWrite.erase(buffersToWrite.begin() + 2, buffersToWrite.end());
    }

    // 写入文件
    for (size_t i = 0; i < buffersToWrite.size(); ++i) {
      output.append(buffersToWrite[i]->data(), buffersToWrite[i]->length());
      std::cout.write(buffersToWrite[i]->data(), buffersToWrite[i]->length());
    }

    // 限制缓冲区的数量
    if (buffersToWrite.size() > 2) {
      buffersToWrite.resize(2);
    }

    // 如果 newBuffer1 为空就从 buffersToWrite 缓冲区容器中取出一个
    if (!newBuffer1) {
      assert(!buffersToWrite.empty());
      newBuffer1 = buffersToWrite.back();
      buffersToWrite.pop_back();
      newBuffer1->reset(); // 置空
    }

    // 如果 newBuffer2 为空就从 buffersToWrite 缓冲区容器中取出一个
    if (!newBuffer2) {
      assert(!buffersToWrite.empty());
      newBuffer2 = buffersToWrite.back();
      buffersToWrite.pop_back();
      newBuffer2->reset();
    }

    // 清空容器
    buffersToWrite.clear();
    output.flush();
  }
  output.flush();
}
