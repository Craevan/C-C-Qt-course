#ifndef C_C_QT_COURSE_GAMECONTROLLER_H
#define C_C_QT_COURSE_GAMECONTROLLER_H

#include <string>
#include <vector>
#include "../model/GameModel.h"

class GameController {
public:
    GameController() = default;
    ~GameController() = default;
    const std::vector<std::vector<char>>* returnGrid();

    void startGame(std::string playerXName, std::string playerOName);

    bool gameOver();

    std::string getTurn();

    bool isMoveValid(std::string move);

    bool outOfBounds();

    bool spaceTaken();

    std::string gameResult();
    void resetGame();
private:

    GameModel data;
};


#endif
