#include <iostream>
#include <vector>

class A {
public:
  int *pointer;
  A() : pointer(new int(1)) { std::cout << "构造" << pointer << std::endl; }

  // 无意义的对象拷贝
  A(A &a) : pointer(new int(*a.pointer)) { std::cout << "拷贝" << std::endl; }

  A(A &&a) : pointer(a.pointer) {
    a.pointer = nullptr;
    std::cout << "移动" << std::endl;
  }

  ~A() {
    std::cout << "析构" << std::endl;
    delete pointer;
  }
};

// 防止编译器优化
A return_rvalue(bool test) {
  A a, b;
  if (test) {
    return a; // 等价于 static_cast<A&&>(a)
  } else {
    return b; // 等价于 static_cast<A&&>(b)
  }
}

int main(int argc, char *argv[]) {
  A obj = return_rvalue(false);
  std::cout << "obj: " << std::endl;
  std::cout << obj.pointer << std::endl;
  std::cout << *obj.pointer << std::endl;

  A obj2 = std::move(obj);
  std::cout << "obj2: " << std::endl;
  std::cout << obj2.pointer << std::endl;
  std::cout << *obj2.pointer << std::endl;

  std::string str = "hello";
  std::vector<std::string> vec;

  // 拷贝
  vec.push_back(str);
  std::cout << "str: " << str << std::endl;

  // 移动
  vec.push_back(std::move(str));
  // str 值发生移动 输出为空
  std::cout << "str: " << str << std::endl;

  return 0;
}
