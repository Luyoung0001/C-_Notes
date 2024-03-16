#include <iostream>

int main() {
    wchar_t string1[] = L"hello";
    char16_t string2[] = u"hello1";
    char32_t string3[] = U"hello2";

    // g++ -o main otherstring.cxx -std=c++11
    // 运行后输出有点奇怪,可能编码不对
    std::wcout << string1 << std::endl; // 输出宽字符
    std::cout << string2 << std::endl;  // 输出 UTF-16 字符
    std::cout << string3 << std::endl;  // 输出 UTF-32 字符

    return 0;
}
