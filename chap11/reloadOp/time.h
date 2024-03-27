#ifndef TIME_H_
#define TIME_H_
class Time {
    int hour;
    int minute;

  public:
    Time();
    Time(int hour, int minute = 0);
    void AddMin(int min);
    void AddHr(int hr);
    void Reset(int h,int m);
    // Time Sum(const Time &time) const;
    Time operator+(const Time &T)const;
    void show() const;
};
#endif