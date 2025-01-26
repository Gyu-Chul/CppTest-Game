#include "Player.h"

//기본 생성자로 player 객체 만드는 경우: 즉 매개변수 없이 고정값으로 만들 때 활용되는 생성자
//Player::Player()
//    : id("basicID"), exp(0), money(0), level(1), maxStage(0), presentSession(1), hp(100.0f), mp(50.0f),
//    baseAttack(10), baseDefense(5), inventory{ nullptr, nullptr } {
//    // 기본 생성자 내부 구현
//    inventory[0] = new HealingPotion(0, 50, 0.5f);
//    inventory[1] = new ManaPotion(0, 30, 0.3f);
//}

// 우리는 DB에 있는 해당 id, exp 등등을 불러와서 그것에 맞게 생성하기 위한 생성자
Player::Player(string id, int exp, int money, int level, int mst)
    : id(id), exp(exp), money(money), level(level), maxStage(mst) {
    // 인벤토리 초기화
    inventory[0] = new HealingPotion(0, 50, 0.5f);
    inventory[1] = new ManaPotion(0, 30, 0.3f);
}

// 이 객체는 프로그램 시작 전에 이미 객체로 만들어져 있음.
// 전역변수를 일단 생성해놓고 로그인 하면 이것의 데이터를 갱신하는 형태
Player player("DefaultName", 1, 1, 1, 1);



void Player::attack(Monster& monster) {
    int damage = max(0, getAttackPower() - monster.defense);
    monster.takeDamage(damage);
    cout << id << " attacks the monster for " << damage << " damage!\n";
}


void Player::mpAttack(Monster& monster) {
    if (mp >= 20) {
        int damage = max(0, (getAttackPower() * 2) - monster.defense);
        monster.takeDamage(damage);
        mp -= 20;
        cout << id << " uses a special attack for " << damage << " damage! MP remaining: " << mp << "\n";
    }
    else {
        cout << "Not enough MP to use a special attack!\n";
    }
}


void Player::defense() {
    cout << id << " defends and reduces incoming damage!\n";
    baseDefense += 10; // Temporary defense boost for this turn
}

void Player::runout() {
    cout << id << " runs away from the battle!\n";
}


void Player::useHealingPotion() {
    if (inventory[0]->number > 0) {
        hp = min(100.0f, hp + 50.0f); // Heal up to maximum HP
        inventory[0]->useItem();
        cout << id << " uses a healing potion. Current HP: " << hp << "\n";
    }
    else {
        cout << "No healing potions left!\n";
    }
}

void Player::useManaPotion() {
    if (inventory[1]->number > 0) {
        mp = min(50.0f, mp + 30.0f); // Restore up to maximum MP
        inventory[1]->useItem();
        cout << id << " uses a mana potion. Current MP: " << mp << "\n";
    }
    else {
        cout << "No mana potions left!\n";
    }
}

// 인벤토리 출력
void Player::showInventory() const {
    cout << "Inventory:" << endl;
    cout << "    Healing Potions: " << inventory[0]->number << endl;
    cout << "    Mana Potions: " << inventory[1]->number << endl;
}


void Player::takeDamage(int damage) {
    hp = max(0.0f, hp - damage);
    cout << id << " takes " << damage << " damage. Current HP: " << hp << "\n";
}


// 장비 착용
bool Player::equipItem(Tool* tool) {
    if (equippedTools.size() < MAX_TOOLS) {
        equippedTools.push_back(tool);
        return true;
    }
    else {
        std::cout << "Cannot equip more items. Inventory is full!" << std::endl;
        return false;
    }
}

// 장비 해제
bool Player::unequipItem(size_t index) {
    if (index < equippedTools.size()) {
        equippedTools.erase(equippedTools.begin() + index);
        return true;
    }
    else {
        std::cout << "Invalid item index!" << std::endl;
        return false;
    }
}

// 총 공격력 계산
int Player::getAttackPower() const {
    int totalPower = baseAttack;
    for (const auto& item : equippedTools) {
        totalPower += item->power;
    }
    return totalPower;
}

// 총 방어력 계산
int Player::getDefensePower() const {
    int totalDefense = baseDefense;
    for (const auto& item : equippedTools) {
        totalDefense += item->defensePower;
    }
    return totalDefense;
}

// 장착된 장비 확인
void Player::showEquippedTools() const {
    std::cout << "Equipped Items:" << std::endl;
    for (size_t i = 0; i < equippedTools.size(); ++i) {
        const auto& item = equippedTools[i];
        std::cout << "    " << i+1 << ": " << item->name
            << " (Power: " << item->power
            << ", Defense: " << item->defensePower
            << ")" << std::endl;
    }
}



