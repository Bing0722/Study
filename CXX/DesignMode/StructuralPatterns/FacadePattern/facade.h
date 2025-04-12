#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <string>

/**
 * 子系统可以接受来自外观或客户端的请求。
 * 无论是哪种情况，对于子系统来说，外观只是另一个客户端，并且不属于子系统的一部分。
 */
class SubSystem1 {
public:
  std::string Operation1() const { return "SubSystem1: Ready!\n"; }

  std::string OperationN() const { return "SubSystem1: Go!\n"; }
};

/**
 * 一些外观可以同时与多个子系统一起工作。
 */
class SubSystem2 {
public:
  std::string Operation1() const { return "SubSystem2: Get ready!\n"; }

  std::string OperationZ() const { return "SubSystem2: Fire!\n"; }
};

/**
 * 外观类为一个或多个子系统的复杂逻辑提供了一个简单的接口。
 * 外观将客户端请求委派给子系统中的适当对象。
 * 外观还负责管理它们的生命周期。
 * 所有这些都屏蔽了客户端不需要的子系统复杂性。
 */
class Facade {
protected:
  SubSystem1 *subsystem1_;
  SubSystem2 *subsystem2_;

  /**
   * 根据应用程序的需求，你可以为外观提供现有的子系统对象，
   * 或者让外观自己创建它们。
   */
public:
  /**
   * 在这种情况下，我们将内存所有权委派给外观类。
   */
  Facade(SubSystem1 *subsystem1 = nullptr, SubSystem2 *subsystem2 = nullptr) {
    this->subsystem1_ = subsystem1 ?: new SubSystem1;
    this->subsystem2_ = subsystem2 ?: new SubSystem2;
  }

  ~Facade() {
    delete subsystem1_;
    delete subsystem2_;
  }

  /**
   * 外观的方法是访问子系统复杂功能的便捷方式。
   * 然而，客户端只能使用到子系统的一部分能力。
   */
  std::string Operation() {
    std::string result = "Facade initializes subsystems:\n";
    result += this->subsystem1_->Operation1();
    result += this->subsystem2_->Operation1();
    result += "Facade orders subsystems to perform the action:\n";
    result += this->subsystem1_->OperationN();
    result += this->subsystem2_->OperationZ();
    return result;
  }
};
#endif // FACADE_H
