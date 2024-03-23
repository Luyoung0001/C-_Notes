#include "coordin.h"
#include <cmath>
#include <iostream>
using namespace std;

polar rect_to_polar(const rect &xyplace) {
    polar answer;
    answer.distance = sqrt(xyplace.x * xyplace.x + xyplace.y * xyplace.y);
    answer.angle = atan2(xyplace.y, xyplace.x);
    return answer;
    // 它会返回 answer 的副本给调用者。
    // 这意味着调用 rect_to_polar 函数时，会创建一个新的 polar 对象，
    // 并将其值初始化为 answer 的值，然后返回给调用者。
}
void show_polar(const polar &p) {
    const double Rad_to_deg = 57.29577;

    cout << "distance: " << p.distance;
    cout << "\nangle: " << p.angle * Rad_to_deg;
    cout << "degrees\n";
}