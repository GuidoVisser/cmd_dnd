#include <string>
#include <iostream>
#include <random>

#include "creature.h"
#include "action.h"
#include "dice.h"

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

Creature::Creature(string creature_id, Position &startPosition): 
    creatureID(creature_id),
    position(startPosition) { }

void Creature::performSingleTargetAttack(Creature &target) {

    cout << creatureID << " attacks " << target.getCreatureID() << endl;

    bool attackHits = attackAction.checkForHitAgainstArmorClass(target.getArmorClass());

    if (attackHits) {
        int damage = attackAction.calculateDamage();
        cout << "The attack hits for " << damage << " damage!\n";
        target.takeDamage(damage);
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

void Creature::changePosition(int newX, int newY) {
    position.moveTo(newX, newY);
}

Position Creature::getPosition() {
    return position;
}

// Skeleton::Skeleton(int &numCreatures): Creature(numCreatures) {
//     attackDie = Die(20);
//     damageDie = Die(6);
//     creatureType = "skeleton";
//     creatureID = "S1";
//     attackModifier = 3;
//     armorClass = 11;
//     maxHealth = 10;
//     health = maxHealth;
// };