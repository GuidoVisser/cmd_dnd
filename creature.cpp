#include <string>
#include <iostream>
#include <random>

#include "creature.h"
#include "action.h"
#include "dice.h"
#include "board.h"

using namespace std;

// CanPerformActions::CanPerformActions() {};

// int CanPerformActions::performSingleTargetAttackAgainstArmorClass(TargetedAttackAction attackAction, int targetArmorClass) {
//     bool attackHits = attackAction.checkForHitAgainstArmorClass(targetArmorClass);
//     if (attackHits) {
//         return attackAction.calculateDamage();
//     } else {
//         return 0;
//     }
// }

Creature::Creature(string creature_name, string creature_id) : creatureID(creature_id) { }

void Creature::performSingleTargetAttack(Creature &target) {

    cout << creatureID << " attacks " << target.getCreatureID() << endl;

    bool attackHits = attackAction.checkForHitAgainstArmorClass(target.getArmorClass());

    if (attackHits) {
        int damage = attackAction.calculateDamage();
        cout << "The attack hits for " << damage << " damage!\n";
        target.takeDamage(damage);
    }
}

Creature::~Creature() {
    if (boardPosition != NULL) {
        if (boardPosition->creatureOnPosition == this) {
            boardPosition->creatureOnPosition = NULL;
        }
    }
}

void Creature::takeDamage(int damage) {
    health -= damage;

    if (health <= 0) {
        getKilled();
    }

    return;
}

void Creature::getKilled () {

    cout << creatureID << " dies!\n";
    isAlive = false;

    boardPosition->creatureOnPosition = NULL;

    return;
}

void Creature::resetHealth() {
    health = maxHealth;

    return;
}

int Creature::getArmorClass() {
    return armorClass;
}

string Creature::getCreatureType() {
    return creatureType;
}

string Creature::getCapitalCreatureType() {
    string capitalCreatureType = creatureType;
    capitalCreatureType[0] = toupper(capitalCreatureType[0]);

    return capitalCreatureType;
}

string Creature::getCreatureID() {
    return creatureID;
}

bool Creature::getAliveStatus() {
    return isAlive;
}

Position Creature::getBoardPosition() {
    if (boardPosition != NULL) {
        return boardPosition->getPosition();
    } else {
        return Position(-1, -1);
    }
}

void Creature::moveTo(BoardTile* newPosition) {
    
    if (newPosition->isAvailableForCreature()) {
        boardPosition->creatureOnPosition = NULL;
        newPosition->creatureOnPosition = this;

        boardPosition = newPosition;
    }
}

//######################################

Human::Human(string creature_name, string creatureID): Creature(creature_name, creatureID) {
    creatureType = "human";
    armorClass = 14;
    maxHealth = 25;
    health = maxHealth;

    attackAction = TargetedAttackAction(Die(8), 4);
};

Skeleton::Skeleton(string creature_name, string creatureID): Creature(creature_name, creatureID) {
    creatureType = "skeleton";
    armorClass = 11;
    maxHealth = 10;
    health = maxHealth;

    attackAction = TargetedAttackAction(Die(6), 3);
}
