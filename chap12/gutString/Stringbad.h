#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>
class Stringbad {
  private:
    static int string_nums;
    char *str;
    int length;

  public:
    static int numsOfStruct;
    Stringbad(const char *str);
    Stringbad();
    ~Stringbad();
    // 复制构造函数
    Stringbad(const Stringbad &str);

    // 赋值运算符重载
    Stringbad &operator=(const Stringbad &str);
    // 友元函数
    friend std::ostream &operator<<(std::ostream &os, Stringbad &str);
};
#endif