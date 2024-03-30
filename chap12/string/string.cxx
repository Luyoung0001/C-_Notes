#include "string.h"

int String::string_nums = 0;

String::String() {

    this->length = 0;
    this->str = new char[1];
    this->str[0] = '\0';
    string_nums++;
}
String::String(const char *s) {

    this->length = std::strlen(s);
    this->str = new char[this->length];
    std::strcpy(this->str, s);
    string_nums++;
}

String::~String() {
    delete this->str;
    this->string_nums--;
}

// 复制构造函数的显式定义
String::String(const String &str) {

    string_nums++;

    this->length = str.length;
    this->str = new char[this->length + 1];
    std::strcpy(this->str, str.str);

    std::cout << "复制构造函数调用\n\n";
}
// 赋值运算符重载
String &String::operator=(const String &str) {

    if (this == &str) {
        return *this;
    }
    delete[] this->str;
    this->length = str.length;
    this->str = new char[this->length + 1];
    std::strcpy(this->str, str.str);
    return *this;
}

// 如果将一个常规的 std::string 对象赋值给自定义的 string,最好重载赋值运算符
String &String::operator=(const char *str) {
    delete this->str;
    this->length = std::strlen(str);
    this->str = new char[this->length + 1];

    std::strcpy(this->str, str);
    return *this;
}


char &String::operator[](int i) {
    // 将返回类型声明为char &，便可以给特定元素赋值
    return this->str[i];
}

std::ostream &operator<<(std::ostream &os, String &str) {
    os << "string: " << str.str << std::endl;
    return os;
}