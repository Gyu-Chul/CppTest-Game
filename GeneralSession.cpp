#include "GeneralSession.h"
#include "DataSession.h"
#include "Player.h"
#include <iostream>

using namespace std;

// �÷��̾� ��ü�� �ܺο��� ���޵ȴٰ� ����
extern Player player;

void GeneralSession::checkMyInfo() {
    // ���� ���
    cout << "\n\n=== My Info ===" << endl;
    cout << "Name: " << player.id << endl;
    cout << "Level: " << player.level << endl;
    cout << "Experience: " << player.exp << endl;
    cout << "Money: " << player.money << endl;
    cout << "Attack Power: " << player.getAttackPower() << endl;
    cout << "Defense Power: " << player.getDefensePower() << endl;
    cout << "================" << endl;
    player.showEquippedTools();
    player.showInventory();
    cout << "================" << endl;
    // �̰����� player ��ü�� �Ӽ��� ��� �����ϵ��� ����.. but ���� player ��ü�� �Ҿ����ϴ� �̿� ����
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
