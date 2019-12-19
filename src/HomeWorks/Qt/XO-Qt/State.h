#ifndef STATE_H
#define STATE_H

enum GameState {
    WIN = 6,
    LOSE = -6,
    TIE = 0,
    PLAY = 1,
    END = -1
};
enum {
    X = 1,
    O = -1,
    EMPTY = 0
};

struct Move {
    int score;
    int location;

    Move(){}
    Move(int s) : score(s) {}
};

struct CurrentPlay {
    int player;
    CurrentPlay() : player(X) {}
    inline void Toggle() {
        player *= -1;
    }
};

extern int displayBoard[9];
extern CurrentPlay currentPlay;

#endif // STATE_H
