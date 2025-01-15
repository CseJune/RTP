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
Tutor::Tutor(Character a, const string& name, TutorType type) : name(name), hp(100), type(type) {}

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
    Item* newItem = ItemFactory::CreateItem("ChatGPT");
    setItem(newItem);
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

//튜터 공격력 감소 아이템
void Tutor::reduceAttackDamage(int addReduction)
{
    int currentAdd = this->getAdd();
    TutorType currentTutorType = this->getType();
    switch (currentTutorType)
    {
    case TutorType::Manager:
        if(currentAdd < 50) // 매니저 튜터 공격력 최소치
        this->setAdd(currentAdd - 5); // 매니저 튜터 공격력 감소치 

    case TutorType::Basic:
        if (currentAdd < 0) // 베이직 튜터 공격력 최소치
            this->setAdd(currentAdd - 10); // 베이직 튜터 공격력 감소치

    case TutorType::Standard:
        if (currentAdd < 0) //  스탠다드 튜터 공격력 최소치
            this->setAdd(currentAdd - 20); // 스탠다드 튜터 공격력 감소치

    case TutorType::Challenge:
        if (currentAdd < 0) // 챌린지 튜터 공격력 최소치
            this->setAdd(currentAdd - 30); // 챌린지 튜터 공격력 감소치

    case TutorType::Boss:
        if (currentAdd < 0) // 보스 튜터 공격력 최소치
            this->setAdd(currentAdd - 50); // 보스 튜터 공격력 감소치
    }
    
}

void Tutor::ReduceHealth(int hpReduction)
{
    int currentHp = this->getHp();
    TutorType currentTutorType = this->getType();
    switch (currentTutorType)
    {
    case TutorType::Manager:
        if (currentHp < 50) // 매니저 튜터 체력 최소치
            this->setHp(currentHp - 10); // 매니저 튜터 체력 감소치 

    case TutorType::Basic:
        if (currentHp < 0) // 베이직 튜터 체력 최소치
            this->setHp(currentHp - 20); // 베이직 튜터 체력 감소치

    case TutorType::Standard:
        if (currentHp < 0) //  스탠다드 튜터 체력 최소치
            this->setHp(currentHp - 50); // 스탠다드 튜터 체력 감소치

    case TutorType::Challenge:
        if (currentHp < 0) // 챌린지 튜터 체력 최소치
            this->setHp(currentHp - 70); // 챌린지 튜터 체력 감소치

    case TutorType::Boss:
        if (currentHp < 0) // 보스 튜터 체력 최소치
            this->setHp(currentHp - 100); // 보스 튜터 체력 감소치
    }
}