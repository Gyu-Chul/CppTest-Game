#include "Item.h"

Item::Item(int n, int p, float dp) : number(n), price(p), dropPercent(dp) {}

void Item::addItem() {
    number++;
}

void Item::useItem() {
    if (number > 0) {
        number--;
        cout << "Item used. Remaining: " << number << endl;
    }
    else {
        cout << "No item left to use!" << endl;
    }
}

// HealingPotion 구현
HealingPotion::HealingPotion(int n, int p, float dp) : Item(n, p, dp) {}

void HealingPotion::useItem() {
    if (number > 0) {
        number--;
        cout << "Healing potion used! Remaining: " << number << endl;
    }
    else {
        cout << "No healing potion left!" << endl;
    }
}

// ManaPotion 구현
ManaPotion::ManaPotion(int n, int p, float dp) : Item(n, p, dp) {}

void ManaPotion::useItem() {
    if (number > 0) {
        number--;
        cout << "Mana potion used! Remaining: " << number << endl;
    }
    else {
        cout << "No mana potion left!" << endl;
    }
}
