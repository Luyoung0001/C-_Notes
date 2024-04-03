#ifndef LACKSDMA_H_
#define LACKSDMA_H_

#include "basedma.h"
class lacksDMA : public baseDMA {
  private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];

  public:
    lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);
    ~lacksDMA();
    friend std::ostream &operator<<(std::ostream &os, const lacksDMA &rs);
};
#endif