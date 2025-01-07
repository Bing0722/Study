#ifndef COR_H
#define COR_H

#include <iostream>

/**
 * 处理器接口声明了一个方法，用于构建处理器链。
 * 它还声明了一个方法，用于执行请求。
 */
class Handler {
public:
  virtual Handler *SetNext(Handler *handler) = 0;
  virtual std::string Handle(std::string request) = 0;
};

/**
 * 默认的链式行为可以在一个基础处理器类中实现。
 */
class AbstractHandler : public Handler {
  /**
   * @var Handler
   */
private:
  Handler *next_handler_;

public:
  AbstractHandler() : next_handler_(nullptr) {}
  Handler *SetNext(Handler *handler) override {
    this->next_handler_ = handler;
    // 从这里返回处理器可以让我们以方便的方式链接处理器，例如：
    // monkey->setNext(squirrel)->setNext(dog);
    return handler;
  }
  std::string Handle(std::string request) override {
    if (this->next_handler_) {
      return this->next_handler_->Handle(request);
    }

    return {};
  }
};

/**
 * 所有具体处理器要么处理请求，要么将其传递给链中的下一个处理器。
 */
class MonkeyHandler : public AbstractHandler {
public:
  std::string Handle(std::string request) override {
    if (request == "Banana") {
      return "Monkey: I'll eat the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};
class SquirrelHandler : public AbstractHandler {
public:
  std::string Handle(std::string request) override {
    if (request == "Nut") {
      return "Squirrel: I'll eat the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};
class DogHandler : public AbstractHandler {
public:
  std::string Handle(std::string request) override {
    if (request == "MeatBall") {
      return "Dog: I'll eat the " + request + ".\n";
    } else {
      return AbstractHandler::Handle(request);
    }
  }
};

#endif // COR_H
