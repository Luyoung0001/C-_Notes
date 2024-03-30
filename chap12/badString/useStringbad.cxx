// and delete with classes / vegnews.cpp-- using new /
// compile with strngbad.cpp
#include "Stringbad.h"
using std::cout;
using std::endl;

void callme1(Stringbad &); // pass by reference
void callme2(Stringbad);   // pass by value
int main() {
    cout << "Starting an inner block.in:\n";
    Stringbad headline1("Celery stalks at Midnight"); // 无法被正常析构
    Stringbad headline2("Lettuce prey");
    Stringbad sports("Spinach Leaves Bowl for Dollars"); // 无法被正常析构

    cout << "headlinel:" << headline1 << endl;
    cout << "headline2:" << headline2 << endl;
    cout << "sports:" << sports << endl;

    callme1(headline1);
    cout << "headline1:" << headline1 << endl;

    // 这里调用赋值构造函数,因为按值传递了对象
    // 调用完直接析构
    // 析构了原来对象中的 str,因此 cout << "headline2:" << headline2 << endl
    // 会打印乱码: string: 0@?Xh?
    callme2(headline2);
    cout << "headline2:" << headline2 << endl;

    cout << "Initialize one object to another:\n";
    // 调用赋值运算符重载函数进行赋值初始化,赋值构造函数

    // 相当于:
    // Stringbad sailor = Stringbad(sports);
    // 调用的构造函数如下:
    // Stringbad(const Stringbad &);

    // 隐式赋值运算
    Stringbad sailor = sports; // 正常析构
    cout << "sailor:" << sailor << endl;
    cout << "Assign one object to another:\n";

    Stringbad knot; // 默认构造函数, 正常析构
    knot = headline1;
    cout << "knot:" << knot << endl;

    cout << "Exiting the block.in\n";
    cout << "End of main()\n";

    cout << "构造了:" << Stringbad::numsOfStruct << "次.\n\n";
    return 0;
}
void callme1(Stringbad &rsb) {
    cout << "String passed by reference:\n";
    cout << " << rsb << : " << rsb << "\n";
}

// 这里会调用复制构造函数(由编译器生成)
void callme2(Stringbad sb) {
    cout << "String passed by value:\n";
    cout << " << sb << : " << sb << "\n";
}
// 一个内存不能被析构两次,不然会报错误:main(31881,0x102a4c580) malloc: *** error
// for object 0x13f606990: pointer being freed was not allocated
// 以下是运行结果:
// Starting an inner block.in:
// 构造对象:0x16d4a3488
// 构造:s

// 构造对象:0x16d4a3478
// 构造:s

// 构造对象:0x16d4a3458
// 构造:s

// headlinel:对象以及类的信息:
// 对象:0x16d4a3488
// 对象.str 中指向的内存地址:0x600001c81100
// length: 25
// string: Celery stalks at Midnight
// 类的对象的个数3

// headline2:对象以及类的信息:
// 对象:0x16d4a3478
// 对象.str 中指向的内存地址:0x600001e84030
// length: 12
// string: Lettuce prey
// 类的对象的个数3

// sports:对象以及类的信息:
// 对象:0x16d4a3458
// 对象.str 中指向的内存地址:0x600001c81120
// length: 31
// string: Spinach Leaves Bowl for Dollars
// 类的对象的个数3

// String passed by reference:
//  << rsb << : 对象以及类的信息:
// 对象:0x16d4a3488
// 对象.str 中指向的内存地址:0x600001c81100
// length: 25
// string: Celery stalks at Midnight
// 类的对象的个数3

// headline1:对象以及类的信息:
// 对象:0x16d4a3488
// 对象.str 中指向的内存地址:0x600001c81100
// length: 25
// string: Celery stalks at Midnight
// 类的对象的个数3

// String passed by value:
//  << sb << : 对象以及类的信息:
// 对象:0x16d4a3440
// 对象.str 中指向的内存地址:0x600001e84030
// length: 12
// string: Lettuce prey
// 类的对象的个数3

// 析构对象前对象的数目: 3
// 析构掉对象:0x16d4a3440
// 析构掉对象.str 中指向的内存地址:0x600001e84030
// 析构对象后对象的数目: 2

// headline2:对象以及类的信息:
// 对象:0x16d4a3478
// 对象.str 中指向的内存地址:0x600001e84030
// length: 12
// string: 0@?Xh?
// 类的对象的个数2

// Initialize one object to another:
// sailor:对象以及类的信息:
// 对象:0x16d4a3430
// 对象.str 中指向的内存地址:0x600001c81120
// length: 31
// string: Spinach Leaves Bowl for Dollars
// 类的对象的个数2

// Assign one object to another:
// 构造对象:0x16d4a3420
// 默认构造:C++
// knot:对象以及类的信息:
// 对象:0x16d4a3420
// 对象.str 中指向的内存地址:0x600001c81100
// length: 25
// string: Celery stalks at Midnight
// 类的对象的个数3

// Exiting the block.in
// End of main()
// 构造了:4次.

// 析构对象前对象的数目: 3
// 析构掉对象:0x16d4a3420
// 析构掉对象.str 中指向的内存地址:0x600001c81100
// 析构对象后对象的数目: 2

// 析构对象前对象的数目: 2
// 析构掉对象:0x16d4a3430
// 析构掉对象.str 中指向的内存地址:0x600001c81120
// 析构对象后对象的数目: 1

// 析构对象前对象的数目: 1
// main(39331,0x102c8c580) malloc: *** error for object 0x600001c81120: pointer
// being freed was not allocated main(39331,0x102c8c580) malloc: *** set a
// breakpoint in malloc_error_break to debug zsh: abort      ./main