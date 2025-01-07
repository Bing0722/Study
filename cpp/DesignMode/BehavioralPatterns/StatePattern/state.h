#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

/**
 * 基础状态类（State）声明了所有具体状态类需要实现的方法，
 * 并且提供了一个对与状态相关联的上下文对象（Context）的引用。
 * 状态可以利用这个引用将上下文切换到另一个状态。
 */
class Context;

class State {
  /**
   * @var Context
   */
protected:
  Context *context_;

public:
  virtual ~State() {}

  void set_context(Context *context) { this->context_ = context; }

  virtual void Handle1() = 0;
  virtual void Handle2() = 0;
};

/**
 * 上下文类（Context）定义了客户端感兴趣的接口。
 * 它还维护了一个对状态子类实例的引用，这个实例表示上下文的当前状态。
 */
class Context {
  /**
   * @var State 上下文当前状态的引用。
   */
private:
  State *state_;

public:
  Context(State *state) : state_(nullptr) { this->TransitionTo(state); }
  ~Context() { delete state_; }
  /**
   * 上下文允许在运行时更改状态对象。
   */
  void TransitionTo(State *state) {
    std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
    if (this->state_ != nullptr)
      delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
  }
  /**
   * 上下文将其部分行为委托给当前的状态对象。
   */
  void Request1() { this->state_->Handle1(); }
  void Request2() { this->state_->Handle2(); }
};

/**
 * 具体状态类（ConcreteState）实现了与上下文状态相关的各种行为。
 */

class ConcreteStateA : public State {
public:
  void Handle1() override;

  void Handle2() override { std::cout << "ConcreteStateA handles request2.\n"; }
};

class ConcreteStateB : public State {
public:
  void Handle1() override { std::cout << "ConcreteStateB handles request1.\n"; }
  void Handle2() override {
    std::cout << "ConcreteStateB handles request2.\n";
    std::cout << "ConcreteStateB wants to change the state of the context.\n";
    this->context_->TransitionTo(new ConcreteStateA);
  }
};

inline void ConcreteStateA::Handle1() {
  {
    std::cout << "ConcreteStateA handles request1.\n";
    std::cout << "ConcreteStateA wants to change the state of the context.\n";

    this->context_->TransitionTo(new ConcreteStateB);
  }
}

#endif // STATE_H
