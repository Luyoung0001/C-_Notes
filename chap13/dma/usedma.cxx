#include "basedma.h"
#include "hasdma.h"
#include "lacksdma.h"
#include <iostream>
int main() {
    using std::cin;
    using std::cout;

    baseDMA b1 ("l1",8);
    lacksDMA lb1("red","l2",9);
    hasDMA h1("style","l3",10);

    cout << "baseMDA b1: ";
    cout << b1;

    cout << "lacksDMA lb1: ";
    cout << lb1;

    cout << "hasDMA h1: ";
    cout << h1;

    lacksDMA lb2(lb1);
    cout << "调用复制构造函数之后的复制结果:";
    cout << lb2;

    hasDMA h2;
    h2 = h1;
    cout << "调用赋值构造函数之后的赋值结果:";
    cout << h2;

    // 继续构造
    lacksDMA l3("Yellow",b1);
    cout << "lacksDMA l3: ";
    cout << l3;

    hasDMA h3("styleNew",b1);
    cout << "hasDMA h3: ";
    cout << h3;

    return 0;
}
