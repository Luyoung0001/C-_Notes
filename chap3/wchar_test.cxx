#include <iostream>
int main(){
    wchar_t s = 'b';
    std::wcout << s << std::endl; // 此时想要智能输出,可以使用 wcout
    return 0;
}