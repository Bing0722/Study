#ifndef _ADAPTER_MULTIPLE_INHERITANCE_H
#define _ADAPTER_MULTIPLE_INHERITANCE_H

#include <algorithm>
#include <string>

class Target {
public:
  virtual ~Target() = default;
  virtual std::string Request() const {
    return "Target: The default target's behavior.";
  }
};

class Adaptee {
public:
  std::string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

class Adapter : public Target, public Adaptee {
public:
  Adapter() {}
  std::string Request() const override {
    std::string to_reverse = SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }
};

#endif // ADAPTER_MULTIPLE_INHERITANCE_H
