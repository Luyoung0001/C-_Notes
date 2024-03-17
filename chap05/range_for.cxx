#include <iostream>
using namespace std;
int main() {
    double nums[5] = {1.2, 1.3, 1.4, 1.5, 1.6};
    // C++11新增了一种循环：基于范围（range-based）的for循环
    for (double elem : nums) {
        cout << elem << endl;
    }
    // 如果要修改这些值,可以使用引用
    for (double &x : nums) {
        x -= 1;
    }
    // 修改后输出
    for (double elem : nums) {
        cout << elem << endl;
    }
    return 0;
}