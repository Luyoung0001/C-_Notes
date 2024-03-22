#include <iostream>
using namespace std;
// void print(int a, int b = 2,int c); 无效,
// 要为某个参数设置默认值，则必须为它右边的所有参数提供默认值
void print(int a, int b = 2, int c = 5);
int main() {
    print(3, 45, 6);
    print(3); // 实参按从左到右的顺序依次被赋给相应的形参，而不能跳过任何参数。
    return 0;
}
// 只有原型指定了默认值,函数定义与没有默认参数时完全相同
void print(int a, int b, int c) {
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}