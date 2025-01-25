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



//스토어에 들어오면서 DB에서 현재 인벤토리 정보 얻어와서 객체 생성
//스토어 클래스의 역할은 그냥 버튼 입력 받아서 인벤토리 함수의 동적 배열인 벡터를 수정해주는 것 뿐일듯

