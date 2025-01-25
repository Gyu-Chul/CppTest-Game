#include "World.h"
#include "DataSession.h"
#include "Player.h"

World::World(int n)
	: number(n) {}

int main() {
	// System 객체 생성
	System system; 
	
	// 메인 루프
	
	while (player.presentSession != 0) { // presentSession == 0이면 종료 
		system.executeSession(); } cout << "Game exited successfully." << endl; return 0;


	return 0;

}

