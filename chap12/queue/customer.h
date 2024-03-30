#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <cstdlib>
class Customer {
  private:
    long arrive;
    int processtime;

  public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};
#endif