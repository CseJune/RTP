﻿#include "Monster.h" // "Tutor.h"로 변경
#include "Item.h"
#include "Character.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Logger.h"

using namespace std;
// 기본 생성자
Tutor::Tutor() : name(""), hp(0), add(0), type(TutorType::Manager) {} // 기본 타입은 Manager로 설정

// 초기화 생성자
Tutor::Tutor(Character a, const string& name, TutorType type) : name(name), hp(100), type(type) {}

// 튜터 스테이서스
void Tutor::displayStatus()
{
	cout << "이름 : " << name << endl;
	writeLog("튜터 이름 : " + name);
	cout << "코딩력 : " << add << endl;
	writeLog("튜터 코딩력 : " + name);
	cout << "체력 : " << hp << endl;
	writeLog("튜터 체력 : " + to_string(hp));
}

// Getter
string Tutor::getName() const { return name; }
int Tutor::getHp() const { return hp; }
int Tutor::getAdd() const { return add; }
int Tutor::getGold() const { return gold; }
Item* Tutor::getItem() const { return item; }
TutorType Tutor::getType() const { return type; }

// Setter
void Tutor::setHp(int hp) { this->hp = hp; }
void Tutor::setAdd(int add) { this->add = add; }
void Tutor::setGold(int gold) { this->gold = gold; }
void Tutor::setItem(Item* newItem)
{
	if (item != nullptr)
		delete item;
	{
		item = newItem;
	}
}
// 피해 처리
void Tutor::takeDamage(int add) {
	hp -= add;
	if (hp < 0) hp = 0;
}

// ManagerTutor 생성자
ManagerTutor::ManagerTutor(Character a, string name) : Tutor(a, name, TutorType::Manager)
{
	random_device rd;
	mt19937 gen(rd());

	//HP 랜덤 설정
	uniform_int_distribution<int> disHp(a.getLevel() * 70, a.getLevel() * 75);  // HP를 위한 dis
	setHp(disHp(gen));

	//Add 랜덤 설정
	uniform_int_distribution<int> disAdd(a.getLevel() * 5, a.getLevel() * 10);  // Add를 위한 dis
	setAdd(disAdd(gen));

	//Gold 랜덤 설정
	uniform_int_distribution<int> disGold(1000, 2000);  // Gold를 위한 dis
	setGold(disGold(gen));

	//아이템 랜덤 생성
	vector<string> possibleItems = { "HealthPotion", "CodingBooster", "MaxHealthPotion", "TutorAttackReduction", "TutorHealthReduction" };
	uniform_int_distribution<int> disItem(0, possibleItems.size() - 1);
	string selectedItem = possibleItems[disItem(gen)];
	Item* newItem = ItemFactory::CreateItem(selectedItem);
	setItem(newItem);
}

// BasicTutor 생성자
BasicTutor::BasicTutor(Character a, string name) : Tutor(a, name, TutorType::Basic)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> disHp(a.getLevel() * 80, a.getLevel() * 85);  // HP를 위한 dis
	setHp(disHp(gen));

	uniform_int_distribution<int> disAdd(a.getLevel() * 20, a.getLevel() * 25);  // Add를 위한 dis
	setAdd(disAdd(gen));

	//Gold 랜덤 설정
	uniform_int_distribution<int> disGold(3000, 3500);  // Gold를 위한 dis
	setGold(disGold(gen));

	//아이템 랜덤 생성
	vector<string> possibleItems = { "HealthPotion", "CodingBooster", "MaxHealthPotion", "TutorAttackReduction", "TutorHealthReduction" };
	uniform_int_distribution<int> disItem(0, possibleItems.size() - 1);
	string selectedItem = possibleItems[disItem(gen)];
	Item* newItem = ItemFactory::CreateItem(selectedItem);
	setItem(newItem);
}

// StandardTutor 생성자
StandardTutor::StandardTutor(Character a, string name) : Tutor(a, name, TutorType::Standard)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> disHp(a.getLevel() * 100, a.getLevel() * 110);  // HP를 위한 dis
	setHp(disHp(gen));

	uniform_int_distribution<int> disAdd(a.getLevel() * 27, a.getLevel() * 32);  // Add를 위한 dis
	setAdd(disAdd(gen));

	//Gold 랜덤 설정
	uniform_int_distribution<int> disGold(5000, 6000);  // Gold를 위한 dis
	setGold(disGold(gen));

	//아이템 랜덤 생성
	vector<string> possibleItems = { "HealthPotion", "CodingBooster", "MaxHealthPotion", "TutorAttackReduction", "TutorHealthReduction" };
	uniform_int_distribution<int> disItem(0, possibleItems.size() - 1);
	string selectedItem = possibleItems[disItem(gen)];
	Item* newItem = ItemFactory::CreateItem(selectedItem);
	setItem(newItem);
}

// ChallengeTutor 생성자
ChallengeTutor::ChallengeTutor(Character a, string name) : Tutor(a, name, TutorType::Challenge)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> disHp(a.getLevel() * 110, a.getLevel() * 120);  // HP를 위한 dis
	setHp(disHp(gen));

	uniform_int_distribution<int> disAdd(a.getLevel() * 30, a.getLevel() * 35);  // Add를 위한 dis
	setAdd(disAdd(gen));

	//Gold 랜덤 설정
	uniform_int_distribution<int> disGold(7000, 8000);  // Gold를 위한 dis
	setGold(disGold(gen));

	//아이템 랜덤 생성
	Item* newItem = ItemFactory::CreateItem("ChatGPT");
	setItem(newItem);
}

// BossTutor 생성자
BossTutor::BossTutor(Character a, string name) : Tutor(a, name, TutorType::Boss)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> disHp(a.getLevel() * 120, a.getLevel() * 130);  // HP를 위한 dis
	setHp(disHp(gen));

	uniform_int_distribution<int> disAdd(a.getLevel() * 33, a.getLevel() * 38);  // Add를 위한 dis
	setAdd(disAdd(gen));

	//Gold 랜덤 설정
	uniform_int_distribution<int> disGold(10000, 12000);  // Gold를 위한 dis
	setGold(disGold(gen));
}



//튜터 공격력 감소 아이템
void Tutor::reduceAttackDamage(int addReduction)
{
	TutorType currentTutorType = this->getType();

	switch (currentTutorType)
	{
	case TutorType::Manager:
		reduceAdd(3, 5);  //최소치, 감소치
		break;

	case TutorType::Basic:
		reduceAdd(55, 15);
		break;

	case TutorType::Standard:
		reduceAdd(140, 20);
		break;

	case TutorType::Challenge:
		reduceAdd(240, 25);
		break;

	case TutorType::Boss:
		reduceAdd(300, 30);
		break;
	}

}


void Tutor::ReduceHealth(int hpReduction)
{
	TutorType currentTutorType = this->getType();

	switch (currentTutorType)
	{
	case TutorType::Manager:
		reduceHp(40, 10);  //최소치, 감소치
		break;

	case TutorType::Basic:
		reduceHp(180, 15);
		break;

	case TutorType::Standard:
		reduceHp(500, 40);
		break;

	case TutorType::Challenge:
		reduceHp(900, 60);
		break;


	case TutorType::Boss:
		reduceHp(1400, 80);
		break;
	}
}

void Tutor::reduceAdd(int a, int b)
{
	int currentAdd = this->getAdd();
	this->setAdd(currentAdd - b);
	if (currentAdd - b <= a)
	{
		this->setAdd(a);
		cout << "튜터의 코딩력이 최소치인 " << a << " 까지 감소했습니다." << endl;
	}
	else
	{
		cout << "튜터의 공격력이 " << b << " 만큼 감소했습니다." << endl;
	}
}
void Tutor::reduceHp(int a, int b)
{
	int currentHp = this->getHp();
	this->setHp(currentHp - b);
	if (currentHp - b <= a)
	{
		this->setHp(a);
		cout << "튜터의 체력이 최소치인 " << a << " 까지 감소했습니다." << endl;
	}
	else
	{
		cout << "튜터의 체력이 " << b << " 만큼 감소했습니다." << endl;
	}
}

