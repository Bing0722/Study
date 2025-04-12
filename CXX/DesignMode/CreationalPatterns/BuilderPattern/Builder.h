#ifndef _BUILDER_H
#define _BUILDER_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Product1
 * @brief 只有当你的产品非常复杂并且需要大量配置时，使用建造者模式才有意义。
 * @brief 与其他创建型模式不同，不同的具体建造者可以生产不相关的产品。
 * #brief 换句话说，各个建造者的结果可能并不总是遵循相同的接口。
 *
 */
class Product1 {
public:
  std::vector<std::string> parts_;
  void ListParts() const {
    std::cout << "Product parts: ";
    for (size_t i = 0; i < parts_.size(); i++) {
      if (parts_[i] == parts_.back()) {
        std::cout << parts_[i];
      } else {
        std::cout << parts_[i] << ", ";
      }
    }
    std::cout << "\n\n";
  }
};

/**
 * @class Builder
 * @brief 建造者接口指定了创建产品对象不同部分的方法。
 *
 */
class Builder {
public:
  virtual ~Builder() {}
  virtual void ProducePartA() const = 0;
  virtual void ProducePartB() const = 0;
  virtual void ProducePartC() const = 0;
};

/**
 * @class ConcreteBuilder1
 * @brief 具体建造者类遵循建造者接口，并提供构建步骤的具体实现。
 * @brief 程序中可能有多个不同实现方式的建造者变体。
 *
 */
class ConcreteBuilder1 : public Builder {
  /**
   * 一个新的建造者实例应包含一个空白的产品对象，该对象将在后续的组装过程中使用。
   */
public:
  ConcreteBuilder1() { this->Reset(); }

  ~ConcreteBuilder1() { delete product; }

  void Reset() { this->product = new Product1; }

  /**
   * 所有的生产步骤都使用相同的产品实例。
   */
  void ProducePartA() const override {
    this->product->parts_.push_back("PartA1");
  }

  void ProducePartB() const override {
    this->product->parts_.push_back("PartB1");
  }

  void ProducePartC() const override {
    this->product->parts_.push_back("PartC1");
  }
  /**
   * 具体建造者应提供自己的方法来获取结果。
   * 这是因为不同类型的建造者可能会创建完全不同的产品，这些产品不遵循相同的接口。
   * 因此，这些方法不能在基础建造者接口中声明（至少在静态类型语言中是这样）。
   * 请注意，PHP 是一种动态类型语言，这种方法可以出现在基础接口中。
   * 然而，为了清晰起见，我们不会在此声明。
   *
   * 通常，在将最终结果返回给客户端后，建造者实例应准备好开始生产另一个产品。
   * 因此，通常在 `getProduct` 方法体的末尾调用重置方法。
   * 然而，这种行为并非强制要求，你可以让建造者等待客户端代码显式调用重置方法后再处理上一个结果。
   */

  /**
   * 在这里，请注意内存所有权的问题。
   * 一旦调用 GetProduct，使用此函数的用户需要负责释放该内存。
   * 这里更好的做法可能是使用智能指针来避免内存泄漏。
   */
  Product1 *GetProduct() {
    Product1 *result = this->product;
    this->Reset();
    return result;
  }

private:
  Product1 *product;
};

/**
 * @class Director
 * @brief 主管仅负责按照特定顺序执行建造步骤。
 * @brief 当根据特定的顺序或配置生产产品时，主管类非常有用。
 * @brief 严格来说，主管类是可选的，因为客户端可以直接控制建造者。
 *
 */
class Director {
public:
  void set_builder(Builder *builder) { this->builder = builder; }
  /**
   * 主管与客户端代码传递给它的任何建造者实例一起工作。
   * 通过这种方式，客户端代码可以改变新组装产品的最终类型。
   */
  void BuildMinimalViableProduct() { this->builder->ProducePartA(); }

  void BuildFullFeatureProduct() {
    this->builder->ProducePartA();
    this->builder->ProducePartB();
    this->builder->ProducePartC();
  }

private:
  Builder *builder;
};

#endif // BUILDER_H
