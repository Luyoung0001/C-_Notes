#include <iostream>
using namespace std;
int main() {
    int a;
    a = 10, 40; // 在所有运算符中，逗号运算符的优先级是最低的
    cout << a << endl;
    a = (10, 40); // C++规定，逗号表达式的值是第二部分的值
    cout << a << endl;
    return 0;
}