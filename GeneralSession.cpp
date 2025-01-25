#include "GeneralSession.h"
#include "DataSession.h"
#include "Player.h"
#include <iostream>

using namespace std;

// 플레이어 객체는 외부에서 전달된다고 가정
extern Player player;

void GeneralSession::checkMyInfo() {
    // 예시 출력
    cout << "=== My Info ===" << endl;
    cout << "Name: " << player.name << endl;
    cout << "Level: " << player.level << endl;
    cout << "Experience: " << player.exp << endl;
    cout << "Money: " << player.money << endl;
    cout << "================" << endl;
    // 이곳에서 player 객체의 속성을 모두 노출하도록 구현.. but 아직 player 객체가 불안정하니 미완 보류
}

void GeneralSession::goToShop() {
    // 상점으로 이동 (세션 값 변경)
    player.presentSession = 3;
    cout << "You have entered the shop." << endl;
}

void GeneralSession::enterDungeon() {
    // 던전으로 이동 (세션 값 변경)
    player.presentSession = 4;
    cout << "You have entered the dungeon." << endl;
}

void GeneralSession::logout() {
    // DB 최신화 및 로그아웃 처리
    DataSession dataSession("datas.txt");
    const int playerToken = player.token; // 토큰은 상수로 가정
    dataSession.update(playerToken, "level", to_string(player.level));
    dataSession.update(playerToken, "exp", to_string(player.exp));
    dataSession.update(playerToken, "money", to_string(player.money));
    dataSession.update(playerToken, "presentstage", to_string(player.presentSession));
    cout << "Your progress has been saved. Logging out..." << endl;

    // 세션 종료
    player.presentSession = 0;
}
