#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;


// StartGame 함수 정의
void StartGame(int start) 
{
    if (start == 1) {
        cout << "게임을 시작합니다.\n";
    }
    else if (start == 2) 
    {
        cout << "캠프를 탈주하셨습니다.\n";
        exit(0);
    }
}

// StartBoss 함수 정의
void StartBoss() {
    int Boss = 0; // 초기화
    while (true) 
    {
        cout << "1. GPT 사용\n";
        cin >> Boss;

        if (Boss == 1) 
        {
            cout << "데미지가 들어가지 않습니다.\n";
            break;
        }
        else 
        {
            cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
        }
    }
}

//전투 함수 정의
void battle(Character& A, Tutor& B)
{
    cout << "전투를 시작합니다!\n";
    while (A.getHp() > 0 && B.getHp() > 0)
    {
        // 플레이어가 공격
        int damageToTutor = A.getAdd();
        B.takeDamage(damageToTutor);
        cout << A.name << "이(가) " << B.name << "에게 " << damageToTutor << "의 피해를 입혔습니다!\n";

        // 튜터가 공격
        if (B.getHp() > 0)
        {
            int damageToCharacter = B.getAdd();
            A.takeDamage(damageToCharacter);
            cout << B.name << "이(가) " << A.name << "에게 " << damageToCharacter << "의 피해를 입혔습니다!\n";
        }

        // 전투 결과 확인
        if (B.getHp() <= 0)
        {
            cout << B.name << "를 물리쳤습니다!\n";
            A.inventory.gold += 10; // 보상
            A.exp += 100;
        }
        else if (A.getHp() <= 0) {
            cout << A.name << "이(가) 제적 당했습니다...\n";

        }
    }
}

//전투 후 보유 골드, 레벨, 경험치 확인
void AfterBattle()
{
    cout << A.name << "의 남은 체력: " << A.getHp() << "\n";
    cout << "보유한 골드: " << A.inventory.gold << "\n";
    cout << A.name << "의 Level: " << A.Level() << "\n";
    cout << "획득한 경험치: " << A.exp << "\n";
}

      /*  int main()
        {
            int start = 0;

            cout << "코딩을 시작하시겠습니까?\n";
            cout << "1. 시작한다 \n2. 종료한다\n";
            cin >> start;

            StartGame(start);

            cout << "으하하하 나는 김이진 매니저다 너같이 GPT만 쓰는 개발자는 용서할 수 없지!\n";
            cout << "매니저와 조우하셨습니다. 무엇을 하시겠습니까?\n";

            StartBoss();

            return 0;
        }*/