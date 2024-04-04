#include "student1.h"
#include <istream>
using std::string;
double Student::Average() const {
    if (ArrayDb::size() > 0) {
        return ArrayDb::sum() / ArrayDb::size();
    }
    return 0;
}
const std::string &Student::Name() const { return (const string &)*this; }

double &Student::operator[](int i) { return ArrayDb::operator[](i); }
double Student::operator[](int i) const { return ArrayDb::operator[](i); }

// 私有方法定义
std::ostream &Student::arr_out(std::ostream &os) const {
    int lim = ArrayDb::size();
    int i;
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4) {
                os << std::endl;
            }
        }
        if (i % 5 != 0) {
            os << std::endl;
        }
    } else
        os << "空成绩列表.";
    return os;
}

// 友元函数
std::istream &operator>>(std::istream &is, Student &stu) {
    is >> (string &)stu;
    return is;
}
std::istream &getline(std::istream &is, Student &stu) {
    getline(is, (string &)stu);
    return is;
}
std::ostream &operator<<(std::ostream &os, const Student &stu) {
    os << "Scores for " << (const string &)stu << ":\n";
    // 调用私有成员函数
    stu.arr_out(os);
    return os;
}