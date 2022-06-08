#include "creature_human.h"
#include "action.h"
#include "position.h"

Human::Human(string creatureID, Position startPosition): Creature(creatureID, startPosition) {
    creatureType = "human";
    armorClass = 14;
    maxHealth = 25;
    health = maxHealth;

    attackAction = TargetedAttackAction(Die(8), 4);
};