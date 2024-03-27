#include "time.h"
#include <iostream>
Time::Time() {
    this->hour = 0;
    this->minute = 0;
}
Time::Time(int hour, int minute) {
    this->hour = hour;
    this->minute = minute;
}
void Time::AddMin(int min) {
    this->minute += min;
    hour += this->minute / 60;
    this->minute %= 60;
}
void Time::AddHr(int hr) { this->hour += hr; }
void Time::Reset(int h, int m) {
    this->hour = h;
    this->minute = m;
}
Time Time::Sum(const Time &time) const {
    // 有返回值
    Time rtime;
    rtime.hour = this->hour + time.hour + (this->minute + time.minute) / 60;
    rtime.minute = (this->minute + time.minute) % 60;
    return rtime;
}

// 友元函数重载 <<
std::ostream &operator<<(std::ostream &os, const Time &time) {
    os << "Hour:" << time.hour << "; Minute: " << time.minute;
    return os;
}
void Time::show() const {
    std::cout << "Hour: " << this->hour << std::endl;
    std::cout << "Minute: " << this->minute << std::endl;
}