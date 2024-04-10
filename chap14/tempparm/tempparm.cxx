#include "../TP/stacktp.h"
#include <iostream>

// 可以混合使用模板参数和常规参数，例如，Crab类的声明可以像下面这样打头
template <template <typename T> class Thing, typename U, typename V>
class Crab {
  private:
    Thing<U> s1;
    Thing<V> s2;

  public:
    Crab() {}
    bool push(U a, V x) { return s1.push(a) && s2.push(x); }
    bool pop(U &a, V &x) { return s1.pop(a) && s2.pop(x); }
};

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    Crab<Stack, int, double> nebula;
    int ni;
    double nb;
    cout << "请输入 (int,double) pairs, 比如 (4,3.5):\n";
    while (cin >> ni >> nb && ni > 0 && nb > 0) {
        if (!nebula.push(ni, nb))
            break;
    }
    while (nebula.pop(ni, nb)) {
        cout << "ni: " << ni << "\n"
             << "nb: " << nb << endl;
    }
    cout << "Done!\n";

    return 0;
}
