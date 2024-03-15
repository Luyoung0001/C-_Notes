#include <iostream>
using namespace std;
int main() {
    string *s1 = new string("hello");
    string *s2 = new string();
    // s1 = s2;
    cout << *s1 << endl;
    // cout << *s2 << endl;
    return 0;
}