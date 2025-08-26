#ifndef _CURRENT_THREAD_H
#define _CURRENT_THREAD_H

#include <stdint.h>

namespace CurrentThread {
extern __thread int t_cachedTid;
extern __thread char t_tidString[32];
extern __thread int t_tidStringLength;
extern __thread const char *t_threadName;

void cacheTid();

inline int tid() {
  // 如果 t_cachedTid == 0，说明当前线程还没有获取过 TID，于是调用 cacheTid()
  // 缓存 GCC 提供的分支预测优化
  if (__builtin_expect(t_cachedTid == 0, 0)) {
    cacheTid();
  }
  return t_cachedTid;
}

inline const char *tidString() { return t_tidString; }

inline int tidStringLength() { return t_tidStringLength; }

inline const char *name() { return t_threadName; }

} // namespace CurrentThread

#endif // _CURRENT_THREAD_H
