#include "position.h"

Position::Position(int x, int y): x(x), y(y) { }

int Position::getX() {
    return x;
}

int Position::getY() {
    return y;
}

void Position::moveTo(int newX, int newY) {
    x = newX;
    y = newY;
}
