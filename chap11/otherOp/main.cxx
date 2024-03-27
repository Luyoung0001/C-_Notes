#include "time.h"
#include <iostream>
int main() {
    Time t1(10, 50);
    Time t2(8, 20);

    t1.show();
    t2.show();

    t1.Sum(t2);
    t1.show();

    t1.AddHr(20);
    t1.AddMin(80);
    t1.show();

    t1.Reset(0, 0);
    t1.show();
    std::cout << t1 << t2 << "this is a test!" << std::endl;

    return 0;
}