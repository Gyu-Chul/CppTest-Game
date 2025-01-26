#ifndef SYSTEM_H
#define SYSTEM_H

#include "Player.h"
#include "TitleSession.h"
#include "GeneralSession.h"
#include "StoreSession.h"
#include "StageSession.h"
#include <iostream>

class System {
private:
    TitleSession titleSession;
    GeneralSession generalSession; // 일반 세션 객체
    StoreSession storeSession;     // 상점 세션 객체
    StageSession stageSession;

public:
    // 현재 세션 실행
    void executeSession();

    // 세션 핸들러
    void handleTitleSession();
    void handleGeneralSession();
    void handleStoreSession();
    void handleStageSession();
    
};

#endif // SYSTEM_H
