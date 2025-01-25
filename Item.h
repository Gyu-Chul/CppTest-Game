#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item {
public:
    int number;        // 아이템 개수
    int price;         // 가격
    float dropPercent; // 드랍 확률

    Item(int n, int p, float dp);

    // 아이템 추가
    void addItem();

    // 아이템 사용
    virtual void useItem();
};

class HealingPotion : public Item {
public:
    HealingPotion(int n, int p, float dp);

    void useItem() override; // 힐링 포션 사용
};

class ManaPotion : public Item {
public:
    ManaPotion(int n, int p, float dp);

    void useItem() override; // 마나 포션 사용
};

#endif // ITEM_H
