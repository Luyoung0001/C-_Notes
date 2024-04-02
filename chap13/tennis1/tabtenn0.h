#ifndef TABTENN0_H_
#define TABTENN0_H_

#include <string>

using std::string;
class TableTennisPlayer {
private:
    string firstName; // 在类中正常使用 string 类型的成员变量
    string lastName;
    bool hasTable;

public:
    TableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};
#endif