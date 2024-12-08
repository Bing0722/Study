#ifndef _PROTOTYPE_H
#define _PROTOTYPE_H

#include <iostream>
#include <unordered_map>

using std::string;

enum Type { PROTOTYPE_1 = 0, PROTOTYPE_2 };

/**
 * @class Prototype
 * @brief 具有克隆能力的示例类。
 *
 */
class Prototype {
protected:
  string prototype_name_;
  float prototype_field_;

public:
  Prototype() {}
  Prototype(string prototype_name) : prototype_name_(prototype_name) {}
  virtual ~Prototype() {}
  virtual Prototype *Clone() const = 0;
  virtual void Method(float prototype_field) {
    this->prototype_field_ = prototype_field;
    std::cout << "Call Method from " << prototype_name_
              << " with field : " << prototype_field << std::endl;
  }
};

/**
 * @class ConcretePrototype1
 * @brief ConcretePrototype1 是 Prototype 的子类，并实现了克隆方法。
 * @brief 在这个示例中，Prototype 类的所有数据成员都在栈上。
 * @brief 如果你的属性中有指针，例如：String*
 * @brief 你需要实现拷贝构造函数，以确保从克隆方法中得到深拷贝。
 *
 */
class ConcretePrototype1 : public Prototype {
private:
  float concrete_prototype_field1_;

public:
  ConcretePrototype1(string prototype_name, float concrete_prototype_field)
      : Prototype(prototype_name),
        concrete_prototype_field1_(concrete_prototype_field) {}

  /**
   * 请注意，Clone 方法返回一个指向新 ConcretePrototype1 副本的指针。
   * 因此，客户端（调用克隆方法的代码）有责任释放该内存。
   * 如果你了解智能指针，你可能更倾向于在这里使用 unique_pointer。
   */
  Prototype *Clone() const override { return new ConcretePrototype1(*this); }
};

class ConcretePrototype2 : public Prototype {
private:
  float concrete_prototype_field2_;

public:
  ConcretePrototype2(string prototype_name, float concrete_prototype_field)
      : Prototype(prototype_name),
        concrete_prototype_field2_(concrete_prototype_field) {}
  Prototype *Clone() const override { return new ConcretePrototype2(*this); }
};

/**
 * @class PrototypeFactory
 * @brief 在 PrototypeFactory 中，你有两个具体的原型，每个具体原型类一个。
 * @brief 所以，每次你想创建一个子弹时，可以使用现有的原型并克隆它们。
 *
 */
class PrototypeFactory {
private:
  std::unordered_map<Type, Prototype *, std::hash<int>> prototypes_;

public:
  PrototypeFactory() {
    prototypes_[Type::PROTOTYPE_1] =
        new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
    prototypes_[Type::PROTOTYPE_2] =
        new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
  }
  /**
   * 小心释放所有分配的内存。
   * 再次提醒，如果你了解智能指针，使用它会更好。
   */
  ~PrototypeFactory() {
    delete prototypes_[Type::PROTOTYPE_1];
    delete prototypes_[Type::PROTOTYPE_2];
  }
  /**
   * 请注意，在这里你只需要指定你想要的原型类型，
   * 方法将会从该类型的对象创建新实例。
   */
  Prototype *CreatePrototype(Type type) { return prototypes_[type]->Clone(); }
};

#endif // PROTOTYPE_H
