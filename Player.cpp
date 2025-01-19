#include "Player.h"


Player::Player(string name, int id, int exp, int money, int level, int prse, float hp, float mp, const array<int, 10>& items)
    : name(name), id(id), exp(exp), money(money), level(level), presentSession(prse), hp(hp), mp(mp), items(items) {}



void Player::attack() {
    cout << name << " attacks the enemy!" << endl;
}

void Player::defense() {
    cout << name << " defends!" << endl;
}

void Player::runout() {
    cout << name << " runs away!" << endl;
}

void Player::mpAttack() {
    cout << name << " uses a magic attack!" << endl;
}

void Player::usingItem() {
    cout << name << " uses an item." << endl;
}

void Player::buyItem() {
    cout << name << " buys an item." << endl;
}
