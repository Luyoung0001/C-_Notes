#include "waitermi.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
void Waiter::Set() {
    cout << "输入 waiter 的名字:\n";
    Worker::Get();
    Get();
}
void Waiter::Show() const {
    cout << "Waiter 信息:\n";
    Worker::Data();
    Data();
}
// protected
void Waiter::Data() const { cout << "rating:" << panache << endl; }
void Waiter::Get() {
    cout << "请输入 rating :";
    cin >> panache;
    while (cin.get() != '\n') {
        continue;
    }
}