#ifndef _ABSTRACTFACTORY_H
#define _ABSTRACTFACTORY_H

#include <string>

/**
 * @class AbstractProductA
 * @brief 每个产品系列中的不同产品都应有一个基础接口。
 * @brief 所有产品的变体都必须实现此接口。
 *
 */
class AbstractProductA {
public:
  virtual ~AbstractProductA() {}
  virtual std::string UsefulFunctionA() const = 0;
};

/**
 * @class ConcreteProductA1
 * @brief 具体产品由对应的具体工厂创建。
 *
 */
class ConcreteProductA1 : public AbstractProductA {
public:
  std::string UsefulFunctionA() const override {
    return "The result of the product A1.";
  }
};

class ConcreteProductA2 : public AbstractProductA {
public:
  std::string UsefulFunctionA() const override {
    return "The result of the product A2.";
  }
};

/**
 * @class AbstractProductB
 * @brief
 * 所有产品都可以相互交互，但只有相同具体变体的产品之间才能实现正确的交互。
 *
 */
class AbstractProductB {
  /**
   * 产品 B 能够执行其自身的功能...
   */
public:
  virtual ~AbstractProductB() {}
  virtual std::string UsefulFunctionB() const = 0;

  /**
   * ...但它也可以与 ProductA 协作。
   *
   * 抽象工厂确保它创建的所有产品都是同一变体，
   * 因此具有兼容性。
   */
  virtual std::string
  AnotherUserfulFunctionB(const AbstractProductA &collaborator) const = 0;
};

/**
 * @class ConcreteProductB1
 * @brief 具体产品由相应的具体工厂创建。
 *
 */
class ConcreteProductB1 : public AbstractProductB {
public:
  std::string UsefulFunctionB() const override {
    return "The result of the product B1.";
  }

  /**
   * 变体 Product B1 只能与变体 Product A1 正确协作。
   * 然而，它接受任何 AbstractProductA 的实例作为参数。
   */
  std::string
  AnotherUserfulFunctionB(const AbstractProductA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B1 collaborating with ( " + result + " )";
  }
};

class ConcreteProductB2 : public AbstractProductB {
public:
  std::string UsefulFunctionB() const override {
    return "The result of the product B2.";
  }

  /**
   * 变体 Product B2 只能与变体 Product A2 正确协作。
   * 然而，它接受任何 AbstractProductA 的实例作为参数。
   */
  std::string
  AnotherUserfulFunctionB(const AbstractProductA &collaborator) const override {
    const std::string result = collaborator.UsefulFunctionA();
    return "The result of the B2 collaborating with ( " + result + " )";
  }
};

/**
 * @class AbstractFactory
 * @brief 抽象工厂接口声明了一组方法，这些方法返回不同的抽象产品。
 * @brief 些产品被称为一个系列，并通过一个高级主题或概念相关联。
 * @brief 同一系列的产品通常能够彼此协作。
 * #brief
 * 一个系列的产品可能有多个变体，但一种变体的产品与另一种变体的产品不兼容。
 *
 */
class AbstractFactory {
public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
};

/**
 * @class ConcreteFactory1
 * @brief 具体工厂生产属于单一变体的一系列产品。
 * @brief 工厂保证生成的产品是兼容的。
 * @brief
 * 请注意，具体工厂方法的签名返回的是抽象产品，而在方法内部实例化的是具体产品。
 *
 */
class ConcreteFactory1 : public AbstractFactory {
public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB1();
  }
};

/**
 * @class ConcreteFactory2
 * @brief 每个具体工厂都有一个对应的产品变体。
 *
 */
class ConcreteFactory2 : public AbstractFactory {
public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB2();
  }
};

#endif // ABSTRACTFACTORY_H
