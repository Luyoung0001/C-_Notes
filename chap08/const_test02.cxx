#include <iostream>
using namespace std;
int main() {
    // 右值引用
    double &&pt = 35.6;
    int i = 10;
    double &&pt1 = i * 24 + 56.3;
    cout << pt << " " << pt1 << endl;
    return 0;
}