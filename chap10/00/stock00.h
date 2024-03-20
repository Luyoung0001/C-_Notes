#ifndef STOCK00_H_
#define STOCK00_H_
#include <string>
class Stock {
  private: // 默认private
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = shares * share_val;
    } // 自动成为内联函数,这将拥有内联函数的特性

  public:
    const Stock& topval(const Stock &s) const;
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    // void update(double newPrice);
    void show()const;
    Stock(const std::string &c0,long n, double pr);
    Stock();
    ~Stock();
};
#endif