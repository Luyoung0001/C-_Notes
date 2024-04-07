#ifndef SINGERMI_H_
#define SINGERMI_H_

#include "workermi.h"
class Singer : virtual public Worker {
  protected:
    enum { other, alto, contralto, soprano, bass, baritone, tenor };
    enum { Vtypes = 7 };
    void Data() const;
    void Get();

  private:
    static std::string pv[Vtypes];
    int voice;

  public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string &s, long n, int v) : Worker(s, n), voice(v) {}
    Singer(const Worker &wk, int v = other) : Worker(wk), voice(other) {}
    void Set();
    void Show() const;
};

#endif
