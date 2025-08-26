#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

class NonCopyable {
public:
  NonCopyable() {}
  ~NonCopyable() {}

  NonCopyable(const NonCopyable &) = delete;
  NonCopyable &operator=(const NonCopyable &) = delete;

private:
};

#endif // _NONCOPYABLE_H
