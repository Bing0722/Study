#ifndef PROXY_H
#define PROXY_H

#include <iostream>

class Subject {
public:
  virtual void Request() const = 0;
};

class RealSubject : public Subject {
public:
  void Request() const override {
    std::cout << "RealSubject Request" << std::endl;
  }
};

class Proxy : public Subject {
private:
  RealSubject *real_subject_;
  bool CheckAccess() const {
    std::cout << "Proxy CheckAccess" << std::endl;
    return true;
  }
  void LogAccess() const { std::cout << "Proxy LogAccess" << std::endl; }

public:
  Proxy(RealSubject *real_subject)
      : real_subject_(new RealSubject(*real_subject)) {}

  ~Proxy() { delete real_subject_; }

  void Request() const override {
    if (this->CheckAccess()) {
      this->real_subject_->Request();
      this->LogAccess();
    }
  }
};

#endif // PROXY_H
