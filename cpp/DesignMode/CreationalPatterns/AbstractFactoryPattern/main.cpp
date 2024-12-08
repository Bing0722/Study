#include "AbstractFactory.h"

#include <iostream>

/**
 * 客户端代码仅通过抽象类型（AbstractFactory 和
 * AbstractProduct）与工厂和产品进行交互。
 * 这使得你可以将任何工厂或产品子类传递给客户端代码，而不会破坏其功能。
 */
void ClientCode(const AbstractFactory &factory) {
  const AbstractProductA *product_a = factory.CreateProductA();
  const AbstractProductB *product_b = factory.CreateProductB();
  std::cout << product_b->UsefulFunctionB() << "\n";
  std::cout << product_b->AnotherUserfulFunctionB(*product_a) << "\n";

  delete product_a;
  delete product_b;
}

int main(int argc, char *argv[]) {
  std::cout << "Client: Testing client code with the first factory type:\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the second factory "
               "type:\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}
