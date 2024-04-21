#include <iostream>
#include <memory>
#include <string>

std::unique_ptr<std::string> demo(const char *s) {
    std::unique_ptr<std::string> temp(new std::string(s));
    return temp;
}

int main() {
    // 调用demo函数，返回一个unique_ptr<string>，并将其赋值给ps
    std::unique_ptr<std::string> ps;
    ps = demo("Uniquely special");

    // 输出ps所指向的字符串内容
    std::cout << *ps << std::endl;

    return 0;
}
