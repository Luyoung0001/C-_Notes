#include <array>

// C++11新增了一项功能——使用模板提供一系列别名，如下所示
template <typename T>
using arraytp = std::array<T, 12>;

int main(){
    arraytp<int> iarr;
    arraytp<double> darr;
    return 0;
}