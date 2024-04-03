#ifndef DMA_H_
#define DMA_H_
#include <ostream>
class baseDMA {
  private:
    char *label;
    int rating;

  public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA &rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA &rs);
    // 友元函数
    friend std::ostream & operator<<(std::ostream &os,const baseDMA &rs);
};
#endif