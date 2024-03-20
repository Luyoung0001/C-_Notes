#include <iostream>
using namespace std;

int main() {
    // 这将无法通过编译，因为a和a位于相同的作用域内，
    // 它们将发生冲突。为避免这种问题，C++11提供了一种新枚举，其枚举量的作用域为类。
    // enum egg { a, b, c };
    // enum meat { a, b, c };

    // 也可使用关键字struct代替class。无论使用哪种方式，都需要使用枚举名来限定枚举量：
    enum class egg { a = 10, b, c };
    enum class meat { a = 100, b, c };

    egg egg1 = egg::a;
    meat meat1 = meat::a;

    cout << (int)egg1 << endl;
    cout << (int)meat1 << endl;

    return 0;
}