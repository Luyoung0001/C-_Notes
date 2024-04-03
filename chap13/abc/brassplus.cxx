#include "brassplus.h"


using std::cout;
using std::endl;

BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml,
                     double r)
    : AcctABC(s, an, bal), maxLoan(ml), rate(r), owesBank(0.0) {}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
    : AcctABC(ba), maxLoan(ml), rate(r), owesBank(0.0) {} // 使用默认构造函数

void BrassPlus::ViewAcct() const {

    // 访问abc
    Formatting f = AcctABC::SetFormat();
    cout << "BrassPlus Client: " << this->FullName() << endl;
    cout << "Account Number: " << this->AcctNum() << endl;
    cout << "Balance: $" << this->Balance() << endl;

    // 访问自身变量
    cout << "Maximum loan: $" << this->maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";

    // 访问ABC
    AcctABC::Restore(f);
}

void BrassPlus::Withdraw(double amt) {
    Formatting f = AcctABC::SetFormat();
    double bal = AcctABC::Balance();
    if (amt <= bal) {
        AcctABC::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    } else {
        cout << "信用额度超出,交易终止.\n";
    }
    AcctABC::Restore(f);
}