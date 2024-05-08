#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int multiplier = 5;
    std::vector<int> values = {1, 2, 3, 4, 5};

    // Lambda 表达式：捕获 multiplier 值，接受一个整数参数，返回乘以 multiplier
    // 的结果
    auto lambda = [multiplier](int value) { return value * multiplier; };

    std::transform(values.begin(), values.end(), values.begin(), lambda);

    for (int value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
