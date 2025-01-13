#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include <chrono>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows 시스템에서 화면 초기화
#else
    system("clear"); // Unix 기반 시스템에서 화면 초기화
#endif
}

void slowPrint(const string& text, int delayMs = 150) {
    for (char c : text) {
        cout << c << flush; // 한 글자 출력 후 출력 버퍼를 강제로 플러시
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // 딜레이
    }
    cout << endl; // 최종적으로 줄 바꿈
}

int main()
{
    int start = 0;
    GameManager manager;  // GameManager 객체 생성

    slowPrint ("코딩을 시작하시겠습니까?\n");
    slowPrint  ("1. 시작한다 \n2. 종료한다\n");
    cin >> start;
    clearScreen();

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