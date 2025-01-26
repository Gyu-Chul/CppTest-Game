#include "storeSession.h"

// 플레이어 객체는 외부에서 전달된다고 가정
extern Player player;

void StoreSession::buyHealingPotion() {
    const int healingPotionPrice = 50;
    if (player.money >= healingPotionPrice) {
        player.money -= healingPotionPrice;
        player.inventory[0]->addItem();
        cout << "Healing potion purchased! Total: " << player.inventory[0]->number
            << ". Remaining money: " << player.money << endl;
    }
    else {
        cout << "Not enough money to buy a Healing Potion!" << endl;
    }
}

void StoreSession::buyManaPotion() {
    const int manaPotionPrice = 30;
    if (player.money >= manaPotionPrice) {
        player.money -= manaPotionPrice;
        player.inventory[1]->addItem();
        cout << "Mana potion purchased! Total: " << player.inventory[1]->number
            << ". Remaining money: " << player.money << endl;
    }
    else {
        cout << "Not enough money to buy a Mana Potion!" << endl;
    }
}

void StoreSession::sellHealingPotion() {
    const int healingPotionSellPrice = 25;
    if (player.inventory[0]->number > 0) {
        player.inventory[0]->useItem();
        player.money += healingPotionSellPrice;
        cout << "Healing potion sold! Remaining potions: " << player.inventory[0]->number
            << ". Money earned: " << healingPotionSellPrice
            << ". Total money: " << player.money << endl;
    }
    else {
        cout << "You don't have any Healing Potions to sell!" << endl;
    }
}

void StoreSession::sellManaPotion() {
    const int manaPotionSellPrice = 15;
    if (player.inventory[1]->number > 0) {
        player.inventory[1]->useItem();
        player.money += manaPotionSellPrice;
        cout << "Mana potion sold! Remaining potions: " << player.inventory[1]->number
            << ". Money earned: " << manaPotionSellPrice
            << ". Total money: " << player.money << endl;
    }
    else {
        cout << "You don't have any Mana Potions to sell!" << endl;
    }
}


void StoreSession::showAndBuyEquipment() {
    vector<Tool*> availableTools = {
        new BasicSword(),
        new HighQualitySword(),
        new WarriorSword(),
        new MagicianStick(),
        new LowArmor(),
        new MiddleArmor(),
        new HighArmor()
    };

    int choice;
    do {
        cout << "\n\n=== Equipment Store ===" << endl;
        for (size_t i = 0; i < availableTools.size(); ++i) {
            cout << i + 1 << ". " << availableTools[i]->name
                << " (Price: " << availableTools[i]->price
                << ", Power: " << availableTools[i]->power
                << ", Defense: " << availableTools[i]->defensePower << ")" << endl;
        }
        cout << availableTools.size() + 1 << ". Back to Store Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= availableTools.size()) {
            Tool* selectedTool = availableTools[choice - 1];
            if (player.money >= selectedTool->price) {
                player.money -= selectedTool->price;
                player.equipItem(new Tool(*selectedTool));
                cout << "You purchased: " << selectedTool->name
                    << ". Remaining money: " << player.money << endl;
            }
            else {
                cout << "Not enough money to buy " << selectedTool->name << "!" << endl;
            }
        }
        else if (choice != availableTools.size() + 1) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != availableTools.size() + 1);

    // Cleanup dynamically allocated tools
    for (Tool* tool : availableTools) {
        delete tool;
    }
}


void StoreSession::sellEquippedTool() {
    // 현재 장착된 장비 보여줌
    player.showEquippedTools();

    if (player.equippedTools.empty()) {
        cout << "You have no equipped items to sell!" << endl;
        return;
    }

    // 장비 선택
    size_t choice;
    cout << "Enter the index of the item you want to sell (or 0 to cancel): ";
    cin >> choice;

    // 선택한 장비 처리
    if (choice == 0) {
        cout << "Canceled selling an item." << endl;
        return;
    }

    if (choice > 0 && choice <= player.equippedTools.size()) {
        Tool* toolToSell = player.equippedTools[choice - 1];
        int sellPrice = toolToSell->price / 2; // 판매가는 가격의 절반

        // 장비 해제
        if (player.unequipItem(choice - 1)) {
            player.money += sellPrice;
            cout << "You sold " << toolToSell->name << " for " << sellPrice
                << " gold. Current money: " << player.money << endl;
            delete toolToSell; // 동적 메모리 해제
        }
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
    }
}
