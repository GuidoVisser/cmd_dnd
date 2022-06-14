#pragma once
using namespace std;

class Position {
public:
    Position();
    Position(int x, int y);

    int getX();
    int getY();

    bool isSamePositionAs(Position pos);

protected:
    int x;
    int y;
};

