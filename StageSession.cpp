#include "StageSession.h"
#include <iostream>
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

// 전투 스테이지
void StageSession::battleStage(int stageNumber) {
    cout << "\n--- Stage " << stageNumber << " ---\n";

    // 몬스터 생성
    Monster* monster = createMonster(stageNumber);

    // 전투 루프
    while (player.hp > 0 && monster->hp > 0) {
        // 플레이어의 턴
        cout << "\nPlayer's Turn:\n";
        cout << "1. Basic Attack\n2. Special Attack\n3. Use Healing Potion\n4. Use Mana Potion\n5. Run\nChoose an action: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // 기본 공격
            player.attack(*monster);
            break;
        }
        case 2: {
            // 특수 공격
            player.mpAttack(*monster);
            break;
        }
        case 3:
            // 힐링 포션 사용
            player.useHealingPotion();
            break;
        case 4:
            // 마나 포션 사용
            player.useManaPotion();
            break;
        case 5:
            // 도망
            cout << "You ran away from the battle!\n";
            delete monster; // 메모리 해제
            player.presentSession = 2; // General Session으로 복귀
            return;
        default:
            cout << "Invalid choice! Please choose again.\n";
            continue;
        }

        // 몬스터가 패배한 경우
        if (monster->hp <= 0) {
            cout << "\nThe monster has been defeated!\n";
            break;
        }

        // 몬스터의 턴
        cout << "\nMonster's Turn:\n";
        if (monster->mp >= 30) {
            monster->specialAttack();
        }
        else {
            monster->attack();
        }

        // 플레이어가 패배한 경우
        if (player.hp <= 0) {
            cout << "\nYou have been defeated!\n";
            break;
        }

        // 현재 상태 출력
        cout << "\n[Current Status]\n";
        cout << "Player HP: " << player.hp << "\nPlayer MP: " << player.mp << endl;
        cout << "Monster HP: " << monster->hp << "\nMonster MP: " << monster->mp << endl;
    }

    // 스테이지 클리어 메시지
    if (player.hp > 0 && monster->hp <= 0) {
        cout << "\nYou cleared Stage " << stageNumber << "!\n";

        // 경험치 보상
        player.exp += stageNumber * 10;
        cout << "You earned " << stageNumber * 10 << " experience points.\n";

        // 돈 보상
        player.money += 50; // 고정된 금액으로 보상
        cout << "You earned 50 gold. Total Money: " << player.money << " gold.\n";

        // 레벨 업 처리
        if (player.exp >= 100) {
            player.level++;
            player.exp -= 100;
            cout << "Congratulations! You leveled up to Level " << player.level << "!\n";
        }
    }


    delete monster; // 몬스터 객체 메모리 해제

    // 스테이지 종료 후 General Session으로 복귀
    player.presentSession = 2; // General Session 세션 값
    cout << "Returning to General Session...\n";
}
