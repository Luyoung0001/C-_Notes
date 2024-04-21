#include <iostream>
#include <memory>

void func(std::unique_ptr<int> ptr) { std::cout << *ptr << std::endl; }

int main() {
    std::unique_ptr<int> ptr(new int(10));
    func(std::move(ptr));

    // 此时ptr已经失去所有权，不能再使用
    // std::cout << *ptr << std::endl; // 这里会编译错误
    // 是的，如果不使用std::move()将unique_ptr对象传递给函数，
    // 会导致编译错误。因为unique_ptr是独占所有权的智能指针，
    // 不能直接进行复制或传递所有权，必须使用std::move()来转移所有权。
    // 如果不使用std::move()，编译器会认为试图复制或传递unique_ptr对象，从而导致编译错误。

    return 0;
}
