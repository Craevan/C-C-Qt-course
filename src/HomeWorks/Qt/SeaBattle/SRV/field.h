#ifndef FIELD_H
#define FIELD_H

#include <QVector>

enum Cell {
        CLEAR = 0, SHIP, DOT, HALF
    };

class Field {
public:
    void fieldInitialization(const QString& string);
    Cell getCell(int x, int y);
    void setCell(int x, int y);
    static bool isCorrect(const QString& string);
private:
    QVector<Cell> gameField;
};

#endif // FIELD_H
