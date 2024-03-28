#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt {
  private:
    static const int Lbs_per_stn = 14; // pounds per stone
    int stone;
    double pds_left;
    double pounds;

  public:
    // 使用 explicit 表明只能通过显式转换数据类型
    // 将Stonewt对象初始化为double值时;
    // 将double值赋给Stonewt对象时;
    // 将double值传递给接受Stonewt参数的函数时;
    // 返回值被声明为Stonewt的函数试图返回double值时.
    explicit Stonewt(double lbs);
    explicit Stonewt(int stn, double lbs = 0);

    // 将对象转化为 double,int 类型的转化方法声明
    // C++11 标准
    explicit operator double() const;
    explicit operator int() const;

    Stonewt();
    ~Stonewt();

    void show_lbs() const;
    void show_stn() const;
};
#endif