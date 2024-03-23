#ifndef COORDIN_H_
#define COORDIN_H_
struct polar{
    double distance;
    double angle;
};

struct rect{
    double x;
    double y;
};

polar rect_to_polar(const rect &xypos);
void show_polar(const polar &dapos);

#endif