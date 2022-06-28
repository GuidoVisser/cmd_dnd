#pragma once
#include <iostream>

using namespace std;

#include "dice.h"

class Action{
public:
    Action();
    bool checkActionPoints(int &actionPoints);

};

class TargetedAttackAction : public Action {
public:
    TargetedAttackAction();
    TargetedAttackAction(Die damageDie, int attackModifier);

    bool checkForHitAgainstArmorClass(int targetArmorClass);
    int calculateDamage();

    // bool targetInRange(int target_x, int target_y, int current_x, int current_y);
    // Creature getTargetCreature(int target_x, int target_y);

protected:
    Die attackDie = Die(20);
    Die damageDie;
    int attackModifier;

    // int hitRange;
};

// TODO : Implement later

class MoveAction : public Action {
public:
    MoveAction(int movementRange);
private:
    int movementRange;
};

class BonusAction : public Action {
public:
    BonusAction();
};

class Reaction : public Action {
public:
    Reaction();
};

class legendaryAction : public Action {
public:
    legendaryAction();
};

// class CanPerformAction {
// public:
//     virtual void perform(Action);
//     virtual void attack() = 0;
//     virtual void move() = 0;
//     virtual void bonusAction() = 0;
// }

// Human::perform(Action action) {
//     position.x 
//     action.damage
// }

// class Pop {
//     virtual int type() { 0; }
// };

// class ActionMan: Pop {
//     override int type() { 1; }
// };

// ActionMan man;
// Pop pop;

// man.type(); // 1
// pop.type(); // 0

// Pop *manneke = new ActionMan;
// manneke.type(); // 1