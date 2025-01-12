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
void GameManager::StartGame(int start)
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
void GameManager::StartBoss()
{
    int Boss = 0; // �ʱ�ȭ
    while (true)
    {
        cout << "1. �ڵ� ����\n";
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

// Tutor ���� �Լ� ����
void generateTutor(Character& A, Tutor& B)
{
    while (A.getLevel() <= 2)
    {
        srand((unsigned int)time(NULL)); // ���� �õ� ����
        NewTutor tutorType = static_cast<NewTutor>(rand() % 4);  // 0���� 3���� ���� �� ����
        switch (tutorType)
        {
        case ManagerTutor:
            currentTutor = new ManagerTutor(A, "������");
            break;
        case BasicTutor:
            currentTutor = new BasicTutor(A, "������");
            break;
        case StandardTutor:
            currentTutor = new StandardTutor(A, "������");
            break;
        case ChallengeTutor:
            currentTutor = new ChallengeTutor(A, "�赵��");
            break;
        }
    }
}

// battle �Լ� ����
void battle(Character& A, Tutor& B)
{
    cout << "������ �����մϴ�!\n";
    GenerateTutor(A); // Ʃ�� ����

    while (A.getHp() > 0 && B.getHp() > 0)
    {
        // �÷��̾ ����
        int damageToTutor = A.getAdd();
        B.takeDamage(damageToTutor);
        cout << A.getName() << "��(��) " << B.getName() << "���� " << damageToTutor << "�� ���ظ� �������ϴ�!\n";

        // Ʃ�Ͱ� ����
        if (B.getHp() > 0)
        {
            int damageToCharacter = B.getAdd();
            A.takeDamage(damageToCharacter);
            cout << B.getName() << "��(��) " << A.getName() << "���� " << damageToCharacter << "�� ���ظ� �������ϴ�!\n";
        }

        // ���� ��� Ȯ��
        if (B.getHp() <= 0)
        {
            cout << B.getName() << "�� �����ƽ��ϴ�!\n";
            A.setGold(A.getGold() + 10); // ����
            A.setExp(A.getExp() + 100); // ����ġ ȹ��
        }
        else if (A.getHp() <= 0) {
            cout << A.getName() << "��(��) ���� ���߽��ϴ�...\n";
        }
    }
}

// Tutor �Լ� ���� (�߰� �Լ��� ����)
void Tutor()
{
    if (currentTutor != nullptr)
    {
        cout << currentTutor->getName() << "��(��) ��ſ��� �����մϴ�!\n";
    }
    else
    {
        cout << "Ʃ�Ͱ� �����ϴ�.\n";
    }
}

// ���� �� ���� ���, ����, ����ġ Ȯ��
void AfterBattle(Character& A)
{
    cout << A.getName() << "�� ���� ü��: " << A.getHp() << "\n";
    cout << "������ ���: " << A.getGold() << "\n"; // ��尡 ����� ǥ�õǵ��� ����
    cout << A.getName() << "�� Level: " << A.getLevel() << "\n";
    cout << "ȹ���� ����ġ: " << A.getExp() << "\n";
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