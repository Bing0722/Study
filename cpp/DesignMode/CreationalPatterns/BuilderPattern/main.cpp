#include "Builder.h"
#include <iostream>

/**
 * 客户端代码创建一个建造者对象，将其传递给主管，然后启动构建过程。
 * 最终结果从建造者对象中获取。
 */

/**
 * 我使用了原始指针以简化示例，但你可能更倾向于在这里使用智能指针。
 */
void ClientCode(Director &director) {
  ConcreteBuilder1 *builder = new ConcreteBuilder1();
  director.set_builder(builder);
  std::cout << "Standard basic product:\n";
  director.BuildMinimalViableProduct();

  Product1 *p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "Standard full featured product:\n";
  director.BuildFullFeatureProduct();

  p = builder->GetProduct();
  p->ListParts();
  delete p;

  std::cout << "Custom product:\n";
  builder->ProducePartA();
  builder->ProducePartC();
  p = builder->GetProduct();
  p->ListParts();
  delete p;

  delete builder;
}

int main(int argc, char *argv[]) {
  Director *director = new Director();
  ClientCode(*director);
  delete director;
  return 0;
}
