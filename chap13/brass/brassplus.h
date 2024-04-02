#ifndef BRASSPLUS_H_
#define BRASSPLUS_H_
#include "brass.h"
class BrassPlus : public Brass {
    double maxLoan;
    double rate;
    double owesBank;

  public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 0.0, double rate = 0.11125);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
    
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);

    void ResetMax(double m) { this->maxLoan = m; }
    void ResetRate(double r) { this->rate = r; }
    void ResetOwes() { this->owesBank = 0; }
};
#endif