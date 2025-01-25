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
       

        //여기서 생성되는 이 녀석을 전역변수로써 사용 되어야 함.

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
