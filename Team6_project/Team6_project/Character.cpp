#include <iostream>
#include <vector>
#include "Character.h"
#include "Inventory.h"

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
	: hp(200), maxhp(200), add(30), exp(0), name(name), level(0), gold(999999), inventory(new Inventory())
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

void Character::addItemToInventory(Item* item) 
{
	if (!inventory) 
	{
		inventory = new Inventory();
	}
	inventory->addItem(item);
}

void Character::useItemFromInventory(string& itemName) 
{
	if (inventory) 
	{
		inventory->useItem(itemName, this);
	}
	else 
	{
		std::cout << "인벤토리가 없습니다.\n";
	}
}

// level 함수 구현
void Character::levelUp()
{
if (level >= 10) {
	exp = 0;  // 레벨 10이 되면 경험치는 0으로 고정
	return;  // 더 이상 레벨업이 되지 않음
}
	while (exp >= 100 && level < 10)
	{
		exp -= 100;
		level++;

		hp += (level * 20);
		maxhp += (level * 20);
		add += (level * 5);
		hp = maxhp;  // 레벨업 시 체력 회복

		if (hp > maxhp) {
			hp = maxhp;  // HP가 최대 HP를 초과하지 않도록 설정
		}
	}
}

void Character::takeDamage(int add) {
	hp -= add;
	if (hp < 0) hp = 0;
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