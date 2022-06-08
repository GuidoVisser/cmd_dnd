#include <vector>
using namespace std;

#include "board.h"
#include "creature.h"
#include "position.h"

// ###################################################

Board::Board() { }

Board::Board(int width, int height, vector<Creature> &creaturesOnBoard): 
            width(width), 
            height(height),
            creaturesOnBoard(creaturesOnBoard) {
    
    // 0 : position is free
    // 1 : position is occupied by other creature
    // (e.g. 2+ : position is obstructed/trapped/difficult terrain/etc.)
    positionStatus = new int*[width];

    for (int i=0; i < width; i++) {
        positionStatus[i] = new int[height];
    }

    for (int i=0; i < width; i++) {
        for (int j=0; j < height; j++) {
            positionStatus[i][j] = 0;
        }
    }

    creaturePositions = positionStatus;
    positionStatus[0][0] = 1;
    cout << creaturePositions[0][0] << endl;

    for (int i=0; i<creaturesOnBoard.size();i++) {

    }

}

Board::~Board() {
    for (int i=0; i<width; i++) {
        delete positionStatus[i];
    }
    delete positionStatus;
}

bool Board::checkIfPositionIsFree(Position pos) {
    if (getPositionStatus(pos) == 0) {
        return true;
    } else {
        return false;
    }
}

int Board::getPositionStatus(Position pos) { 
    return positionStatus[pos.getX()][pos.getY()];
}

void Board::setPositionStatus(Position pos, int status) {
    positionStatus[pos.getX()][pos.getY()] = status;
}

void Board::renderBoard() {
    // Construct row divider
    string rowDivider = "";
    for (int i=0; i<width; i++) {
        rowDivider += "#===="; 
    }
    rowDivider +="#\n";

    // construct empty positions
    string emptyPositionString = "#    ";
    string lineEnd = "#\n";
    
    for (int i=0; i<height; i++) {
        string line = "";
        for (int j=0; j<width; j++) {
            // TODO | check creature positions
            line += emptyPositionString;
        }
        line += lineEnd;

        cout << rowDivider;
        cout << line;
    }
    cout << rowDivider;
}

// #====#====#====#====# 
// #    # Gi #    #    #
// #====#====#====#====#
// #    # He #    #    #
// #====#====#====#====# 
// #    #    #    #    #
// #====#====#====#====#
// #    #    #    # Je #
// #====#====#====#====#