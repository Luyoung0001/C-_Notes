#include "student.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

void set(Student &sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main() {
    Student students[pupils] = {Student(quizzes), Student(quizzes),
                                Student(quizzes)};

    // 设置
    for (int i = 0; i < pupils; i++) {
        set(students[i], quizzes);
    }

    cout << "\n学生列表:\n";
    for (int i = 0; i < pupils; i++) {
        cout << students[i].Name() << endl;
    }

    cout << "\n考试结果:\n";
    for (int i = 0; i < pupils; i++) {
        cout << students[i]
             << endl; // 友元函数:friend std::ostream &operator<<(std::ostream
                      // &os, const Student &stu);
    }

    cout << "Down.\n";
    return 0;
}
void set(Student &sa, int n) {
    cout << "请输入学生的姓名:" ;
    getline(cin, sa); // 友元函数调用

    cout << "请输入测试成绩:\n";
    for (int i = 0; i < n; i++) {
        // 重载[]运算符: double &operator[](int i);
        while (!(cin >> sa[i])) {
            cin.clear();
            // 刷掉异常字符
            while (cin.get() != '\n') {
                continue;
            }
            cout << "输入了异常值,请重新输入.\n";
        }
    }
    cin.get(); // 刷掉换行符
}