#include "lacksdma.h"

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r) {
    std::strncpy(color, c, 39); // 数组,直接赋值
    color[39] = '\0';
}
lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs) {
    std::strncpy(color, c, 39); // 数组,直接赋值
    color[39] = '\0';
}
lacksDMA::~lacksDMA() {}
std::ostream &operator<<(std::ostream &os, const lacksDMA &ls) {
    os << "Color: " << ls.color << std::endl;
    os << (const baseDMA &)ls;
    // 强制类型转换,因为友元函数不是任何类的成员函数
    // 不会有多态特性,因此不能借助多态省略掉强制转换
    os << std::endl;
    return os;
}