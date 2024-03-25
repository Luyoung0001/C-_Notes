#include "namesp.h"
#include <iostream>

// 定义命名空间中的原型
namespace pers {
using std::cin;
using std::cout;
using std::endl;
void getPerson(Person &rp) {
    cout << "请输入名:";
    cin >> rp.fname;

    cout << "请输入姓:";
    cin >> rp.lname;
}
void showPerson(const Person &rp) {
    cout << "姓名:" << rp.fname << ',' << rp.lname << endl;
}
} // namespace pers

namespace debts {
// pers 中已经加入了部分 std::cin, cout, endl, 因此这里不需要再加了

void getDebt(Debt &rd) {
    getPerson(rd.name);
    cout << "请输入负债:";
    cin >> rd.mount;
}
void showDebt(const Debt &rd) {
    showPerson(rd.name);
    cout << "debt:" << rd.mount << '$' << endl;
}
double sumDebts(const Debt arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i].mount;
    }
    return total;
}
} // namespace debts
