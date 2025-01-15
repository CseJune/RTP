#pragma once
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string>
#include "ItemFactory.h"
//#include "CodingBooster.h"
//#include "HealthPotion.h"
//#include "MaxHealthPotion.h"
//#include "TutorAttackReduction.h"
//#include "TutorHealthReduction.h"

using namespace std;

enum class TutorType {
	Manager,
	Basic,
	Standard,
	Challenge,
	Boss
};

class Tutor
{

public:
	Tutor();
	Tutor(Character a, const string& name, TutorType type);

	// Getter
	string getName() const;
	int getHp() const;
	int getAdd() const;
	Item* getItem() const;
	int getGold() const;
	TutorType getType() const;

	// Setter
	void setHp(int hp);
	void setAdd(int add);
	void setItem(Item* item);
	void setGold(int gold);

	// 기능 메서드
	void takeDamage(int add); // 피해 처리
	virtual void reduceAttackDamage(int add);
	virtual void ReduceHealth(int hp);

private:
	string name;
	int hp;
	int add;
	TutorType type; // 튜터의 등급
	int gold;
	Item* item;
	void reduceAdd(int a, int b);
	void reduceHp(int a, int b);
};

class ManagerTutor : public Tutor
{
public:
	ManagerTutor(Character a, string name);  // public으로 선언
};

class BasicTutor : public Tutor
{
public:
	BasicTutor(Character a, string name);  // public으로 선언
};

class StandardTutor : public Tutor
{
public:
	StandardTutor(Character a, string name);  // public으로 선언
};

class ChallengeTutor : public Tutor
{
public:
	ChallengeTutor(Character a, string name);  // public으로 선언
};

class BossTutor : public Tutor
{
public:
	BossTutor(Character a, string name);  // public으로 선언
};


