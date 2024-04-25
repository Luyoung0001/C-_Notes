#include <iostream>
#include <vector>

// 自定义函数对象，用于打印容器中的元素
struct Print {
    template <typename T> void operator()(const T &value) const {
        std::cout << value << " ";
    }
};

// 函数模板，接受一个容器和一个函数对象，并对容器中的每个元素执行函数对象的操作
template <typename Container, typename Function>
void process(const Container &container, Function func) {
    for (const auto &elem : container) {
        func(elem);
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::vector<double> values = {1.1, 2.2, 3.3, 4.4, 5.5};

    // 使用自定义的 Print 函数对象打印 numbers,values 中的元素
    process(numbers, Print()); // 输出：1 2 3 4 5
    process(values, Print());  // 输出：1.1 2.2 3.3 4.4 5.5

    return 0;
}
