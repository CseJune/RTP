#pragma once
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string>
#include "ItemFactory.h"

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
	TutorType getType() const;

	// Setter
	void setHp(int hp);
	void setAdd(int add);

	// 기능 메서드
	void takeDamage(int add); // 피해 처리
	//virtual void reduceAttackDamage(int addreduction);

private:
	string name;
	int hp;
	int add;
	TutorType type; // 튜터의 등급
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


