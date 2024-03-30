// and delete with classes / vegnews.cpp-- using new /
// compile with strngbad.cpp
#include "string.h"
using std::cout;
using std::endl;

void callme1(String &);
void callme2(String);
int main() {
    cout << "Starting an inner block.in:\n";
    String headline1("Celery stalks at Midnight");    // 1
    String headline2("Lettuce prey");                 // 2
    String sports("Spinach Leaves Bowl for Dollars"); // 3

    cout << "headlinel:" << headline1 << endl;
    cout << "headline2:" << headline2 << endl;
    cout << "sports:" << sports << endl;

    callme1(headline1);
    cout << "headline1:" << headline1 << endl;

    callme2(headline2); // 4
    cout << "headline2:" << headline2 << endl;

    cout << "Initialize one object to another:\n";
    // 隐式赋值运算
    // 复制构造函数
    String sailor = sports; // 正常析构 5
    cout << "sailor:" << sailor << endl;
    cout << "Assign one object to another:\n";

    String knot;   // 默认构造函数, 正常析构 6
    knot = headline1; // 常规赋值过程
    cout << "knot:" << knot << endl;
    // ===========================================================

    cout << "Exiting the block.in\n";
    cout << "End of main()\n";
    return 0;
}
void callme1(String &rsb) {
    cout << "String passed by reference:\n";
    cout << " << rsb << : " << rsb << "\n";
}

// 这里会调用复制构造函数(由编译器生成)
void callme2(String sb) {
    cout << "String passed by value:\n";
    cout << " << sb << : " << sb << "\n";
}
