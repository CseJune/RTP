#include "Inventory.h"
#include "Character.h"
#include <iostream>
#include <vector>
#include <string>

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
bool Inventory::useItem(const string& itemName, Character* character)
{
	auto it = find_if(items.begin(), items.end(), [&itemName](Item* item)
		{
			return item->GetName() == itemName;
		});// 반복자와 find를 사용해 인벤토리에 있는 아이템 순회

	if (it != items.end()) // 아이템을 찾으면( 반복자가 find를 사용했는데, 끝까지 갔을때가 아니라면 )
	{
		(*it)->Use(character);
		delete* it;
		items.erase(it);
		return true;
	}

	cout << "아이템을 찾을 수 없습니다." << itemName << endl;
	return false; // false 반환
}

// 드롭 아이템 함수 추가
void Inventory::dropItem(Item* item)
{
	if (item != nullptr)
	{
		cout << " 튜터가 " << item->GetName() << "를 드롭했습니다." << endl;

		// 플레이어 인벤토리에 아이템 추가 로직
		Character* player = Character::getinstance();
		player->getInventory()->addItem(item);
		// 메모리 반환
		item = nullptr;
	}
}