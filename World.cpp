#include "World.h"
#include "DataSession.h"

World::World(int n)
	: number(n) {}

<<<<<<< HEAD
int main() {

	World testWorld(1);
	BasicSword basicSword;
	HighQualitySword highQualitySword;
	WarriorSword warriorSword;
	MagicianStick magicianStick;
	LowArmor lowArmor;
	MiddleArmor middleArmor;
	HighArmor highArmor;
	HealingPotion hp(20, 2);
	ManaPotion mp(20, 2);

	array<int, 10> dummyItems = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Warrior warrior("Aragon", 1, 0, 100, 1, 0, 100.0f, 50.0f, dummyItems);
	warrior.attack();
	warrior.usingItem();

	Slime slime;
	slime.attack();
	slime.defensing();

	System system;

	system.clear();
	system.fail();

	cout << "Basic Sword - Price: " << basicSword.price << ", Defense Power: " << basicSword.defensePower << ", Power: " << basicSword.power << endl;
	cout << "High Quality Sword - Price: " << highQualitySword.price << ", Defense Power: " << highQualitySword.defensePower << ", Power: " << highQualitySword.power << endl;
	cout << "Warrior Sword - Price: " << warriorSword.price << ", Defense Power: " << warriorSword.defensePower << ", Power: " << warriorSword.power << endl;
	cout << "Magician Stick - Price: " << magicianStick.price << ", Defense Power: " << magicianStick.defensePower << ", Power: " << magicianStick.power << endl;

	cout << "Low Armor - Price: " << lowArmor.price << ", Defense Power: " << lowArmor.defensePower << ", Power: " << lowArmor.power << endl;
	cout << "Middle Armor - Price: " << middleArmor.price << ", Defense Power: " << middleArmor.defensePower << ", Power: " << middleArmor.power << endl;
	cout << "High Armor - Price: " << highArmor.price << ", Defense Power: " << highArmor.defensePower << ", Power: " << highArmor.power << endl;

	DataSession ("datas.txt");


	session.create("minchul2", "12345");

	// Read
	std::cout << "User ID: " << session.read(1, "userId") << std::endl;
	std::cout << "Token : " << session.read(1, "token") << std::endl;

	// Update
	session.update(1, "level", "10");
	std::cout << "Updated Level: " << session.read(1, "level") << std::endl;

	// Delete
	//session.Delete(3);

	return 0;


}
=======
//int main() {
//
//	World testWorld(1);
//	BasicSword basicSword;
//	HighQualitySword highQualitySword;
//	WarriorSword warriorSword;
//	MagicianStick magicianStick;
//	LowArmor lowArmor;
//	MiddleArmor middleArmor;
//	HighArmor highArmor;
//	HealingPotion hp(20, 2);
//	ManaPotion mp(20, 2);
//
//	array<int, 10> dummyItems = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	Warrior warrior("Aragon", 1, 0, 100, 1, 0, 100.0f, 50.0f, dummyItems);
//	warrior.attack();
//	warrior.usingItem();
//
//	Slime slime;
//	slime.attack();
//	slime.defensing();
//
//	System system;
//
//	system.clear();
//	system.fail();
//
//	cout << "Basic Sword - Price: " << basicSword.price << ", Defense Power: " << basicSword.defensePower << ", Power: " << basicSword.power << endl;
//	cout << "High Quality Sword - Price: " << highQualitySword.price << ", Defense Power: " << highQualitySword.defensePower << ", Power: " << highQualitySword.power << endl;
//	cout << "Warrior Sword - Price: " << warriorSword.price << ", Defense Power: " << warriorSword.defensePower << ", Power: " << warriorSword.power << endl;
//	cout << "Magician Stick - Price: " << magicianStick.price << ", Defense Power: " << magicianStick.defensePower << ", Power: " << magicianStick.power << endl;
//
//	cout << "Low Armor - Price: " << lowArmor.price << ", Defense Power: " << lowArmor.defensePower << ", Power: " << lowArmor.power << endl;
//	cout << "Middle Armor - Price: " << middleArmor.price << ", Defense Power: " << middleArmor.defensePower << ", Power: " << middleArmor.power << endl;
//	cout << "High Armor - Price: " << highArmor.price << ", Defense Power: " << highArmor.defensePower << ", Power: " << highArmor.power << endl;
//}
>>>>>>> aa26b0a6761aa1d8f9959b4d9c5f6c853d847f02
