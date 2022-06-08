#pragma once
using namespace std;
#include<random>

class Die {
public:
    Die();
    Die(int nFaces);
    
    int roll();
    int roll(int numberOfDice);
    int rollAdvantage();
    int rollDisadvantage();

private:
    uniform_int_distribution<int> _die;
};