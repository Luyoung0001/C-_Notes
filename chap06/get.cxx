#include <iostream>
using namespace std;
const int Max = 5;
int main() {
    int golf[Max];
    for (int i = 0; i < Max; i++) {
        cout << "round #" << i + 1 << ": ";
        while (!(cin >> golf[i])) { // 当输入非法字符时
            // cin.clear()
            // 函数的作用是清除输入流的错误状态，它不会直接清除输入缓冲区中的数据。换句话说，cin.clear()
            // 不会清除输入缓冲区中的字符，而是重置输入流的错误状态，使得输入流可以继续接受新的输入。
            cin.clear();

            // 进入内层 while 循环,使用 cin.get()
            // 来逐个读取输入缓冲区中的字符,直到遇到换行符'\n'为止
            // 将缓冲区的字符全部刷掉
            while (cin.get() != '\n') {
                continue;
            }
            cout << "请输入一个数字:";
        }
    }
    double total = 0.0;
    for (int i = 0; i < Max; i++) {
        total += golf[i];
    }
    cout << total / Max << " = average score " << Max << " rounds\n";
    return 0;
}