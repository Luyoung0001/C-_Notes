#include <iostream>
using namespace std;
// 模板声明
template <typename T> void Swap(T &a, T &b);
int main() {
    int a1 = 1, a2 = 10;
    double b1 = 0.1, b2 = 1.01;
    // 第一个Swap( )函数接受两个int参数，因此编译器生成该函数的int版本。
    // 也就是说，用int替换所有的T，生成下面这样的定义
    Swap(a1, a2);
    Swap(b1, b2);
    // swap(a1,b1); C++中已经定义了这个函数

    cout << "交换后a1:" << a1 << " a2:" << a2 << endl;
    cout << "交换后b1:" << b1 << " b2:" << b2 << endl;

    return 0;
}

// 模板定义
template <typename T> void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
// 函数模板不能缩短可执行程序。对于程序清单8.11，
// 最终仍将由两个独立的函数定义，就像以手工方式定义了这些函数一样。
// 最终的代码不包含任何模板，而只包含了为程序生成的实际函数