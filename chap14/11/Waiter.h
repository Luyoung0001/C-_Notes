#ifndef WAITER_H_
#define WAITER_H_
#include "Worker0.h"
class Waiter : public Worker {
  private:
    int panache;

  public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string &s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

#endif
