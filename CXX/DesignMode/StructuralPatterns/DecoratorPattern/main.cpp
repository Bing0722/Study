#include "decorator.h"
#include <iostream>

/**
 * 客户端代码通过组件接口与所有对象交互。
 * 这样可以使其与具体的组件类解耦。
 */
void ClientCode(Component *component) {
  // ...
  std::cout << "RESULT: " << component->Operation();
  // ...
}

int main() {
  /**
   * 这样客户端代码可以支持简单组件...
   */
  Component *simple = new ConcreteComponent;
  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";
  /**
   * ...以及被装饰的组件。
   *
   * 注意，装饰器不仅可以包装简单组件，还可以包装其他装饰器。
   */
  Component *decorator1 = new ConcreteDecoratorA(simple);
  Component *decorator2 = new ConcreteDecoratorB(decorator1);
  std::cout << "Client: Now I've got a decorated component:\n";
  ClientCode(decorator2);
  std::cout << "\n";

  delete simple;
  delete decorator1;
  delete decorator2;

  return 0;
}
