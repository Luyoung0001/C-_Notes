#include <cstdlib>
#include <iostream>
int main() {
    std::cout << 5.0 / 0 << std::endl;
    std::abort();
    return 0;
}