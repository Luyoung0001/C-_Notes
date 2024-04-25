#include <algorithm>
#include <array>
#include <iostream>
#include <valarray>
#include <vector>
int main() {
    using namespace std;
    vector<double> ved1(10, 1.0), ved2(10, 2.0), ved3(10, 3.0);
    array<double, 10> vod1({1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0});
    array<double, 10> vod2{};
    array<double, 10> vod3{5.0};
    valarray<double> vad1(1.0, 10), vad2(2.0, 10), vad3(3.0, 10);

    transform(vod1.begin(), vod1.end(), vod2.begin(), vod3.begin(),
              plus<double>());

    vad3 = vad1 + vad2; // overloaded
    vad1 = vad1 * 4;    // overloaded
    vad1 = 4 * vad1;

    vad3 = log(vad1); // overloaded

    return 0;
}