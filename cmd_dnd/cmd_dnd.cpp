#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <vector>

#include "creature.h"
#include "creature_human.h"
#include "action.h"
#include "board.h"

using namespace std;

int getNumHumans();
int getNumSkeletons();
void checkUserInput(int &nHumans, int &nSkeletons);
void startMessage(int nHumans, int nSkeletons);
void simulateBattle(Creature &creature1, Creature &creature2);

int main() {   
    

    string humanID = "Henry";
    string human2ID = "Jeff";
    string skeletonID = "Gipsy";

    // // Get user input
    // int nHumans = getNumHumans();
    // int nSkeletons = getNumSkeletons();

    // checkUserInput(nHumans, nSkeletons);

    // Define fighters
    Human henry = Human(humanID, Position(1, 2));
    Human jeff = Human(human2ID, Position(3, 3));


    // Skeleton skeletons(nSkeletons);

    // Simulate the battle
    // startMessage(nHumans, nSkeletons);
    simulateBattle(henry, jeff);

    cout << "Battle ended\n";

    vector<Creature> creatures;
    creatures.push_back(henry);
    creatures.push_back(jeff);


    Board board = Board(4,4, creatures);
    board.renderBoard();
}

int getNumHumans() {
    int nHumans;
    cout << "Please enter how many humans will fight: \n";
    cin >> nHumans;
    return nHumans;
}

int getNumSkeletons() {
    unsigned int nSkeletons;
    cout << "Please enter how many skeletons there are: \n";
    cin >> nSkeletons;
    return nSkeletons;
}

void checkUserInput(int &nHumans, int &nSkeletons) {
    /*
        Check if the input of the user is positive
    */ 
    if ((nSkeletons <= 0) || (nHumans <= 0)) {
        cout << "Please give me some real numbers! you nippletassel!\n";
        
        nHumans = getNumHumans();
        nSkeletons = getNumSkeletons();

        checkUserInput(nHumans, nSkeletons);
    }
}

void startMessage(int nHumans, int nSkeletons) {
    cout << nSkeletons << " skeletons vs. " << nHumans << " humans\nLet the fight begin!\n";
}

void simulateBattle(Creature &creature1, Creature &creature2) {
    
    int turnCount = 0;
    bool battleOngoing = true;

    while (battleOngoing) {

        if (turnCount % 2 == 0) {
            cout << "==============================\n" << creature1.getCreatureID() <<"'s Turn\n==============================\n";
            creature1.performSingleTargetAttack(creature2);
            cout << "==============================\n\n";

            if (!creature2.getAliveStatus()) {
                cout << creature1.getCreatureID() << " Wins!\n";
                battleOngoing = false;
            }

        } else {
            // creature2's turn
            cout << "==============================\n" << creature2.getCreatureType() <<"s' Turn\n==============================\n";
            creature2.performSingleTargetAttack(creature1);
            cout << "==============================\n\n";

            if (!creature1.getAliveStatus()) {
                cout << creature2.getCreatureID() << " Wins!\n";
                battleOngoing = false;
            }
        }
        turnCount++;
    }
}

