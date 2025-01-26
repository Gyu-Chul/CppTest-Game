#include "StageSession.h"
#include <iostream>
#include "raylib.h"
using namespace std;

// 스테이지에 따라 몬스터 생성
Monster* StageSession::createMonster(int stageNumber) {
    if (stageNumber == 1) {
        return new Slime(50.0f, 10.0f, 5, 2); // Slime: 체력, 마나, 공격력, 방어력
    }
    else if (stageNumber == 2) {
        return new WildNoar(100.0f, 20.0f, 10, 5); // WildNoar
    }
    else if (stageNumber == 3) {
        return new Boss(200.0f, 50.0f, 20, 10); // Boss
    }
    else {
        cout << "Invalid stage number. Defaulting to Slime." << endl;
        return new Slime(50.0f, 10.0f, 5, 2);
    }
}

void StageSession::battleStage(int stageNumber) {
    // 스테이지 시작 메시지
    std::cout << "\n--- Stage " << stageNumber << " ---\n";

    // 몬스터 생성
    Monster* monster = createMonster(stageNumber);

    // 전투 루프
    bool waitingForInput = true; // 입력 대기 플래그
    while (!WindowShouldClose() && player.hp > 0 && monster->hp > 0) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 스테이지 정보 출력
        DrawText(("--- Stage " + std::to_string(stageNumber) + " ---").c_str(), 300, 50, 20, BLACK);

        // 플레이어와 몬스터 상태 출력
        DrawText(("Player HP: " + std::to_string(player.hp)).c_str(), 50, 150, 20, DARKGREEN);
        DrawText(("Player MP: " + std::to_string(player.mp)).c_str(), 50, 180, 20, DARKGREEN);
        DrawText(("Monster HP: " + std::to_string(monster->hp)).c_str(), 50, 250, 20, RED);
        DrawText(("Monster MP: " + std::to_string(monster->mp)).c_str(), 50, 280, 20, RED);

        // 행동 선택 출력
        DrawText("1. Basic Attack", 50, 350, 20, DARKGRAY);
        DrawText("2. Special Attack", 50, 380, 20, DARKGRAY);
        DrawText("3. Use Healing Potion", 50, 410, 20, DARKGRAY);
        DrawText("4. Use Mana Potion", 50, 440, 20, DARKGRAY);
        DrawText("5. Run", 50, 470, 20, RED);

        DrawText("Enter your choice in the console (1-5):", 50, 520, 20, BLUE);

        EndDrawing();

        // 콘솔에서 사용자 입력 대기
        int choice = -1;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        // 입력값 처리
        if (choice >= 1 && choice <= 5) {
            waitingForInput = false;
        }
        else {
            std::cin.clear(); // 잘못된 입력 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
            std::cout << "Invalid choice! Please try again.\n";
            continue;
        }

        // 선택에 따라 동작 실행
        switch (choice) {
        case 1: // 기본 공격
            player.attack(*monster);
            break;
        case 2: // 특수 공격
            player.mpAttack(*monster);
            break;
        case 3: // 힐링 포션 사용
            player.useHealingPotion();
            break;
        case 4: // 마나 포션 사용
            player.useManaPotion();
            break;
        case 5: // 도망
            std::cout << "You ran away from the battle!\n";
            delete monster; // 메모리 해제
            player.presentSession = 2; // General Session으로 복귀
            return;
        default:
            std::cout << "Invalid choice! Please try again.\n";
            continue;
        }

        // 몬스터가 패배한 경우
        if (monster->hp <= 0) {
            std::cout << "\nThe monster has been defeated!\n";
            break;
        }

        // 몬스터의 턴
        std::cout << "\n\nMonster's Turn:\n";
        if (monster->mp >= 30) {
            monster->specialAttack();
        }
        else {
            monster->attack();
        }

        // 플레이어가 패배한 경우
        if (player.hp <= 0) {
            std::cout << "\nYou have been defeated!\n";
            break;
        }
    }

    // 스테이지 클리어 처리
    if (player.hp > 0 && monster->hp <= 0) {
        std::cout << "\n\nYou cleared Stage " << stageNumber << "!\n";

        // 경험치 보상
        player.exp += stageNumber * 10;
        std::cout << "You earned " << stageNumber * 10 << " experience points.\n";

        // 돈 보상
        player.money += 50; // 고정된 금액으로 보상
        std::cout << "You earned 50 gold. Total Money: " << player.money << " gold.\n";

        // 레벨 업 처리
        if (player.exp >= 100) {
            player.level++;
            player.exp -= 100;
            std::cout << "Congratulations! You leveled up to Level " << player.level << "!\n";
        }
        // maxStage 갱신
        if (stageNumber >= player.maxStage) {
            player.maxStage = stageNumber + 1; // 갱신
            cout << "\nNew record! Your max stage is now " << player.maxStage << "!\n\n";
        }
    }

    // 몬스터 객체 메모리 해제
    delete monster;

    // 스테이지 종료 후 General Session으로 복귀
    player.presentSession = 2;
    std::cout << "Returning to General Session...\n";
}
