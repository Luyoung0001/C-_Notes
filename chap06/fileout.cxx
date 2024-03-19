#include <fstream>
#include <iostream>
using namespace std;
// 使用文件输出的主要步骤如下:
// 1．包含头文件fstream。
// 2．创建一个ofstream对象。
// 3．将该ofstream对象同一个文件关联起来。
// 4．就像使用cout那样使用该ofstream对象。
int main() {
    ofstream outFile;
    ofstream fout;

    // 将对象和文件关联起来
    outFile.open("fish.txt");
    char filename[50] = {0};
    cin >> filename;
    fout.open(filename);

    double wt = 125.8;
    outFile << wt;
    char line[81] = "Ohsjhvfiudjvidijfvijdfv cbuewhu.";
    fout << line << endl;

    // 关闭文件
    outFile.close();
    

    return 0;
}