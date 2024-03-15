#include <iostream>
int main(){
    // 非 std 命名空间中
    int std = 10;
    int endl = 20;
    std::cout << std << "+"<< endl << std::endl;
    return 0;
}