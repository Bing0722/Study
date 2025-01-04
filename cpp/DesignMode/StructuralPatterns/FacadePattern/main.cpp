#include "facade.h"

/**
 * 客户端代码通过外观提供的简单接口与复杂的子系统交互。
 * 当外观管理子系统的生命周期时，客户端甚至可能不知道子系统的存在。
 * 这种方法可以让你控制复杂性。
 */
void ClientCode(Facade *facade) { std::cout << facade->Operation(); }

/**
 * 客户端代码可能已经创建了一些子系统对象。
 * 在这种情况下，用这些对象来初始化外观可能是值得的，而不是让外观创建新的实例。
 */
int main() {
  SubSystem1 *subsystem1 = new SubSystem1;
  SubSystem2 *subsystem2 = new SubSystem2;
  Facade *facade = new Facade(subsystem1, subsystem2);
  ClientCode(facade);

  delete facade;

  return 0;
}
