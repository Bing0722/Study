#ifndef _FACTORYMETHOD_H
#define _FACTORYMETHOD_H

#include <string>

/**
 * @class Product
 * @brief Product 接口声明了所有具体产品类必须执行的操作必须实现
 *
 */
class Product {
public:
  virtual ~Product() {}
  virtual std::string Operator() const = 0;
};

/**
 * @class ConcretProduct1
 * @brief 具体产品提供了产品接口的各种实现
 *
 */
class ConcretProduct1 : public Product {
public:
  std::string Operator() const override {
    return "{Result of the ConcretProduct1}";
  }
};

/**
 * @class ConcretProduct1
 * @brief 具体产品提供了产品接口的各种实现
 *
 */
class ConcretProduct2 : public Product {
public:
  std::string Operator() const override {
    return "{Result of the ConcretProduct2}";
  }
};

/**
 * @class Creator
 * @brief Creator 类声明一个工厂方法，该方法返回一个Product 类的对象。
 * @brief 创建者的子类通常提供这个方法的实现。
 *
 */
class Creator {
  // 请注意，创作者类也可能提供工厂方法的默认实现
public:
  virtual ~Creator() {}
  virtual Product *FactoryMethod() const = 0;

  /**
   * 还要注意，尽管其名称是“创作者”，但创作者的主要职责并不是创建产品。
   * 通常，它包含一些依赖于工厂方法返回的产品对象的核心业务逻辑。
   * 子类可以通过重写工厂方法并返回不同类型的产品，从而间接地改变这些业务逻辑。
   */

  std::string SomeOperation() const {
    // 调用工厂方法来创建一个产品对象。
    Product *product = this->FactoryMethod();
    // 现在，使用该产品。
    std::string result =
        "Creator: The same creator's code has just worked with " +
        product->Operator();
    delete product;
    return result;
  }
};

/**
 * @class ConcretCreator1
 * @brief 具体创建者重写工厂方法，以便更改生成产品的类型。
 *
 */
class ConcretCreator1 : public Creator {
  /**
   * 请注意，尽管方法实际上返回的是具体产品，但方法的签名仍然使用抽象产品类型。
   * 通过这种方式，创作者可以保持独立于具体的产品类。
   */
public:
  Product *FactoryMethod() const override { return new ConcretProduct1(); }
};

/**
 * @class ConcretCreator2
 * @brief 具体创建者重写工厂方法，以便更改生成产品的类型。
 *
 */
class ConcretCreator2 : public Creator {
public:
  Product *FactoryMethod() const override { return new ConcretProduct2(); }
};

#endif // FACTORYMETHOD_H
