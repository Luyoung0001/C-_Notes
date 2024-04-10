#include <iostream>
// 类模板的另一项新特性是，可以为类型参数提供默认值
template <class T1, class T2 = int> class Pair {
  private:
    T1 a;
    T2 b;

  public:
    T1 &first();
    T2 &second();

    // 这里会调用默认复制函数,生成临时变量
    T1 first() const { return a; }
    T2 second() const { return b; }

    Pair<T1, T2>(const T1 &t1, const T2 &t2) : a(t1), b(t2) {}
    Pair(){};
};

template <class T1, class T2> T1 &Pair<T1, T2>::first() { return a; }
template <class T1, class T2> T2 &Pair<T1, T2>::second() { return b; }

int main() {
    using std::cout;
    using std::endl;
    Pair<int, std::string> pairs(1, "string1");
    cout << pairs.first() << endl;
    cout << pairs.second() << endl;

    //
    pairs.first() = 2;
    pairs.second() = "string2";

    cout << pairs.first() << endl;
    cout << pairs.second() << endl;

    return 0;
}