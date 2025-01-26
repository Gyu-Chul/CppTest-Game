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



// stage 기본 클래스 생성 후
//몇 번째 스테이지에 들어오는 것인지 System에게 전달 받으면
//그 난이도에 맞는 monster 객체 생성
//
//stageMain()
// ->몇단계인지에 따라서 난이도의 monster 객체 생성, DB에서 플레이어 정보 받아서 player 객체 생성
// ->몬스터와 플레이어의 전투; 번갈아가면서 액션 취하기->플레이어는 직접 선택, 몬스터는 랜덤하게 스킬 사용하도록 만들기
// ->한 번 액션이 끝날 때마다 hp, mp 보여주기
// ->어느 한 쪽의 hp가 0이 되면 stageClear or stageFail 호출
//
//stageClear()
// ->경험치 올려주기, 아이템 드롭, 체력 만땅으로 채워주기, 최고 스테이지 갱신이면 maxStage 올려주기, 변화 내용 DB로 전송하기(아이템 사용내역, 경험치 등등)
// ->아이템이 드롭되었을 때, 빈 슬롯 없으면 걍 못 먹는거고 빈 슬롯 있으면 무조건 주워가는 걸로 통일
//stageFail()
// ->경험치 0으로 줄이기, 500원 압수, 변화 내용 DB로 전송하기(아이템 사용내역, 경험치 등등)
