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
	virtual ~Tutor(); // 소멸자 (가상 소멸자)

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
	//virtual void reduceAttackDamage(int addreduction);

private:
	string name;
	int hp;
	int add;
	TutorType type; // 튜터의 등급
	int gold;
	/*CodingBooster item;
	HealthPotion item;
	MaxHealthPotion item;
	TutorAttackReduction item;
	TutorHealthReduction item;*/
	Item* item;
};

class ManagerTutor : public Tutor
{
public:
	ManagerTutor();
	ManagerTutor(Character a, string name);  // public으로 선언
	~ManagerTutor();
};

class BasicTutor : public Tutor
{
public:
	BasicTutor(Character a, string name);  // public으로 선언
	~BasicTutor();
};

class StandardTutor : public Tutor
{
public:
	StandardTutor(Character a, string name);  // public으로 선언
	~StandardTutor();
};

class ChallengeTutor : public Tutor
{
public:
	ChallengeTutor(Character a, string name);  // public으로 선언
	~ChallengeTutor();
};

class BossTutor : public Tutor
{
public:
	BossTutor(Character a, string name);  // public으로 선언
	~BossTutor();
};


