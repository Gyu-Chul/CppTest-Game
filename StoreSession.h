#ifndef STORE_SESSION_H
#define STORE_SESSION_H

#include "Player.h"
#include <iostream>

class StoreSession {
public:
	void buyHealingPotion();
	void buyManaPotion();
	void sellHealingPotion();
	void sellManaPotion();
	void showAndBuyEquipment();
	void sellEquippedTool();
};

#endif // STORE_SESSION_H
