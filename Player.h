#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <array>

using namespace std;

class Player {
public:
    string name;
    int id;
    int exp;
    int money;
    int level;
    int presentSession;
    float hp;
    float mp;
    array<int, 10> items;

    Player(string name, int id, int exp, int money, int level, int prse, float hp, float mp, const array<int, 10>& items);

    void attack();
    void defense();
    void runout();
    void mpAttack();
    void usingItem();
    void buyItem();
};

class Warrior : public Player {
public:
    array<int, 10> startingItems = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    Warrior(string name, int id, int exp, int money, int level, int prse, float hp, float mp, const array<int, 10>& items)
        : Player("test warrior", 00001, 0, 1000, 1, 1, 500, 500, startingItems) {}
};

class Magician : public Player {
public:
    Magician(string name, int id, int exp, int money, int level, int prse, float hp, float mp, const array<int, 10>& items)
        : Player(name, id, exp, money, level, prse, hp, mp, items) {}
};


#endif
