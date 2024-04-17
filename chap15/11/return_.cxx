#include <iostream>
#include <string>

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
        std::cout << "Base copy constructor called.\n" << std::endl;
    }
    // 赋值构造
    Base &operator=(const Base &other) {
        std::cout << "Base = constructor called.\n" << std::endl;
        if (this != &other) { // 检查自我赋值
            data = other.data;
        }
        return *this;
    }
};

Base r1() {
    Base b(5);
    return b;
}
void r2(Base base) { std::cout << base.value() << std::endl; }
int main() {
    // 这里进行了优化
    // 编译器偷偷地增加了一个参数,传入了b1的地址,直接在函数内部构造了b1对象
    // 因此这里的复制构造, 赋值构造都不会被调用
    Base b1 = r1();

    // 这里会老实的调用复制构造函数
    r2(b1);

    // 之后析构掉临时对象copied from b1
    std::cout << "Done!\n";
    // 最后析构掉b1
    return 0;
}
