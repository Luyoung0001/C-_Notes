#include <iostream>
using namespace std;
struct time_traval {
    int hours;
    int mins;
};
time_traval sum(const time_traval t1, const time_traval t2);
time_traval sumone(const time_traval &t1, const time_traval &t2); // 引用
time_traval sumtwo(const time_traval *t1, const time_traval *t2); // 传址
time_traval *sum3(const time_traval *t1, const time_traval *t2); // 返回地址
void show(const time_traval t);
int main() {
    time_traval time1 = {2, 50};
    time_traval time2 = {3, 40};

    time_traval time3 = sum(time1, time2);
    time_traval time4 = sumone(time1, time2);
    time_traval time5 = sumtwo(&time1, &time2);
    time_traval *time6 = sum3(&time1, &time2);

    show(time3);
    show(time4);
    show(time5);
    show(*time6);

    return 0;
}
time_traval sum(const time_traval t1, const time_traval t2) {
    time_traval total;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / 60;
    total.mins = (t1.mins + t2.mins) % 60;
    return total;
}
time_traval sumone(const time_traval &t1, const time_traval &t2) {
    time_traval total;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / 60;
    total.mins = (t1.mins + t2.mins) % 60;
    return total;
}
time_traval sumtwo(const time_traval *t1, const time_traval *t2) {
    time_traval total;
    total.hours = t1->hours + t2->hours + (t1->mins + t2->mins) / 60;
    total.mins = (t1->mins + t2->mins) % 60;
    return total;
}
time_traval *sum3(const time_traval *t1, const time_traval *t2) {
    time_traval *total = new time_traval;
    total->hours = t1->hours + t2->hours + (t1->mins + t2->mins) / 60;
    total->mins = (t1->mins + t2->mins) % 60;
    return total;
}
void show(const time_traval t) { cout << t.hours << ' ' << t.mins << endl; }