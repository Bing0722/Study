#ifndef _CONDITION_H
#define _CONDITION_H

#include "MutexLock.h"
#include "noncopyable.h"
#include <cerrno>
#include <pthread.h>

class Condition : public NonCopyable {

public:
  explicit Condition(MutexLock &mutex) : mutex_(mutex) {
    pthread_cond_init(&cond_, NULL);
  }

  ~Condition() { pthread_cond_destroy(&cond_); }

  void wait() { pthread_cond_wait(&cond_, mutex_.get()); }
  void notify() { pthread_cond_signal(&cond_); }
  void notifyAll() { pthread_cond_broadcast(&cond_); }

  // 等待超时
  bool waitForSeconds(int seconds) {
    struct timespec abstime;
    clock_gettime(CLOCK_REALTIME, &abstime);
    abstime.tv_sec += static_cast<time_t>(seconds);
    return ETIMEDOUT == pthread_cond_timedwait(&cond_, mutex_.get(), &abstime);
  }

private:
  pthread_cond_t cond_;
  MutexLock &mutex_;
};

#endif // _CONDITION_H
