#include <iostream>
#include <iterator>
#include <vector>

int main() {
    using namespace std;

    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    vector<int> dice(10);

    // 从数组复制到向量
    copy(casts, casts + 10, dice.begin());
    cout << "Let the dice be cast!\n";

    // 创建一个 ostream 迭代器
    ostream_iterator<int, char> out_iter(cout, " ");

    // 从 vector 复制到输出
    copy(dice.begin(), dice.end(), out_iter);
    cout << endl;

    // 隐式使用反向迭代器
    cout << "Implicit use of reverse iterator.\n";
    copy(dice.rbegin(), dice.rend(), out_iter);
    cout << endl;

    // 显式使用反向迭代器
    cout << "Explicit use of reverse iterator.\n";
    vector<int>::reverse_iterator ri;
    for (ri = dice.rbegin(); ri != dice.rend(); ++ri) {
        cout << *ri << ' ';
    }
    cout << endl;

    return 0;
}
