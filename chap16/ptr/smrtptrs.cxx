#include <iostream>
#include <memory>
#include <string>

class Report {
  private:
    std::string str;

  public:
    Report(const std::string s) : str(s) {
        std::cout << "Object created!\n" << std::endl;
    }
    ~Report() { std::cout << "Object deleted!\n" << std::endl; }
    void comment() const { std::cout << str << std::endl; }
};

// 智能指针
int main() {

    {
        std::unique_ptr<Report> ps(new Report("using unique_ptr."));
        ps->comment();
    }
    {
        std::auto_ptr<Report> ps(new Report("using auto_ptr.")); //  C++11 已不再支持
        ps->comment();
    }
    {
        std::shared_ptr<Report> ps(new Report("using shared_ptr."));
        ps->comment();
    }
    return 0;
}
