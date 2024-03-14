#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int a = rand();
    int b = rand();
    int main = rand(); // main 不是关键字
    cout << a << endl;
    cout << b << endl;
    cout << main << endl;
    return 0;
}