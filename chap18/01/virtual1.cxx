#include <iostream>
using namespace std;

class Base {

  public:
    virtual ~Base() {}
    virtual void show() { cout << "Base show" << endl; }
};

class Derived : public Base {
  public:
    using Base::show; // 将 Base 类的 show 方法引入派生类的作用域
    void show(int x) { cout << "Derived show with int: " << x << endl; }
};

int main() {
    Derived d;
    d.show();   // 调用 Base 的 show
    d.show(10); // 调用 Derived 的 show(int)
}
