#include "ratedplayer.h"
#include <iostream>
int main() {
    using std::cout;
    TableTennisPlayer player1("Chunk", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    RatedPlayer r1(2, player1);
    RatedPlayer r2(5, player2);
    RatedPlayer r3(5, "Pgins", "Helos", true);

    // 使用默认参数,这里不会生成默认构造函数,不然就会
    // 使得下面的构造函数调用产生歧义,因为编译器不知道调用哪一个
    // 构造函数
    RatedPlayer r4;
    r1.Name();

    if (r1.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }

    r2.Name();
    if (player2.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }
    r3.Name();
    if (r3.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }
    r4.Name();
    if (r4.HasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": have not a table.\n";
    }

    return 0;
}