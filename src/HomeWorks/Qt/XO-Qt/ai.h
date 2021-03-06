#ifndef AI_H
#define AI_H

#include "State.h"

class Ai {
private:
    enum {
        WIN_SCORE = 100,
        TIE_SCORE = 0,
        INF = 999999
    };

public:
    Move Search(int player);
};

extern Ai ai;

#endif // AI_H
