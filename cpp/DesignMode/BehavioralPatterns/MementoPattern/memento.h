#ifndef MEMENTO_H
#define MEMENTO_H

#include <ctime>
#include <iostream>
#include <vector>

/**
 * 备忘录接口提供了一种方法来检索备忘录的元数据，例如创建日期或名称。
 * 然而，它并不暴露发起人的状态。
 */
class Memento {
public:
  virtual ~Memento() {}
  virtual std::string GetName() const = 0;
  virtual std::string date() const = 0;
  virtual std::string state() const = 0;
};

/**
 * 具体备忘录类包含存储发起人状态的基础设施。
 */
class ConcreteMemento : public Memento {
private:
  std::string state_;
  std::string date_;

public:
  ConcreteMemento(std::string state) : state_(state) {
    this->state_ = state;
    std::time_t now = std::time(0);
    this->date_ = std::ctime(&now);
  }
  /**
   * 发起者在恢复状态时会使用此方法。
   */
  std::string state() const override { return this->state_; }
  /**
   * 其余的方法由 Caretaker 用于显示元数据。
   */
  std::string GetName() const override {
    return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
  }
  std::string date() const override { return this->date_; }
};

/**
 * 发起者持有一些可能随时间改变的重要状态。
 * 它还定义了一种方法，用于将状态保存在备忘录中，
 * 以及从备忘录中恢复状态的另一种方法。
 */
class Originator {
  /**
   * @var string 为了简单起见，发起者的状态存储在一个变量中。
   */
private:
  std::string state_;

  std::string GenerateRandomString(int length = 10) {
    const char alphanum[] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < length; i++) {
      random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
  }

public:
  Originator(std::string state) : state_(state) {
    std::cout << "Originator: My initial state is: " << this->state_ << "\n";
  }
  /**
   * 发起者的业务逻辑可能会影响其内部状态。
   * 因此，客户端在通过 save() 方法启动业务逻辑之前，
   * 应该备份状态。
   */
  void DoSomething() {
    std::cout << "Originator: I'm doing something important.\n";
    this->state_ = this->GenerateRandomString(30);
    std::cout << "Originator: and my state has changed to: " << this->state_
              << "\n";
  }

  /**
   * 将当前状态保存到备忘录中。
   */
  Memento *Save() { return new ConcreteMemento(this->state_); }
  /**
   * 从备忘录对象中恢复发起者的状态。
   */
  void Restore(Memento *memento) {
    this->state_ = memento->state();
    std::cout << "Originator: My state has changed to: " << this->state_
              << "\n";
  }
};

/**
 * Caretaker 不依赖于 Concrete Memento 类。
 * 因此，它无法访问存储在备忘录中的发起者的状态。
 * 它通过基础的 Memento 接口与所有备忘录一起工作。
 */
class Caretaker {
  /**
   * @var Memento[]
   */
private:
  std::vector<Memento *> mementos_;

  /**
   * @var Originator
   */
  Originator *originator_;

public:
  Caretaker(Originator *originator) : originator_(originator) {}

  ~Caretaker() {
    for (auto m : mementos_)
      delete m;
  }

  void Backup() {
    std::cout << "\nCaretaker: Saving Originator's state...\n";
    this->mementos_.push_back(this->originator_->Save());
  }
  void Undo() {
    if (!this->mementos_.size()) {
      return;
    }
    Memento *memento = this->mementos_.back();
    this->mementos_.pop_back();
    std::cout << "Caretaker: Restoring state to: " << memento->GetName()
              << "\n";
    try {
      this->originator_->Restore(memento);
    } catch (...) {
      this->Undo();
    }
  }
  void ShowHistory() const {
    std::cout << "Caretaker: Here's the list of mementos:\n";
    for (Memento *memento : this->mementos_) {
      std::cout << memento->GetName() << "\n";
    }
  }
};

#endif // MEMENTO_H
