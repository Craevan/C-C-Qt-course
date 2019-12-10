#ifndef C_C_QT_COURSE_GAMEVIEW_H
#define C_C_QT_COURSE_GAMEVIEW_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../controller/GameController.h"

class GameView {
public:
    GameView();
    ~GameView() = default;
    void printBoard();
private:
    GameController controller;
    bool playGame();

};


#endif
