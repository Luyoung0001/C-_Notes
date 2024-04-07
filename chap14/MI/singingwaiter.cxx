#include "singingwaiter.h"
#include <iostream>
using std::cout;

// protected
void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}
void SingingWaiter::Get() {
    Waiter::Get();
    Singer::Get();
}
void SingingWaiter::Set() {
    cout << "请输入 singing waiter 的名字:";
    Worker::Get();
    Get();
}
void SingingWaiter::Show() const {
    cout << "singing Waiter:\n";
    Worker::Data();
    Data();
}
