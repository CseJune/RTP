#include "Inventory.h"
#include "Character.h"
#include <iostream>
#include <vector>
#include <string>
#include "Logger.h"

// 인벤토리 아이템 추가 로직
void Inventory::addItem(Item* item)
{
	if (item)
	{
		items.push_back(item);
	}
}

// 인벤토리 아이템 출력 로직
void Inventory::displayInventory()
const {
	if (items.empty())
	{
		cout << " 인벤토리가 비어있습니다 " << endl;
		return;
	}

	cout << " 인벤토리 " << endl;
	for (size_t i = 0; i < items.size(); ++i)
	{
		cout << "[" << (i + 1) << "] " << items[i]->GetName() << endl;
	}
}


// 인벤토리에 아이템 사용 로직
bool Inventory::useItem(const string& itemName, Character* character, Tutor* tutor)
{
	auto it = find_if(items.begin(), items.end(), [&itemName](Item* item)
		{
			return item->GetName() == itemName;
		});// 반복자와 find를 사용해 인벤토리에 있는 아이템 순회

	if (it != items.end()) // 아이템을 찾으면( 반복자가 find를 사용했는데, 끝까지 갔을때가 아니라면 )
	{
		(*it)->Use(character);
		(*it)->Use(tutor);

		if (tutor != nullptr)
		{
			cout << "아이템 사용 후 능력치:\n";
			writeLog("아이템 사용 후 능력치: ");
			character->displayStatus();
		}
		items.erase(it);
		return true;
		// 능력치 출력 (예시: HP, Attack, Defense)
		/*cout << "레벨: " << character->getLevel() << endl;
		cout << "체력 : " << character->getHp() << " / " << "최대 체력 : " << character->getMaxHp() << endl;
		cout << "코딩력: " << character->getAdd() << endl;*/
		/*delete* it;*/
	}

	cout << "아이템을 찾을 수 없습니다." << itemName << endl;
	return false; // false 반환
}

// 드롭 아이템 함수 추가
void Inventory::dropItem(Item* item)
{
	if (item != nullptr)
	{
		cout << " \n튜터가 " << item->GetName() << "을(를) 드롭했습니다." << endl;

		// 플레이어 인벤토리에 아이템 추가 로직
		Character* player = Character::getinstance();
		player->getInventory()->addItem(item);
		// 메모리 반환
		item = nullptr;
	}
}

Item* Inventory::findItem(const string& itemName) 
{
	auto it = find_if(items.begin(), items.end(), [&itemName](Item* item)
		{
			return item->GetName() == itemName;

		});
	if (it != items.end())
	{
		return *it;
	}
	return nullptr;
}


void Inventory::removeItem(const string& itemName)
{
	auto it = find_if(items.begin(), items.end(), [&itemName](Item* item)
		{
			return item->GetName() == itemName; // 아이템 이름 비교
		});

	if (it != items.end()) // 아이템이 발견되었으면
	{
		items.erase(it);     // 벡터에서 아이템 제거
		cout << itemName << "을(를) 제거 했습니다!" << endl;
	}
	else
	{
		cout << itemName << "을(를) 찾을 수 없습니다!" << endl;
	}
}
// 아이템 목록의 개수를 반환하는 함수
int Inventory::getItemCount() const {
	return items.size();
}

// 인덱스를 통해 아이템 이름을 얻는 함수
string Inventory::getItemNameByIndex(int index) const {
	if (index >= 0 && index < items.size()) {
		return items[index]->GetName();
	}
	return "";
}