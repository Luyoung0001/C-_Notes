#include <algorithm>
#include <iostream>
#include <vector>

// 普通函数
int generateValue() { return 5; }

// 函数对象
struct Generator {
    int operator()() { return 10; }
};

int main() {
    std::vector<int> vec(5);

    // 使用普通函数
    std::generate(vec.begin(), vec.end(), generateValue);

    // 使用函数对象
    Generator generator;
    std::generate(vec.begin(), vec.end(), generator);

    // 输出结果
    for (int v : vec) {
        std::cout << v << " "; // 将输出 10, 10, 10, 10, 10
    }
    std::cout << std::endl;

    return 0;
}
