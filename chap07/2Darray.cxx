#include <iostream>
using namespace std;
int sum(int (*arr)[4], int size);
// int sum(int arr[][4], int size);
int main() {
    const int Size = 3;
    int arr[Size][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
    cout << sum(arr, Size) << endl;
    return 0;
}

int sum(int (*arr)[4], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 4; j++) {
            total += arr[i][j];
        }
    }
    return total;
}
// int sum(int arr[][4], int size) {
//     int total = 0;
//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < 4; j++) {
//             total += arr[i][j];
//         }
//     }
//     return total;
// }