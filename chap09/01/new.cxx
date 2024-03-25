#include <iostream>
#include <new>
using namespace std;
struct chaff {
    char dross[20];
    int flag;
};

char buffer1[50];
char buffer2[200];

int main() {
    chaff *p1, *p2;
    int *p3, *p4;

    p1 = new chaff;
    p3 = new int[20];

    p2 = new (buffer1) chaff;
    p4 = new (buffer2) int[10];

    // 述代码从buffer1中分配空间给结构chaff，
    // 从buffer2中分配空间给一个包含20个元素的int数组

    return 0;
}