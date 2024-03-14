#include <iostream>
int main() {
    int a = 100;
    // 有两种类型转换方式
    double b = (double)a;
    char c = char(a);

    // 也能使用关键字 auto

    auto d = 3.55;
    std::cout << d << std::endl;

    std::cout << b << ' ' << c << std::endl;
    return 0;
}