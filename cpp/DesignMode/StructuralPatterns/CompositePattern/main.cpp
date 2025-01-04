#include "Composite.h"
#include <iostream>

/**
 * 客户端代码通过基础接口与所有组件进行交互。
 */
void ClientCode(const Component *component) {
  std::cout << "Result: " << component->Operation() << std::endl;
}

/**
 * 由于子节点管理操作在基础组件类中声明，客户端代码可以与任何组件（无论是简单的还是复杂的）进行交互，
 * 而不依赖于它们的具体类。
 */
void ClientCode2(Component *component1, Component *component2) {
  if (component1->IsComposite()) {
    component1->Add(component2);
  }
  std::cout << "Result: " << component1->Operation() << std::endl;
}

/**
 * 这样，客户端代码可以支持简单的叶子组件...
 */

int main() {
  Component *simple = new Leaf;
  std::cout << "Client: I've got a simple component:\n";
  ClientCode(simple);
  std::cout << "\n\n";

  Component *tree = new Composite;
  Component *branch1 = new Composite;

  Component *leaf_1 = new Leaf;
  Component *leaf_2 = new Leaf;
  Component *leaf_3 = new Leaf;
  branch1->Add(leaf_1);
  branch1->Add(leaf_2);
  Component *branch2 = new Composite;
  branch2->Add(leaf_3);
  tree->Add(branch1);
  tree->Add(branch2);
  std::cout << "Client: Now I've got a composite tree:\n";
  ClientCode(tree);
  std::cout << "\n\n";

  std::cout << "Client: I don't need to check the component classes even when "
               "manager the tree:\n";

  ClientCode2(tree, simple);
  std::cout << "\n";

  delete simple;
  delete tree;
  delete branch1;
  delete branch2;
  delete leaf_1;
  delete leaf_2;
  delete leaf_3;

  return 0;
}
