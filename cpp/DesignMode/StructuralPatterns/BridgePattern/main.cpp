#include "Bridge.h"
#include <iostream>

/**
 * 除了初始化阶段，其中一个 Abstraction 对象与特定的 Implementation 对象关联，
 * 客户端代码应该只依赖于 Abstraction 类。这样，客户端代码可以支持任何抽象-
 * 实现的组合。
 */
void ClientCode(const Abstraction &abstraction) {
  // ...
  std::cout << abstraction.Operation();
  // ...
}

/**
 * 客户端代码应能够与任何预配置的抽象-实现组合协同工作。
 */
int main(int argc, char *argv[]) {
  Implementation *implementation = new ConcreteImplementationA;
  Abstraction *abstraction = new Abstraction(implementation);
  ClientCode(*abstraction);
  std::cout << std::endl;
  delete implementation;
  delete abstraction;

  implementation = new ConcreteImplementationB;
  abstraction = new ExtendedAbstraction(implementation);
  ClientCode(*abstraction);

  delete implementation;
  delete abstraction;

  return 0;
}
