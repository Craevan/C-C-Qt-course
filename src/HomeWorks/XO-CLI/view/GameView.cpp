#include "GameView.h"

GameView::GameView() {
    while(playGame());
}

bool GameView::playGame() {
    std::string playerOneName, playerTwoName;
    std::cout<< "Введите имя игрока 1. Он будет играть крестиком: ";
    getline(std::cin,playerOneName);
    std::cout<< "Введите имя игрока 2. Он будет играть ноликом: ";
    getline(std::cin,playerTwoName);
    controller.startGame(playerOneName, playerTwoName);

    while(!controller.gameOver()){
        std::string playerTurn = controller.getTurn();
        std::string move;

        do {
            if(controller.outOfBounds()){
                std::cout<<"Данная позиция выходит за пределы границ. Сделайте ход в пределах границ.\n";
            }
            if(controller.spaceTaken()){
                std::cout<<"Данная позиция уже занята. Выберите пустую клетку поля.\n";
            }
            printBoard();
            std::cout << playerTurn << ", ваш ход: ";
            std::cin >> move;
        }while(!controller.isMoveValid(move));
    }

    std::string winner = controller.gameResult();

    if(winner.empty()){
        std::cout<<"\nGame Over!!! НИЧЬЯ\n";
    }
    else{
        std::cout<<"\n"<<winner<< " победил!\n";
    }
    printBoard();

    std::string playAgain;
    std::cout<<"Хотите сыграть еще одну партию? Введите 'yes' для игры, 'no' для выхода.\n";
    do{
        std::cin>>playAgain;
        transform( playAgain.begin(), playAgain.end(), playAgain.begin(), std::ptr_fun <int, int> (tolower));
        if(playAgain == "no"){
            return false;
        }
        else if(playAgain == "yes"){
            std::cout<<"Начинаем новую игру.\n";
            std::cin.get();
            controller.resetGame();
            return true;
        }
        else {
            std::cout << "!!!Введите 'yes' для игры, 'no' для выхода.!!!\n";
        }
    }
    while(true);
}

void GameView::printBoard() {
    const std::vector<std::vector<char>>* grid = controller.returnGrid();

    std::cout<<"\n";
    for(auto itToVectors = grid->begin(); itToVectors != grid->end(); ++itToVectors){
        for(auto itVector = itToVectors->begin(); itVector != itToVectors->end(); itVector++){
            std::cout<< *itVector;
            if(itVector+1 != itToVectors->end()){
                std::cout<<"|";
            }
        }
        if(itToVectors+1 != grid->end()) {
            std::cout << "\n-----\n";
        }
    }
    std::cout<<"\n\n";
}