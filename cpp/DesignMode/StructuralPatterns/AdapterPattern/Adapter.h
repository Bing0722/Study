#ifndef _ADAPTER_H
#define _ADAPTER_H

#include <algorithm>
#include <string>

/**
 * @class Target
 * @brief 定义了客户端代码使用的领域特定接口
 *
 */
class Target {
public:
  virtual ~Target() = default;

  virtual std::string Resquest() const {
    return "Target: The default target's behavior.";
  }
};

/**
 * @class Adaptee
 * @brief 包含一些有用的行为，但其接口与现有的客户端代码不兼容
 * @brief 在客户端代码可以使用它之前，Adaptee 需要进行一些适配。
 *
 */
class Adaptee {
public:
  std::string SpecificRequest() const {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

/**
 * @class Adapter
 * @brief 使 Adaptee 的接口与 Target 的接口兼容。
 *
 */
class Adapter : public Target {
public:
  Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
  std::string Resquest() const override {
    std::string to_reverse = this->adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (TRANSLATED) " + to_reverse;
  }

private:
  Adaptee *adaptee_;
};

#endif // ADAPTER_H
