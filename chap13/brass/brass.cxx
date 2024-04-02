#include "brass.h"
#include "format.h"
#include <algorithm>
#include <ios>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 类的定义
Brass::Brass(const string &s, long an, double bal) {
    this->fullName = s;
    this->accNum = an;
    this->balance = bal;
}

void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "存入的钱不能为负数,群存钱行为取消.\n";

    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    // 设置格式
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) {
        cout << "取得的钱不能为负数,存钱行为取消.\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "你要取的钱为:" << amt << ".大于你的余额,取钱行为取消.\n";
    }
    restore(initialState, prec);
}
double Brass::Balance() const { return balance; }

void Brass::ViewAcct() const {
    // 格式输出
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << accNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec); // 保存原来的格式
}