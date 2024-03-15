#include <iostream>
int main() {

    // 面向行的输入
    char LastName[20] = {0};
    char FirstName[20] = {0};
    std::cout << "输入姓:" << std::endl;
    // 改进建议:每次调用完 get()后,再调用一次 get()刷掉换行符
    
    std::cin.get(LastName, sizeof(LastName)).get();

    std::cout << "输入名:" << std::endl;
    std::cin.get(FirstName, sizeof(FirstName)).get();

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