#include <iostream>
#include <string>

int a = 0;

class Base {
    int data;

  public:
    Base(int d = 0) : data(d) {}
    virtual ~Base() { std::cout << "Base destructor called.\n" << std::endl; }
    virtual void display() const {
        std::cout << "Base base value:" << data << "\n" << std::endl;
    }
    int value() const { return data; }
    // 复制构造
    Base(const Base &other) : data(other.data) {
        a++;
        std::cout << "Base copy constructor called.\n" << std::endl;
    }
};

class Derived : public Base {
    char data;

  public:
    Derived(char c = 'a') : Base(), data(c) {}
    virtual ~Derived() {
        std::cout << "Derived destructor called.\n" << std::endl;
    }
    virtual void display() const override {
        std::cout << "Derived base value:" << Base::value() << std::endl;
        std::cout << "Derived derived value:" << data << "\n" << std::endl;
    }
    // 复制构造
    Derived(const Derived &other) : Base(other), data(other.data) {
        a++;
        std::cout << "Derived copy constructor called.\n" << std::endl;
    }
};

void throwException(bool useDerived) {
    if (useDerived) {
        Derived d('b');
        throw d;
    } else {
        Base b(100);
        throw b;
    }
}

int main() {
    try {
        // 使用基类的引用捕获异常

        // 调用一次基类复制构造+1
        // 调用一次派生类复制构造+1

        // 析构抛出对象
        try {
            std::cout << "---------------开始构造--------------" << std::endl;
            throwException(true);
        } catch (Base &b) {
            std::cout << "\na: " << a << std::endl;
            b.display(); // 多态调用
            // 生命周期结束,析构指向的对象
            std::cout << "---------------开始析构--------------" << std::endl;
        }

        // 调用一次基类复制构造+1
        // 调用一次派生类复制构造+1
        // 析构抛出对象

        // 由于catch()参数是对象
        // 继续调用基类复制构造+1

        try {
            std::cout << "---------------开始构造--------------" << std::endl;
            throwException(true);

        } catch (Base b) {
            std::cout << "\na: " << a << std::endl;
            b.display(); // 非多态调用,发生切片现象
            // 生命周期结束,析构异常对象副本,以及异常对象
            std::cout << "---------------开始析构--------------" << std::endl;
        }

        // 调用一次基类复制构造+1
        // 析构抛出对象
        try {
            std::cout << "---------------开始构造--------------" << std::endl;
            throwException(false);
        } catch (Base &b) {
            std::cout << "\na: " << a << std::endl;
            b.display();
            // 生命周期结束,析构指向的对象
            std::cout << "---------------开始析构--------------" << std::endl;
        }

        // 调用基类复制构造+1
        // 析构抛出对象
        // 由于 catch()参数是对象
        // 调用复制构造+1
        try {
            std::cout << "---------------开始构造--------------" << std::endl;
            throwException(false);
        } catch (Base b) {
            std::cout << "\na: " << a << std::endl;
            b.display();
            // 生命周期结束,析构异常对象副本,以及异常对象
            std::cout << "---------------开始析构--------------" << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "\nCaught exception: " << e.what() << std::endl;
    }

    return 0;
}
