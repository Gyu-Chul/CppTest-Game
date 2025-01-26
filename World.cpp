#include "World.h"
#include "DataSession.h"
#include "Player.h"

World::World(int n)
	: number(n) {}

int main() {
	System system; 
	
	while (player.presentSession != 0) 
	{ 
		system.executeSession(); 
	} 
	cout << "Game exited successfully." << endl; 
	return 0;

}

