#include <algorithm>
#include <iostream>
#include <vector>

// 定义一个函数，用于执行特定操作
void squareAndPrint(int num) {
    std::cout << num << " squared is: " << num * num << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用函数指针执行特定操作，这里是输出数字的平方
    void (*funcPtr)(int) = squareAndPrint;
    std::for_each(numbers.begin(), numbers.end(), funcPtr); // 事实上,编译器会自动包装


    return 0;
}
