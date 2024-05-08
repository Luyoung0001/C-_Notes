#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// 普通函数
int generateValue() { return 5; }

int main() {
    std::vector<int> vec(10);

    // 使用普通函数
    std::generate(vec.begin(), vec.end(), generateValue);

    // 使用函数对象
    struct Generator {
        int operator()() { return 10; }
    };
    Generator generator;
    std::generate(vec.begin(), vec.end(), generator);

    // 使用 Lambda 表达式
    std::generate(vec.begin(), vec.end(), []() { return 15; });

    // 打印结果
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
