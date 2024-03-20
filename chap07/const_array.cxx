#include <iostream>
using namespace std;
int fillArray(int *arr, int limit);
void showArray(const int *arr, int n); // read-only
void revalue(int r, int *arr, int n);
int main() {
    const int Size = 10;
    int arr[Size] = {0};                 // 初始化
    int inputNum = fillArray(arr, Size); // 填充
    showArray(arr, Size);                // 显示
    revalue(2, arr, Size);               // 扩大
    showArray(arr, Size);

    return 0;
}
int fillArray(int *arr, int limit) {
    int i;
    for (i = 0; i < limit; i++) {
        cout << "输入值#" << (i + 1) << ":";

        while (!(cin >> arr[i])) {
            // 错误输入
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
            cout << "输入错误请重新输入:" << endl;
        }
    }
    return i;
}
void showArray(const int *arr, int n) {
    // 这意味着不能使用ar修改该数据，也就是说，可以使用像ar[0]这样的值，
    // 但不能修改。注意，这并不是意味着原始数组必须是常量，而只是意味着不
    // 能在show_array( )函数中使用ar来修改这些数据
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}
void revalue(int r, int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *= r;
    }
}