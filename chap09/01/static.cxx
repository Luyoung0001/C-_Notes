#include <iostream>
using namespace std;
int globle = 10000;       // external linkage
static int one_file = 50; // internal linkage
int main() { return 0; }

void func1() {
    static int count = 0; // static duration, no linkage
}