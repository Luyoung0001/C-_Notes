#include "time.h"
#include <iostream>
int main() {
    Time t1(10, 50);
    Time t2(8, 20);

    t1.show();
    t2.show();

    t1 = t1 + t2; // 运算符重载
    t1.show();

    t1.AddHr(20);
    t1.AddMin(80);
    t1.show();

    t1.Reset(1, 20);
    t1 = t1 * 1.5;
    t1.show();
    // 这里就会失效,因为该表达式无法转化为
    // t1.oprater*(1.5),它转化为了 1.5.oprater(t1) 为了解决这种问题,
    // 可以通过友元函数来解决 t1 = 1.5 * t1;

    // 解决问题后
    t1 = 1.5 * t1;

    t1.show();

    return 0;
}