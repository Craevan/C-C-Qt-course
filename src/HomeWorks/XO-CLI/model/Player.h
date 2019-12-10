#ifndef C_C_QT_COURSE_PLAYER_H
#define C_C_QT_COURSE_PLAYER_H

#include <string>

class Player {
public:
    Player() = default;
    ~Player() = default;

    void initializePlayer(std::string playerName, char playerMark);

    std::string getName();

    char getMark();

    void updateDidWin();

    bool didWin();
private:

    std::string name;

    char mark;

    bool winner = false;

};

#endif
