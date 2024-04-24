#include <iostream>
#include <vector>
#include <algorithm>

// 定义一个类，其中重载了 () 运算符
class FunctionObject {
public:
    // 重载 () 运算符，用于执行特定操作
    void operator()(int num) const {
        std::cout << num << " squared is: " << num * num << std::endl;
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用函数对象执行特定操作，这里是输出数字的平方
    FunctionObject f;
    std::for_each(numbers.begin(), numbers.end(), f);

    return 0;
}
