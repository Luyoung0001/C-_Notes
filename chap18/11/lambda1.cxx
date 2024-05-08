#include <iostream>
int main() {
    {
        int x = 10;
        auto copy = [x]() mutable {
            x = 20; // 修改的是 x 的副本，不影响外部的 x
            std::cout << "Inside lambda: " << x << std::endl;
        };
        copy();
        std::cout << "Outside lambda: " << x
                  << std::endl; // 输出 10, 外部的 x 未改变
    }
    
    {
        int y = 10;
        auto ref = [&y]() {
            y = 20; // 直接修改 y，影响外部的 y
            std::cout << "Inside lambda: " << y << std::endl;
        };
        ref();

        std::cout << "Outside lambda: " << y
                  << std::endl; // 输出 20, 外部的 y 已被修改
    }

    {
        int a = 10, b = 20;
        auto mixed = [a, &b]() {
            std::cout << "Value capture a: " << a << std::endl;
            std::cout << "Reference capture b before change: " << b
                      << std::endl;
            b = 30; // 修改 b 的值，影响外部的 b
        };
        mixed();
        std::cout << "Outside lambda, new b: " << b << std::endl; // 输出 30
    }
    return 0;
}