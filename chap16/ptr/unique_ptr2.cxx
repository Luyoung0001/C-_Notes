#include <iostream>

template<typename T>
class unique_ptr {
private:
    T* ptr; // 指向动态分配的内存的指针

public:
    explicit unique_ptr(T* p = nullptr) : ptr(p) {} // 构造函数

    ~unique_ptr() { // 析构函数
        delete ptr; // 释放动态分配的内存
    }

    unique_ptr(const unique_ptr&) = delete; // 禁用复制构造函数
    unique_ptr& operator=(const unique_ptr&) = delete; // 禁用复制赋值运算符

    unique_ptr(unique_ptr&& other) noexcept // 移动构造函数
        : ptr(other.ptr) {
        other.ptr = nullptr; // 置空源对象的指针，防止重复释放
    }

    unique_ptr& operator=(unique_ptr&& other) noexcept { // 移动赋值运算符
        if (this != &other) {
            delete ptr; // 释放当前对象指向的内存
            ptr = other.ptr; // 转移资源所有权
            other.ptr = nullptr; // 置空源对象的指针，防止重复释放
        }
        return *this;
    }

    T* release() { // 释放资源所有权
        T* temp = ptr;
        ptr = nullptr; // 置空指针，防止析构函数重复释放
        return temp;
    }

    T* get() const { // 获取指针
        return ptr;
    }

    T* operator->() const { // 重载箭头运算符
        return ptr;
    }

    T& operator*() const { // 解引用操作符
        return *ptr;
    }
};

int main() {
    unique_ptr<int> up(new int(42));
    std::cout << *up << std::endl; // 输出：42

    unique_ptr<int> up2 = std::move(up); // 移动构造
    std::cout << *up2 << std::endl; // 输出：42
    std::cout << (up.get() == nullptr) << std::endl; // 输出：1，up已经转移所有权，不再指向任何对象

    unique_ptr<int> up3(new int(100));
    up3 = std::move(up2); // 移动赋值
    std::cout << *up3 << std::endl; // 输出：42
    std::cout << (up2.get() == nullptr) << std::endl; // 输出：1，up2已经转移所有权，不再指向任何对象

    return 0;
}
