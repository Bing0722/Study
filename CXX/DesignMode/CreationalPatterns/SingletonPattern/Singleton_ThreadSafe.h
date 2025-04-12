#ifndef _SINGLETON_THREAD_SAFE_H
#define _SINGLETON_THREAD_SAFE_H

#include <mutex>
#include <string>

/**
 * @class Singleton
 * @brief 单例类定义了 `GetInstance`
 * 方法，作为构造函数的替代方案，让客户端反复访问同一个类的实例。
 *
 */
class Singleton {
  /**
   * 单例的构造函数/析构函数应始终为私有，
   * 以防止通过 `new`/`delete` 操作符直接调用构造函数/析构函数。
   */
private:
  static Singleton *pinstance_;
  static std::mutex mutex_;

protected:
  Singleton(const std::string value) : value_(value) {}
  ~Singleton() {}
  std::string value_;

public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;
  static Singleton *GetInstance(const std::string &value);
  void SomeBusinessLogic() {
    // ...
  }

  std::string value() const { return value_; }
};

Singleton *Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

Singleton *Singleton::GetInstance(const std::string &value) {
  std::lock_guard<std::mutex> lock(mutex_);
  if (pinstance_ == nullptr) {
    pinstance_ = new Singleton(value);
  }
  return pinstance_;
}
#endif // SINGLETON_THREAD_SAFE_H
