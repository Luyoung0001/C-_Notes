#include <iostream>
using namespace std;

class Base {
  public:
    virtual ~Base() {}
    virtual void show() { cout << "Show from Base" << endl; }
};

class Derived : public Base {
  public:
    // 这个函数虽然与基类函数同名，但因为参数不同，它实际上隐藏了基类的 show()
    void show(int x) { cout << "Show from Derived with int: " << x << endl; }
};

int main() {
    Derived d;
    d.show(5); // 调用 Derived 的 show(int)
    // d.show();  // 错误：Base 类中的 show() 被隐藏，无法直接调用

    // 要调用基类的 show() 方法，需要明确指定
    d.Base::show(); // 正确调用 Base 的 show()
}
