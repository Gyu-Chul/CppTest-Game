#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>
#include "Item.h"     
#include "Monster.h"
#include "Player.h"
#include "Tool.h"

class World {

public:

	int number;
	int playerCount = 0;

	World(int n);


	void login() {}

	//void register() {}

};

#endif