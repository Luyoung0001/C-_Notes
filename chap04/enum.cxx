#include <iostream>
int main(){
    enum spectrum{a,b,c,d,e,f,g};
    spectrum band = b;
    std::cout << band << std::endl;

    // 强制转型
    spectrum band1 = (spectrum)3;
    std::cout << band1 << std::endl;

    // 枚举可以被提升到 int
    int band2 = a+1;

    // spectrum band3 = 3; 这是错误的,因为int不能被提升到枚举

    // 当然,可以强转
    spectrum band4 = (spectrum)5;

    // 更灵活
    spectrum band5 = spectrum(a+3); // 这里的逻辑是,a 被转成 int,之后和 3 相加,然后被转成枚举

    // 枚举自定义以及范围

    enum bits{a = 2,b,c = 10,d};
    bits band6 = bits(6); // 合法,在其范围中

    return 0;
}