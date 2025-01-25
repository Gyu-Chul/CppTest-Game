#ifndef PLAYER_H
#define PLAYER_H

#include "Tool.h"
#include "Item.h"
#include <iostream>
#include <vector>

using namespace std;

class Player {
public:


    int id;
    int exp = 0;           // 경험치
    int level = 1;         // 레벨
    int money = 0;         // 돈
    int maxStage = 0;      // 최고로 클리어한 스테이지
    int presentSession = 1;// 현재 들어와있는 세션 위치
    float hp = 100.0f;     // 기본 HP
    float mp = 50.0f;      // 기본 MP

    int baseAttack = 10;   // 기본 공격력
    int baseDefense = 5;   // 기본 방어력

    vector<Tool*> equippedTools; // 장착된 모든 장비
    const size_t MAX_TOOLS = 5;  // 최대 장비 슬롯

    Item* inventory[2]; // 2칸짜리 아이템 배열 (0: HealingPotion, 1: ManaPotion)

    Player(); // 기본 생성자 선언

    Player(int id, int exp = 0, int money = 0, int level = 1, int mst = 0);

    void attack();
    void defense();
    void runout();
    void mpAttack();
    void usingItem();

    bool equipItem(Tool* item);       // 장비 착용
    bool unequipItem(size_t index);   // 장비 해제
    int getAttackPower() const;      // 총 공격력 계산
    int getDefensePower() const;     // 총 방어력 계산
    void showEquippedTools() const;  // 장착된 아이템 출력

    void useHealingPotion(); // 힐링 포션 사용
    void useManaPotion();    // 마나 포션 사용

    void showInventory() const; // 인벤토리 출력 (포션 개수 확인)
};

class Warrior : public Player {
public:
    Warrior(const string& name, int id)
        : Player(id) {}
};

class Magician : public Player {
public:
    Magician(const string& name, int id)
        : Player(id) {}
};


extern Player player; // 다른 파일에서 정의될 변수 선언

#endif // PLAYER_H
