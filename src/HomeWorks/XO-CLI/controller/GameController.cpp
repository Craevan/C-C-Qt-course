#include "GameController.h"

void GameController::startGame(std::string playerXName, std::string playerOName) {
    data.setNames(std::move(playerXName), std::move(playerOName));
}

const std::vector<std::vector<char>>* GameController::returnGrid(){
    return data.returnGrid();
}


bool GameController::gameOver() {
    Status temp = data.getStatus();
    return temp == Status::draw or temp == Status::winner;
}


std::string GameController::gameResult() {
    return data.returnResult();
}


std::string GameController::getTurn() {
    return data.playerTurn();
}


bool GameController::isMoveValid(std::string move){
    return data.getMove(std::move(move));
}


bool GameController::outOfBounds() {
    return data.getStatus() == Status::outOfBoundsInput;
}


bool GameController::spaceTaken(){
    return data.getStatus() == Status::alreadyOccupied;
}

void GameController::resetGame() {
    data.resetGame();
}
