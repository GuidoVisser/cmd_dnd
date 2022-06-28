#include "action.h"

Action::Action() { }

bool Action::checkActionPoints(int &actionPoints) { 
    if (actionPoints > 0) {
        return true;
    } else {
        return false;
    }
};

// ###################################################

TargetedAttackAction::TargetedAttackAction() { }

TargetedAttackAction::TargetedAttackAction(Die damageDie, int attackModifier): damageDie(damageDie), attackModifier(attackModifier) { }

bool TargetedAttackAction::checkForHitAgainstArmorClass(int targetArmorClass) {
    int attackRoll = attackDie.roll() + attackModifier;

    return (attackRoll >= targetArmorClass);
}

int TargetedAttackAction::calculateDamage() {
    int damage = damageDie.roll() + attackModifier;

    return damage;
}

// void TargetedAttackAction::performAction(Creature &target) {
//     bool attackHits = checkForHitAgainstArmorClass(target.getArmorClass());

//     if (attackHits) {
//         int damage = calculateDamage();
//         target.takeDamage(damage);
//     }
// }