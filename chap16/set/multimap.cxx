#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<int, std::string> codes;

    // 向多重映射中插入一些条目
    codes.insert(std::make_pair(718, "New York"));
    codes.insert(std::make_pair(709, "New York"));
    codes.insert(std::make_pair(415, "San Francisco"));
    codes.insert(std::make_pair(718, "Oakland"));
    codes.insert(std::make_pair(718, "Brooklyn"));

    // 使用 equal_range() 查找键为 718 的所有条目
    // std::pair<std::multimap<int, std::string>::iterator,
    //           std::multimap<int, std::string>::iterator> range =
    //           codes.equal_range(718);

    auto range = codes.equal_range(718);
    std::cout << "Cities with area code 718:\n";
    // 遍历找到的所有条目并输出
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << (*it).second << std::endl;
    }

    return 0;
}
