#include <iostream>
using namespace std;
int main() {
    // 指针变量不仅仅是指针，而且是指向特定类型的指针.这样是为了让编译器得到指针后,明确偏移量
    int donuts = 6;
    int *p = &donuts;
    cout << *p << endl;
    // 指针的危险
    // 由于 fellow 没有初始化,我们并不清楚它指向哪里
    // 以下代码将 fellow所指的地址中的值修改为 23333,当然这很危险
    long *fellow;
    *fellow = 23333;

    // 好消息是,编译器可以通过这种危险代码,但是操作系统不会让这种程序随意执行
    // 这种悬空指针一般都会出发段错误:
    // zsh: segmentation fault  ./main

    // 指针的值
    // 虽然,指针本身是一个整数值,一般为 uint_64,但是不能随意地将一个整数赋给指针变量,除非强转.
    int *pt;
    pt = (int*)0xB8000000;


    return 0;
}