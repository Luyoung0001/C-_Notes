#ifndef TIME_H_
#define TIME_H_
#include <iostream>
class Time {
    int hour;
    int minute;

  public:
    Time();
    Time(int hour, int minute = 0);
    void AddMin(int min);
    void AddHr(int hr);
    void Reset(int h, int m);
    Time Sum(const Time &time) const;
    void show() const;
    // 重载 << 运算符,友元函数
    friend std::ostream &operator<<(std::ostream &os, const Time &time);
};
#endif