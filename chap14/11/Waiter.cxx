#include "Waiter.h"
#include "Worker0.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
void Waiter::Set() {
    Worker::Set();
    cout << "输入 waiter 的 panache rating: ";
    cin >> panache;
    while (cin.get() != '\n') {
        continue;
    }
    cin.get();
}
void Waiter::Show() const {
    cout << "Waiter 信息:\n";
    Worker::Show();
    cout << "Waiter 的 panache rating:" << panache << endl;
}