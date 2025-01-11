#include <iostream>
#include <vector>
#include "Character.h"

using namespace std;

//캐릭터를 생성하기 위한 정적 멤버변수 초기화
Character* Character::instance = nullptr; 

//getinstance 메서드 정의
Character* Character::getinstance(string name)
{
	if (instance == nullptr) // instance가 없으면 새로 생성
	{
		instance = new Character();
		instance->name = name; // 이름 설정
	}
	return instance; // 항상 동일한 인스턴스 반환
}


// 캐릭터 초기 생성자
Character::Character()
	: hp(200), maxhp(200), add(30), exp(0), name(name), level(1), gold(0)
{}

// display 출력 함수 구현 (인벤토리는 좀있다가)
void Character::displayStatus()
{
	cout << "이름 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "코딩력 : " << add << endl;
	cout << "골드 : " << gold << endl;
	cout << "경험치 : " << exp << endl;
	cout << "체력 : " << hp << ", " << "최대 체력 : " << maxhp << endl;
}

// 인벤토리 아이템 추가 로직
void Inventory::addItem(string& item)
{
	items.push_back(item);
}

// 인벤토리 아이템 출력 로직
void Inventory::displayInventory()
{
	if (items.empty())
	{
		cout << " 인벤토리가 비어있습니다 " << endl;
	}

	else
	cout << " 인벤토리 " << endl;
	for (size_t i = 0; i < items.size(); ++i)
	{
		cout << "[" << (i + 1) << "] " << items[i] << endl;
	}
}

// 인벤토리에 아이템 사용 로직
bool Inventory::useItem(string& item)
{
	auto it = find(items.begin(), items.end(), item); // 반복자와 find를 사용해 인벤토리에 있는 아이템 순회
	if (it != items.end()) // 아이템을 찾으면( 반복자가 find를 사용했는데, 끝까지 갔을때가 아니라면 )
	{
		items.erase(it); // 아이템 삭제
		return true; // true 반환
	}
	return false; // false 반환
}

// level 함수 구현
void Character::levelUp()
{
	if (exp >= 100 && level < 10) 
	{
		exp = exp - need_levelUp_exp;
		++level;

		hp += (level * 20);
		maxhp += (level * 20);
		add += (level * 5);

		if (hp > maxhp)
		{
			hp = maxhp;
		}
		if (level == 10)
		{
			exp = 0;
		}
	}
}
//int main()
//{
//	string characterName;
//
//	cout << "캐릭터 이름 입력 : ";
//	cin >> characterName;
//
//	Character* player = Character::getinstance(characterName);
//	player->displayStatus();
//
//	Inventory a;
//	
//	string b = "전설의 검";
//	a.addItem(b);
//	a.displayInventory();
//}