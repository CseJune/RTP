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
    GameManager manager;  // GameManager ��ü ����

    cout << "�ڵ��� �����Ͻðڽ��ϱ�?\n";
    cout << "1. �����Ѵ� \n2. �����Ѵ�\n";
    cin >> start;

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