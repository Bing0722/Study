#ifndef _SIGNLETON_THREAD_SAFE_NEW_H
#define _SIGNLETON_THREAD_SAFE_NEW_H

#include <string>
#include <thread>

/**
 * @class Singleton
 * @brief 使用静态局部变量来进行单例
 * @brief 不过，这种方法仅适用于静态实例需要在第一次访问时初始化，
 * @brief 并且不需要手动管理资源（例如，构造函数的参数不能传递不同值）。
 *
 */
class Singleton {
public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;

  static Singleton *GetInstance();

  void SomeBusinessLogic() {
    // ...
  }

  std::string value() const { return value_; }

protected:
  Singleton() {}
  ~Singleton() {}
  std::string value_;
};

Singleton *Singleton::GetInstance() {
  static Singleton *Instance_ = new Singleton();
  return Instance_;
}

#endif // SIGNLETON_THREAD_SAFE_NEW_H
