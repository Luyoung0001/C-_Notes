#include <iostream>

int main() {
    using std::cout;
    cout << "12345678901234567890\n";
    char ch = 'K';
    int t = 273;
    cout << ch << ":\n";
    cout << t << ":\n";
    cout << -t << ":\n";

    double f1 = 1.200;
    cout << f1 << ":\n";
    cout << (f1 + 1.0 / 9.0) << ":\n";

    double f2 = 1.67E2;
    cout << f2 << ":\n";
    f2 += 1.0 / 9.0;
    cout << f2 << ":\n";
    cout << (f2 * 1.0e4) << ":\n";

    // 面的函数调用将cout对象的计数系统格式状态设置为十六进制,整数会受影响,小数不受影响
    hex(cout);
    // ostream类重载了<<运算符，这使得上述用法与函数调用hex（cout）等价
    cout << std::hex;
    double f3 = 2.3e-4;
    cout << f3 << ":\n";
    cout << f3 / 10 << ":\n";

    // 设置宽度
    // width( )方法只影响将显示的下一个项目，然后字段宽度将恢复为默认值
    // 由于width( )是成员函数，因此必须使用对象（这里为cout）来调用它

    cout << '#' << "\n";
    cout.width(12);
    // 在默认情况下，cout用空格填充字段中未被使用的部分，可以用fill( )成员函数来改变填充字符
    cout.fill('*');
    // 12被放到宽度为12个字符的字段的最右边，这被称为右对齐
    cout << '#' << "\n";

    // 与字段宽度不同的是，新的填充字符将一直有效，直到更改它为止
    cout.width(12);
    cout << 10 << "\n";
    cout << 16 << "\n";

    return 0;
}
