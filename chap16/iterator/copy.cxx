#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    using std::cout;
    int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
    std::vector<int> dice(10);
    std::copy(casts, casts + 10, dice.begin());

    // 打印复制后的vector内容
    cout << "Copied array to vector: ";
    for (int value : dice) {
        cout << value << " ";
    }
    cout << std::endl;

    // 声明迭代器
    std::ostream_iterator<int, char> out_iter(cout, " ");
    *out_iter++ = 15; // 对 out_iter 进行操作，类似于 cout << 15 << " ";

    std::copy(dice.begin(), dice.end(), out_iter);
    cout << std::endl;

    // 使用反向迭代器逆序输出 dice 中的元素
    std::copy(dice.rbegin(), dice.rend(), out_iter);
    cout << std::endl;

    return 0;
}
