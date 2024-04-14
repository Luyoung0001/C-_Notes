#include "tv.h"
#include <iostream>

int main() {
    using std::cout;
    Tv s42;
    cout << "初始化:电视--->s42:\n";
    s42.settings();

    cout << std::endl;
    s42.onoff(); // 打开电视,并从电视上进行操控
    s42.chanup();
    s42.volup();
    s42.settings();

    // 用遥控器
    Remote grey;
    cout << std::endl;
    grey.set_chan(s42, 10);
    grey.voldown(s42);
    s42.settings();

    return 0;
}