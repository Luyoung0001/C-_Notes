#include "workermi.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

Worker::~Worker() {}

// protected
void Worker::Data() const {
    cout << "Name: " << fullname << endl;
    cout << "ID" << id << endl;
}

void Worker::Get(){
    cout << "输入工人的名字:";
    getline(cin, fullname);
    cout << "输入工人的ID:";
    cin >> id;
    while (cin.get() != '\n') {
        continue;
    }
}