#include <array>
#include <iostream>
using namespace std;
int main(){
    array<int, 5> ai;
    array<double, 4> ad = {1.2,2.1,3.43,4.3}; // 这里的 n 只能是常量,因为其不可变
    ad[3] = 4.0;
    ad[-1] = 10.0;
    //ad.at(-2) = 10; libc++abi: terminating with uncaught exception of type std::out_of_range: array::at
    //                  zsh: abort      ./main. 这会检查下标的合法性,而上面的写法不检查,语法允许的.
    cout << ad[-1] << endl;
    cout << ad[3] << endl;
    // 如果输出的double值是整数或者是小数点后面都是0的浮点数，
    // 输出时会省略小数点和末尾的0，直接显示整数形式。
    // 这种行为是为了减少输出的冗余信息，提高可读性。

    return 0;
}