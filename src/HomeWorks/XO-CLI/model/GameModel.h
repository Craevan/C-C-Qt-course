#ifndef C_C_QT_COURSE_GAMEMODEL_H
#define C_C_QT_COURSE_GAMEMODEL_H

#include <vector>
#include <string>
#include "Status.h"
#include "Player.h"

class GameModel {
public:
    GameModel();
    ~GameModel() = default;

    const std::vector<std::vector<char>>* returnGrid();

    void setNames(std::string nameOne, std::string nameTwo);

    Status getStatus();

    std::string playerTurn();

    bool getMove(std::string move);

    std::string returnResult();

    void resetGame();

    void fillTable();


private:
    void checkIfWon(int row, int col);
    bool updateGrid(int row, int col);

    std::vector<std::vector<char>>grid{3,std::vector<char>(3)};
    Player playerX;
    Player playerO;
    Status gameStatus = Status::validInput;

    bool xTurn = true;
    unsigned short numberOfMoves = 0;

    const unsigned short minimumMovesToWin = 5;
    const unsigned short maxMoves = 9;

};


#endif
