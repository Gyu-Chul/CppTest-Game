#include "Item.h"
#include <iostream>

Item::Item(int p, float dp) : price(p), dropPercent(dp) {}


HealingPotion::HealingPotion(int p, float dp) : Item(p, dp) {}

void HealingPotion::healing() {
    std::cout << "Healing potion used!" << std::endl;
}

ManaPotion::ManaPotion(int p, float dp) : Item(p, dp) {}

void ManaPotion::manaHealing() {
    std::cout << "Mana potion used!" << std::endl;
}
