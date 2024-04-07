#ifndef SINGINGWAITER_H_
#define SINGINGWAITER_H_
#include "singermi.h"
#include "waitermi.h"
class SingingWaiter : public Singer, public Waiter {
  protected:
    void Data() const;
    void Get();

  public:
    SingingWaiter() {}
    SingingWaiter(const std::string &s, long n, int p = 0, int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker &wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter &wk, int v = other)
        : Worker(wk), Waiter(wk), Singer(wk, v) {}
    SingingWaiter(const Singer &wk, int p = 0)
        : Worker(wk), Waiter(wk, p), Singer(wk) {}
    void Set();
    void Show() const;
};

#endif