#ifndef STRING_H_
#define STRING_H_
#include <iostream>
class String {
  private:
    static int string_nums;
    char *str;
    int length;

  public:
    String(const char *str);
    String();
    ~String();
    // 复制构造函数
    String(const String &str);
    // 赋值运算符重载
    String &operator=(const String &str);
    String &operator=(const char *str);

    // []运算符重载
    char &operator[](int i);
    // 友元函数
    friend std::ostream &operator<<(std::ostream &os, String &str);

};
#endif