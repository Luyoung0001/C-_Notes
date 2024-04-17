#include <iostream>
#include <string>

class MyClass {
  private:
    int data;

  public:
    MyClass(int d = 0) : data(d) {
        std::cout << "Constructor called. Data: " << data << std::endl;
    }

    MyClass(const MyClass &other) : data(other.data) {
        std::cout << "Copy constructor called. Data: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructor called. Data: " << data << std::endl;
    }
    // 赋值构造
    MyClass &operator=(const MyClass &other) {
        std::cout << "Myclass = constructor called.\n" << std::endl;
        if (this != &other) { // 检查自我赋值
            data = other.data;
        }
        return *this;
    }

    int getData() const { return data; }
};

MyClass createObject(int value) {
    MyClass m1(value); // 栈内创建对象
    return m1;         // 触发复制构造函数
}

int main() {
    MyClass obj = createObject(10);
    std::cout << "Returned object data: " << obj.getData() << std::endl;

    return 0;
}
