#ifndef SYSTEM_H
#define SYSTEM_H

#include "Player.h"
#include "generalSession.h"
#include "storeSession.h"
#include <iostream>

class System {
private:
    GeneralSession generalSession; // 일반 세션 객체
    StoreSession storeSession;     // 상점 세션 객체

public:
    // 현재 세션 실행
    void executeSession();

    // 세션 핸들러
    void handleGeneralSession();
    void handleStoreSession();
};

#endif // SYSTEM_H
