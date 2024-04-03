#ifndef BRASSPLUS_H_
#define BRASSPLUS_H_

#include "acctabc.h"
#include "brass.h"

class BrassPlus : public AcctABC {
  private:
    double maxLoan;
    double rate;
    double owesBank;

  public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double rate = 0.1);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);

    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);

    void ResetMax(double m) { this->maxLoan = m; }
    void ResetRate(double r) { this->rate = r; }
    void ResetOwes() { this->owesBank = 0; }

    virtual ~BrassPlus(){}

};
#endif
