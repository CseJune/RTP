#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <thread>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include <chrono>
#include "Logger.h"


using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Windows 시스템에서 화면 초기화
#else
    system("clear"); // Unix 기반 시스템에서 화면 초기화
#endif
}

void slowPrint(const string& text, int delayMs = 15) {
    for (char c : text) {
        cout << c << flush; // 한 글자 출력 후 출력 버퍼를 강제로 플러시
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // 딜레이
    }
    cout << endl; // 최종적으로 줄 바꿈
}

void slowPrint1(const string& text, int delayMs = 50) {
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
    slowPrint1 (" 6조 팀 과제 ");
    slowPrint ("게임을 시작하시겠습니까?\n");
	writeLog("게임을 시작하시겠습니까?");
    slowPrint  ("1. 시작한다 \n2. 종료한다\n");
    cin >> start;

    if (start == 1) {
        manager.StartGame(start); 
		writeLog("캠프 입장 ");
        //manager.StartBoss();// GameManager 객체의 StartGame 호출
    }
    else {
        cout << "캠프를 탈주하셨습니다. " << endl;
		writeLog("캠프 탈주 ");
    }

    cout << "공쥬님은 오늘 게임을 종료하고 기모찌한 낮잠을 선택하셨어요.\n";
	writeLog("공쥬님은 오늘 게임을 종료하고 기모찌한 낮잠을 선택하셨어요. ");
    //cout << "매니저와 조우하셨습니다. 무엇을 하시겠습니까?\n";
    return 0;
}