#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "GameManager.h"

using namespace std;


// StartGame 함수 정의
void StartGame(int start) {
    if (start == 1) {
        cout << "게임을 시작합니다.\n";
    }
    else if (start == 2) {
        cout << "캠프를 탈주하셨습니다.\n";
        exit(0);
    }
}

// StartBoss 함수 정의
void StartBoss() {
    int Boss = 0; // 초기화
    while (true) {
        cout << "1. GPT 사용\n";
        cin >> Boss;

        if (Boss == 1) {
            cout << "데미지가 들어가지 않습니다.\n";
            break;
        }
        else {
            cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
        }
    }
}

//전투 함수 정의
void battle() {
    cout << "전투를 시작합니다!\n";
    while (player.hp > 0 && Monster.hp > 0) {
        int damageToMonster = player.add;
        Monster.health -= damageToMonster;
        cout << "플레이어가 " << damageToMonster << "의 피해를 입혔습니다!\n";
        if (Monster.health <= 0) {
            cout << Monster.name << "를 물리쳤습니다!\n";
            inventory.gold += 10; // 보상
            return;
        }

        int main() {
            int start = 0;

            cout << "코딩을 시작하시겠습니까?\n";
            cout << "1. 시작한다 \n2. 종료한다\n";
            cin >> start;

            StartGame(start);

            cout << "으하하하 나는 김이진 매니저다 너같이 GPT만 쓰는 개발자는 용서할 수 없지!\n";
            cout << "매니저와 조우하셨습니다. 무엇을 하시겠습니까?\n";

            StartBoss();

            return 0;
        }