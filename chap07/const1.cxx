#include <iostream>
using namespace std;
int main() {
    int sloth = 3;
    const int *ps = &sloth; // can not change value like *ps = 10
    // *ps = 20;               // 不合法
    int *const finger =
        &sloth; // finger always points to sloth, ban:fing = &va1;
    int ok = 10;
    // finger = &ok; // 不合法
    *finger = 30; // 合法

    // 通常，将指针作为函数参数来传递时，可以使用指向const的指针来保护数据

    return 0;
}