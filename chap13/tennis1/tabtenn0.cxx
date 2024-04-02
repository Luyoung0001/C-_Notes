#include "tabtenn0.h"
#include <iostream>
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln,
                                     bool ht) {
    this->firstName = fn; // 先调用复制构造函数,再用赋值运算符=
    this->lastName = ln;
    this->hasTable = ht;
}
void TableTennisPlayer::Name() const {
    std::cout << "lastname: " << this->lastName;
}
