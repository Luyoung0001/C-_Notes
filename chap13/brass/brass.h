#ifndef BRASS_H_
#define BRASS_H_
#include <string>
class Brass {
  private:
    std::string fullName;
    long accNum;
    double balance;

  public:
    Brass(const std::string &s = "NullBody", long an = -1, double bal = 0.0);
    void Deposit(double amt);

    // 基类中声明虚方法,这个方法很好,它会根据实际情况调用不同的方法
    virtual void Withdraw(double amt);
    virtual void ViewAcct() const;
    virtual ~Brass();

    double Balance() const;
};
#endif