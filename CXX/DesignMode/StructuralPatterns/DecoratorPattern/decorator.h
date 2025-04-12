#ifndef DECORATOR_H
#define DECORATOR_H

#include <string>

/**
 * 基础组件接口定义了可以被装饰器修改的操作。
 */
class Component {
public:
  virtual ~Component() {}
  virtual std::string Operation() const = 0;
};

/**
 * 具体组件提供操作的默认实现。
 * 这些类可能有多种变体。
 */
class ConcreteComponent : public Component {
public:
  std::string Operation() const override { return "ConcreteComponent"; }
};

/**
 * 基础装饰器类遵循与其他组件相同的接口。
 * 这个类的主要目的是为所有具体装饰器定义包装接口。
 * 包装代码的默认实现可能包括一个用于存储被包装组件的字段，以及初始化它的方式。
 */
class Decorator : public Component {
protected:
  Component *component_;

public:
  Decorator(Component *component) : component_(component) {}
  /**
   * 装饰器将所有工作委托给被包装的组件。
   */
  std::string Operation() const override {
    return this->component_->Operation();
  }
};

/**
 * 具体装饰器调用被包装的对象，并以某种方式修改其结果。
 */
class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(Component *component) : Decorator(component) {}
  /**
   * 装饰器可以调用操作的父实现，而不是直接调用被包装对象。
   * 这种方法简化了装饰器类的扩展。
   */
  std::string Operation() const override {
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
  }
};

/**
 * 装饰器可以在调用被包装对象之前或之后执行它们的行为。
 */
class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(Component *component) : Decorator(component) {}
  std::string Operation() const override {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
  }
};

#endif // DECORATOR_H
