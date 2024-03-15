#include <iostream>
int main() {
    char s1[] = {'h', 'e', 'l', 'l', 'o'};       // not a string
    char s2[] = {'h', 'e', 'l', 'l', 'o', '\n'}; // a string

    // 字符串输入

    // 这个例子的实际结果是，cin把Alistair作为第一个字符串，
    // 并将它放到name数组中。这把Dreeb留在输入队列中。当cin
    // 在输入队列中搜索用户喜欢的甜点时，它发现了Dreeb，因此cin读取Dreeb，并将它放到dessert数组中
    char s[200] = {0};
    char s3[200] = {0};
    std::cout << "请输入姓名:" << std::endl;
    std::cin >> s;
    std::cout << "请输入菜名:" << std::endl;
    std::cin >> s3;

    std::cout << s << ' ' << s3 << std::endl;
    return 0;
}