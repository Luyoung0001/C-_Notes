#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

const int LIM = 5;
double arr1[LIM] = {36, 39, 42, 45, 48};
double arr2[LIM] = {2.5, 2.5, 2.5, 2.5, 2.5};

// 函数适配器，用于包装 std::multiplies<double>
struct multip1 {
    double operator()(double x, double y) const {
        return std::multiplies<double>()(
            x, y); // 调用 std::multiplies<double> 的函数调用运算符
    }
};

int main() {
    std::vector<double> gr8(arr1, arr1 + LIM);
    std::vector<double> m8(arr2, arr2 + LIM);
    std::ostream_iterator<double, char> out(std::cout, " ");

    // 使用 std::transform
    // 将两个向量中的元素逐个相乘，并将结果输出到标准输出流中
    std::transform(gr8.begin(), gr8.end(), m8.begin(), out, multip1());
    std::cout << std::endl;
    return 0;
}
