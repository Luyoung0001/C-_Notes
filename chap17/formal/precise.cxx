// precise.cpp -- setting the precision
#include <ios>
#include <iostream>

int main() {
    using std::cout;
    float price1 = 20.40;
    float price2 = 1.9 + 8.0 / 9.0;

    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    // cout.precision(8) 设置的是输出的总位数，而不是小数点后的位数
    // ios_base::setf(fmtflags __fmtfl)
    // {
    //     fmtflags __r = __fmtflags_;
    //     __fmtflags_ |= __fmtfl;
    //     return __r;
    // }
    cout.setf(std::ios_base::showpoint);
    cout.setf(std::ios_base::showpos);
    cout.precision(6);
    cout << 2.0 << "\n";
    cout << "\"Furry Friends\" is $" << price1 << "!\n";
    cout << "\"Fiery Friends\" is $" << price2 << "!\n";

    return 0;
}
