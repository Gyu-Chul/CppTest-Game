#include "World.h"
#include "DataSession.h"
#include "Player.h"
#include "raylib.h"


World::World(int n)
	: number(n) {}

int main() {
	// System ��ü ����
	System system; 

	// ���� ����
	
	while (player.presentSession != 0) 
	{ 
		cout << player.id << endl;


		system.executeSession(); 



	} 
	cout << "Game exited successfully." << endl; 
	return 0;

}

