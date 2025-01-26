#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include "Player.h"
using namespace std;

// Monster 기본 클래스
class Monster {
public:
    float hp;
    float mp;
    int power;
    int defense;

    Monster(float hp, float mp, int pw, int df);

    void attack();
    void specialAttack();
    void takeDamage(int damage);
};

// Slime 클래스
class Slime : public Monster {
public:
    Slime(float hp = 100, float mp = 100, int pw = 50, int df = 50);
};

// WildNoar 클래스
class WildNoar : public Monster {
public:
    WildNoar(float hp = 150, float mp = 150, int pw = 100, int df = 100);
};

// Boss 클래스
class Boss : public Monster {
public:
    Boss(float hp = 300, float mp = 300, int pw = 200, int df = 200);
};

#endif // MONSTER_H