#include "brassplus.h"
#include "chap13/brass/brass.h"
#include "format.h"
#include <iostream>
using std::cout;
using std::endl;

BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml,
                     double r)
    : Brass(s, an, bal) {
    this->maxLoan = ml;
    this->owesBank = 0.0;
    this->rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : Brass(ba) {
    this->maxLoan = ml;
    this->owesBank = 0.0;
    this->rate = r;
}

void BrassPlus::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcct(); // 基类
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}
void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "信用额度超出,交易终止.\n";
    }
    restore(initialState, prec);
}