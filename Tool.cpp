#include "Tool.h"

BasicSword::BasicSword() : Tool(1, "Basic Sword", 50, 0, 3) {}

HighQualitySword::HighQualitySword() : Tool(2, "High Quality Sword", 150, 0, 10) {}

WarriorSword::WarriorSword() : Tool(3, "Warrior Sword", 450, 0, 45) {}

MagicianStick::MagicianStick() : Tool(4, "Magician Stick", 450, 0, 5) {}

LowArmor::LowArmor() : Tool(5, "Low Armor", 100, 2, 0) {}

MiddleArmor::MiddleArmor() : Tool(6, "Middle Armor", 250, 5, 0) {}

HighArmor::HighArmor() : Tool(7, "High Armor", 650, 12, 0) {}
