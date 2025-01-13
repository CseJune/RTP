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
    system("cls"); // Windows �ý��ۿ��� ȭ�� �ʱ�ȭ
#else
    system("clear"); // Unix ��� �ý��ۿ��� ȭ�� �ʱ�ȭ
#endif
}

void slowPrint(const string& text, int delayMs = 150) {
    for (char c : text) {
        cout << c << flush; // �� ���� ��� �� ��� ���۸� ������ �÷���
        this_thread::sleep_for(chrono::milliseconds(delayMs)); // ������
    }
    cout << endl; // ���������� �� �ٲ�
}

int main()
{
    int start = 0;
    GameManager manager;  // GameManager ��ü ����

    slowPrint ("�ڵ��� �����Ͻðڽ��ϱ�?\n");
    slowPrint  ("1. �����Ѵ� \n2. �����Ѵ�\n");
    cin >> start;
    clearScreen();

    if (start == 1) {
        manager.StartGame(start); 
        //manager.StartBoss();// GameManager ��ü�� StartGame ȣ��
    }
    else {
        cout << "������ �����մϴ�." << endl;
    }

    cout << "�������� ���� ������ �Ŵ����� �ʰ��� GPT�� ���� �����ڴ� �뼭�� �� ����!\n";
    cout << "�Ŵ����� �����ϼ̽��ϴ�. ������ �Ͻðڽ��ϱ�?\n";
    return 0;
}