#ifndef WAITERMI_H_
#define WAITERMI_H_
#include "workermi.h"
class Waiter : virtual public Worker {
  private:
    int panache;
  protected:
    void Data() const;
    void Get();

  public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string &s, long n, int p = 0)
        : Worker(s, n), panache(p) {}
    Waiter(const Worker &wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

#endif
