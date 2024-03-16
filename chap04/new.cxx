#include <iostream>
using namespace std;
int main() {
    // 指针真正的用武之地在于，在运行阶段分配未命名的内存以存储值,这是 OOP
    // 的关键
    int *pt = new int;
    *pt = 10;
    cout << *pt << endl;
    // 释放内存,如果程序就此结束,没必要归还.
    delete pt;
    // delete pt; // 释放两次
    int test = 10;
    int *p = &test;

    // delete p; // 不被允许

    /*  10
        main(46540,0x101400580) malloc: *** error for object 0x1556068f0: pointer being
        freed was not allocated main(46540,0x101400580) malloc: *** set a breakpoint in
        malloc_error_break to debug zsh: abort      ./main
    */

   // 释放空指针没有任何问题
   int *ptr = nullptr;
   delete ptr;



    return 0;
}