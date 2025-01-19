#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    int price;
    float dropPercent;

    Item(int p, float dp);
};

class HealingPotion : public Item {
public:

    HealingPotion(int p, float dp);


    void healing();
};

class ManaPotion : public Item {
public:

    ManaPotion(int p, float dp);


    void manaHealing();
};

#endif 
