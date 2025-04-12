#include "FactoryMethod.h"
#include <iostream>

/**
 * @brief 客户端代码通过基接口与具体创作者的实例进行交互。
 * @brief 只要客户端通过基接口继续与创作者交互，就可以传递任何创作者的子类。
 *
 * @param creator Creator对象参数
 */
void ClientCode(const Creator &creator) {
  std::cout
      << "Client: I'm not aware of the creator's class, but it still works.\n"
      << creator.SomeOperation() << std::endl;
}

int main(int argc, char *argv[]) {
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  Creator *creator = new ConcretCreator1();
  ClientCode(*creator);
  std::cout << std::endl;
  std::cout << "App: Launched with the ConcreteCreator2.\n";
  Creator *creator2 = new ConcretCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;
  return 0;
}
