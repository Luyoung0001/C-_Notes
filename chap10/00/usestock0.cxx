#include "stock00.h"
#include <iostream>
int main() {
    Stock cat;
    cat.acquire("Cats", 20, 1);
    cat.show();
    cat.buy(20, 1);
    cat.show();
    cat.sell(39, 2);
    cat.show();
    cat.buy(39, 1);
    cat.show();
    return 0;
}