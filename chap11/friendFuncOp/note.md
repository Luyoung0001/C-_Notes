## 运算符重载
- 1.成员函数
- 2.非成员函数
- - (1)全局方法,通过类内部的公有方法访问私有变量
- - (2)友元函数


## 例子

成员函数:
```C++
Time Time::operator+(const Time &time) const {
    Time rtime;
    rtime.hour = this->hour + time.hour + (this->minute + time.minute) / 60;
    rtime.minute = (this->minute + time.minute) % 60;
    return rtime;
}
```

友元函数:
```C++
// 定义一个真正的友元函数
// 如果以后发现需要函数直接访问私有数据，则只要修改函数定义即可，而不必修改类原型
Time operator*(double times, const Time &t) {
    Time rtime;
    double totalMin = (t.hour * 60 + t.minute) * times;

    rtime.hour = int(totalMin) / 60;
    rtime.minute = int(totalMin) % 60;
    return rtime;
}
```

全局函数重载:
```C++
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // 不使用友元函数，也不是类的成员函数，而是全局函数重载加法运算符
};

// 全局函数定义，重载加法运算符
Complex operator+(const Complex& a, const Complex& b) {
    // 通过类的 public 方法,访问私有变量
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.0, 4.0);

    Complex result = c1 + c2; // 使用重载的加法运算符
    std::cout << "Result: " << result.real << " + " << result.imag << "i" << std::endl;

    return 0;
}

```