#include <iostream>
int main() {

    // 面向行的输入
    char string[200] = {0};
    std::cout << "输入一段话:" << std::endl;
    std::cin.getline(string, sizeof(string));
    std::cout << "这段话是:" << string << std::endl;

    return 0;
}