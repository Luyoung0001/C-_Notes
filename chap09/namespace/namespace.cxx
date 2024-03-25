#include <iostream>
using namespace std;

namespace Jack {
double pail;
} // namespace Jack

namespace Jill {
double pail;
} // namespace Jill

double pail;
double *p1 = &pail;
int main() {
    // using声明将特定的名称添加到它所属的声明区域中
    using Jack::pail; // put pail into a local namespace
    // double pail = 20; // 错误
    pail = 2;
    double *p2 = &pail; // Jack::pail into a local namespace
    ::pail = 1;        // global pail

    cout << "global pail: " << pail << " at " << p1 << endl;
    cout << "local pail: " << ::pail << " at " << p2 << endl;
    return 0;
}
