#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

const int LIM = 5;
double arr1[LIM] = {36, 39, 42, 45, 48};

int main() {
    std::vector<double> gr8(arr1, arr1 + LIM);
    std::vector<double> m8(arr1, arr1 + LIM);
    std::ostream_iterator<double, char> out(std::cout, " ");

    // std::transform(gr8.begin(), gr8.end(), m8.begin(), out, std::bind1st(std::multiplies<double>(),2.5));
    std::transform(gr8.begin(), gr8.end(), m8.begin(), out, std::bind(std::multiplies<double>(), std::placeholders::_1, 2.5));
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
