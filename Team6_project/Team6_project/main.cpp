#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;

int main()
{
    int start = 0;
    GameManager manager;  // GameManager 객체 생성

    cout << "코딩을 시작하시겠습니까?\n";
    cout << "1. 시작한다 \n2. 종료한다\n";
    cin >> start;

    if (start == 1) {
        manager.StartGame(start); 
        //manager.StartBoss();// GameManager 객체의 StartGame 호출
    }
    else {
        cout << "게임을 종료합니다." << endl;
    }

    cout << "으하하하 나는 김이진 매니저다 너같이 GPT만 쓰는 개발자는 용서할 수 없지!\n";
    cout << "매니저와 조우하셨습니다. 무엇을 하시겠습니까?\n";
    return 0;
}