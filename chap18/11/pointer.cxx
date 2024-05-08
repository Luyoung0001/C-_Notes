#include <iostream>
void exampleFunction(int x) {
    std::cout << "Function called with value: " << x << std::endl;
}

class FunctionWrapper {
    using FuncPtr = void (*)(int);
    FuncPtr func_;

  public:
    FunctionWrapper(FuncPtr func) : func_(func) {}

    void operator()(int x) const { func_(x); }
};

int main() {
    FunctionWrapper fw(exampleFunction);
    fw(10); // 调用 exampleFunction(10)
}
