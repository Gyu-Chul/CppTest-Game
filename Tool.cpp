#include "Tool.h"

BasicSword::BasicSword() : Tool("Basic Sword", 50, 0, 3) {}

HighQualitySword::HighQualitySword() : Tool("High Quality Sword", 150, 0, 10) {}

WarriorSword::WarriorSword() : Tool("Warrior Sword", 450, 0, 45) {}

MagicianStick::MagicianStick() : Tool("Magician Stick", 450, 0, 5) {}

LowArmor::LowArmor() : Tool("Low Armor", 100, 2, 0) {}

MiddleArmor::MiddleArmor() : Tool("Middle Armor", 250, 5, 0) {}

HighArmor::HighArmor() : Tool("High Armor", 650, 12, 0) {}
