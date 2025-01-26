#ifndef STAGE_SESSION_H
#define STAGE_SESSION_H

#include "Player.h"
#include "Monster.h"
#include <iostream>

class StageSession {
public:
    void battleStage(int stageNumber); // 특정 스테이지의 전투를 처리
private:
    Monster* createMonster(int stageNumber); // 스테이지에 따라 몬스터 생성
};

#endif // STAGE_SESSION_H

