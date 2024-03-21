#include <iostream>
using namespace std;
int main() {
    int age = 39;
    int &ap = age;         // 引用,一旦绑定不能松绑,类似下面
    int const *ap1 = &age; // 指针,不可松绑的指针
    
    return 0;
}