#include <iostream>
using namespace std;
int main() {
    char ch = 0;
    cin.get(ch);
    // n hao #xcsdvfbg
    // n hao %

    // 该程序回显了每个字符，并将全部字符计算在内，其中包括空格。
    // 输入仍被缓冲，因此输入的字符个数仍可能比最终到达程序的要多。

    // 头文件iostream将cin.get(ch)的参数声明为引用类型，因此该函数可以修改其参数的值。
    while (ch != '#') {
        cout << ch;
        cin.get(ch);
    }
    // basic_istream& get(char_type& __c) {
    //   int_type __ch = get();
    //   if (__ch != traits_type::eof())
    //     __c = traits_type::to_char_type(__ch);
    //   return *this;
    // }
    cin.get(ch);
    cout << ch;
    return 0;
}