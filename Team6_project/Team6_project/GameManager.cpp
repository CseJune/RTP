#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;


// StartGame �Լ� ����
void GameManager::StartGame(int start)
{
    string characterName;
    cout << "ĳ���� �̸� �Է�: ";
    cin >> characterName;

    // ĳ���� ��ü ���� (�̱��� ����)
    Character* player = Character::getinstance(characterName);
    player->displayStatus();

    vector<Item*> inventory;  // �÷��̾��� ������ ���

    // ������ 10�� ������ ������ ���� �ݺ�
    while (player->getLevel() < 10)
    {
        // �޴� ���
        cout << "\n1. ���� ����\n2. ������ ���\n3. ����\n����: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            // ���� ����
            Tutor* monster = nullptr;

            // ������ �´� Ʃ��(����) ����
            if (player->getLevel() >= 8) {
                monster = new ChallengeTutor(*player, "ç���� Ʃ��");
            }
            else if (player->getLevel() >= 6) {
                monster = new StandardTutor(*player, "���Ĵٵ� Ʃ��");
            }
            else if (player->getLevel() >= 3) {
                monster = new BasicTutor(*player, "������ Ʃ��");
            }
            else {
                monster = new ManagerTutor(*player, "�Ŵ��� Ʃ��");
            }

            // ���� ����
            battle(*player, *monster);
            player->displayStatus();

            // ����ġ�� 100�� ������ ������
            if (player->getLevel() >= 10) {
                cout << "���� 10�� �����߽��ϴ�! ���� Ʃ�Ͱ� �����մϴ�!\n";
                Tutor* boss = new BossTutor(*player, "������ �Ŵ���");
                battle(*player, *boss);
                break;  // �������� ���� �� ���� ����
            }
        }
        else if (choice == 2) {
            // ������ ��� ����
            cout << "\n������ ���:\n";
            cout << "1. HealthPotion\n";
            cout << "2. CodingBooster\n";
            cout << "3. MaxHealthPotion\n";
            cout << "4. TutorAttackReduction\n";
            cout << "5. ChatGPT\n";
            cout << "�������� �����ϼ��� (1-5): ";
            int itemChoice;
            cin >> itemChoice;

            Item* selectedItem = nullptr;

            // ������ ����
            switch (itemChoice) {
            case 1: selectedItem = ItemFactory::CreateItem("HealthPotion"); break;
            case 2: selectedItem = ItemFactory::CreateItem("CodingBooster"); break;
            case 3: selectedItem = ItemFactory::CreateItem("MaxHealthPotion"); break;
            case 4: selectedItem = ItemFactory::CreateItem("TutorAttackReduction"); break;
            case 5: selectedItem = ItemFactory::CreateItem("ChatGPT"); break;
            default:
                cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���.\n";
                continue;
            }

            // ������ ���
            if (selectedItem) {
                selectedItem->Use(player);  // ������ ���
                delete selectedItem;  // ������ ��� �� �޸� ����
            }
        }
        else if (choice == 3) {
            cout << "���� ����!\n";
            break;
        }
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
void generateTutor(Character& A, Tutor*& currentTutor)
{
    while (A.getLevel() <= 2)
    {
        srand((unsigned int)time(NULL)); // ���� �õ� ����
        TutorType tutorType = static_cast<TutorType>(rand() % 4);  // 0���� 3���� ���� �� ����
        switch (tutorType)
        {
        case TutorType::Manager:
            currentTutor = new ManagerTutor(A, "������");
            break;
        case TutorType::Basic:
            currentTutor = new BasicTutor(A, "������");
            break;
        case TutorType::Standard:
            currentTutor = new StandardTutor(A, "������");
            break;
        case TutorType::Challenge:
            currentTutor = new ChallengeTutor(A, "�赵��");
            break;
        case TutorType::Boss:
            currentTutor = new BossTutor(A, "������");
            break;
        }
    }

    };

// battle �Լ� ����
void GameManager::battle(Character & A, Tutor & B)
    {
        cout << "������ �����մϴ�!\n";

        while (A.getHp() > 0 && B.getHp() > 0)
        {
            // �÷��̾ ����
            int add = A.getAdd();
            B.takeDamage(add);
            cout << A.getName() << "��(��) " << B.getName() << "���� " << add << "�� ���ظ� �������ϴ�!\n";

            // Ʃ�Ͱ� ����
            if (B.getHp() > 0)
            {
                int add = B.getAdd();
                A.takeDamage(add);
                cout << B.getName() << "��(��) " << A.getName() << "���� " << add << "�� ���ظ� �������ϴ�!\n";
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
    };

/* Tutor �Լ� ���� (�߰� �Լ��� ����)
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
}*/

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