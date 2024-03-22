#include <iostream>
using namespace std;
// 定义一个结构
struct student {
    int id;
    string name;
    double weight;
};

// 模板声明
template <typename T> void Swap(T &a, T &b);
// 模板重载
template <typename T> void Swap(T &a, T &b, int n);
// 显示具体化
template <> void Swap<student>(student &a, student &b);

// 显示信息
void show(const student s1, const student s2);

int main() {
    int a1 = 1, a2 = 10;
    Swap(a1, a2); // 模板重载
    cout << "交换后a1:" << a1 << " a2:" << a2 << endl;
    Swap(a1, a2, 4);

    // 使用函数显式实例化
    double b1 = 10.4;
    double b2 = 30.5;
    Swap<>(b1, b2);
    cout << "b1:" << b1 << endl;
    cout << "b2:" << b2 << endl;

    // 对结构体进行操作
    student st1 = {1, "Tom", 68.5};
    student st2 = {2, "Lucy", 40.5};
    show(st1, st2);
    Swap(st1, st2); // 优先采用具体化的模板
    show(st1, st2);

    return 0;
}

// 模板定义
template <typename T> void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T> void Swap(T &a, T &b, int n) {
    cout << n << endl;
    T temp = a;
    a = b;
    b = temp;
}
// 显示具体化
// 只交换 weight
template <> void Swap(student &a, student &b) {
    double temp = a.weight;
    a.weight = b.weight;
    b.weight = temp;
}

// 显示信息
void show(const student s1, const student s2) {
    cout << "s1的 id:" << s1.id << endl;
    cout << "s1的 name:" << s1.name << endl;
    cout << "s1的 weight:" << s1.weight << endl;
    cout << "s2的 id:" << s2.id << endl;
    cout << "s2的 name:" << s2.name << endl;
    cout << "s2的 weight:" << s2.weight << '\n' << endl;
}
