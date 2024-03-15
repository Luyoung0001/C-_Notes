#include <iostream>
#include <climits>
using namespace std;
int main() {
    long long a = 0;
    int b = sizeof(b);
    int a1 = INT_MAX;

    // c++ 初始化特有的方法
    int b1(5);
     // int c1{7}; 已经失效
    int c = {6};

    cout << b << endl; // 4 Byte

    cout << a1 << endl;

    cout << b1 << endl;

    cout << c <<endl;

    // cout << c1 <<endl;

    return 0;
}