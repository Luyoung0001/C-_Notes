#include <iostream>
class Linear {
  private:
    double slope;
    double y0;

  public:
    Linear(double sl = 1, double y_ = 0) : slope(sl), y0(y_) {}
    double operator()(double x) { return y0 + slope * x; }
};

int main() {
    Linear linear(1, 3);
    double ans = linear(2.0);
    std::cout << ans << std::endl;
    return 0;
}