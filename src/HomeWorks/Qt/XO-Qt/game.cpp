#include "game.h"
#include "board.h"
#include "ai.h"
#include "State.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

Game::Game(QWidget *parent) : QDialog(parent) {
    this->setWindowTitle("XO-Qt RC1");
    this->setFixedSize(300, 300);

    QSize size(100, 100);
    boardRects[0] = QRect(QPoint(0, 0), size);
    boardRects[1] = QRect(QPoint(0, 100), size);
    boardRects[2] = QRect(QPoint(0, 200), size);
    boardRects[3] = QRect(QPoint(100, 0), size);
    boardRects[4] = QRect(QPoint(100, 100), size);
    boardRects[5] = QRect(QPoint(100, 200), size);
    boardRects[6] = QRect(QPoint(200, 0), size);
    boardRects[7] = QRect(QPoint(200, 100), size);
    boardRects[8] = QRect(QPoint(200, 200), size);

    player = X;

}

Game::~Game() {}


void Game::paintEvent(QPaintEvent *e) {
    painter = new QPainter(this);

    painter->fillRect(this->rect(), QColor(255, 255, 255));

    QPen borderPen(Qt::darkGray);
    borderPen.setWidth(4);

    painter->setPen(borderPen);
    painter->drawRects(boardRects, 9);

    for(int i = 0; i < 9; i++) {
        QString path;
        switch(displayBoard[i]) {
            case EMPTY: path = ""; break;
            case X: path = ":/img/x.png"; break;
            case O: path = ":/img/0.png"; break;
        }

        painter->drawPixmap(boardRects[i].x()+10, boardRects[i].y()+10,
                           boardRects[i].width()-20, boardRects[i].height()-20,
                           QPixmap(path));
    }
}

void Game::mousePressEvent(QMouseEvent *e) {
    for(int i = 0; i < 9; i++) {
        if(boardRects[i].contains(e->pos()) && displayBoard[i] == EMPTY) {
            if(CheckGame() == PLAY) {
                board.SetSquare(i, currentPlay.player);
                displayBoard[i] = currentPlay.player;
                QWidget::update();
            }

            if(CheckGame() == WIN) {
                if(currentPlay.player == player)
                    Win();
                else
                    Lose();
                return;
            }

            if(CheckGame() == LOSE) {
                if(currentPlay.player == player)
                    Lose();
                else
                    Win();
                return;
            }

            if(CheckGame() == TIE) {
                Tie();
                return;
            }

            if(CheckGame() == PLAY) {
                currentPlay.Toggle();

                PlayAi();
                QWidget::update();
            }

            if(CheckGame() == WIN) {
                if(currentPlay.player == player)
                    Win();
                else
                    Lose();
                return;
            }

            if(CheckGame() == LOSE) {
                if(currentPlay.player == player)
                    Lose();
                else
                    Win();
                return;
            }
            if(CheckGame() == TIE) {
                Tie();
                return;
            }

            if(CheckGame() == PLAY) {
                currentPlay.Toggle();
                return;
            }

            break;
        }
    }
}


void Game::Tie() {
    QMessageBox tie;
    tie.setWindowTitle("Result");
    tie.setText("Tie");
    tie.setFixedSize(400, 400);
    tie.exec();
    Reset();
}


void Game::Lose() {
    QMessageBox lose;
    lose.setWindowTitle("Result");
    lose.setText("You lose");
    lose.setFixedSize(400, 400);
    lose.exec();
    Reset();
}

void Game::Win() {
    QMessageBox win;
    win.setWindowTitle("Result");
    win.setText("You win");
    win.setFixedSize(400, 400);
    win.exec();
    Reset();
}

GameState Game::CheckGame() {
    return board.Evaluate(currentPlay.player);
}

void Game::Reset() {
    painter->end();
    board.Init();
    currentPlay.player = X;
    for(int i = 0; i < 9; i++) {
        displayBoard[i] = EMPTY;
    }
}

void Game::PlayAi() {
    Move bestMove = ai.Search(currentPlay.player);
    board.SetSquare(bestMove.location, currentPlay.player);
    displayBoard[bestMove.location] = currentPlay.player;
}
