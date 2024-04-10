#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

template <typename T> class hasFriend {
  private:
    T item;
    static int cnt;

  public:
    hasFriend(const T &i) : item(i) { cnt++; }
    ~hasFriend() { cnt--; }
    friend void counts();
    friend void reports(hasFriend<T> &);

};
// 初始化
template <typename T>
int hasFriend<T>::cnt = 0;

// 友元函数
void counts(){
    cout << "init count: " << hasFriend<int>::cnt << "; ";
    cout << "double count: " << hasFriend<double>::cnt << endl;
}
// 重载
// 该程序还提供两个report()函数，它们分别是某个特定HasFriend具体化的友元
void reports(hasFriend<int> &hf){
    cout << "hasFriend<int>: " << hf.item << endl;
}

void reports(hasFriend<double> &hf){
    cout << "hasFriend<double>: " << hf.item << endl;
}

int main(){
    cout << "No objects declared: ";
    counts();

    // 生成类
    hasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();

    hasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();

    hasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();

    reports(hfi1);
    reports(hfi2);
    reports(hfdb);

    return 0;
}