#include "coordin.h"
#include <iostream>
using namespace std;
int main() {
    rect rplace;
    polar pplace;
    cout << "请输入x,y:";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "请输入接下来的x,y(输入其它退出!):";
    }
    cout << "Bye" << endl;

    return 0;
}