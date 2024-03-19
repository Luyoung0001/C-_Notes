#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream Infile;
    ifstream fin;
    Infile.open("bowling.txt"); // 打开文件

    char filename[50] = {0};
    cin >> filename;
    fin.open(filename); // 打开失败?
    if (!fin.is_open()) {
        cout << "不能打开这个文件!" << endl;
    }

    double wt;
    Infile >> wt;

    cout << wt << endl;
    return 0;
}