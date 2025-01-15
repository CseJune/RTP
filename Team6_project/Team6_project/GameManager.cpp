#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "Monster.h"
#include <set>
#include "Shop.h"
#include "Logger.h"

using namespace std;

set<string> generatedTutors;// 생성된 튜터 이름을 저장하는 set (사용하기 위해서는 #include <set> 사용 필요)
Shop* shop;  // 상점 객체 포인터

// StartGame 함수 정의
void GameManager::StartGame(int parameter) {
    string characterName;
    cout << "캐릭터 이름 입력: ";
	writeLog("캐릭터 생성 ");
    cin >> characterName;

    Character* player = Character::getinstance(characterName);
    player->displayStatus();
	writeLog("캐릭터 이름 입력: " + characterName);

    Tutor* currentTutor = nullptr;  // 현재 튜터 포인터

    while (true) {
        int choice;
        int LeaveCamp;
        
        if (player->getLevel() == 0)
        {
            cout << "\n1. 캠프 입장\n2. 인벤토리 열기\n3. 상점 입장\n4. 캠프 탈주\n선택: ";            
            cin >> choice;
        }
        else {
            cout << "\n1. 전투 시작\n2. 인벤토리 열기\n3. 상점 입장\n4. 캠프 탈주\n선택: ";   
            cin >> choice;
        }

        if (player->getLevel() == 9 && choice == 1){
            cout << "실력이 부족하군요.\n";
            cout << "무엇이 부족한지 생각해 보셨나요?\n";
            cout << "당신 혼자선 불가능합니다.\n";
			writeLog("실력이 부족하군요. 무엇이 부족한지 생각해 보셨나요? 당신 혼자선 불가능합니다.");
        }

        if (player->getLevel() == 0 && choice == 1) {
            cout << "으하하하 나는 김이진 매니저다 사전 캠프부터 참여하고 와라!\n";
            cout << "선빵을 당하셨습니다...\n당신은 사망하였습니다...\n군필 여고생으로 환생 합니다.\n";
            player->setLevel(1);
            cout << "레벨 1로 환생 합니다.\n";
			writeLog("레벨 1로 환생 ");
		}
		else if (player->getLevel() == 0 && choice == 2) {
			cout << "\n아이템 목록:\n";
			writeLog("아이템 목록 ");
			/*cout << "1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. ChatGPT\n";*/
			writeLog("1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. TutorHealthReduction\n");
			Character* player = Character::getinstance();
			Inventory* inventory = player->getInventory();
			inventory->displayInventory();
			cout << "아이템을 선택하세요 (1-5): ";
			writeLog("아이템 선택 ");
			int itemChoice;
			cin >> itemChoice;
			// 인덱스를 확인하고 아이템 선택 후 사용
			if (itemChoice >= 1 && itemChoice <= inventory->getItemCount()) {
				string itemName = inventory->getItemNameByIndex(itemChoice - 1);  // 아이템 이름을 인덱스로부터 얻음
				if (inventory->useItem(itemName, player, currentTutor)) {  // 선택한 아이템 사용
					cout << "아이템 사용 성공!\n";
					writeLog("아이템 사용 성공 ");
				}
				else {
					cout << "아이템 사용 실패.\n";
					writeLog("아이템 사용 실패 ");
				}
			}
			else {
				cout << "잘못된 선택입니다.\n";
			}
		}
        else if (player->getLevel() == 0 && choice == 4) {
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
        else if (choice == 3) {
            int shopChoice;
            
            if (shop == nullptr)
            {
                shop = new Shop();
            }

            while (true) {
               /* cout << "\n===== 상점 =====\n";*/
                shop->displayItems(player);  // 상점 아이템 목록 표시
				writeLog("상점 입장 ");
                cout << "\n1. 아이템 구매\n2. 아이템 판매\n3. 상점 나가기\n선택: ";
                cin >> shopChoice;

                if (shopChoice == 1) {  // 아이템 구매
                    cout << "구매하고 싶은 아이템의 번호를 입력하세요: ";
                    int itemChoice;
                    cin >> itemChoice;

                    if (itemChoice >= 1 && itemChoice <= shop->getAvailableItems().size()) {
                        string itemName = shop->getAvailableItems()[itemChoice - 1]->GetName();
                        shop->buyItem(player, itemName);  // 아이템 구매 처리
                    }
                    else {
                        cout << "잘못된 선택입니다.\n";
                    }
                }
                else if (shopChoice == 2) {  // 아이템 판매
                    // 인벤토리에서 판매 가능한 아이템 목록 출력
                    Inventory* inventory = player->getInventory();
                    cout << "판매 가능한 아이템 목록:\n";
                    inventory->displayInventory();  // 인벤토리에서 아이템 목록 출력

                    cout << "판매하고 싶은 아이템의 번호를 입력하세요: ";
                    int itemChoice;
                    cin >> itemChoice;

                    if (itemChoice >= 1 && itemChoice <= inventory->getItemCount()) {
                        string itemName = inventory->getItemNameByIndex(itemChoice - 1);  // 아이템 이름을 인덱스로부터 얻음
                        shop->sellItem(player, itemName);  // 아이템 판매 처리
                        cout << "아이템을 판매한 후 상점에서 나갑니다.\n";
						wcerr << "아이템을 판매한 후 상점에서 나갑니다.\n";
                        break;  // 상점에서 나가기
                    }
                    else {
                        cout << "잘못된 선택입니다.\n";
                    }
                }
                else if (shopChoice == 3) {  // 상점 나가기
					writeLog("상점 나가기 ");
                    break;  // 상점에서 나가기
                }
                else {
                    cout << "잘못된 선택입니다.\n";
                }
			}
		}

        else if (choice == 1) {
            if (currentTutor == nullptr || currentTutor->getHp() <= 0) {
                srand((unsigned int)time(NULL));

                while (true) {
                    string tutorName;

                    if (player->getLevel() >= 8 && generatedTutors.find("강창밍") == generatedTutors.end()) {
                        tutorName = "강창밍";
						writeLog("강창밍 튜터 생성 ");
                    }
                    else if (player->getLevel() >= 6) {
                        if (generatedTutors.find("문승헌") == generatedTutors.end()) {
                            tutorName = "문승헌";
							writeLog("문승헌 튜터 생성 ");
                        }
                        else if (generatedTutors.find("최만성") == generatedTutors.end()) {
                            tutorName = "최만성";
							writeLog("최만성 튜터 생성 ");
                        }
                    }
                    else if (player->getLevel() >= 3) {
                        if (generatedTutors.find("한우정") == generatedTutors.end()) {
                            tutorName = "한우정";
							writeLog("한우정 튜터 생성 ");
                        }
                        else if (generatedTutors.find("박정신") == generatedTutors.end()) {
                            tutorName = "박정신";
							writeLog("박정신 튜터 생성 ");
                        }
                        else if (generatedTutors.find("박경후") == generatedTutors.end()) {
                            tutorName = "박경후";
							writeLog("박경후 튜터 생성 ");
                        }
                    }
                    else {
                        if (generatedTutors.find("배재희") == generatedTutors.end()) {
                            tutorName = "배재희";
							writeLog("배재희 매니저 생성 ");
                        }
                        else if (generatedTutors.find("박지민") == generatedTutors.end()) {
                            tutorName = "박지민";
							writeLog("박지민 매니저 생성 ");
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
                        break;
                    }
                }
            }

            battle(*player, *currentTutor);

            if (currentTutor->getHp() <= 0) {
                delete currentTutor;
                currentTutor = nullptr;
            }
            if (player->getLevel() >= 9) {
                cout << "뭔가 사용해야지 보스전을 할 수 있을 것 같은데?\n";
				writeLog("뭔가 사용해야지 보스전을 할 수 있을 것 같은데? ");
            }

            if (player->getLevel() >= 10) {
                cout << "레벨 10에 도달했습니다! 보스 튜터가 등장합니다!\n";
				writeLog("레벨 10에 도달했습니다! 보스 튜터가 등장합니다! ");
                Tutor* boss = new BossTutor(*player, "김이진 매니저");
				writeLog("김이진 매니저 생성 ");
                battle(*player, *boss);
                delete boss;
                break;
            }
        }
        else if (choice == 2) {
            cout << "\n아이템 목록:\n";
            /*cout << "1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. ChatGPT\n";*/
            Character* player = Character::getinstance();
            Inventory* inventory = player->getInventory();
            inventory->displayInventory();
            cout << "인벤토리 닫기 (0)" << endl;
            cout << "아이템을 선택하세요 (0-5): " << endl;
            int itemChoice;
            cin >> itemChoice;

            // 인덱스를 확인하고 아이템 선택 후 사용
            if (itemChoice >= 1 && itemChoice <= inventory->getItemCount()) {
                string itemName = inventory->getItemNameByIndex(itemChoice - 1);  // 아이템 이름을 인덱스로부터 얻음
                if (inventory->useItem(itemName, player, currentTutor)) {  // 선택한 아이템 사용
                    cout << "아이템 사용 성공!\n";
                }
                else {
                    cout << "아이템 사용 실패.\n";
                }
            }
            else {
                cout << "잘못된 선택입니다.\n";
            }
            


        }
        else if (choice == 4) {
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

//void AfterBattle(Character& A)
//{
//    cout << A.getName() << "의 남은 체력: " << A.getHp() << "\n";
//    cout << "보유한 골드: " << A.getGold() << "\n"; // 골드가 제대로 표시되도록 수정
//    cout << A.getName() << "의 Level: " << A.getLevel() << "\n";
//    cout << "획득한 경험치: " << A.getExp() << "\n";
//}

// battle 함수 정의
void GameManager::battle(Character& A, Tutor& B) {

    while (A.getHp() > 0 && B.getHp() > 0) 
{
        cout << "전투를 시작합니다!\n";

        // 플레이어가 공격
        int playerDamage = A.getAdd();
        B.takeDamage(playerDamage);
        cout << A.getName() << "이(가) 과제를 제출하였다!\n";
		writeLog(A.getName() + "이(가) 과제를 제출하였다! ");
        cout << A.getName() << "이(가) " << B.getName() << "에게 " << playerDamage << "의 피해를 입혔습니다!\n";
		writeLog(A.getName() + "이(가) " + B.getName() + "에게 " + to_string(playerDamage) + "의 피해를 입혔습니다! ");

        // 전투 종료 조건 확인
        if (B.getHp() <= 0) {
            cout << B.getName() << "를 물리쳤습니다!\n";
            writeLog(B.getName() + "를 물리쳤습니다! ");
            Character* player = Character::getinstance();
            Inventory* inventory = player->getInventory();
            inventory->dropItem(B.getItem());
       
            A.setGold(A.getGold() + B.getGold()); // 보상
            A.setExp(A.getExp() + 100); // 경험치 획득
            // 현재 상태 출력
            A.displayStatus();

            //cout << "\n" << A.getName() << "의 레벨: " << A.getLevel() << endl;
            //cout << A.getName() << "의 체력: " << A.getHp() << endl;
            //cout << A.getName() << "의 코딩력: " << A.getAdd() << endl;
            //cout << A.getName() << "의 보유 골드: " << A.getGold() << endl;

            break; // 전투 종료
        }

        // 튜터가 반격
        int tutorDamage = B.getAdd();
        A.takeDamage(tutorDamage);
        cout << "그게 네 최선이야?!\n";
		writeLog("그게 네 최선이야?! ");
        cout << B.getName() << "이(가) " << A.getName() << "에게 " << tutorDamage << "의 피해를 입혔습니다!\n";
		writeLog(B.getName() + "이(가) " + A.getName() + "에게 " + to_string(tutorDamage) + "의 피해를 입혔습니다! ");

        // 전투 종료 조건 확인
        if (A.getHp() <= 0) {
            cout << A.getName() << "이(가) 제적 당했습니다...\n";
            cout << "당신은 패배자입니다.\n긁?\n";
			writeLog(A.getName() + "이(가) 제적 당했습니다... 당신은 패배자입니다. 긁? ");
            exit(0); // 게임 종료
        }

        // 현재 상태 출력
        cout << "\n" << A.getName() << "의 체력: " << A.getHp() << endl;
        cout << B.getName() << "의 체력: " << B.getHp() << endl;

        // 턴 종료 후 메뉴로 복귀
        cout << "\n현재 선택 메뉴로 돌아갑니다.\n";
		writeLog("현재 선택 메뉴로 돌아갑니다. ");
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