// iomanip.cpp -- using manipulators from iomanip
// some systems require explicitly linking the math library
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    // 现在可以生成几乎完全对齐的列了。使用fixed控制符导致显示末尾的0
    using namespace std;
    // use new standard manipulators
    cout << fixed << right;

    // use iomanip manipulators
    cout << setw(6) << "N" << setw(14) << "square root" << setw(15)
         << "fourth root\n";

    double root;
    for (int n = 10; n <= 100; n += 10) {
        root = sqrt(double(n));
        cout << setw(6) << setfill('.') << n << setfill(' ') << setw(12)
             << setprecision(3) << root << setw(14) << setprecision(4)
             << sqrt(root) << endl;
    }

    return 0;
}

//      N   square root   fourth root
// ....10       3.162        1.7783
// ....20       4.472        2.1147
// ....30       5.477        2.3403
// ....40       6.325        2.5149
// ....50       7.071        2.6591
// ....60       7.746        2.7832
// ....70       8.367        2.8925
// ....80       8.944        2.9907
// ....90       9.487        3.0801
// ...100      10.000        3.1623