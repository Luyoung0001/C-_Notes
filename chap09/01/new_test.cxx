#include <iostream>
#include <new> // 包含头文件 <new>，用于使用 placement new

using namespace std;

const int BUF = 512; // 定义缓冲区大小为 512 字节
const int N = 5;     // 定义数组大小为 5

char buffer[BUF]; // 静态数组 buffer，用于放置 placement new 分配的内存

int main() {
    double *pd1, *pd2; // 声明指向 double 类型的指针 pd1 和 pd2
    int i;             // 声明整型变量 i 用于循环计数

    cout << "Calling new and placement new:\n";

    // 使用 new 在堆上分配存储空间，pd1 指向该存储空间
    pd1 = new double[N];

    // 使用 placement new 将数据放置在 buffer 数组中，pd2 指向该存储空间
    pd2 = new (buffer) double[N];

    // 对数组中的元素赋值
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;

    // 输出内存地址信息
    cout << "Memory addresses:\n"
         << " heap: " << pd1 << " static: " << (void *)buffer << endl;

    // 输出内存内容信息
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++) {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    // 第二次调用 new 和 placement new
    cout << "\nCalling new and placement new a second time:\n";

    double *pd3, *pd4; // 声明指向 double 类型的指针 pd3 和 pd4

    // 使用 new 在堆上分配存储空间，pd3 指向该存储空间
    pd3 = new double[N];

    // 使用 placement new 将数据放置在 buffer 数组中，pd4 指向该存储空间
    // 定位new运算符使用传递给它的地址，它不跟踪哪些内存单元已被使用，也不查找未使用的内存块。
    pd4 = new (buffer) double[N];

    // 对数组中的元素赋值
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;

    // 输出内存内容信息
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
        cout << pd3[i] << " at " << &pd3[i] << "; " << pd4[i] << " at "
             << &pd4[i] << endl;

    // 第三次调用 new 和 placement new
    cout << "\nCalling new and placement new a third time:\n";

    // 释放 pd1 指向的堆上的存储空间
    delete[] pd1;

    // 使用 new 在堆上分配存储空间，pd1 指向该存储空间
    pd1 = new double[N];

    // 使用 placement new 将数据放置在 buffer 数组中，pd2 指向该存储空间
    pd2 = new (buffer + N * sizeof(double)) double[N];

    // 对数组中的元素赋值
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;

    // 输出内存内容信息
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
        cout << pd1[i] << " at " << &pd1[i] << "; " << pd2[i] << " at "
             << &pd2[i] << endl;

    // 释放 pd1 和 pd3 指向的堆上的存储空间
    delete[] pd1;
    delete[] pd3;
    // delete[] pd2; // 将引发段错误: 而delete只能用于这样的指针：指向常规new运算符分配的堆内存

    return 0;
}
