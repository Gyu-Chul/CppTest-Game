#include "TitleSession.h"
#include "DataSession.h"
#include <iostream>
#include "Player.h"


using namespace std;
DataSession dataSession("datas.txt");
int userToken;

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

        userToken = matchedToken;
        string uid = dataSession.read(userToken, "userId");
        string lev = dataSession.read(userToken, "level");
        string xp = dataSession.read(userToken, "exp");
        string mey = dataSession.read(userToken, "money");
        string mst = dataSession.read(userToken, "presentstage");

        string bag1_0 = dataSession.read(userToken, "bag1");
        string bag2_0= dataSession.read(userToken, "bag2");
        string bag3_0 = dataSession.read(userToken, "bag3");
        string bag4_0 = dataSession.read(userToken, "bag4");
        string bag5_0 = dataSession.read(userToken, "bag5");

        int bag1 = stoi(bag1_0);
        int bag2 = stoi(bag2_0);
        int bag3 = stoi(bag3_0);
        int bag4 = stoi(bag4_0);
        int bag5 = stoi(bag5_0);

        string manapotioncount = dataSession.read(userToken, "manapotioncount");
        string healingpotioncount = dataSession.read(userToken, "healingpotioncount");

        int level = stoi(lev);
        int exp = stoi(xp);
        int money = stoi(mey);
        int presentStage = stoi(mst);

        int healCount = stoi(healingpotioncount);
        int manaCount = stoi(manapotioncount);

        player.id = uid;
        player.exp = exp;
        player.money = money;
        player.level = level;
        player.maxStage = presentStage;


        player.inventory[0]->number = healCount;  // DB에서 받아온 힐링 포션의 개수 대입
        player.inventory[1]->number = manaCount;  // DB에서 받아온 마나 포션의 개수 대입

        
        //장비 넣는 로직
        vector<Tool*> availableTools = {
        new BasicSword(),
        new HighQualitySword(),
        new WarriorSword(),
        new MagicianStick(),
        new LowArmor(),
        new MiddleArmor(),
        new HighArmor()
        };

        vector<int> bags = { bag1, bag2, bag3, bag4, bag5 };

        for (int bag : bags) {
            if (bag != 0) {
                player.equipItem(new Tool(*availableTools[bag-1]));
            }
        }
        for (Tool* tool : availableTools) {
            delete tool;
        }

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
