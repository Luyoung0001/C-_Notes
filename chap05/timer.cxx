#include <ctime>
#include <iostream>
using namespace std;
int main() {
    cout << "输入要延迟的时间:" << endl;
    float time;
    cin >> time;
    clock_t delay = time * CLOCKS_PER_SEC;

    cout << "开始计时:" << endl;
    clock_t start = clock();
    while (clock() - start < delay)
        ;

    cout << "计时结束!" << endl;

    return 0;
}