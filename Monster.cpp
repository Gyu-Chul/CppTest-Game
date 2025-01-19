#include "Monster.h"


Monster::Monster(float hp, float mp, int pw, int df)
    : hp(hp), mp(mp), power(pw), defense(df) {}

void Monster::attack() {
    cout << "Monster attack!" << endl;
}

void Monster::defensing() {
    cout << "Monster defensed!" << endl;
}

void Monster::specialAttack() {
    cout << "Monster uses Special Attack!" << endl;
}





Slime::Slime(float hp, float mp, int pw, int df)
    : Monster(hp, mp, pw, df) {}



WildNoar::WildNoar(float hp, float mp, int pw, int df)
    : Monster(hp, mp, pw, df) {}



Boss::Boss(float hp, float mp, int pw, int df)
    : Monster(hp, mp, pw, df) {}
