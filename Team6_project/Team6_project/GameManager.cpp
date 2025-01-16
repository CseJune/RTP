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
#include <chrono>
#include <thread>

using namespace std;

set<string> generatedTutors;// 생성된 튜터 이름을 저장하는 set (사용하기 위해서는 #include <set> 사용 필요)
Shop* shop;  // 상점 객체 포인터

void clearScreen();
void slowPrint(const string& text, int delayMs = 1);

// StartGame 함수 정의
void GameManager::StartGame(int parameter) {
	initializeLog();
	string characterName;
	cout << "캐릭터 이름 입력: ";
	writeLog("캐릭터 생성 ");
	cin >> characterName;

	Character* player = Character::getinstance(characterName);
	player->displayStatus();

	Tutor* currentTutor = nullptr;  // 현재 튜터 포인터

	while (true) {
		int choice;
		int LeaveCamp;

		if (player->getLevel() == 0)
		{
			cout << "\n☞ ☞ ☞ ☞ 1. 캠프 입장 ☜ ☜ ☜ ☜ \n♥ ♥ ♥ 2. 인벤토리 열기 ♥ ♥ ♥ \n♡ ♡ ♡ ♡ 3. 상점 입장 ♡ ♡ ♡ ♡ \n☞ ☞ ☞ ☞ 4. 캠프 탈주 ☜ ☜ ☜ ☜ \n선택: ";
			cin >> choice;
		}
		else {
			cout << "\n1. 전투를 시작해서 적들을 혼내줄래요! \n2. 곤듀님의 귀여운 인벤토리를 열어볼까요? \n3. 상점에 가서 곤듀님 취향저격 아이템 쇼핑! \n4. 곤듀님, 캠프에서 탈출하실 거예요? \n선택: ";
			cin >> choice;
		}

		if (player->getLevel() == 9 && choice == 1) {
			cout << "실력이 부족하군요.\n";
			cout << "무엇이 부족한지 생각해 보셨나요?\n";
			cout << "당신 혼자선 불가능합니다.\n";
			writeLog("실력이 부족하군요. 무엇이 부족한지 생각해 보셨나요? 당신 혼자선 불가능합니다.");
		}
		
		if (player->getLevel() == 0 && choice == 1) {
			/*slowPrint ( "주인공은 건강히 군대를 제대하고 프로그래머로써 대기업에 취업하기 위해 스파르타 코딩 캠프에 지원했었다. \n" );
			slowPrint ( "GPT를 사용해서 과제들을 해결하고, 스파르타 코딩 캠프를 진행했었는데 진행 중에 김이진 매니저에게 GPT사용을 들켰고 GPT를 압수당했다. \n" );
			slowPrint ( "GPT를 잃은 주인공은 코딩실력이 매우 하락하였고 마지막 과제를 수행하지 못한 나머지 모든 튜터들은 주인공에게 실망했다. \n" );
			slowPrint ( "그 자괴감과 수치심에 주인공은 캠프를 탈주하게 되었다. \n" );
			slowPrint ( "이때 갑자기 돌진하는 트럭에 치여서 죽은줄 알았으나 눈을 떠보니 GPT를 잃은 상태로 처음 스파르타 코딩 캠프에 돌아오게 되었다. \n" );
			slowPrint ("그런데");
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << "." << endl;
			
			this_thread::sleep_for(chrono::seconds(2));
			cout << "\n ♥ ♥ ♥ ♥ ♥ ♥ 여고생이 되어버렸지 모야 ♥ ♥ ♥ ♥ ♥ " << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << " ♥ ♥ ♥ ♥ ♥ ♥ 이제 복수의 시간이얏 ♥ ♥ ♥ ♥ ♥ ♥ " << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << " ♥ ♥ ♥ ♥ ♥ ♥ 곤듀의 GPT를 되찾뀨 ♥ ♥ ♥ ♥ ♥ ♥ " << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << " ♥ ♥ ♥ ♥ ♥ ♥ 대기업 추천서를 얻쟈 ♥ ♥ ♥ ♥ ♥ ♥ " << endl;
			this_thread::sleep_for(chrono::seconds(2));

			slowPrint ("환생했더니 군필여고생이 튜터님을 죽일 수 밖에 없었던 이유♥ ");*/
			player->setLevel(1);
			cout << "\n곤듀! 스파르타 세상에 등쟝!\n";
			cout << "곤듀가 레벨 1로 환생하였습니다." << endl;
			writeLog("곤듀! 스파르타 세상에 등쟝! ");
		}
		else if (player->getLevel() == 0 && choice == 2) {
			cout << "\n곤쥬님~ 이 중에서 찰떡템 골라볼까요? : \n";
			writeLog("곤듀만의 비밀 상점 목록 ");
			/*cout << "1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. ChatGPT\n";*/
			writeLog("1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. TutorHealthReduction\n");
			Character* player = Character::getinstance();
			Inventory* inventory = player->getInventory();
			inventory->displayInventory();
			cout << " 곤듀의 선택! : ";
			writeLog("아이템 선택! ");
			int itemChoice;
			cin >> itemChoice;
			// 인덱스를 확인하고 아이템 선택 후 사용
			if (itemChoice >= 1 && itemChoice <= inventory->getItemCount()) {
				string itemName = inventory->getItemNameByIndex(itemChoice - 1);  // 아이템 이름을 인덱스로부터 얻음
				if (inventory->useItem(itemName, player, currentTutor)) {  // 선택한 아이템 사용
					cout << "곤듀 강화 성공♥\n";
					writeLog("곤듀 강화 성공♥ ");
				}
				else {
					cout << "곤듀 강화 실패ㅠ_ㅠ.\n";
					writeLog("곤듀 강화 실패ㅠ_ㅠ ");
				}
			}
			else {
				clearScreen();
				cout << "이런! 곤듀님, 잘못된 선택이에요!\n";
			}
		}
		else if (player->getLevel() == 0 && choice == 4) {
			cout << "정말 캠프를 떠나시겠습니까?\n";
			cout << "\n1. 네\n2. 아니요\n선택:";
			cin >> LeaveCamp;
			if (LeaveCamp == 2) {
				clearScreen();
				slowPrint("좋은 선택이야♥ 곤듀는 빨간불에도 멈추지 않는다고 Boy~♥\n");
			}
			else if (LeaveCamp == 1) {
				clearScreen();
				slowPrint ("어.딜.도.망.가? 곤듀는 빨간불에도 멈추지 않는다고 Boy~♥\n");
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
				cout << "\n1. 곤듀님의 쇼핑타임! 아이템을 사서 힘을 키워요!\n2. 아이템 팔아서 귀여운 곤듀님만의 재산을 쌓아요!\n3. 아쉽지만, 상점은 잠시 안녕! 새로운 모험을 떠나요!\n 곤듀의 선택: ";
				cin >> shopChoice;

				if (shopChoice == 1) {  // 아이템 구매
					cout << "곤듀님~ 어떤 아이템이 마음에 드세요? 번호를 골라주세요~! : ";
					int itemChoice;
					cin >> itemChoice;

					if (itemChoice >= 1 && itemChoice <= shop->getAvailableItems().size()) {
						string itemName = shop->getAvailableItems()[itemChoice - 1]->GetName();
						shop->buyItem(player, itemName);  // 아이템 구매 처리
					}
					else {
						cout << "이런! 곤듀님, 잘못된 선택이에요!\n";
					}
				}
				else if (shopChoice == 2) {  // 아이템 판매
					// 인벤토리에서 판매 가능한 아이템 목록 출력
					Inventory* inventory = player->getInventory();
					cout << "곤듀님! 판매 가능한 아이템 목록이에요~!\n";
					inventory->displayInventory();  // 인벤토리에서 아이템 목록 출력

					cout << "아이템을 팔고 싶으면 번호를 골라주세요! ";
					int itemChoice;
					cin >> itemChoice;

					if (itemChoice >= 1 && itemChoice <= inventory->getItemCount()) {
						string itemName = inventory->getItemNameByIndex(itemChoice - 1);  // 아이템 이름을 인덱스로부터 얻음
						shop->sellItem(player, itemName);  // 아이템 판매 처리
						cout << "아이템을 팔았어요! 이제 곤듀님은 돈도 많이 벌어요~!\n";
						writeLog( "아이템을 팔았어요! 이제 곤듀님은 돈도 많이 벌어요~!\n");
						break;  // 상점에서 나가기
					}
					else {
						cout << "이런! 곤듀님, 잘못된 선택이에요!\n";
					}
				}
				else if (shopChoice == 3) {  // 상점 나가기
					writeLog("상점 나가기 ");
					break;  // 상점에서 나가기
				}
				else {
					cout << "이런! 곤듀님, 잘못된 선택이에요!\n";
				}
			}
		}

		else if (choice == 1) {
			if (currentTutor == nullptr || currentTutor->getHp() <= 0) {
				srand((unsigned int)time(NULL));

				while (true) {
					string tutorName;

					if (player->getLevel() >= 10 && generatedTutors.find("김이진") == generatedTutors.end()) {
						tutorName = "김이진";
						writeLog("김이진 매니저 생성 ");
						cout << "곤듀님! 레벨 10에 도달했어요! 드디어... 보스 튜터가 나타났어요! \n";
						cout << "이제 곤듀님의 진짜 힘을 보여줄 때에요! " << endl;
				writeLog("레벨 10에 도달했습니다! 보스 튜터가 등장합니다! ");
					}
					else if (player->getLevel() == 9) {
						return;
						writeLog("강창밍 튜터 생성 ");
					}

					else if (player->getLevel() >= 8 && generatedTutors.find("강창밍") == generatedTutors.end()) {
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

						if (tutorName == "김이진") {
							currentTutor = new BossTutor(*player, tutorName);
						}

						else if (tutorName == "강창밍") {
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

					/*if (!tutorName.empty() && generatedTutors.find(tutorName) == generatedTutors.end()) {
						generatedTutors.insert(tutorName);

						if (tutorName == "김이진") {
							currentTutor = new BossTutor(*player, tutorName);
						}*/
						//    break; // 새로운 튜터를 성공적으로 생성했으므로 루프 종료
						//}
					else if (generatedTutors.size() == 1 + 1 + 2 + 3 + 2) {
						break;
					}
				}
			}

			battle(*player, *currentTutor);

			if (currentTutor->getHp() <= 0) {
				delete currentTutor;
				currentTutor = nullptr;
			}
			if (player->getLevel() == 9) {
				cout << "어머나! 보스 튜터와 전투 전에 뭔가 필요한 것 같아요!\n";
				cout << "전투에 승리하려면 준비물이 필수에요!" << endl;
				writeLog("어머나! 보스 튜터와 전투 전에 뭔가 필요한 것 같아요! ");
			}

			if (player->getLevel() >= 10) 
			{
				/*cout << "레벨 10에 도달했습니다! 보스 튜터가 등장합니다!\n";
				writeLog("레벨 10에 도달했습니다! 보스 튜터가 등장합니다! ");*/
				/*Tutor* boss = new BossTutor(*player, "김이진 매니저");
				writeLog("김이진 매니저 생성 ");
				battle(*player, *boss);
				delete boss;*/
			}
		}
		else if (choice == 2) {
			cout << "\n아이템 목록:\n";
			/*cout << "1. HealthPotion\n2. CodingBooster\n3. MaxHealthPotion\n4. TutorAttackReduction\n5. ChatGPT\n";*/
			Character* player = Character::getinstance();
			Inventory* inventory = player->getInventory();
			inventory->displayInventory();
			cout << "곤듀님의 귀여운 인벤토리를 닫아볼까요? ♥(0)♥" << endl;

			if (inventory->getItemCount() != 0)
			{
				cout << "곤듀님만의 비밀 무기를 선택하세요! ♥번호입력♥ : ";
			}
			int itemChoice;
			cin >> itemChoice;

			// 인덱스를 확인하고 아이템 선택 후 사용
			if (itemChoice >= 1 && itemChoice <= inventory->getItemCount()) {
				string itemName = inventory->getItemNameByIndex(itemChoice - 1);  // 아이템 이름을 인덱스로부터 얻음
				if (inventory->useItem(itemName, player, currentTutor)) {  // 선택한 아이템 사용
					/*cout << "아이템 사용 성공!\n";*/
				}
				else {
					/*cout << "아이템 사용 실패.\n";*/
				}
			}
			else if (itemChoice == 0)
			{
				cout << "곤듀님의 귀여운 인벤토리를 닫았어요!.\n";
			}
			else
			{
				cout << "이런! 곤듀님, 잘못된 선택이에요! \n";
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
			cout << "이런! 곤듀님, 잘못된 선택이에요! 다시 선택해볼까요?\n";
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
		cout << "곤듀님 출동♥ 상대를 함락시킬 시간이에요♥ (♥)`ω´(♥) \n";

		// 플레이어가 공격
		int playerDamage = A.getAdd();
		B.takeDamage(playerDamage);
		cout << A.getName() << "곤듀의 화려한 코딩 테크닉을 받아랏~♥ \n";
		writeLog(A.getName() + "곤듀의 화려한 코딩 테크닉을 받아랏~♥ ");
		cout << A.getName() << "곤듀가 " << B.getName() << "에게 " << playerDamage << "의 피해를 주었어요~♥ 곤듀님, 너무 귀엽지만 강해요! \n";
		writeLog(A.getName() + "곤듀가 " + B.getName() + "에게 " + to_string(playerDamage) + "의 피해를 주었어요~♥ 곤듀님, 너무 귀엽지만 강해요! ");

		// 전투 종료 조건 확인
		if (B.getHp() <= 0) {
			cout << B.getName() << "을(를) 핑크빛 코딩력으로 함락시켰습니다♥ \n";
			writeLog(B.getName() + "을(를) 핑크빛 코딩력으로 함락시켰습니다♥ ");
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

			// 보스 튜터 처치 확인
			if (B.getType() == TutorType::Boss) { // isBoss()는 Tutor 클래스의 함수로, 보스 여부 확인
				cout << "축하합니다! 김이진 매니저님에게 ♥인정♥받았습니다. \n";
				cout << "김이진 매니저님이 제출한 과제를 보고 기쁨의 눈물을 흘립니다. \n";
				cout << "김이진 매니저 : 이제 스파르타 캠프를 졸업하셔도 되겠군요... \n";
				cout << "주인공 : 드디어 대기업 입사 추천서를 주시는 건가요? \n";
				cout << "김이진 매니저 : 네♥ 지금 드리겠습니다. 하지만 마음이 바뀌신다면.. 스파르타는 항상 열려있습니다. \n";


				//분기 1 대기업 추천서 받기
				cout << " 1. 곤듀님, 대기업에 입사할 준비가 됐어~ ♥ " << endl;
				cout << " 2. 스파르타의 전설, 곤듀님과 함께 시작합니다~ ♥ " << endl;
				int choice = 0;
				cin >> choice;
				if (choice == 1)
				{
					slowPrint ( "대기업 입사 추천서를 받았습니다.\n");
					slowPrint ( "곤듀는 대기업 입사 추천서를 가지고 C기업에 지원했으나 면접에서 외모로 인해 탈락했다. \n");
					slowPrint ( "결국 곤듀는 프로그래머가 아닌 군인의 길을 걷기로 결정했다. \n");
					slowPrint ( "♥ ♥ ♥ ♥ ♥ ♥ ♥ 곤 듀 충 뗭 ♥ ♥ ♥ ♥ ♥ ♥ ♥ \n");
				}
				//분기 2 대기업 추천서 받지 않기
				else if(choice == 2)
				{
					slowPrint ( "대기업 입사 추천서를 거절했습니다.\n");
					slowPrint ("곤듀는 매니저님에 말에 따라 스파르타 회사에 들어가기로 결정했다.\n");
					slowPrint ( "곤듀의 특출난 외모덕분에 강의가 너무 재밌어 수강생들의 실력이 대폭 향상되었다.\n");
					slowPrint ( "♥ ♥ ♥ ♥ ♥ ♥ ♥ 스 빠 루 따! ♥ ♥ ♥ ♥ ♥ ♥ ♥ \n");
				}
				
				writeLog("보스 튜터 처치: 게임 종료 ");
				exit(0); // 게임 종료
			}
			break; // 전투 종료
		}



		// 튜터가 반격
		int tutorDamage = B.getAdd();
		A.takeDamage(tutorDamage);
		cout << " ♥ 이 귀여운 실수들은 일부러 한 거지? 혹시 내가 고쳐주길 바랐던 건가? ♥ \n";
		writeLog(" ♥ 이 귀여운 실수들은 일부러 한 거지? 혹시 내가 고쳐주길 바랐던 건가? ♥ ");
		cout << B.getName() << "이(가) " << A.getName() << "곤듀에게 " << tutorDamage << "의 피해를 입혔어요! 으앙, 너무 아프잖아요! \n";
		writeLog(B.getName() + "이(가) " + A.getName() + "곤듀에게 " + to_string(tutorDamage) + "의 피해를 입혔어요! 으앙, 너무 아프잖아요! ");

		// 전투 종료 조건 확인
		if (A.getHp() <= 0)
			{
			cout << A.getName() << "곤듀님이 패배했습니다... 너무 귀여운 곤듀님도 때로는 힘이 부족해요... \n";
			cout << "어머나~ 곤듀님이 이길 줄 알았는데...\n곤듀 바보!\n";
			writeLog(A.getName() + "곤듀님이 패배했습니다... 너무 귀여운 곤듀님도 때로는 힘이 부족해요... ");
			exit(0); // 게임 종료
		}

		// 현재 상태 출력
		cout << "\n" << A.getName() << "의 체력: " << A.getHp() << endl;
		cout << B.getName() << "의 체력: " << B.getHp() << endl;

		// 턴 종료 후 메뉴로 복귀
		cout << "\n곤듀의 선택! \n";
		writeLog("곤듀의 선택! ");
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