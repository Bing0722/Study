#ifndef _SIGNLETON_H
#define _SIGNLETON_H

#include <iostream>
#include <string>
#include <thread>

/**
 * @class Singleton
 * @brief Singleton 类定义了 `GetInstance`
 * 方法，作为构造函数的替代方案，让客户端反复访问同一个类的实例。
 *
 */
class Singleton {
public:
  /**
   * 单例类不应该是可克隆的。
   */
  Singleton(Singleton &other) = delete;

  /**
   * 单例类不应该是可赋值的。
   */
  void operator=(const Singleton &) = delete;

  /**
   * 这是控制访问单例实例的静态方法。
   * 在第一次调用时，它创建一个单例对象并将其放入静态字段中。
   * 在随后的调用中，它返回存储在静态字段中的现有客户端对象。
   */
  static Singleton *GetInstance(const std::string &value);

  /**
   * 最后，任何单例类都应该定义一些业务逻辑，
   * 这些逻辑可以在其实例上执行。
   */
  void SomeBusinessLogic() {
    // ...
  }

  std::string value() const { return value_; }

protected:
  /**
   * Singleton 的构造函数应始终是私有的，以防止通过 `new`
   * 操作符直接调用构造函数。
   */
  Singleton(const std::string value) : value_(value) {}

  static Singleton *singleton_;
  std::string value_;
};

Singleton *Singleton::singleton_ = nullptr;

/**
 * 静态方法应定义在类外部。
 */
Singleton *Singleton::GetInstance(const std::string &value) {
  /**
   * 这是创建实例的更安全方式。如果使用 instance = new Singleton，
   * 在两个实例线程同时访问时可能会造成危险。
   */
  if (singleton_ == nullptr) {
    singleton_ = new Singleton(value);
  }
  return singleton_;
}

#endif // SIGNLETON_H
