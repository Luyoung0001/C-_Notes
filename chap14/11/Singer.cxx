#include "Singer.h"
#include "Worker0.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

std::string Singer::pv[] = {"other", "alto",     "contralto", "soprano",
                            "bass",  "baritone", "tenor"};

void Singer::Set() {
    Worker::Set();
    cout << "请输入歌手的嗓音范围:\n";
    int i;
    for (i = 0; i < Vtypes; i++) {
        cout << i << ": " << pv[i] << " ";
        if (i % 4 == 0) {
            cout << endl;
        }
    }
    if (i % 4 != 0) {
        cout << endl;
    }
    while (cin >> voice && (voice < 0 || voice >= Vtypes)) {
        cout << "范围错误,请重新输入:";
    }
    while (cin.get() != '\n') {
        continue;
    }
    cin.get();
}

void Singer::Show() const {
    cout << "Singer: \n";
    Worker::Show();
    cout << "Vocal ranger:" << pv[voice] << endl;
}