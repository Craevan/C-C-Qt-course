#include "game.h"
#include "State.h"
#include <QApplication>


int displayBoard[9];
CurrentPlay currentPlay;
Board board;
Ai ai;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Game game;
    game.show();

    return app.exec();
}
