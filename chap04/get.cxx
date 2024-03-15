#include <iostream>
int main() {

    // 面向行的输入
    char LastName[20] = {0};
    char FirstName[20] = {0};
    std::cout << "输入姓:" << std::endl;
    std::cin.get(LastName, sizeof(LastName));

    std::cout << "输入名:" << std::endl;
    std::cin.get(FirstName, sizeof(FirstName));

    // 打印测试
    std::cout << "名字是:" << LastName << ' ' << FirstName << std ::endl;
    /* 结果是:
        输入姓:
        lu
        输入名:
        名字是:lu
    */
    // 之所以有这样的结果是因为,get()不会舍弃上一次输入的换行符,会把换行符留在缓冲区里.下次输入的时候,会直接
    // 获取这个换行符,导致输入提前完成
    // 改进方法是,输入完成后,直接调用 get()函数,将缓冲区中的换行符拿出来,再继续输入.
    return 0;
}