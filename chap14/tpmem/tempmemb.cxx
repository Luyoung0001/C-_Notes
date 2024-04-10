#include <iostream>
using std::cout;
using std::endl;
template <class T> class beta {
  private:
    template <class V> // nested tp
    class hold {
      private:
        V val;

      public:
        hold() {}
        hold(const V &v) : val(v) {}
        void show() const { cout << val << endl; }
        V &value() { return val; }
    };

    hold<T> q;   //模板对象
    hold<int> n; // 具体对象

  public:
    beta(T t, int i) : q(t), n(i) {} // 构造函数

    // 模板函数
    template <typename U> U blab(U u, T t) {
        return (n.value() + q.value()) * u / t;
    }
    void show() const {
        q.show();
        n.show();
    }
};
int main() {
    // 调用一系列构造函数
    beta<double> guy(1.5, 3);
    cout << "T 被设置为 double:" << endl;

    guy.show();
    cout << "调用函数模板:\n";
    cout << guy.blab(2, 0.5) << endl; // (1.5+3)*2/2.5 = 9/0.5=18 返回类型是 int
    cout << guy.blab(2.5, 2) << endl; // (1.5+3)*2.5/2 = 5.625 返回类型是 dounle

    return 0;
}