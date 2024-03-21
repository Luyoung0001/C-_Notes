#include <iostream>
using namespace std;

struct free_throws {
    string name;
    int made;
    int attempts;
    float percent;
};

void set_pc(free_throws &ft);
int main() {
    free_throws ft = {"Jack", 5, 10, 99.0};
    set_pc(ft);
    cout << ft.percent << endl; // 引用传参节省系统资源
    return 0;
}
void set_pc(free_throws &ft) { ft.percent = 0; }
