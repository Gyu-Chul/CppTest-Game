#include "Player.h"

Player::Player(int id, int exp, int money, int level, int mst, int pss, float hp, float mp)
    : id(id), exp(exp), money(money), level(level), maxStage(mst), presentSession(pss), hp(hp), mp(mp) {
    // 인벤토리 초기화
    inventory[0] = new HealingPotion(0, 50, 0.5f);
    inventory[1] = new ManaPotion(0, 30, 0.3f);
}


void Player::attack() {
    cout << id << " attacks the enemy!" << endl;
}

void Player::defense() {
    cout << id << " defends!" << endl;
}

void Player::runout() {
    cout << id << " runs away!" << endl;
}

void Player::mpAttack() {
    cout << id << " uses a Special attack!" << endl;
}

void Player::usingItem() {
    cout << id << " uses an item." << endl;
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
        std::cout << i << ": " << item->name
            << " (Power: " << item->power
            << ", Defense: " << item->defensePower
            << ")" << std::endl;
    }
}



// 힐링 포션 사용
void Player::useHealingPotion() {
    inventory[0]->useItem();
}

// 마나 포션 사용
void Player::useManaPotion() {
    inventory[1]->useItem();
}

// 인벤토리 출력
void Player::showInventory() const {
    cout << "Inventory:" << endl;
    cout << "Healing Potions: " << inventory[0]->number << endl;
    cout << "Mana Potions: " << inventory[1]->number << endl;
}
