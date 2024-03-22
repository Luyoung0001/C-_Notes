#include <iostream>
using namespace std;
template <typename T1, typename T2> auto Add(T1 a, T2 b) -> decltype(a + b);
int main() {
    double a = 1.23;
    int b = 100;
    auto c = Add(a, b);
    cout << "c:" << c << endl;

    return 0;
}
template <typename T1, typename T2> auto Add(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}