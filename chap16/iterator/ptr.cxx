#include <algorithm>
#include <iostream>
#include <random>

const int SIZE = 10;
double Receipts[SIZE];

int main() {
    // 为数组添加随机值
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1000.0);

    for (int i = 0; i < SIZE; i++) {
        Receipts[i] = dis(gen);
    }

    // 对数组进行排序
    std::sort(Receipts, Receipts + SIZE);

    // 输出排序后的数组
    for (int i = 0; i < SIZE; i++) {
        std::cout << Receipts[i] << " ";
    }

    return 0;
}