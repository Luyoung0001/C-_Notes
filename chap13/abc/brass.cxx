#include "brass.h"
#include <iostream>

using std::cout;
using std::endl;

void Brass::Withdraw(double amt) {
    if (amt < 0) {
        cout << "取得的钱不能为负数,存钱行为取消.\n";
    } else if (amt <= Balance()) {
        AcctABC::Withdraw(amt);
    } else {
        cout << "你要取的钱为:" << amt << ".大于你的余额,取钱行为取消.\n";
    }
}
void Brass::ViewAcct() const {
    Formatting f = AcctABC::SetFormat();

    cout << "Client: " << this->FullName() << endl;
    cout << "Account Number: " << this->AcctNum() << endl;
    cout << "Balance: $" << this->Balance() << endl;

    AcctABC::Restore(f);
}