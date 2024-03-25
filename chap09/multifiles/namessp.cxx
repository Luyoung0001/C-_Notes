#include "namesp.h"
#include <iostream>
void other(void);
void another(void);

int main() {
    using debts::Debt;
    using debts::showDebt; // 如果函数被重载，则一个using声明将导入所有的版本

    Debt golf = {{"Benney", "Goatsniff"}, 120.0};
    showDebt(golf);
    other();
    another();
    return 0;
}
void other(void) {
    using namespace debts;
    using std::cin;
    using std::cout;
    using std::endl;

    // 并没有明确指出 sp2 中是否包含了 using std::cout;
    // 或类似的声明，如果没有这样的声明，sp2 是无法直接使用 cout 的。

    Person dg = {"Doodles", "Gloster"};
    showPerson(dg);
    cout << endl;

    Debt zippy[3];
    for (int i = 0; i < 3; i++) {
        getDebt(zippy[i]);
    }
    for (int i = 0; i < 3; i++) {
        showDebt(zippy[i]);
    }

    cout << "总共的负债为: " << sumDebts(zippy, 3) << '$' << endl;
    return;
}

void another(void) {
    using pers::Person;

    Person collector = {"Milo", "Rightshift"};
    pers::showPerson(collector);
    std::cout << std::endl;
    return;
}