#include <iostream>
using namespace std;
int main() {
    // 在这里，string s2 = s1; 语句会创建一个新的 std::string 对象 s2，并将 s1
    // 中的内容复制到 s2 中。这样，s1 和 s2
    // 就成为两个独立的对象，它们的值相同但是地址不同。

    // 总的来说，对象之间的赋值操作在C++中是非常常见和合法的，并且对于标准库中的
    // std::string 类型，这种操作是非常常见的用法之一
    
    string s1 = "hello";
    string s2 = s1;
    string *p1 = &s1;
    string *p2 = &s2;
    cout << p1 << ' ' << p2 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}