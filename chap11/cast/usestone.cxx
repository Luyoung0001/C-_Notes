#include "stonewt.h"


int main() {
    Stonewt s1;
    s1 = (Stonewt)30.5; // use construter: Stonewt(double lbs)
    s1.show_lbs();
    s1.show_stn();

    Stonewt s2;
    s2 = (Stonewt)30; // use construter: Stonewt(int stn, double lbs)
    s2.show_lbs();
    s2.show_stn();

    Stonewt s3(30);

    // 将 int,double类型通过转化方法,转为对象
    double d1 = (double)s1;
    int i1 = (int)s2;

    std::cout << d1 << std::endl;
    std::cout << i1 << std::endl;

    return 0;
}