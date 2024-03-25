#include <string>
namespace pers {
struct Person {
    std::string fname;
    std::string lname;
};
void getPerson(Person &);
void showPerson(const Person &);
} // namespace pers
namespace debts {
using namespace pers; // 将所有声明全部导入,在此之前,pers 中并没有 cout,cin,endl
                      // 等等
struct Debt {
    Person name;
    double mount;
};
void getDebt(Debt &);
void showDebt(const Debt &);
double sumDebts(const Debt arr[], int n);
} // namespace debts