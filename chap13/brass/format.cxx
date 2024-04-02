#include "format.h"
#include <iostream>
using std::cout;
format setFormat() {
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}
void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}