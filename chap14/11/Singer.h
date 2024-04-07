#ifndef SINGER_H_
#define SINGER_H_

#include "Worker0.h"
class Singer : virtual public Worker {
  protected:
    enum { other, alto, contralto, soprano, bass, baritone, tenor };
    enum { Vtypes = 7 };

  private:
    static std::string pv[Vtypes];
    int voice;

  public:
    Singer() : Worker(),voice(other){}
    Singer(const std::string &s,long n,int v):Worker(s,n),voice(v){}
    Singer(const Worker &wk,int v = other):Worker(wk),voice(other){}
    void Set();
    void Show() const;
};

#endif
