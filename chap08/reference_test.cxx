#include <iostream>
using namespace std;
struct free_throws {
    string name;
    int made;
    int attempts;
    float percent;
};
void display(const free_throws &ft);
void set_pc(free_throws &ft);
free_throws &accumulate(free_throws &target, const free_throws &source);

int main() {
    free_throws one = {"IB", 12, 14};
    free_throws two = {"AK", 13, 16};
    free_throws three = {"MM", 7, 10};
    free_throws four = {"WL", 121, 142};
    free_throws five = {"LL", 11, 19};
    free_throws team = {"Tg", 0, 0};

    set_pc(one);
    display(one);

    accumulate(team, one);
    display(team);

    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);

    free_throws dup;
    dup = accumulate(team, five); // 这里返回的是引用,不用创建临时变量,可以用引用 team 直接赋值到 dup
    cout << "display team:" << endl;
    display(team);

    cout << "display dup:" << endl;
    display(dup);

    accumulate(dup, five) = four; // 返回的是 dup的引用,且对 dup 进行了赋值
    display(four);
    display(dup); // 它们应该一致

    return 0;
}

void display(const free_throws &ft) {
    cout << "Name:" << ft.name << '\n';
    cout << "Made:" << ft.made << '\n';
    cout << "Attempts:" << ft.attempts << '\n';
    cout << "Percent:" << ft.percent << '\n';
    cout << '\n';
}
void set_pc(free_throws &ft) {
    if (ft.attempts != 0) {
        ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
    } else {
        ft.percent = 0;
    }
}
free_throws &accumulate(free_throws &target, const free_throws &source) {
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}
// 运行结果:
// Name:IB
// Made:12
// Attempts:14
// Percent:85.7143

// Name:Tg
// Made:12
// Attempts:14
// Percent:85.7143

// Name:Tg
// Made:25
// Attempts:30
// Percent:83.3333

// Name:Tg
// Made:153
// Attempts:182
// Percent:84.0659

// display team:
// Name:Tg
// Made:164
// Attempts:201
// Percent:81.592

// display dup:
// Name:Tg
// Made:164
// Attempts:201
// Percent:81.592

// Name:WL
// Made:121
// Attempts:142
// Percent:0

// Name:WL
// Made:121
// Attempts:142
// Percent:0