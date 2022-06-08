#pragma once
using namespace std;

#include "creature.h"
#include "action.h"
#include "dice.h"
#include "position.h"

class Human : public Creature {
public:
    Human(string creatureID, Position startPosition);
};

// ##############################################################

// class HumanStandardAttackAction : public TargetedAttackAction {
// public:
//     HumanStandardAttackAction();
//     void performAction(Creature &target);
// };