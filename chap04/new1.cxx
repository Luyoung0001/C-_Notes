#include <iostream>
int main() {
    using namespace std;

    // 分配
    int *psome = new int[10];
    // 释放
    delete[] psome;
    // 这里应该注意指针和数组名的差别,它们不是等价的
    double *p = new double[3];
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;
    cout << p[0] << endl;
    p = p + 1; // 差别
    cout << p[1] << endl;

    // 数组的地址,这里可以看出区别
    short tell[10];
    cout << sizeof(tell) << endl;
    cout << tell << endl;
    cout << &tell << endl;
    cout << tell + 1 << endl;
    cout << &tell + 1 << endl;
    // 看这个声明
    short(*pas)[10] = &tell; // pas 为 short(*)[20]复合类型
    short* p1[20]; // p1 是一个指针数组

    // 在cout和多数C++表达式中，char数组名、char指针以及用引号括起的字符串常量都被解释为字符串第一个字符的地址
    // 字符串字面值是常量，这就是为什么代码在声明中使用关键字const的原因。
    // 以这种方式使用const意味着可以用 string1 来访问字符串，但不能修改它
    const char *string1 = "hello";
    // string1[1] = 'a'; // bus error,根本原因它被存储在常量区
    cout << string1 << endl;

    char string2[] = "hello";
    string2[1] = 'a'; // 正常行为,它被存储在栈区,可以修改
     cout << string2 << endl;


    return 0;
}