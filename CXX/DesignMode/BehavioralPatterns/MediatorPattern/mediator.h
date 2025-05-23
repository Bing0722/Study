#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <iostream>
#include <string>

/**
 * 中介者接口声明了一个方法，用于组件通知中介者各种事件。
 * 中介者可以对这些事件做出反应，并将执行传递给其他组件。
 */
class BaseComponent;
class Mediator {
public:
  virtual void Notify(BaseComponent *sender, std::string event) const = 0;
};

/**
 * 基础组件为组件对象提供了存储中介者实例的基本功能。
 */
class BaseComponent {
protected:
  Mediator *mediator_;

public:
  BaseComponent(Mediator *mediator = nullptr) : mediator_(mediator) {}
  void set_mediator(Mediator *mediator) { this->mediator_ = mediator; }
};

/**
 * 具体组件实现了各种功能。它们不依赖于其他组件，也不依赖于任何具体的中介者类。
 */
class Component1 : public BaseComponent {
public:
  void DoA() {
    std::cout << "Component 1 does A.\n";
    this->mediator_->Notify(this, "A");
  }
  void DoB() {
    std::cout << "Component 1 does B.\n";
    this->mediator_->Notify(this, "B");
  }
};

class Component2 : public BaseComponent {
public:
  void DoC() {
    std::cout << "Component 2 does C.\n";
    this->mediator_->Notify(this, "C");
  }
  void DoD() {
    std::cout << "Component 2 does D.\n";
    this->mediator_->Notify(this, "D");
  }
};

/**
 * 具体中介者通过协调多个组件实现协作行为。
 */
class ConcreteMediator : public Mediator {
private:
  Component1 *component1_;
  Component2 *component2_;

public:
  ConcreteMediator(Component1 *c1, Component2 *c2)
      : component1_(c1), component2_(c2) {
    this->component1_->set_mediator(this);
    this->component2_->set_mediator(this);
  }
  void Notify(BaseComponent *sender, std::string event) const override {
    if (event == "A") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
      this->component2_->DoC();
    }
    if (event == "D") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      this->component1_->DoB();
      this->component2_->DoC();
    }
  }
};

#endif // MEDIATOR_H
