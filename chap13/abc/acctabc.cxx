#include "acctabc.h"

#include <algorithm>

using std::cout;
using std::string;

AcctABC::AcctABC(const std::string &s, long an, double bal) {
    this->fullName = s;
    this->acctNum = an;
    this->balance = bal;
}
void AcctABC::Withdraw(double amt){
    balance -= amt;
}
void AcctABC::Deposit(double amt) {
    if (amt < 0) {
        cout << "存入的钱不能为负数,群存钱行为取消.\n";

    } else {
        balance += amt;
    }
}
// protected
AcctABC::Formatting AcctABC::SetFormat() const {
    Formatting f;
    f.flags = cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}
void AcctABC::Restore(Formatting &f) const {
    cout.setf(f.flags, std::ios_base::floatfield);
    cout.precision(f.pr);
}