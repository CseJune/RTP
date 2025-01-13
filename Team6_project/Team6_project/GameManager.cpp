#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include <set>

using namespace std;

set<string> generatedTutors;// 생성된 튜터 이름을 저장하는 set (사용하기 위해서는 #include <set> 사용 필요)


// StartGame 함수 정의
void GameManager::StartGame(int start) {
    string characterName;
    cout << "캐릭터 이름 입력: ";
    cin >> characterName;

    Character* player = Character::getinstance(characterName);
    player->displayStatus();

    Tutor* currentTutor = nullptr;  // 현재 튜터 포인터

    while (true) {
        int choice;
        int LeaveCamp;
        
        if (player->getLevel() == 0)
        {
            cout << "\n1. 캠프 입장\n2. 상점 입장\n3. 캠프 탈주\n4. 인벤토리 열기\n선택: ";            
            cin >> choice;
        }
        else {
            cout << "\n1. 전투 시작\n2. 인벤토리 열기\n3. 캠프 탈주\n선택: ";   
            cin >> choice;
        }
        if (player->getLevel() == 0 && choice == 1) {
            cout << "으하하하 나는 김이진 매니저다 사전 캠프부터 참여하고 와라!\n";
            cout << "선빵을 당하셨습니다...\n당신은 사망하였습니다...\n군필 여고생으로 환생 합니다.\n";
            player->setLevel(1);
            cout << "레벨 1로 환생 합니다.\n";
        }
        else if (player->getLevel() == 0 && choice == 3) {
            cout << "정말 캠프를 떠나시겠습니까?\n";
            cout << "\n1. 네\n2. 아니요\n선택:";
                cin >> LeaveCamp;
                if (LeaveCamp == 2) {
                    return;
                }
                else if(LeaveCamp == 1){
                    cout << "캠프를 탈주합니다.";
                    return;
                }
        }
        else if (choice == 1) {
            if (currentTutor == nullptr || currentTutor->getHp() <= 0) {
                srand((unsigned int)time(NULL));

                while (true) {
                    string tutorName;

                    if (player->getLevel() >= 8 && generatedTutors.find("강창밍") == generatedTutors.end()) {
                        tutorName = "강창밍";
                    }
                    else if (player->getLevel() >= 6) {
                        if (generatedTutors.find("문승헌") == generatedTutors.end()) {
                            tutorName = "문승헌";
                        }
                        else if (generatedTutors.find("최만성") == generatedTutors.end()) {
                            tutorName = "최만성";
                        }
                    }
                    else if (player->getLevel() >= 3) {
                        if (generatedTutors.find("한우정") == generatedTutors.end()) {
                            tutorName = "한우정";
                        }
                        else if (generatedTutors.find("박정신") == generatedTutors.end()) {
                            tutorName = "박정신";
                        }
                        else if (generatedTutors.find("박경후") == generatedTutors.end()) {
                            tutorName = "박경후";
                        }
                    }
                    else {
                        if (generatedTutors.find("배재희") == generatedTutors.end()) {
                            tutorName = "배재희";
                        }
                        else if (generatedTutors.find("박지민") == generatedTutors.end()) {
                            tutorName = "박지민";
                        }
                    }

                    if (!tutorName.empty() && generatedTutors.find(tutorName) == generatedTutors.end()) {
                        generatedTutors.insert(tutorName);

                        if (tutorName == "강창밍") {
                            currentTutor = new ChallengeTutor(*player, tutorName);
                        }
                        else if (tutorName == "문승헌" || tutorName == "최만성") {
                            currentTutor = new StandardTutor(*player, tutorName);
                        }
                        else if (tutorName == "한우정" || tutorName == "박정신" || tutorName == "박경후") {
                            currentTutor = new BasicTutor(*player, tutorName);
                        }
                        else if (tutorName == "배재희" || tutorName == "박지민") {
                            currentTutor = new ManagerTutor(*player, tutorName);
                        }

                        break; // 새로운 튜터를 성공적으로 생성했으므로 루프 종료
                    }
                    else if (generatedTutors.size() == 1 + 2 + 3 + 2) {
                        // 모든 튜터가 생성되었으면 더 이상 생성하지 않음
                        cout << "모든 튜터를 물리쳤습니다. 축하합니다!\n";
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
                cout << "레벨 10에 도달했습니다! 보스 튜터가 등장합니다!\n";
                Tutor* boss = new BossTutor(*player, "김이진 매니저");
                battle(*player, *boss);
                delete boss;
                break;
            }
        }
        else if (choice == 2) {
            cout << "\n아이템 목록:\n";
            cout << "1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. ChatGPT\n";
            cout << "아이템을 선택하세요 (1-5): ";
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
                cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
                continue;
            }

            if (selectedItem) {
                selectedItem->Use(player);
                delete selectedItem;
            }
        }
        else if (choice == 3) {
            cout << "게임 종료!\n";
            if (currentTutor != nullptr) {
                delete currentTutor;
            }
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 선택해주세요.\n";
        }
    }
}


// StartBoss 함수 정의
void GameManager::StartBoss()
{
    int Boss = 0; // 초기화
    while (true)
    {
        cout << "1. 코딩 공격\n";
        cin >> Boss;

        if (Boss == 1)
        {
            cout << "데미지가 들어가지 않습니다.\n";
            break;
        }
        else
        {
            cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
        }
    }
}

//// Tutor 생성 함수 정의
//void generateTutor(Character& A, Tutor*& currentTutor)
//{
//    while (A.getLevel() <= 2)
//    {
//        srand((unsigned int)time(NULL)); // 랜덤 시드 설정
//        TutorType tutorType = static_cast<TutorType>(rand() % 4);  // 0에서 3까지 랜덤 값 생성
//        switch (tutorType)
//        {
//        case TutorType::Manager:
//            currentTutor = new ManagerTutor(A, "배재희");
//            break;
//        case TutorType::Basic:
//            currentTutor = new BasicTutor(A, "박지민");
//            break;
//        case TutorType::Standard:
//            currentTutor = new StandardTutor(A, "이찬형");
//            break;
//        case TutorType::Challenge:
//            currentTutor = new ChallengeTutor(A, "김도연");
//            break;
//        case TutorType::Boss:
//            currentTutor = new BossTutor(A, "김이진");
//            break;
//        }
//    }
//
//    };

void AfterBattle(Character& A)
{
    cout << A.getName() << "의 남은 체력: " << A.getHp() << "\n";
    cout << "보유한 골드: " << A.getGold() << "\n"; // 골드가 제대로 표시되도록 수정
    cout << A.getName() << "의 Level: " << A.getLevel() << "\n";
    cout << "획득한 경험치: " << A.getExp() << "\n";
}

// battle 함수 정의
void GameManager::battle(Character& A, Tutor& B) {
    cout << "전투를 시작합니다!\n";

    while (A.getHp() > 0 && B.getHp() > 0) {

        // 플레이어가 공격
        int playerDamage = A.getAdd();
        B.takeDamage(playerDamage);
        cout << A.getName() << "이(가) 과제를 제출하였다!\n";
        cout << A.getName() << "이(가) " << B.getName() << "에게 " << playerDamage << "의 피해를 입혔습니다!\n";

        // 전투 종료 조건 확인
        if (B.getHp() <= 0) {
            cout << B.getName() << "를 물리쳤습니다!\n";
            // 현재 상태 출력
            cout << "\n" << A.getName() << "의 체력: " << A.getHp() << endl;
            A.setGold(A.getGold() + 10); // 보상
            A.setExp(A.getExp() + 100); // 경험치 획득
            //현재 보유 골드 출력
            cout << "\n" << A.getName() << "의 보유 골드: " << A.getGold() << endl;
            break; // 전투 종료
        }

        // 튜터가 반격
        int tutorDamage = B.getAdd();
        A.takeDamage(tutorDamage);
        cout << "그게 네 최선이야?!\n";
        cout << B.getName() << "이(가) " << A.getName() << "에게 " << tutorDamage << "의 피해를 입혔습니다!\n";

        // 전투 종료 조건 확인
        if (A.getHp() <= 0) {
            cout << A.getName() << "이(가) 제적 당했습니다...\n";
            break; // 전투 종료
        }

        // 현재 상태 출력
        cout << "\n" << A.getName() << "의 체력: " << A.getHp() << endl;
        cout << B.getName() << "의 체력: " << B.getHp() << endl;

        // 턴 종료 후 메뉴로 복귀
        cout << "\n현재 선택 메뉴로 돌아갑니다.\n";
        return; // 메뉴로 복귀
    }
}


/* Tutor 함수 정의 (추가 함수로 예시)
void Tutor()
{
    if (currentTutor != nullptr)
    {
        cout << currentTutor->getName() << "이(가) 당신에게 도전합니다!\n";
    }
    else
    {
        cout << "튜터가 없습니다.\n";
    }
}*/

// 전투 후 보유 골드, 레벨, 경험치 확인

      /*  int main()
        {
            int start = 0;

            cout << "코딩을 시작하시겠습니까?\n";
            cout << "1. 시작한다 \n2. 종료한다\n";
            cin >> start;

            StartGame(start);

            cout << "으하하하 나는 김이진 매니저다 너같이 GPT만 쓰는 개발자는 용서할 수 없지!\n";
            cout << "매니저와 조우하셨습니다. 무엇을 하시겠습니까?\n";

            StartBoss();

            return 0;
        }*/