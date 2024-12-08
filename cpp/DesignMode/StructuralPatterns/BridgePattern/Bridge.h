#ifndef _BRIDGE_H
#define _BRIDGE_H

#include <string>

/**
 * @class Implementation
 * @brief 它不必与 Abstraction 的接口匹配。实际上，这两个接口可以完全不同。
 * @brief 通常，Implementation 接口仅提供基本操作，而 Abstraction
 * 基于这些基本操作定义更高层次的操作。
 *
 */
class Implementation {
public:
  virtual ~Implementation() {}
  virtual std::string OperationImplementation() const = 0;
};

/**
 * @class ConcreteImplementationA
 * @brief 每个具体实现对应一个特定平台，并使用该平台的 API 实现
 * Implementation接口。
 *
 */
class ConcreteImplementationA : public Implementation {
public:
  std::string OperationImplementation() const override {
    return "ConcreteImplementationA: Here's the result on the platform "
           "A.\n";
  }
};
class ConcreteImplementationB : public Implementation {
public:
  std::string OperationImplementation() const override {
    return "ConcreteImplementationA: Here's the result on the platform "
           "B.\n";
  }
};

/**
 * @class Abstraction
 * @brief 它持有
 * Implementation层次结构中一个对象的引用，并将所有实际工作委托给该对象。
 *
 */
class Abstraction {
public:
  Abstraction(Implementation *implementation)
      : implementation_(implementation) {}

  virtual ~Abstraction() {}

  virtual std::string Operation() const {
    return "Abstraction: Base operation with:\n" +
           this->implementation_->OperationImplementation();
  }

protected:
  Implementation *implementation_;
};

/**
 * @class ExtendedAbstraction
 * @brief 客户端代码应能够与任何预配置的抽象-实现组合协同工作。
 *
 */
class ExtendedAbstraction : public Abstraction {
public:
  ExtendedAbstraction(Implementation *implementation)
      : Abstraction(implementation) {}

  std::string Operation() const override {
    return "ExtendedAbstraction: Extended operation with:\n" +
           this->implementation_->OperationImplementation();
  }
};

#endif // BRIDGE_H
