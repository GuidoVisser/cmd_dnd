#pragma once
using namespace std;

class Position {
public:
    Position(int x, int y);

    int getX();
    int getY();
    void moveTo(int newX, int newY);

private:
    int x;
    int y;
};
