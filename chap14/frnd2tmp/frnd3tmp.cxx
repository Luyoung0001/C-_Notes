#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;


// 声明模板函数
template <typename T> void counts();
template <typename T> void report(T &t);

template <typename TT> class hasFriend {
  private:
    TT item;
    static int cnt;

  public:
    hasFriend(const TT &i) : item(i) { cnt++; }
    ~hasFriend() { cnt--; }

    // 然后，在函数中再次将模板声明为友元。这些语句根据类模板参数的类型声明具体化
    friend void counts<TT>();
    friend void report<>(hasFriend<TT> &);

};

// 初始化
template <typename T>
int hasFriend<T>::cnt = 0;

// 提供模板定义
template <typename T>
void counts() {
    cout << "init count: " << hasFriend<T>::cnt << "; \n";
}
template <typename T>
void report(T &hf) { cout << hf.item << endl; }

int main() {
    cout << "No objects declared: ";
    counts<int>();
    counts<double>();

    // 生成类
    hasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts<int>();

    hasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts<int>();

    hasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts<double>();

    report(hfi1);
    report(hfi2);
    report(hfdb);

    return 0;
}