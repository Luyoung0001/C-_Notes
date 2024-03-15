#include <iostream>
using namespace std;
int main() {
    string s1 = "hello";
    string s11 = "hello";
    if(s1 == s11){
        cout << "相等" << endl;
    }
    string s2 = " world";
    string s3 = "!\n";
    s1 += s2;
    s1 += s3;
    cout << s1;

    return 0;
}