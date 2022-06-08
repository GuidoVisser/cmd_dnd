#pragma once
#include <vector>

using namespace std;

#include "creature.h"
#include "position.h"

class Board {
public:
    Board();
    Board(int width, int height, vector<Creature> &creaturesOnBoard);

    ~Board();

    bool checkIfPositionIsFree(Position pos);
    int getPositionStatus(Position pos);
    void setPositionStatus(Position pos, int status);

    void renderBoard();

private:
    int width;
    int height;

    // 2D array of size width x height on initialization
    int** positionStatus;
    // keep track of creature position so you don't 
    // have to loop through creatures when rendering
    // Alternatively check for occupied in positionStatus
    // and loop only trough creatures when position is occupied
    int** creaturePositions; 
    vector<Creature> creaturesOnBoard; // TODO | change to vector
};