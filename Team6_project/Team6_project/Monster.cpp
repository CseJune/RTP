﻿#include "Monster.h" // "Tutor.h"로 변경
#include "Item.h"
#include "Character.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;
// 기본 생성자
Tutor::Tutor() : name(""), hp(0), add(0), type(TutorType::Manager) {} // 기본 타입은 Manager로 설정

// 초기화 생성자
Tutor::Tutor(Character a, const string& name, TutorType type) : name(name), hp(100), add(10), type(type) {}

// 소멸자
Tutor::~Tutor() {}

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
void Tutor::setGold(int gold) {this->gold = gold;}
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
    uniform_int_distribution<int> disHp(a.getLevel() * 50, a.getLevel() * 55);  // HP를 위한 dis
    setHp(disHp(gen));

    //Add 랜덤 설정
    uniform_int_distribution<int> disAdd(a.getLevel() * 5, a.getLevel() * 10);  // Add를 위한 dis
    setAdd(disAdd(gen));

    //Gold 랜덤 설정
    uniform_int_distribution<int> disGold(1000, 2000);  // Gold를 위한 dis
    setGold(disGold(gen));

    //아이템 랜덤 생성
    vector<string> possibleItems = { "HealthPotion", "CodingBooster", "MaxHealthPotion", "TutorAttackReduction", "TutorHealthReduction"};
    uniform_int_distribution<int> disItem(0, possibleItems.size() - 1); 
    string selectedItem = possibleItems[disItem(gen)]; 
    Item* newItem = ItemFactory::CreateItem(selectedItem);
    setItem(newItem);
}

//ManagerTutor 소멸자
ManagerTutor::~ManagerTutor() 
{
    //Item* item = this->getItem(); // this 포인터를 사용하여 현재 객체 참조 
    //if (item != nullptr) 
    //{ 
    //    Character* player = Character::getinstance(); 
    //    player->getInventory()->addItem(item); 
    //    this->setItem(nullptr); // item을 null로 설정하여 소멸자가 끝난 후 메모리 누수 방지
    //} 

  
}

// BasicTutor 생성자
BasicTutor::BasicTutor(Character a, string name) : Tutor(a, name, TutorType::Basic)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 70, a.getLevel() * 75);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 10, a.getLevel() * 15);  // Add를 위한 dis
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

//BasicTutor 소멸자
BasicTutor::~BasicTutor()
{
}

// StandardTutor 생성자
StandardTutor::StandardTutor(Character a, string name) : Tutor(a, name, TutorType::Standard)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 100, a.getLevel() * 110);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 20, a.getLevel() * 25);  // Add를 위한 dis
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

//StandardTutor 소멸자
StandardTutor::~StandardTutor()
{
}

// ChallengeTutor 생성자
ChallengeTutor::ChallengeTutor(Character a, string name) : Tutor(a, name, TutorType::Challenge)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 120, a.getLevel() * 130);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 20, a.getLevel() * 25);  // Add를 위한 dis
    setAdd(disAdd(gen));

    //Gold 랜덤 설정
    uniform_int_distribution<int> disGold(7000, 8000);  // Gold를 위한 dis
    setGold(disGold(gen));

    //아이템 랜덤 생성
    vector<string> possibleItems = { "HealthPotion", "CodingBooster", "MaxHealthPotion", "TutorAttackReduction", "TutorHealthReduction" };
    uniform_int_distribution<int> disItem(0, possibleItems.size() - 1);
    string selectedItem = possibleItems[disItem(gen)];
    Item* newItem = ItemFactory::CreateItem(selectedItem);
    setItem(newItem);
}

//ChallengeTutor 소멸자
ChallengeTutor::~ChallengeTutor()
{
}

// BossTutor 생성자
BossTutor::BossTutor(Character a, string name) : Tutor(a, name, TutorType::Boss)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 150, a.getLevel() * 160);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 20, a.getLevel() * 25);  // Add를 위한 dis
    setAdd(disAdd(gen));

    //Gold 랜덤 설정
    uniform_int_distribution<int> disGold(10000, 12000);  // Gold를 위한 dis
    setGold(disGold(gen));
}

//BossTutor 소멸자
BossTutor::~BossTutor()
{
}


//튜터 공격력 감소 아이템
//void Tutor::reduceAttackDamage(int addReduction)
//{
//
//}