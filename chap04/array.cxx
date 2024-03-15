#include <iostream>
int main() {
    int arr[3] = {1, 2, 3}; // 可以使用这种方式来对数组进行初始化
    int n = sizeof(arr);
    int arr1[5] = {0}; // 如果只初始化第一个元素,后面的元素就会被置为 0
    std::cout << n << std::endl;
    int arr2[] = {
        1, 2, 3, 4,
        5}; // 如果初始化数组时方括号内（[ ]）为空，C++编译器将计算元素个数

    // C++11 新增的声明方法
    double arr3[4] {1, 2, 3, 4};
    double arr6[4] {1, 2, 3, 4};

    int arr4[5] {}; // = 可以省略

    long arr5[4] = {1, 2, 3, 1.2}; // 列表初始化禁止缩窄转换
    std::cout << arr5[3];
    return 0;
}