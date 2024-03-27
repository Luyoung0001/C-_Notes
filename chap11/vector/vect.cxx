#include "vect.h"
#include <cmath>
using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR {

// 计算一弧度包含的角度
const double Rad2Deg = 45 / atan(1);

// 私有方法
void Vector::set_mag() { this->mag = sqrt(x * x + y * y); }
void Vector::set_ang() {
    if (this->x == 0.0 && this->y == 0)
        this->ang = 0.0;
    else
        this->ang = atan2(this->y, this->x);
}

void Vector::set_x() { this->x = this->mag * cos(this->ang); }
void Vector::set_y() { this->y = this->mag * sin(this->ang); }
Vector::Vector() {
    this->ang = 0;
    this->mag = 0;
    this->x = 0;
    this->y = 0;
    this->mode = RECT;
}
Vector::Vector(double n1, double n2, Mode form) {
    this->mode = form;
    if (this->mode == RECT) {
        this->x = n1;
        this->y = n2;
        set_mag();
        set_ang();
    } else if (this->mode == POL) {
        this->mag = n1;
        this->ang = n2;
        set_x();
        set_y();
    } else {
        // 输入错误
        cout << "输入错误,所有的值将会被重置.\n";
        this->ang = 0;
        this->mag = 0;
        this->x = 0;
        this->y = 0;
        this->mode = RECT;
    }
}

void Vector::reset(double n1, double n2, Mode form) {
    this->mode = form;
    if (this->mode == RECT) {
        this->x = n1;
        this->y = n2;
        set_mag();
        set_ang();
    } else if (this->mode == POL) {
        this->mag = n1;
        this->ang = n2;
        set_x();
        set_y();
    } else {
        // 输入错误
        cout << "输入错误,所有的值将会被重置.\n";
        this->ang = 0;
        this->mag = 0;
        this->x = 0;
        this->y = 0;
        this->mode = RECT;
    }
}

void Vector::polar_mode() { this->mode = POL; }
void Vector::rect_mode() { this->mode = RECT; }

// 要更新其它变量
Vector Vector::operator+(const Vector &vect) const {
    return Vector(this->x + vect.x, this->y + vect.y);
}
Vector Vector::operator-(const Vector &vect) const {
    return Vector(this->x - vect.x, this->y - vect.y);
}
// 取反
Vector Vector::operator-() const { return Vector(0 - this->x, 0 - this->y); }
Vector Vector::operator*(double n) const {
    return Vector(n * this->x, n * this->y);
}

// 友元函数
Vector operator*(double n, const Vector &vect) { return vect * n; }
std::ostream &operator<<(std::ostream &os, const Vector &vect) {
    os << "x: " << vect.x << std::endl;
    os << "y: " << vect.y << std::endl;
    os << "angle: " << vect.ang << std::endl;
    os << "magnitude: " << vect.mag << std::endl;

    return os;
}

} // namespace VECTOR