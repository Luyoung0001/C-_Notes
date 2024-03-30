#include "queue.h"
#include <ctime>
#include <iostream>
using namespace std;

const int MIN_PER_HR = 60;
bool newcustomer(double x);
int main() {
    srand(time(0));
    cout << "输入队列最大长度:";
    int qs;
    cin >> qs;
    Queue line(qs); // the queue named line

    cout << "输入模拟总交易时长:";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "请输入每小时来的人数:";
    double perHour;
    cin >> perHour;

    double min_per_cust = MIN_PER_HR / perHour; // 每个人平均交易时间

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long wait_time = 0;
    long line_wait = 0;

    // 模拟开始
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer(min_per_cust)) {
            if (line.isFull())
                turnaways++;
            else {
                customers++;
                temp.set(cycle);
                line.enQueue(temp);
            }
        }
        if(wait_time <= 0 && !line.isEmpty()){
            line.deQueue(temp);
            wait_time = temp.ptime();
            line_wait += cycle-temp.when();
            served++;
        }
        if(wait_time > 0){
            wait_time--;
        }
        sum_line += line.queueCount();
    }
    return 0;
}
bool newcustomer(double x) {
    // x=6时,意味着 大于 1 的概率为 1/6
    return (rand() * x / RAND_MAX < 1);
}