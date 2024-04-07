#include "singingwaiter.h"
#include <cstring>
#include <iostream>

const int SIZE = 5;
int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker *lolas[SIZE];
    int ct = 0;
    for (ct = 0; ct < SIZE; ct++) {
        char choice;
        cout << "请输入选项:\n";
        cout << "w: waiter s: singer "
             << "t: singing waiter q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL) {
            cout << "请输入 w,s,t,p:";
            cin >> choice;
        }
        if (choice == 'q') {
            break;
        }
        switch (choice) {
        case 'w':
            lolas[ct] = new Waiter;
            break;
        case 's':
            lolas[ct] = new Singer;
            break;
        case 't':
            lolas[ct] = new SingingWaiter;
            break;
        }
        cin.get();
        lolas[ct]->Set(); // 多态
    }
    int i;
    cout << "\n这里是记录的信息:\n";
    for (int i = 0; i < ct; i++) {
        cout << endl;
        lolas[i]->Show();
    }
    // free
    for (int i = 0; i < ct; i++) {
        delete lolas[i];
    }
    cout << "Done!\n";

    return 0;
}
