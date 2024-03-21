#include <iostream>
using namespace std;
void hello(int n);
void world(int n);
// 调用函数
void Hello(void (*fp1)(int), void (*fp2)(int), int n);
int main() {
    // 函数指针
    void (*fp1)(int);
    // 赋值
    fp1 = hello;
    void (*fp2)(int) = world;
    // 调用
    Hello(hello, world, 6);

    // 最方便的是使用 auto 关键字
    auto fp3 = world;
    auto fp4 = hello;
    Hello(fp3, fp4, 4);
    return 0;
}
void hello(int n) {
    for (int i = 0; i < n; i++)

        cout << "hello" << endl;
}
void world(int n) {
    for (int i = 0; i < n; i++)

        cout << "world" << endl;
}
void Hello(void (*fp1)(int), void (*fp2)(int), int n) {
    cout << "现在调用函数1:" << endl;
    fp1(n);
    cout << "现在调用函数2:" << endl;
    fp2(n);
}