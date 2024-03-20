#include <iostream>
using namespace std;
int sum1(int *arr, int n);
int sum2(const int *arr, int n);
int main() {
    // 声明一个指向常量的指针p：
    int age = 39;
    const int *p = &age;
    // 不能通过 p 修改 age,但是这并不意味着 age 就是一个常量,
    // 只能说明*p 是一个常量,不能修改.如:
    age++; // 合法
    // *p = 30;, 不合法
    cout << age << endl;
    // 仍然可以用 p 来指向其它变量
    int age1 = 80;
    p = &age1;
    // *p = 79; // 依然不能这样修改

    // 还有以下两种做法
    const float g_earth = 9.8;
    const float *pg = &g_earth;

    const float g_moon = 1.63;
    // float *pm = &g_moon; // 这是无效的,因为通过指针来修改 const 的值很荒谬

    // const 类型的数组
    const int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 20, 31, 20, 31};
    // 禁止将常量数组的地址赋给非常量指针将意味着不能将数组名作为参数传递给使用非常量形参的函数

    // int s1 = sum1(months,12); 不合法
    int s2 = sum2(months, 12);
    // 从这里就可以看出,const 修饰的形参具有很强的兼容性,它能传递一个非 const
    // 或者 const,而没有 const 修饰的形参,只能传递非 const.
    // 使用const使得函数能够处理const和非const实参，否则将只能接受非const数据。

    return 0;
}
int sum1(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
int sum2(const int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
