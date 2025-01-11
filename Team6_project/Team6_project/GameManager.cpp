#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;


// StartGame �Լ� ����
void StartGame(int start) 
{
    if (start == 1) {
        cout << "������ �����մϴ�.\n";
    }
    else if (start == 2) 
    {
        cout << "ķ���� Ż���ϼ̽��ϴ�.\n";
        exit(0);
    }
}

// StartBoss �Լ� ����
void StartBoss() {
    int Boss = 0; // �ʱ�ȭ
    while (true) 
    {
        cout << "1. GPT ���\n";
        cin >> Boss;

        if (Boss == 1) 
        {
            cout << "�������� ���� �ʽ��ϴ�.\n";
            break;
        }
        else 
        {
            cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���.\n";
        }
    }
}

//���� �Լ� ����
void battle(Character A, Tutor B)
{
    cout << "������ �����մϴ�!\n";
    while (A.getHp() > 0 && B.getHp() > 0)
    {
        int damageToTutor = A.getAdd();
        B.takeDamage(damageToTutor) ;
        cout << "�÷��̾ " << damageToTutor << "�� ���ظ� �������ϴ�!\n";

        int damageToCharacter = B.getAdd();
        A.getHp() -= damageToCharacter;
        cout << "Ʃ�Ͱ� " << damageToCharacter << "�� ���ظ� �������ϴ�!\n";

        if (B.getHp()<= 0) 
        {
            cout << B.name << "�� �����ƽ��ϴ�!\n";
            A.inventory.gold += 10; // ����
            A.exp += 100;
        }
        else if (A.getHp() <= 0)
        {
            cout << A.name << "�� ���� ���ϼ̽��ϴ�.\n";         
        }
    }
}

      /*  int main()
        {
            int start = 0;

            cout << "�ڵ��� �����Ͻðڽ��ϱ�?\n";
            cout << "1. �����Ѵ� \n2. �����Ѵ�\n";
            cin >> start;

            StartGame(start);

            cout << "�������� ���� ������ �Ŵ����� �ʰ��� GPT�� ���� �����ڴ� �뼭�� �� ����!\n";
            cout << "�Ŵ����� �����ϼ̽��ϴ�. ������ �Ͻðڽ��ϱ�?\n";

            StartBoss();

            return 0;
        }*/