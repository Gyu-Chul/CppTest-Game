#include "GeneralSession.h"
#include "DataSession.h"
#include "Player.h"
#include "raylib.h"
#include <iostream>

using namespace std;

// �÷��̾� ��ü�� �ܺο��� ���޵ȴٰ� ����
extern Player player;

void GeneralSession::checkMyInfo() {
    bool waitingForInput = true; // 입력 대기 플래그

    while (!WindowShouldClose() && waitingForInput) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 플레이어 정보 출력
        DrawText("=== My Info ===", 300, 50, 20, BLACK);
        DrawText(("Name: " + player.id).c_str(), 300, 100, 20, DARKGRAY);
        DrawText(("Level: " + std::to_string(player.level)).c_str(), 300, 130, 20, DARKGRAY);
        DrawText(("Experience: " + std::to_string(player.exp)).c_str(), 300, 160, 20, DARKGRAY);
        DrawText(("Money: " + std::to_string(player.money)).c_str(), 300, 190, 20, DARKGREEN);
        DrawText(("Attack Power: " + std::to_string(player.getAttackPower())).c_str(), 300, 220, 20, DARKGRAY);
        DrawText(("Defense Power: " + std::to_string(player.getDefensePower())).c_str(), 300, 250, 20, DARKGRAY);

        DrawText("Input any number in the console (0-9) ", 300, 350, 20, BLUE);

        EndDrawing();

        // 콘솔 입력 대기 메시지 출력
        std::cout << "Input any number : ";
        std::string input;
        std::cin >> input; // 콘솔 입력 대기
        waitingForInput = false; // 입력이 들어오면 대기 종료
    }
}


void GeneralSession::goToShop() {
    // �������� �̵� (���� �� ����)
    player.presentSession = 3;
    cout << "You have entered the shop.\n" << endl;
}

void GeneralSession::enterDungeon() {
    // �������� �̵� (���� �� ����)
    player.presentSession = 4;
    cout << "You have entered the dungeon.\n" << endl;
}

void GeneralSession::logout() {
    // DB �ֽ�ȭ �� �α׾ƿ� ó��
    DataSession dataSession("datas.txt");
    const int playerToken = 1; // ��ū�� ����� ����
    dataSession.update(playerToken, "level", to_string(player.level));
    dataSession.update(playerToken, "exp", to_string(player.exp));
    dataSession.update(playerToken, "money", to_string(player.money));
    dataSession.update(playerToken, "presentstage", to_string(player.presentSession));
    cout << "Your progress has been saved. Logging out..." << endl;

    // ���� ����
    player.presentSession = 0;
}
