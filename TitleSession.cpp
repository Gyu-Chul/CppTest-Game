#include "TitleSession.h"
#include "DataSession.h"
#include <iostream>
#include "Player.h"


using namespace std;
DataSession dataSession("datas.txt");

void TitleSession::login() {
    string userId, userPw;
    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> userPw;

    int token = 1;
    bool idFound = false;
    bool loginSuccess = false;
    int matchedToken = -1;

    while (true) {
        string currentId = dataSession.read(token, "userId");
        string currentPw = dataSession.read(token, "userpw");

        if (currentId == "Token not found") break;

        if (currentId == userId) {
            idFound = true;
            if (currentPw == userPw) {
                loginSuccess = true;
                matchedToken = token;
                break;
            }
        }
        token++;
    }

    if (!idFound) {
        cout << "User ID does not exist." << endl;
    }
    else if (!loginSuccess) {
        cout << "Incorrect password." << endl;
    }
    else {
        cout << "Login successful! Token: " << matchedToken << endl;
       
        // Player("gyuchul", 10, 100, 20, 10)에 해당하는 임시 객체를 만들어서, 그것을 기존의 전역 변수 player에다가 복사하고 자멸
        player = Player("gyuchul", 10, 100, 20, 1);  // 기존 객체를 새 객체로 대체

        player.inventory[0]->number = 1;  // DB에서 받아온 힐링 포션의 개수 대입
        player.inventory[1]->number = 1;  // DB에서 받아온 마나 포션의 개수 대입


        player.presentSession = 2; // General Session으로 전환

    }

}

void TitleSession::signUp() {
    string userId, userPw;
    cout << "Enter New User ID: ";
    cin >> userId;
    cout << "Enter New Password: ";
    cin >> userPw;

    DataSession dataSession("datas.txt");

    int token = 1;
    while (true) {
        string currentId = dataSession.read(token, "userId");

        if (currentId == "Token not found") break;

        if (currentId == userId) {
            cout << "User ID already exists. Sign up failed." << endl;
            return;
        }
        token++;
    }

    dataSession.create(userId, userPw);
    cout << "Sign up successful!" << endl;
}
