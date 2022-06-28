#pragma once
using namespace std;

#include "dice.h"
#include "action.h"
#include "position.h"
#include "board.h"

// class CanPerformActions {
// public:
//     CanPerformActions();

//     int performSingleTargetAttackAgainstArmorClass(TargetedAttackAction attackAction, int targetArmorClass);
// };

class Creature {
public:
    Creature(string creature_name, string creature_id);
    ~Creature();

    void takeDamage(int damage);
    void getKilled();
    void resetHealth();
    void performSingleTargetAttack(Creature &target);
    void performMovementAction(Position position);
    
    // Getters for read-only variables
    int getArmorClass();
    string getCreatureType();
    string getCapitalCreatureType();
    string getCreatureID();
    bool getAliveStatus();

    Position getBoardPosition();
    void moveTo(BoardTile* newPosition);

    friend class Board;

protected:
    // attributes
    int maxHealth;
    int armorClass;
    string creatureID;
    string creatureType = "creature";

    // state variables
    int health;
    bool isAlive;
    BoardTile* boardPosition = NULL;

    // actions
    TargetedAttackAction attackAction;
};

class Skeleton : public Creature{
public:
    Skeleton(string creature_name, string creatureID);
};

class Human : public Creature {
public:
    Human(string creature_name, string creatureID);
};
