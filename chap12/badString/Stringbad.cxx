#include "Stringbad.h"

int Stringbad::string_nums = 0;
int Stringbad::numsOfStruct = 0;

Stringbad::Stringbad() {
    std::cout << "构造对象:" << this << std::endl;
    numsOfStruct++;
    this->length = 4;
    this->str = new char[4];
    std::strcpy(this->str, "C++");
    string_nums++;
    std::cout << "默认构造:C++\n";
}
Stringbad::Stringbad(const char *s) {
    std::cout << "构造对象:" << this << std::endl;
    numsOfStruct++;
    this->length = std::strlen(s);
    this->str = new char[this->length];
    std::strcpy(this->str, s);
    string_nums++;
    std::cout << "构造:s\n\n";
}
// 析构函数自动调用
// 但是编译器生成的的默认析构函数不能自动释放掉成员指向的堆内存

Stringbad::~Stringbad() {
    std::cout << "析构对象前对象的数目: " << this->string_nums << std::endl;
    delete this->str;
    this->string_nums--;
    std::cout << "析构掉对象:" << this << std::endl; // 打印指针
    std::cout << "析构掉对象.str 中指向的内存地址:"
              << static_cast<void *>(this->str)
              << std::endl; // 这里必须把字符串指针转成指针,不然会打印字符串

    std::cout << "析构对象后对象的数目: " << this->string_nums << std::endl;
    std::cout << "\n";
}

std::ostream &operator<<(std::ostream &os, Stringbad &str) {
    os << "对象以及类的信息:\n";
    std::cout << "对象:" << &str << std::endl;
    std::cout << "对象.str 中指向的内存地址:" << static_cast<void *>(str.str)
              << std::endl;
    os << "length: " << str.length << std::endl;
    os << "string: " << str.str << std::endl;
    os << "类的对象的个数" << str.string_nums << std::endl;
    os << "\n";
    return os;
}