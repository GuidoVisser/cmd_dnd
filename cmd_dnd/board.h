#pragma once
#include <vector>
#include <string>

#include "position.h"

class Creature;
class BoardTile;

class Board {
public:
    // constructors
    Board() = delete;
    Board(int width, int height);

    // deconstructor
    ~Board();

    void addCreatureToBoard(Creature *addedCreature, Position position);
    
    void renderBoard();

    BoardTile* getTileFromPosition(Position pos);

private:
    int width;
    int height;

    BoardTile** tiles;
    void initializeTiles();

    vector<Creature> creaturesOnBoard;

    string constructPositionString(string positionContent);
};


class BoardTile {
public:
    BoardTile();
    BoardTile(int x, int y);

    Position getPosition();
    bool isAvailableForCreature();

    friend class Board;
    friend class Creature;

private:
    Creature *creatureOnPosition = NULL;
    Position position;

    // for later when pathfinding is added
    int movementCost; // -1 denotes that a position is inaccassible
};