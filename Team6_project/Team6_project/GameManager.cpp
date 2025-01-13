#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"

using namespace std;


// StartGame 함수 정의
void GameManager::StartGame(int start)
{
    string characterName;
    cout << "캐릭터 이름 입력: ";
    cin >> characterName;

    // 캐릭터 객체 생성 (싱글톤 패턴)
    Character* player = Character::getinstance(characterName);
    player->displayStatus();

    vector<Item*> inventory;  // 플레이어의 아이템 목록

    // 레벨이 10에 도달할 때까지 전투 반복
    while (player->getLevel() < 10)
    {
        // 메뉴 출력
        cout << "\n1. 전투 시작\n2. 아이템 목록\n3. 종료\n선택: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            // 전투 시작
            Tutor* monster = nullptr;

            // 레벨에 맞는 튜터(몬스터) 생성
            if (player->getLevel() >= 8) {
                monster = new ChallengeTutor(*player, "챌린지 튜터");
            }
            else if (player->getLevel() >= 6) {
                monster = new StandardTutor(*player, "스탠다드 튜터");
            }
            else if (player->getLevel() >= 3) {
                monster = new BasicTutor(*player, "베이직 튜터");
            }
            else {
                monster = new ManagerTutor(*player, "매니저 튜터");
            }

            // 전투 시작
            battle(*player, *monster);
            player->displayStatus();

            // 경험치가 100을 넘으면 레벨업
            if (player->getLevel() >= 10) {
                cout << "레벨 10에 도달했습니다! 보스 튜터가 등장합니다!\n";
                Tutor* boss = new BossTutor(*player, "김이진 매니저");
                battle(*player, *boss);
                break;  // 보스와의 전투 후 게임 종료
            }
        }
        else if (choice == 2) {
            // 아이템 목록 선택
            cout << "\n아이템 목록:\n";
            cout << "1. HealthPotion\n";
            cout << "2. CodingBooster\n";
            cout << "3. MaxHealthPotion\n";
            cout << "4. TutorAttackReduction\n";
            cout << "5. ChatGPT\n";
            cout << "아이템을 선택하세요 (1-5): ";
            int itemChoice;
            cin >> itemChoice;

            Item* selectedItem = nullptr;

            // 아이템 생성
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

            // 아이템 사용
            if (selectedItem) {
                selectedItem->Use(player);  // 아이템 사용
                delete selectedItem;  // 아이템 사용 후 메모리 해제
            }
        }
        else if (choice == 3) {
            cout << "게임 종료!\n";
            break;
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

// Tutor 생성 함수 정의
void generateTutor(Character& A, Tutor*& currentTutor)
{
    while (A.getLevel() <= 2)
    {
        srand((unsigned int)time(NULL)); // 랜덤 시드 설정
        TutorType tutorType = static_cast<TutorType>(rand() % 4);  // 0에서 3까지 랜덤 값 생성
        switch (tutorType)
        {
        case TutorType::Manager:
            currentTutor = new ManagerTutor(A, "배재희");
            break;
        case TutorType::Basic:
            currentTutor = new BasicTutor(A, "박지민");
            break;
        case TutorType::Standard:
            currentTutor = new StandardTutor(A, "이찬형");
            break;
        case TutorType::Challenge:
            currentTutor = new ChallengeTutor(A, "김도연");
            break;
        case TutorType::Boss:
            currentTutor = new BossTutor(A, "김이진");
            break;
        }
    }

    };

// battle 함수 정의
void GameManager::battle(Character & A, Tutor & B)
    {
        cout << "전투를 시작합니다!\n";

        while (A.getHp() > 0 && B.getHp() > 0)
        {
            // 플레이어가 공격
            int add = A.getAdd();
            B.takeDamage(add);
            cout << A.getName() << "이(가) " << B.getName() << "에게 " << add << "의 피해를 입혔습니다!\n";

            // 튜터가 공격
            if (B.getHp() > 0)
            {
                int add = B.getAdd();
                A.takeDamage(add);
                cout << B.getName() << "이(가) " << A.getName() << "에게 " << add << "의 피해를 입혔습니다!\n";
            }

            // 전투 결과 확인
            if (B.getHp() <= 0)
            {
                cout << B.getName() << "를 물리쳤습니다!\n";
                A.setGold(A.getGold() + 10); // 보상
                A.setExp(A.getExp() + 100); // 경험치 획득
            }
            else if (A.getHp() <= 0) {
                cout << A.getName() << "이(가) 제적 당했습니다...\n";
            }
        }
    };

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
void AfterBattle(Character& A)
{
    cout << A.getName() << "의 남은 체력: " << A.getHp() << "\n";
    cout << "보유한 골드: " << A.getGold() << "\n"; // 골드가 제대로 표시되도록 수정
    cout << A.getName() << "의 Level: " << A.getLevel() << "\n";
    cout << "획득한 경험치: " << A.getExp() << "\n";
}

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