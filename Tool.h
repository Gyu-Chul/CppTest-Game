#ifndef TOOL_H
#define TOOL_H

class Tool {
public:
    int price;
    int defensePower;
    int power;


    Tool(int p, int dfpw, int pw);
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

#endif // TOOL_H
