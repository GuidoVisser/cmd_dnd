#include "position.h"

Position::Position() { x = 0; y = 0; }

Position::Position(int x, int y): x(x), y(y) { }

int Position::getX() {
    return x;
}

int Position::getY() {
    return y;
}

bool Position::isSamePositionAs(Position pos) {
    if ((pos.getX() == x) && (pos.getY() == y)) {
        return true;
    } else {
        return false;
    }
}
