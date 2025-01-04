#ifndef _COMPOSITE_H
#define _COMPOSITE_H

#include <list>
#include <string>

/**
 * @class Component
 * @brief 基础组件类声明了组合中简单对象和复杂对象的通用操作。
 *
 */
class Component {
protected:
  Component *parent_;
  /**
   * 可选地，基础组件可以声明一个接口，用于在树形结构中设置和访问组件的父节点。
   * 它还可以为这些方法提供一些默认实现。
   */
public:
  virtual ~Component() {}
  void SetParent(Component *parent) { this->parent_ = parent; }

  Component *GetParent() { return this->parent_; }

  /**
   * 在某些情况下，将子节点管理操作直接定义在基础组件类中会更有益。
   * 这样，即使在对象树的组装过程中，也无需将具体的组件类暴露给客户端代码。
   * 其缺点是，这些方法对于叶子级组件来说将是空的。
   */
  virtual void Add(Component *component) {}
  virtual void Remove(Component *component) {}

  /**
   * 你可以提供一个方法，让客户端代码判断一个组件是否可以拥有子节点。
   */
  virtual bool IsComposite() const { return false; }

  /**
   * 基础组件可以实现一些默认行为，或者将其留给具体类实现
   * （通过将包含该行为的方法声明为“抽象”）。
   */
  virtual std::string Operation() const = 0;
};

/**
 * 叶子类表示组合的末端对象。叶子节点不能有任何子节点。
 *
 * 通常，叶子对象负责实际的工作，而组合对象仅将工作委托给其子组件。
 *
 */
class Leaf : public Component {
public:
  std::string Operation() const override { return "Leaf"; }
};

/**
 * 组合类表示可能拥有子节点的复杂组件。
 * 通常，组合对象会将实际工作委托给其子节点，然后对结果进行“汇总”。
 *
 */
class Composite : public Component {
protected:
  std::list<Component *> children_;

public:
  /**
   * 组合对象可以向其子节点列表中添加或移除其他组件（无论是简单的还是复杂的）。
   */
  void Add(Component *component) override {
    this->children_.push_back(component);
    component->SetParent(this);
  }

  /**
   * 请记住，这个方法移除了指向列表的指针，但并没有释放内存，
   * 你应该手动释放内存，或者更好地使用智能指针。
   */
  void Remove(Component *component) override {
    children_.remove(component);
    component->SetParent(nullptr);
  }

  bool IsComposite() const override { return true; }

  /**
   * 组合对象以特定的方式执行其主要逻辑。它递归地遍历所有子节点，收集并汇总它们的结果。
   * 由于组合的子节点会将这些调用传递给它们的子节点，依此类推，最终整个对象树都会被遍历。
   */
  std::string Operation() const override {
    std::string result;
    for (const Component *c : children_) {
      if (c == children_.back()) {
        result += c->Operation();
      } else {
        result += c->Operation() + "+";
      }
    }
    return "Branch(" + result + ")";
  }
};

#endif // _COMPOSITE_H
