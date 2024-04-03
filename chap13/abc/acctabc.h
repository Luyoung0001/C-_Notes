#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <ios>
#include <iostream>
#include <string>

class AcctABC {
  private:
    std::string fullName;
    long acctNum;
    double balance;

  protected:
    struct Formatting {
        std::ios_base::fmtflags flags;
        std::streamsize pr;
    };

    const std::string &FullName() const { return fullName; }
    long AcctNum() const { return this->acctNum; }

    Formatting SetFormat() const;
    void Restore(Formatting &f) const;

  public:
    AcctABC(const std::string &s = "NullBody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual ~AcctABC() {}
    double Balance() const { return balance; }

    // 设置纯虚函数,使得其成为 abc
    virtual void Withdraw(double amt) = 0;
    virtual void ViewAcct() const = 0;
};
#endif