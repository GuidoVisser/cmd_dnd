#include <vector>
#include <stdlib.h>

using namespace std;

#include "board.h"
#include "creature.h"
#include "position.h"

Board::Board(int width, int height): 
            width(width), 
            height(height) {
    
    // initialize board positions
    initializeTiles();

}

Board::~Board() {
    for (int i=0; i<width; i++) {
        delete[] tiles[i];
    }
    delete tiles;
}

void Board::initializeTiles() {
    tiles = new BoardTile*[width];

    for (int i=0; i < width; i++) {
        tiles[i] = new BoardTile[height];
    }

    for (int i=0; i < width; i++) {
        for (int j=0; j < height; j++) {
            tiles[i][j] = BoardTile(i, j);
        }
    }
}

void Board::addCreatureToBoard(Creature *addedCreature, Position position) {
    BoardTile* tile = getTileFromPosition(position);

    tile->creatureOnPosition = addedCreature;
    addedCreature->boardPosition = tile;
    creaturesOnBoard.push_back(*addedCreature);
}

BoardTile* Board::getTileFromPosition(Position pos) {
    return &tiles[pos.getX()][pos.getY()];
}

void Board::renderBoard() {
    // Construct row divider
    string output = "";
    string rowDivider = "";
    string lineEnd = "#\n";
    for (int i=0; i<width; i++) {
        rowDivider += "#===="; 
    }
    rowDivider +=lineEnd;
    
    // construct board
    for (int i=0; i<height; i++) {
        string line = "";
        for (int j=0; j<width; j++) {
            if (tiles[i][j].creatureOnPosition != NULL) {
                string id = tiles[i][j].creatureOnPosition->getCreatureID();
                line += constructPositionString(id);
            // construct empty position string if position is not occupied
            } else {
                line += constructPositionString("  ");
            }
        }
        line += lineEnd;

        output += rowDivider;
        output += line;
    }
    output += rowDivider;

    cout << string(100, '\n');
    cout << output;
}

string Board::constructPositionString(string positionContent) {
    return "# " + positionContent + " ";
}

//###################################################
//############         BoardTile         ############
//###################################################

BoardTile::BoardTile() { };

BoardTile::BoardTile(int x, int y) {
    position = Position(x, y);
    movementCost = 1; // for later when pathfinding is added
};

bool BoardTile::isAvailableForCreature() {
    if (creatureOnPosition == NULL) {
        return true;
    } else {
        return false;
    }
}

Position BoardTile::getPosition() {
    return position;
}