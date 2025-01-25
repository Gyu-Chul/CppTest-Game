#include "System.h"

extern Player player;

// 현재 세션 실행
void System::executeSession() {
    switch (player.presentSession) {
    case 1: // GeneralSession 실행
        std::cout << "Executing General Session..." << std::endl;
       /* handleGeneralSession();*/
        break;
    case 3: // StoreSession 실행
        std::cout << "Executing Store Session..." << std::endl;
        handleStoreSession(); // StoreSession에 Player 전달
        break;
    default:
        std::cerr << "Unknown session ID. Unable to execute session." << std::endl;
    }
}


// GeneralSession 핸들러
void System::handleGeneralSession() {
    int choice;
    do {
        cout << "=== General Session ===" << endl;
        cout << "1. Check My Info" << endl;
        cout << "2. Go to Shop" << endl;
        cout << "3. Enter Dungeon" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            generalSession.checkMyInfo();
            break;
        case 2:
            generalSession.goToShop();
            return; // 세션 변경 후 종료
        case 3:
            generalSession.enterDungeon();
            return; // 세션 변경 후 종료
        case 4:
            generalSession.logout();
            return; // 로그아웃 후 종료
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}


// StoreSession 핸들러
void System::handleStoreSession() {
    int choice;
    do {
        cout << "=== Store Session ===" << endl;
        cout << "1. Buy Healing Potion (50 Gold)" << endl;
        cout << "2. Buy Mana Potion (30 Gold)" << endl;
        cout << "3. Sell Healing Potion (25 Gold)" << endl;
        cout << "4. Sell Mana Potion (15 Gold)" << endl;
        cout << "5. Show and Buy Equipment" << endl;
        cout << "6. Back to General Session" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            storeSession.buyHealingPotion();
            break;
        case 2:
            storeSession.buyManaPotion();
            break;
        case 3:
            storeSession.sellHealingPotion();
            break;
        case 4:
            storeSession.sellManaPotion();
            break;
        case 5:
            storeSession.showAndBuyEquipment();
            break;
        case 6:
            player.presentSession = 1; // General Session으로 전환
            cout << "Returning to General Session..." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}
