#include "storeSession.h"
#include "raylib.h"

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
    std::vector<Tool*> availableTools = {
        new BasicSword(),
        new HighQualitySword(),
        new WarriorSword(),
        new MagicianStick(),
        new LowArmor(),
        new MiddleArmor(),
        new HighArmor()
    };

    int choice = -1;        // 선택값 저장
    bool waitingForInput = true; // 입력 대기 플래그

    while (!WindowShouldClose() && waitingForInput) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 제목 출력
        DrawText("=== Equipment Store ===", 300, 50, 20, BLACK);

        // 장비 목록 렌더링
        for (size_t i = 0; i < availableTools.size(); ++i) {
            DrawText(
                (std::to_string(i + 1) + ". " + availableTools[i]->name +
                    " (Price: " + std::to_string(availableTools[i]->price) +
                    ", Power: " + std::to_string(availableTools[i]->power) +
                    ", Defense: " + std::to_string(availableTools[i]->defensePower) + ")").c_str(),
                100, 100 + (30 * i), 18, DARKGRAY
            );
        }

        // 'Back to Store Menu' 옵션 출력
        DrawText(
            (std::to_string(availableTools.size() + 1) + ". Back to Store Menu").c_str(),
            100, 100 + (30 * availableTools.size()), 18, RED
        );

        DrawText("Enter your choice in the console (1-N):", 100, 500, 20, BLUE);

        EndDrawing();

        // 콘솔에서 입력 대기
        std::cout << "Enter your choice (1-" << availableTools.size() + 1 << "): ";
        std::cin >> choice;

        // 입력값 검증 및 처리
        if (!std::cin.fail() && choice >= 1 && choice <= static_cast<int>(availableTools.size() + 1)) {
            waitingForInput = false; // 유효한 입력일 경우 대기 종료
        }
        else {
            std::cin.clear(); // 잘못된 입력 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    // 선택된 동작 처리
    if (choice >= 1 && choice <= static_cast<int>(availableTools.size())) {
        Tool* selectedTool = availableTools[choice - 1];
        if (player.money >= selectedTool->price) {
            player.money -= selectedTool->price;
            player.equipItem(new Tool(*selectedTool));
            std::cout << "You purchased: " << selectedTool->name
                << ". Remaining money: " << player.money << std::endl;
        }
        else {
            std::cout << "Not enough money to buy " << selectedTool->name << "!" << std::endl;
        }
    }
    else if (choice == static_cast<int>(availableTools.size() + 1)) {
        std::cout << "Returning to Store Menu..." << std::endl;
    }

    // 동적으로 할당된 Tool 객체 정리
    for (Tool* tool : availableTools) {
        delete tool;
    }
}
