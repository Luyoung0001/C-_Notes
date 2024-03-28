#include "stonewt.h"

using std::cout;
Stonewt::Stonewt() { this->pds_left = this->pounds = this->stone = 0; }
Stonewt::Stonewt(double lbs) {
    cout << "use construter: Stonewt(double lbs)\n";
    this->stone = (int)lbs / Lbs_per_stn;
    this->pds_left = (int)lbs % Lbs_per_stn + lbs - int(lbs); // 剩余
    this->pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs) {
    cout << "use construter: Stonewt(int stn, double lbs)\n";

    this->stone = stn;
    this->pds_left = lbs;
    this->pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::~Stonewt() {}
void Stonewt::show_lbs() const {
    cout << "Pounds: " << this->pds_left << std::endl;
}
void Stonewt::show_stn() const {
    cout << "Stone: " << this->stone << std::endl;
}
Stonewt::operator double() const { return this->pounds; }
Stonewt::operator int() const { return int(this->pounds + 0.5); }