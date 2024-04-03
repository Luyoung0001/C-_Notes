#include "hasdma.h"


hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &hs)
    : baseDMA(hs) // 调用 base class 的拷贝构造函数
{

    this->style = new char[std::strlen(hs.style) + 1];
    std::strcpy(this->style, hs.style);
}
hasDMA::~hasDMA() { delete [] style;} // 只需要析构多的东西,基类不需要管,它们会自己调用

hasDMA &hasDMA::operator=(const hasDMA &rs) {
    if (this == &rs) {
        return *this;
    }
    baseDMA::operator=(rs);
    delete[] style;
    style = new char[std::strlen(rs.style) + 1];
    std::strcpy(style, rs.style);
    return *this;
}
std::ostream &operator<<(std::ostream &os, const hasDMA &rs) {
    os << (const baseDMA &)rs;
    os << "Style: " << rs.style << std::endl;
    os << std::endl;
    return os;
}