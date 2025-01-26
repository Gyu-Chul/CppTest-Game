#include "Monster.h"


Monster::Monster(float hp, float mp, int pw, int df)
    : hp(hp), mp(mp), power(pw), defense(df) {}

void Monster::attack() {
    int damage = max(0, power - player.getDefensePower());
    player.takeDamage(damage);
    cout << "Monster attacks the player for " << damage << " damage!\n";
}

void Monster::specialAttack() {
    if (mp >= 30) {
        int damage = max(0, (power * 2) - player.getDefensePower());
        player.takeDamage(damage);
        mp -= 30;
        cout << "Monster uses a special attack for " << damage << " damage! Monster MP remaining: " << mp << "\n";
    }
    else {
        cout << "Monster does not have enough MP to use a special attack!\n";
    }
}



void Monster::takeDamage(int damage) {
    hp = max(0.0f, hp - damage);
    cout << "Monster takes " << damage << " damage. Current HP: " << hp << "\n";
}


Slime::Slime(float hp, float mp, int pw, int df)
    : Monster(hp, mp, pw, df) {}



WildNoar::WildNoar(float hp, float mp, int pw, int df)
    : Monster(hp, mp, pw, df) {}



Boss::Boss(float hp, float mp, int pw, int df)
    : Monster(hp, mp, pw, df) {}