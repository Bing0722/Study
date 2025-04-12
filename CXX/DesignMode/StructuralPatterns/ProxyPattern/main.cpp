#include "proxy.h"

/**
 * 客户端代码应该通过 Subject 接口与所有对象（包括 RealSubject 和 Proxy）交互，
 * 以便支持 RealSubject 和 Proxy。在现实生活中，客户端通常直接与 RealSubject
 * 交互。 在这种情况下，为了更容易实现模式，可以让 Proxy 继承自 RealSubject
 * 的类。
 */
void ClientCode(const Subject &subject) {
  // ...
  subject.Request();
  // ...
}

int main() {
  std::cout << "Client: Executing the client code with a real subject:\n";
  RealSubject *real_subject = new RealSubject;
  ClientCode(*real_subject);
  std::cout << "\n";
  std::cout << "Client: Executing the same client code with a proxy:\n";
  Proxy *proxy = new Proxy(real_subject);
  ClientCode(*proxy);
  delete real_subject;
  delete proxy;
  return 0;
}
