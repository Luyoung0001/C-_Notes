#include <iostream>
using namespace std;
int main() {
    // string类重载运算符!=的方式让您能够在下述条件下使用它：
    // 至少有一个操作数为string对象，
    // 另一个操作数可以是string对象，也可以是C-风格字符串。
    string a = "hello";
    string b = "hello";
    if (a == "hello") {
        cout << "==" << endl;
    }
    if (a == b) {
        cout << "==" << endl;
    }
    return 0;
}