#ifndef HASDMA_H_
#define HASDMA_H_
#include "basedma.h"
#include <ostream>
class hasDMA : public baseDMA {
  private:
    char *style;

  public:
    hasDMA(const char *s = "none", const char *l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA &rs);
    hasDMA(const hasDMA &hs); // 复制构造
    ~hasDMA();

    hasDMA &operator=(const hasDMA &rs);
    friend std::ostream & operator<<(std::ostream &os,const hasDMA & rs);
};
#endif
