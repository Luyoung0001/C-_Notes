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
    r2(r1());
    std::cout << "Done!\n";
    return 0;
}
