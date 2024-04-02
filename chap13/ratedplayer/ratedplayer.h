#ifndef RATEDPLAYER_H_
#define RATEDPLAYER_H_
#include "../tennis1/tabtenn0.h"
class RatedPlayer : public TableTennisPlayer {
  private:
    unsigned int rating;

  public:
    // 需要添加自己的构造函数
    RatedPlayer(unsigned int r = 0, const string &fn = "none",
                const string &ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
    unsigned int Rating() const { return this->rating; }
    void ResetRating(unsigned int r) { this->rating = r; }
};
#endif