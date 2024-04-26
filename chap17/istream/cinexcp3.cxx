#include <cctype>
#include <iostream>

int main() {
    using namespace std;

    cout << "Enter numbers: ";
    int sum = 0;
    int input;

    while (cin >> input) {
        sum += input;
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;
    cout << "Now enter a new number: ";

    cin.clear();
    // 导致输入循环终止的不匹配输入仍留在输入队列中，程序必须跳过它
    while (cin.get() != '\n')
        continue;
    cin >> input; 

    return 0;
}
