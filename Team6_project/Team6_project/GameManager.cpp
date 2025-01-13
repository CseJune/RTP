#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include <set>

using namespace std;

set<string> generatedTutors;// ������ Ʃ�� �̸��� �����ϴ� set (����ϱ� ���ؼ��� #include <set> ��� �ʿ�)


// StartGame �Լ� ����
void GameManager::StartGame(int start) {
    string characterName;
    cout << "ĳ���� �̸� �Է�: ";
    cin >> characterName;

    Character* player = Character::getinstance(characterName);
    player->displayStatus();

    Tutor* currentTutor = nullptr;  // ���� Ʃ�� ������

    while (true) {
        int choice;
        int LeaveCamp;
        
        if (player->getLevel() == 0)
        {
            cout << "\n1. ķ�� ����\n2. ���� ����\n3. ķ�� Ż��\n4. �κ��丮 ����\n����: ";            
            cin >> choice;
        }
        else {
            cout << "\n1. ���� ����\n2. �κ��丮 ����\n3. ķ�� Ż��\n����: ";   
            cin >> choice;
        }
        if (player->getLevel() == 0 && choice == 1) {
            cout << "�������� ���� ������ �Ŵ����� ���� ķ������ �����ϰ� �Ͷ�!\n";
            cout << "������ ���ϼ̽��ϴ�...\n����� ����Ͽ����ϴ�...\n���� ��������� ȯ�� �մϴ�.\n";
            player->setLevel(1);
            cout << "���� 1�� ȯ�� �մϴ�.\n";
        }
        else if (player->getLevel() == 0 && choice == 3) {
            cout << "���� ķ���� �����ðڽ��ϱ�?\n";
            cout << "\n1. ��\n2. �ƴϿ�\n����:";
                cin >> LeaveCamp;
                if (LeaveCamp == 2) {
                    return;
                }
                else if(LeaveCamp == 1){
                    cout << "ķ���� Ż���մϴ�.";
                    return;
                }
        }
        else if (choice == 1) {
            if (currentTutor == nullptr || currentTutor->getHp() <= 0) {
                srand((unsigned int)time(NULL));

                while (true) {
                    string tutorName;

                    if (player->getLevel() >= 8 && generatedTutors.find("��â��") == generatedTutors.end()) {
                        tutorName = "��â��";
                    }
                    else if (player->getLevel() >= 6) {
                        if (generatedTutors.find("������") == generatedTutors.end()) {
                            tutorName = "������";
                        }
                        else if (generatedTutors.find("�ָ���") == generatedTutors.end()) {
                            tutorName = "�ָ���";
                        }
                    }
                    else if (player->getLevel() >= 3) {
                        if (generatedTutors.find("�ѿ���") == generatedTutors.end()) {
                            tutorName = "�ѿ���";
                        }
                        else if (generatedTutors.find("������") == generatedTutors.end()) {
                            tutorName = "������";
                        }
                        else if (generatedTutors.find("�ڰ���") == generatedTutors.end()) {
                            tutorName = "�ڰ���";
                        }
                    }
                    else {
                        if (generatedTutors.find("������") == generatedTutors.end()) {
                            tutorName = "������";
                        }
                        else if (generatedTutors.find("������") == generatedTutors.end()) {
                            tutorName = "������";
                        }
                    }

                    if (!tutorName.empty() && generatedTutors.find(tutorName) == generatedTutors.end()) {
                        generatedTutors.insert(tutorName);

                        if (tutorName == "��â��") {
                            currentTutor = new ChallengeTutor(*player, tutorName);
                        }
                        else if (tutorName == "������" || tutorName == "�ָ���") {
                            currentTutor = new StandardTutor(*player, tutorName);
                        }
                        else if (tutorName == "�ѿ���" || tutorName == "������" || tutorName == "�ڰ���") {
                            currentTutor = new BasicTutor(*player, tutorName);
                        }
                        else if (tutorName == "������" || tutorName == "������") {
                            currentTutor = new ManagerTutor(*player, tutorName);
                        }

                        break; // ���ο� Ʃ�͸� ���������� ���������Ƿ� ���� ����
                    }
                    else if (generatedTutors.size() == 1 + 2 + 3 + 2) {
                        // ��� Ʃ�Ͱ� �����Ǿ����� �� �̻� �������� ����
                        cout << "��� Ʃ�͸� �����ƽ��ϴ�. �����մϴ�!\n";
                        break;
                    }
                }
            }

            battle(*player, *currentTutor);

            if (currentTutor->getHp() <= 0) {
                delete currentTutor;
                currentTutor = nullptr;
            }

            if (player->getLevel() >= 10) {
                cout << "���� 10�� �����߽��ϴ�! ���� Ʃ�Ͱ� �����մϴ�!\n";
                Tutor* boss = new BossTutor(*player, "������ �Ŵ���");
                battle(*player, *boss);
                delete boss;
                break;
            }
        }
        else if (choice == 2) {
            cout << "\n������ ���:\n";
            cout << "1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. ChatGPT\n";
            cout << "�������� �����ϼ��� (1-5): ";
            int itemChoice;
            cin >> itemChoice;

            Item* selectedItem = nullptr;
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

            if (selectedItem) {
                selectedItem->Use(player);
                delete selectedItem;
            }
        }
        else if (choice == 3) {
            cout << "���� ����!\n";
            if (currentTutor != nullptr) {
                delete currentTutor;
            }
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n";
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

//// Tutor ���� �Լ� ����
//void generateTutor(Character& A, Tutor*& currentTutor)
//{
//    while (A.getLevel() <= 2)
//    {
//        srand((unsigned int)time(NULL)); // ���� �õ� ����
//        TutorType tutorType = static_cast<TutorType>(rand() % 4);  // 0���� 3���� ���� �� ����
//        switch (tutorType)
//        {
//        case TutorType::Manager:
//            currentTutor = new ManagerTutor(A, "������");
//            break;
//        case TutorType::Basic:
//            currentTutor = new BasicTutor(A, "������");
//            break;
//        case TutorType::Standard:
//            currentTutor = new StandardTutor(A, "������");
//            break;
//        case TutorType::Challenge:
//            currentTutor = new ChallengeTutor(A, "�赵��");
//            break;
//        case TutorType::Boss:
//            currentTutor = new BossTutor(A, "������");
//            break;
//        }
//    }
//
//    };

void AfterBattle(Character& A)
{
    cout << A.getName() << "�� ���� ü��: " << A.getHp() << "\n";
    cout << "������ ���: " << A.getGold() << "\n"; // ��尡 ����� ǥ�õǵ��� ����
    cout << A.getName() << "�� Level: " << A.getLevel() << "\n";
    cout << "ȹ���� ����ġ: " << A.getExp() << "\n";
}

// battle �Լ� ����
void GameManager::battle(Character& A, Tutor& B) {
    cout << "������ �����մϴ�!\n";

    while (A.getHp() > 0 && B.getHp() > 0) {

        // �÷��̾ ����
        int playerDamage = A.getAdd();
        B.takeDamage(playerDamage);
        cout << A.getName() << "��(��) ������ �����Ͽ���!\n";
        cout << A.getName() << "��(��) " << B.getName() << "���� " << playerDamage << "�� ���ظ� �������ϴ�!\n";

        // ���� ���� ���� Ȯ��
        if (B.getHp() <= 0) {
            cout << B.getName() << "�� �����ƽ��ϴ�!\n";
            // ���� ���� ���
            cout << "\n" << A.getName() << "�� ü��: " << A.getHp() << endl;
            A.setGold(A.getGold() + 10); // ����
            A.setExp(A.getExp() + 100); // ����ġ ȹ��
            //���� ���� ��� ���
            cout << "\n" << A.getName() << "�� ���� ���: " << A.getGold() << endl;
            break; // ���� ����
        }

        // Ʃ�Ͱ� �ݰ�
        int tutorDamage = B.getAdd();
        A.takeDamage(tutorDamage);
        cout << "�װ� �� �ּ��̾�?!\n";
        cout << B.getName() << "��(��) " << A.getName() << "���� " << tutorDamage << "�� ���ظ� �������ϴ�!\n";

        // ���� ���� ���� Ȯ��
        if (A.getHp() <= 0) {
            cout << A.getName() << "��(��) ���� ���߽��ϴ�...\n";
            break; // ���� ����
        }

        // ���� ���� ���
        cout << "\n" << A.getName() << "�� ü��: " << A.getHp() << endl;
        cout << B.getName() << "�� ü��: " << B.getHp() << endl;

        // �� ���� �� �޴��� ����
        cout << "\n���� ���� �޴��� ���ư��ϴ�.\n";
        return; // �޴��� ����
    }
}


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