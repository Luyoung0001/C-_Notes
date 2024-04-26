#include <exception>
#include <iostream>

int main() {
    using namespace std;

    // 设置允许抛出异常的状态位为 failbit
    cin.exceptions(ios_base::failbit);

    int num;
    try {
        cout << "Enter a number: ";
        cin >> num;
        // 如果输入的不是整数，会触发异常
    } catch (const ios_base::failure &e) {
        // 捕获异常
        cout << "Caught an ios_base::failure exception: " << e.what() << endl;
    }

    cout << "Last value entered = " << num << endl;

    return 0;
}
