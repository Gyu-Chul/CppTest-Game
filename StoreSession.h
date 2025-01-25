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
};

#endif // STORE_SESSION_H
