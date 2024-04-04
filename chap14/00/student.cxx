#include "student.h"
#include <istream>
double Student::Average() const {
    if (scores.size() > 0) {
        return scores.sum()/ scores.size();
    }
    return 0;
}
const std::string &Student::Name() const { return this->name; }

double &Student::operator[](int i) { return scores[i]; }
double Student::operator[](int i) const { return scores[i]; }

// 私有方法定义
std::ostream &Student::arr_out(std::ostream &os) const {
    int lim = scores.size();
    int i;
    if (lim > 0) {
        for (i = 0; i < lim; i++) {
            os << scores[i] << " ";
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
    is >> stu.name;
    return is;
}
std::istream &getline(std::istream &is, Student &stu) {
    getline(is, stu.name);
    return is;
}
std::ostream &operator<<(std::ostream &os, const Student &stu) {
    os << "Scores for " << stu.name << ":\n";
    // 调用私有成员函数
    stu.arr_out(os);
    return os;
}