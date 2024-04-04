#ifndef STUDENT_H_
#define STUDENT_H_
#include <istream>
#include <ostream>
#include <string>
#include <valarray>
class Student : std::string, std::valarray<double> {
  private:
    typedef std::valarray<double> ArrayDb;
    std::ostream &arr_out(std::ostream &os) const;

  public:
    Student() : std::string("Null Student"), ArrayDb() {} // has-a 构造函数

    // 显示转换函数
    explicit Student(const std::string &s)
        : std::string(s), ArrayDb() {} // has-a 转换函数
    explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}

    Student(const std::string &s, int n) : std::string(s), ArrayDb(n) {}
    Student(const std::string &s, const ArrayDb &a)
        : std::string(s), ArrayDb(a) {}
    Student(const char *str, const double *pd, int n)
        : std::string(str), ArrayDb(pd, n) {}

    ~Student(){};
    double Average() const;
    const std::string &Name() const;
    double &operator[](int i);      // 重载[]运算符,左值可以改
    double operator[](int i) const; // 左值不可改

    // 友元函数
    friend std::istream &operator>>(std::istream &is, Student &stu);
    friend std::istream &getline(std::istream &is, Student &stu);
    friend std::ostream &operator<<(std::ostream &os, const Student &stu);
};

#endif
