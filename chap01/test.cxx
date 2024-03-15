#include <iostream>
using namespace std; // namespace name
int main(){
    cout << "hello world!" << endl;

    // 如果编译器到达main( )函数末尾时没有遇到返回语句，则认为main( )函数以如下语句结尾：
    return 0;
}
// CC -lstdc++ test.cxx 编译, 目的连接标准 c++库

