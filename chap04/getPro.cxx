#include <iostream>
int main() {

    // 面向行的输入
    char LastName[20] = {0};
    char FirstName[20] = {0};
    std::cout << "输入姓:" << std::endl;
    std::cin.get(LastName, sizeof(LastName));

    // 改进
    std::cin.get();

    std::cout << "输入名:" << std::endl;
    std::cin.get(FirstName, sizeof(FirstName));

    // 打印测试
    std::cout << "名字是:" << LastName << ' ' << FirstName << std ::endl;

    /*测试结果为:
        输入姓:
        lu
        输入名:
        liang
        名字是:lu liang
    */

    return 0;
}