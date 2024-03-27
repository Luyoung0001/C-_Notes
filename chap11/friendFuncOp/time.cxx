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

Time Time::operator+(const Time &time) const {
    Time rtime;
    rtime.hour = this->hour + time.hour + (this->minute + time.minute) / 60;
    rtime.minute = (this->minute + time.minute) % 60;
    return rtime;
}

Time Time::operator*(double times) const {
    Time rtime;
    double totalMin = (this->hour * 60 + this->minute) * times;

    rtime.hour = int(totalMin) / 60;
    rtime.minute = int(totalMin) % 60;
    return rtime;
}

// 以下实现看起来非常像友元函数,
// 事实上,如果从外面看,这就是一个友元函数
// 但实际上,它的实现方法并没有访问到类私有变量
// Time operator*(double times, const Time &t) {
//     Time rtime;
//     rtime = t * times; // 利用运算符重载,有效
//     return rtime;
// }

// 定义一个真正的友元函数
// 如果以后发现需要函数直接访问私有数据，则只要修改函数定义即可，而不必修改类原型
Time operator*(double times, const Time &t) {
    Time rtime;
    double totalMin = (t.hour * 60 + t.minute) * times;

    rtime.hour = int(totalMin) / 60;
    rtime.minute = int(totalMin) % 60;
    return rtime;
}

void Time::show() const {
    std::cout << "Hour: " << this->hour << std::endl;
    std::cout << "Minute: " << this->minute << std::endl;
}