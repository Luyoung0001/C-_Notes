#include <iostream>
using namespace std;
int main() {
    char ch = 0;
    cin >> ch;
    // nihao wodedw# csdcs
    // nihaowodedw%
    // 读取char值时，与读取其他基本类型一样，cin将忽略空格和换行符。
    // 因此输入中的空格没有被回显，也没有被包括在计数内。
    while (ch != '#') {
        cout << ch;
        cin >> ch;
    }
    // 按下回车键后，整个字符序列将被发送给程序，但程序在遇到#字符后将结束对输入的处理。
    return 0;
}