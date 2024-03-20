#include <iostream>
using namespace std;
int sum_arr(int arr[], int n);
int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "数量:" << sum_arr(arr1, 10) << endl;

    // 传递常规变量时，函数将使用该变量的拷贝；但传递数组时，函数将使用原来的数组
    // 这种区别并不违反C++按值传递的方法，sum_arr( )函数仍传递了一个值，这个值被
    // 赋给一个新变量，但这个值是一个地址，而不是数组的内容。
    cout << arr1[2] << endl;

    return 0;
}
int sum_arr(int arr[], int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i];
    }
    // 做一点改变
    arr[2] = 2222;
    return ans;
}