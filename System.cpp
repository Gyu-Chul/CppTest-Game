#include "System.h"
#include "raylib.h"
#include "Player.h"

extern Player player;
struct Button {
    Rectangle bounds;
    std::string text;
    Color color;
};


void DrawButton(Button button) {
    DrawRectangleRec(button.bounds, button.color);
    DrawText(button.text.c_str(), button.bounds.x + 10, button.bounds.y + 10, 20, BLACK);
}


// 현재 세션 실행 사실상 이친구가 메인임
void System::executeSession() {
    InitWindow(800, 600, "Game Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch (player.presentSession) {
        case 1:
            handleTitleSession();
            break;
        case 2:
            handleGeneralSession();
            break;
        case 3:
            handleStoreSession();
            break;
        case 4:
            handleStageSession();
            break;
        default:
            CloseWindow();
        }
    }
    CloseWindow();
}


// TitleSession 핸들러
void System::handleTitleSession() {
    std::vector<Button> buttons = {
        {{300, 150, 200, 40}, "0. Login", LIGHTGRAY},
        {{300, 200, 200, 40}, "1. Sign Up", LIGHTGRAY},
        {{300, 250, 200, 40}, "2. Exit", LIGHTGRAY},
    };
    bool waitingForInput = true; // 입력 대기 상태 플래그
    int choice = -1; // 사용자 입력값 저장 변수

    while (!WindowShouldClose() && waitingForInput) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 렌더링
        DrawText("=== Title Session ===", 300, 100, 20, BLACK);
        for (auto& button : buttons) {
            DrawButton(button);
        }

        DrawText("Enter your choice in the console (0-2):", 300, 400, 20, BLUE);

        EndDrawing();

        // 입력 대기
        std::cout << "Enter your choice (0-2): ";
        std::cin >> choice;

        // 입력값 처리
        if (!std::cin.fail() && choice >= 0 && choice <= 2) {
            waitingForInput = false; // 유효한 입력이 있으면 루프 종료
        }
        else {
            std::cin.clear(); // 잘못된 입력 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 남은 입력 버퍼 비우기
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    switch (choice) {
    case 0:
        titleSession.login(); // 로그인 함수 호출
        player.presentSession = 2;
        break;
    case 1:
        titleSession.signUp(); // 회원가입 함수 호출
        break;
    case 2:
        std::cout << "Exiting the program..." << std::endl;
        CloseWindow(); // 프로그램 종료
        return;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }


    
}

// GeneralSession 핸들러
void System::handleGeneralSession() {
    std::vector<Button> buttons = {
        {{300, 150, 200, 40}, "0. Check My Info", LIGHTGRAY},
        {{300, 200, 200, 40}, "1. Go to Shop", LIGHTGRAY},
        {{300, 250, 200, 40}, "2. Enter Dungeon", LIGHTGRAY},
        {{300, 300, 200, 40}, "3. Logout", LIGHTGRAY},
    };

    int choice = -1; // 사용자 입력값 저장 변수
    bool waitingForInput = true; // 입력 대기 플래그

    while (!WindowShouldClose() && waitingForInput) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 화면에 플레이어 정보와 메뉴 렌더링
        DrawText(("Welcome, " + player.id).c_str(), 300, 100, 20, BLACK);
        DrawText(("Gold: " + std::to_string(player.money)).c_str(), 300, 130, 20, DARKGREEN);

        for (auto& button : buttons) {
            DrawButton(button);
        }

        DrawText("Enter your choice in the console (0-3):", 300, 400, 20, BLUE);

        EndDrawing();

        // 입력 대기 (콘솔에서)
        std::cout << "Enter your choice (0-3): ";
        std::cin >> choice;

        // 입력값 검증
        if (!std::cin.fail() && choice >= 0 && choice <= 3) {
            waitingForInput = false; // 유효한 입력일 경우 대기 종료
        }
        else {
            std::cin.clear(); // 잘못된 입력 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 남은 입력 버퍼 비우기
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    // 입력값에 따른 동작 처리
    switch (choice) {
    case 0:
        generalSession.checkMyInfo(); // 플레이어 정보 확인
        break;
    case 1:
        generalSession.goToShop(); // 상점으로 이동
        return;
    case 2:
        generalSession.enterDungeon(); // 던전으로 이동
        return;
    case 3:
        generalSession.logout(); // 로그아웃
        CloseWindow(); // 창 종료
        return;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}



// StoreSession 핸들러
void System::handleStoreSession() {
    std::vector<Button> buttons = {
        {{300, 150, 300, 40}, "0. Buy Healing Potion (50 Gold)", LIGHTGRAY},
        {{300, 200, 300, 40}, "1. Buy Mana Potion (30 Gold)", LIGHTGRAY},
        {{300, 250, 300, 40}, "2. Sell Healing Potion (25 Gold)", LIGHTGRAY},
        {{300, 300, 300, 40}, "3. Sell Mana Potion (15 Gold)", LIGHTGRAY},
        {{300, 350, 300, 40}, "4. Show and Buy Equipment", LIGHTGRAY},
        {{300, 400, 300, 40}, "5. Back to General Session", LIGHTGRAY},
    };

    int choice = -1; // 사용자 입력값 저장 변수
    bool waitingForInput = true; // 입력 대기 플래그

    while (!WindowShouldClose() && waitingForInput) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 제목과 안내 메시지 출력
        DrawText("=== Store Session ===", 300, 50, 20, BLACK);
        DrawText("Enter your choice in the console (0-5):", 300, 500, 20, BLUE);
        // 버튼 출력
        for (auto& button : buttons) {
            DrawButton(button);
        }

        EndDrawing();

        // 콘솔에서 사용자 입력 대기
        std::cout << "Enter your choice (0-5): ";
        std::cin >> choice;

        // 입력값 검증
        if (!std::cin.fail() && choice >= 0 && choice <= 5) {
            waitingForInput = false; // 유효한 입력값이 들어오면 대기 종료
        }
        else {
            std::cin.clear(); // 잘못된 입력 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    // 입력값에 따른 동작 실행
    switch (choice) {
    case 0:
        storeSession.buyHealingPotion(); // 힐링 포션 구매
        break;
    case 1:
        storeSession.buyManaPotion(); // 마나 포션 구매
        break;
    case 2:
        storeSession.sellHealingPotion(); // 힐링 포션 판매
        break;
    case 3:
        storeSession.sellManaPotion(); // 마나 포션 판매
        break;
    case 4:
        storeSession.showAndBuyEquipment(); // 장비 확인 및 구매
        break;
    case 5:
        player.presentSession = 2; // General Session으로 전환
        std::cout << "Returning to General Session..." << std::endl;
        return;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
}



// StageSession 핸들러
void System::handleStageSession() {
    int choice = -1;        // 선택값 저장
    bool waitingForInput = true; // 입력 대기 플래그

    while (!WindowShouldClose() && waitingForInput) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 제목 출력
        DrawText("=== Stage Selection ===", 300, 50, 20, BLACK);

        // 옵션 출력
        DrawText("1. Easy Mode", 300, 150, 20, DARKGRAY);
        DrawText("2. Middle Mode", 300, 200, 20, DARKGRAY);
        DrawText("3. Hard Mode", 300, 250, 20, DARKGRAY);
        DrawText("4. Back to General Session", 300, 300, 20, RED);

        DrawText("Enter your choice in the console (1-4):", 300, 400, 20, BLUE);

        EndDrawing();

        // 콘솔 입력 대기
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        // 입력값 검증
        if (!std::cin.fail() && choice >= 1 && choice <= 4) {
            waitingForInput = false; // 유효한 입력값이 들어오면 대기 종료
        }
        else {
            std::cin.clear(); // 잘못된 입력 초기화
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 입력 버퍼 비우기
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    // 선택된 동작 실행
    if (choice >= 1 && choice <= 3) {
        if (choice > player.maxStage) {
            cout << "\nYou cannot access this stage. Your max stage is " << player.maxStage << ".\n";
        }
        else {
            stageSession.battleStage(choice); // 난이도를 stageNumber로 전달
            return; // 스테이지 전투 종료 후 General Session으로 복귀
        }
    }
    else if (choice == 4) {
        player.presentSession = 2; // General Session으로 전환
        cout << "Returning to General Session...\n";
        return;
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
    }
}



