#include "stock00.h"
#include <iostream>
void Stock::acquire(const std::string &co, long n, double pr) {
    company = co;
    if (n < 0) {
        std::cout << "股票数量不能是负数;" << company
                  << "股票数量将会被设置为 0." << std::endl;
        shares = 0;
    } else {
        shares = n;
        share_val = pr;
        set_tot(); // public 的方法可以调用私有方法
    }
}
void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "要买的股票数量不能为负值,交易取消." << std::endl;
    } else {
        shares += num;
        share_val = price; // 更新价格
        set_tot();
    }
}
void Stock::sell(long num, double price) {
    if (num < 0) {
        std::cout << "你不能卖负数的股票,交易取消." << std::endl;
    } else if (num > shares) {
        std::cout << "你的股票持有数量小于交易量,交易失败." << std::endl;
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::show() {
    std::cout << "Company:" << company << '\n'
              << "shares:" << shares << '\n'
              << "Share Price:$" << share_val << '\n'
              << "Total Worth:$" << total_val << std::endl;
}
