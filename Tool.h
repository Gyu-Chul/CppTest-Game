#ifndef TOOL_H
#define TOOL_H

#include <string>
using namespace std;

class Tool {
public:
    int toolId;
    string name;      // 장비 이름 추가
    int price;        // 가격
    int defensePower; // 방어력
    int power;        // 공격력

    // 매개변수 생성자 (기본값 포함)
    Tool(int id = 0, const string& n = "Unnamed Tool", int p = 0, int dfpw = 0, int pw = 0)
        : toolId(id), name(n), price(p), defensePower(dfpw), power(pw) {}
};

class BasicSword : public Tool {
public:
    BasicSword();
};

class HighQualitySword : public Tool {
public:
    HighQualitySword();
};

class WarriorSword : public Tool {
public:
    WarriorSword();
};

class MagicianStick : public Tool {
public:
    MagicianStick();
};

class LowArmor : public Tool {
public:
    LowArmor();
};

class MiddleArmor : public Tool {
public:
    MiddleArmor();
};

class HighArmor : public Tool {
public:
    HighArmor();
};

#endif // TOOL_H
