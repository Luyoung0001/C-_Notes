#include "vect.h"
#include <iostream>

int main() {
    using namespace VECTOR;
    Vector v1(2, 2, Vector::RECT);
    Vector v2(2, 2, Vector::RECT);
    Vector v3 = v1 + v2;
    std::cout << v3;

    v2 = v3-v1-v2;
    std::cout << v2;

    std::cout << v1.ang_val() << std::endl;
    std::cout << v1.mag_val() << std::endl;
    std::cout << v1.x_val() << std::endl;
    std::cout << v1.y_val() << std::endl;

    // 取反
    v1 = -v1;
    std::cout << v1.ang_val() << std::endl;
    std::cout << v1.mag_val() << std::endl;
    std::cout << v1.x_val() << std::endl;
    std::cout << v1.y_val() << std::endl;


    return 0;
}