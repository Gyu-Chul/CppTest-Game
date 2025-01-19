#include "Tool.h"

Tool::Tool(int p, int dfpw, int pw) : price(p), defensePower(dfpw), power(pw) {}

BasicSword::BasicSword() : Tool(50, 0, 3) {}

HighQualitySword::HighQualitySword() : Tool(150, 0, 10) {}

WarriorSword::WarriorSword() : Tool(450, 0, 45) {}

MagicianStick::MagicianStick() : Tool(450, 0, 5) {}

LowArmor::LowArmor() : Tool(100, 2, 0) {}

MiddleArmor::MiddleArmor() : Tool(250, 5, 0) {}

HighArmor::HighArmor() : Tool(650, 12, 0) {}
