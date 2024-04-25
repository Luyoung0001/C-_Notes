#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

const int LIM = 5;
double arr1[LIM] = {36, 39, 42, 45, 48};
double add(double x, double y) { return x + y; }

int main() {
    std::vector<double> gr8(arr1, arr1 + LIM);
    std::vector<double> m8(arr1, arr1 + LIM);
    std::ostream_iterator<double, char> out(std::cout, " ");

    std::transform(gr8.begin(), gr8.end(), m8.begin(), out, add);
    std::cout << std::endl;

    // 匿名 plus对象
    std::transform(gr8.begin(), gr8.end(), m8.begin(), out, std::plus<double>());

    return 0;
}
