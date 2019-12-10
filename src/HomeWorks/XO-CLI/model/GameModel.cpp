#include "GameModel.h"

GameModel::GameModel() {
    fillTable();
}

void GameModel::fillTable(){
    char pos = '1';
    for(auto & it : grid){
        for(char & vecIt : it){
            vecIt = pos;
            ++pos;
        }
    }
}

void GameModel::setNames(std::string nameOne, std::string nameTwo) {
    playerX.initializePlayer(std::move(nameOne), 'X');
    playerO.initializePlayer(std::move(nameTwo), 'O');
}

const std::vector<std::vector<char>>* GameModel::returnGrid(){
    return &grid;
}

Status GameModel::getStatus(){
    return gameStatus;
}

std::string GameModel::playerTurn() {
    return xTurn ? playerX.getName() : playerO.getName();
}

void GameModel::checkIfWon(int row, int col) {
    char mark = grid[row][col];
    if(mark == grid[row][0] and mark == grid[row][1] and mark == grid[row][2]){
        gameStatus = Status::winner;
    }
    else if(mark == grid[0][col] and mark == grid[1][col] and mark == grid[2][col]){
        gameStatus = Status::winner;
    }
    else if(row == col and mark == grid[0][0] and  mark == grid[1][1] and mark == grid[2][2]){
        gameStatus = Status::winner;
    }
    else if(row + col == 2 and mark == grid[0][2] and mark == grid[1][1] and mark == grid[2][0]){
        gameStatus = Status::winner;
    }
    else if(numberOfMoves == maxMoves){
        gameStatus = Status::draw;
    }
    else{
        gameStatus = Status::validInput;
    }
}

bool GameModel::updateGrid(int row, int col) {
    if(grid[row][col] == 'X' or grid[row][col] == 'O'){
        gameStatus = Status::alreadyOccupied;
        return false;
    }
    ++numberOfMoves;
    if(xTurn){
        grid[row][col] = playerX.getMark();
        xTurn = false;
    }
    else {
        grid[row][col] = playerO.getMark();
        xTurn = true;
    }
    if(numberOfMoves >= minimumMovesToWin){
        checkIfWon(row,col);
        if(gameStatus == Status::winner){
            xTurn ? playerO.updateDidWin() : playerX.updateDidWin();
        }
    }
    else{
        gameStatus = Status::validInput;
    }
    return true;
}

bool GameModel::getMove(std::string move){
    if(move.size() > 1 or move.empty()){
        gameStatus = Status::outOfBoundsInput;
        return false;
    }
    switch (move[0]) {
        case '1': {
            return updateGrid(0, 0);
        }
        case '2': {
            return updateGrid(0, 1);
        }
        case '3': {
            return updateGrid(0, 2);
        }
        case '4': {
            return updateGrid(1, 0);
        }
        case '5': {
            return updateGrid(1, 1);
        }
        case '6': {
            return updateGrid(1, 2);
        }
        case '7': {
            return updateGrid(2, 0);
        }
        case '8': {
            return updateGrid(2, 1);
        }
        case '9': {
            return updateGrid(2, 2);
        }
        default: {
            gameStatus = Status::outOfBoundsInput;
        }
    }

    return false;
}

std::string GameModel::returnResult() {
    if(gameStatus == Status::draw){
        return "";
    }
    else{
        return playerX.didWin() ? playerX.getName() : playerO.getName();
    }
}

void GameModel::resetGame() {
    xTurn = true;
    numberOfMoves = 0;
    gameStatus = Status::validInput;
    fillTable();
}
