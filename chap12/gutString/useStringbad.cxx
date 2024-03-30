// and delete with classes / vegnews.cpp-- using new /
// compile with strngbad.cpp
#include "Stringbad.h"
using std::cout;
using std::endl;

void callme1(Stringbad &);
void callme2(Stringbad);
int main() {
    cout << "Starting an inner block.in:\n";
    Stringbad headline1("Celery stalks at Midnight");    // 1
    Stringbad headline2("Lettuce prey");                 // 2
    Stringbad sports("Spinach Leaves Bowl for Dollars"); // 3

    cout << "headlinel:" << headline1 << endl;
    cout << "headline2:" << headline2 << endl;
    cout << "sports:" << sports << endl;

    callme1(headline1);
    cout << "headline1:" << headline1 << endl;

    callme2(headline2); // 4
    cout << "headline2:" << headline2 << endl;

    cout << "Initialize one object to another:\n";

    // 复制构造函数
    Stringbad sailor = sports; // 正常析构 5
    cout << "sailor:" << sailor << endl;
    cout << "Assign one object to another:\n";

    // ===========================================================
    // 如果没有重载赋值运算符,拷贝将会进行浅拷贝
    // 浅拷贝将会导致自己被析构的时候,析构的是右值的被析构对象
    // 如果最后析构右值对象,那么真正析构它的时候,将会出错:
    // main(31881,0x102a4c580) malloc: *** error
    // for object 0x13f606990: pointer being freed was not allocated


    Stringbad knot;   // 默认构造函数, 正常析构 6
    knot = headline1; // 常规赋值过程
    cout << "knot:" << knot << endl;
    // ===========================================================

    cout << "Exiting the block.in\n";
    cout << "End of main()\n";

    cout << "构造了:" << Stringbad::numsOfStruct << "次.\n\n";
    return 0;
}
void callme1(Stringbad &rsb) {
    cout << "String passed by reference:\n";
    cout << " << rsb << : " << rsb << "\n";
}

// 这里会调用复制构造函数
void callme2(Stringbad sb) {
    cout << "String passed by value:\n";
    cout << " << sb << : " << sb << "\n";
}
