#pragma once
using namespace std;

#include "dice.h"
#include "action.h"
#include "position.h"

// class CanPerformActions {
// public:
//     CanPerformActions();

//     int performSingleTargetAttackAgainstArmorClass(TargetedAttackAction attackAction, int targetArmorClass);
// };

class Creature {
public:
    Creature(string creature_id, Position &startPosition);

    void takeDamage(int damage);
    void getKilled();
    void resetHealth();
    void performSingleTargetAttack(Creature &target);
    
    // Getters for read-only variables
    int getArmorClass();
    string getCreatureType();
    string getCapitalCreatureType();
    string getCreatureID();
    bool getAliveStatus();

    void changePosition(int newX, int newY);
    Position getPosition();

protected:
    int health;
    int maxHealth;
    int armorClass;
    string creatureType = "creature";
    string creatureID;
    bool isAlive;
    TargetedAttackAction attackAction;
    Position position;
};

class Skeleton : public Creature{
public:
    Skeleton(int &numCreatures);
};
