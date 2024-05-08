#include <iostream>
using namespace std;

class Base {
  public:
    virtual void show() final { // 使用 final 禁止进一步覆盖
        cout << "Base show" << endl;
    }
};

class Derived : public Base {
  public:
    void show() { // 编译错误：尝试覆盖 final 方法
        cout << "Derived show" << endl;
    }
};

int main() {
    Derived d;
    d.show();
}
