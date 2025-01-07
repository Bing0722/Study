#ifndef PROXY_H
#define PROXY_H

#include <iostream>

/**
 * Subject 接口为 RealSubject 和 Proxy 声明了通用操作。
 * 只要客户端使用此接口与 RealSubject 交互，就可以传递一个代理而不是实际的
 * RealSubject。
 */
class Subject {
public:
  virtual void Request() const = 0;
};

/**
 * RealSubject 包含一些核心业务逻辑。
 * 通常，RealSubject
 * 能够执行一些有用的工作，这些工作可能会很慢或很敏感，例如校正输入数据。 Proxy
 * 可以在不更改 RealSubject 代码的情况下解决这些问题。
 */
class RealSubject : public Subject {
public:
  void Request() const override {
    std::cout << "RealSubject Request" << std::endl;
  }
};

/**
 * Proxy 拥有与 RealSubject 相同的接口。
 */
class Proxy : public Subject {
private:
  RealSubject *real_subject_;
  bool CheckAccess() const {
    std::cout << "Proxy CheckAccess" << std::endl;
    return true;
  }
  void LogAccess() const { std::cout << "Proxy LogAccess" << std::endl; }

  /**
   * Proxy 维护对 RealSubject 类对象的引用。
   * 它可以是延迟加载的，也可以由客户端传递给 Proxy。
   */
public:
  Proxy(RealSubject *real_subject)
      : real_subject_(new RealSubject(*real_subject)) {}

  ~Proxy() { delete real_subject_; }

  /**
   * Proxy 模式最常见的应用包括延迟加载、缓存、访问控制、日志记录等。
   * Proxy 可以执行这些任务之一，然后根据结果将执行传递给关联的 RealSubject
   * 对象中的相同方法。
   */
  void Request() const override {
    if (this->CheckAccess()) {
      this->real_subject_->Request();
      this->LogAccess();
    }
  }
};

#endif // PROXY_H
