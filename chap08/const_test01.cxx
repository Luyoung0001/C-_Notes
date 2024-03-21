#include <iostream>
using namespace std;
void swap(double &a, double &b);
void swapconst(const double &a, const double &b);
int main() {
    int a = 10, b = 20;
    // 就算类型不一致,也不会创建临时变量,禁止创建临时变量，现在的C++标准正是这样做的
    swap(a, b);
    cout << "a:" << a << "b:" << b << endl;

    int c = 1, d = 2;
    cout << "变量的地址:" << &c << ' ' << "变量的地址:" << &d << endl;
    swapconst(c, d);
    return 0;
}
void swap(double &a, double &b) {
    int temp = a;
    a = b;
    b = temp;
}
void swapconst(const double &a, const double &b) {
    // 这里所做的一切修改,都是在对临时变量修改,徒劳的
    // 如果引用参数是const，则编译器将在下面两种情况下生成临时变量：
    // 实参的类型正确，但不是左值；
    // 实参的类型不正确，但可以转换为正确的类型。
    cout << "临时变量的地址:" << &a << ' ' << "临时变量的地址:" << &b << endl;
    // 变量的地址:0x16b03b2e0 变量的地址:0x16b03b2dc
    // 临时变量的地址:0x16b03b2d0 临时变量的地址:0x16b03b2c8
}