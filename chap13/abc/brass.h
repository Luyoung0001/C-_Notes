#ifndef BRASS_H_
#define BRASS_H_
#include "acctabc.h"
class Brass : public AcctABC {
  public:
    Brass(const std::string &s = "NullBody", long an = -1, double bal = 0.0)
        : AcctABC(s, an, bal) {}
    virtual ~Brass() {}

    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
};
#endif