#ifndef _COUNTDOWNLATCH_H
#define _COUNTDOWNLATCH_H

#include "Condition.h"
#include "MutexLock.h"
#include "noncopyable.h"

/**
 * @class CountDownLatch
 * @brief 线程同步原语
 *
 */
class CountDownLatch : public NonCopyable {
public:
  explicit CountDownLatch(int count);
  ~CountDownLatch();

  void wait();
  void countDown();

private:
  mutable MutexLock mutex_;
  Condition cond_;
  int count_;
};

#endif // _COUNTDOWNLATCH_H
