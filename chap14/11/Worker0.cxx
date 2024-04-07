#include "Worker0.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

Worker::~Worker() {}

void Worker::Set() {
    cout << "输入工人的名字:";
    getline(cin, fullname);
    cout << "输入工人的ID:";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
    cin.get(); // 刷掉换行符
}
void Worker::Show() const {
    cout << "名字:" << fullname << endl;
    cout << "ID:" << id << endl;
}