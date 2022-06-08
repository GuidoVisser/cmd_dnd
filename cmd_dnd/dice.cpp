#include <random>
#include <ctime>
#include <iostream>

#include "dice.h"

using namespace std;

default_random_engine randomGenerator(time(NULL));

Die::Die() {
    _die = uniform_int_distribution<int>(1, 20);    
}

Die::Die(int nFaces) {
    _die = uniform_int_distribution<int>(1, nFaces);
}

int Die::roll() {
    int numberRolled = _die(randomGenerator);
    
    return numberRolled;
}

int Die::roll(int numberOfDice) {
    int numberRolled = 0;
    for (int i=0; i<numberOfDice; i++) {
        numberRolled += _die(randomGenerator);
    }

    return numberRolled;
}

int Die::rollAdvantage() {
    int firstRoll = roll();
    int secondRoll = roll();

    if (firstRoll >= secondRoll) {
        return firstRoll;
    } else {
        return secondRoll;
    }
}

int Die::rollDisadvantage() {
    int firstRoll = roll();
    int secondRoll = roll();

    if (firstRoll <= secondRoll) {
        return firstRoll;
    } else {
        return secondRoll;
    }
}