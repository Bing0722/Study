#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * 观察者设计模式
 *
 * 意图：允许你定义一种订阅机制，以通知多个对象它们正在观察的对象发生的任何事件。
 *
 * 注意：与此模式相关的术语有很多相似的含义。
 * 记住，Subject 也被称为 Publisher（发布者），
 * Observer 通常被称为 Subscriber（订阅者），反之亦然。
 * 此外，“observe”（观察）、“listen”（监听）或“track”（跟踪）通常是一个意思。
 */

#include <iostream>
#include <list>
#include <string>

class IObserver {
public:
  virtual ~IObserver() {};
  virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject {
public:
  virtual ~ISubject() {};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

/**
 * Subject 持有一些重要状态，并在状态发生更改时通知观察者。
 */
class Subject : public ISubject {
public:
  virtual ~Subject() { std::cout << "Goodbye, I was the Subject.\n"; }

  /**
   * 订阅管理方法。
   */
  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override { list_observer_.remove(observer); }
  void Notify() override {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
    }
  }

  void CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    Notify();
  }
  void HowManyObserver() {
    std::cout << "There are " << list_observer_.size()
              << " observers in the list.\n";
  }

  /**
   * 通常，订阅逻辑只是 Subject 能真正做的事情的一小部分。
   * Subject 通常包含一些重要的业务逻辑，
   * 当有重要事件即将发生（或在发生之后）时，会触发通知方法。
   */
  void SomeBusinessLogic() {
    this->message_ = "change message message";
    Notify();
    std::cout << "I'm about to do some thing important\n";
  }

private:
  std::list<IObserver *> list_observer_;
  std::string message_;
};

class Observer : public IObserver {
public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_
              << "\".\n";
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
  }
  void PrintInfo() {
    std::cout << "Observer \"" << this->number_
              << "\": a new message is available --> "
              << this->message_from_subject_ << "\n";
  }

private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

#endif // OBSERVER_H
