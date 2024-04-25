#include <initializer_list>
#include <iostream>

double sum(std::initializer_list<double> il);             // 按值传递
double average(const std::initializer_list<double> &ril); // 按照引用传递

int main() {
    using std::cout;

    cout << "List 1: sum = " << sum({2, 3, 4})
         << ", ave = " << average({2, 3, 4}) << '\n';
    std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << "List 2: sum = " << sum(dl) << ", ave = " << average(dl) << '\n';
    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    cout << "List 3: sum = " << sum(dl) << ", ave = " << average(dl) << '\n';
    return 0;
}

double sum(std::initializer_list<double> il) {
    double tot = 0;
    for (auto p = il.begin(); p != il.end(); p++)
        tot += *p;
    return tot;
}
// initializer_list的迭代器类型为const，因此您不能修改initializer_list中的值

double average(const std::initializer_list<double> &ril) {
    double tot = 0;
    int n = ril.size();
    double ave = 0.0;
    if (n > 0) {
        for (auto p = ril.begin(); p != ril.end(); p++)
            tot += *p;
        ave = tot / n;
    }
    return ave;
}
// 然而，提供initializer_list类的初衷旨在让您能够将一系列值传递给构造函数或其他函数。
