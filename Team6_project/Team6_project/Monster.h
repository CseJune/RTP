#pragma once
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

class Tutor
{
public:
	Tutor(string name, int hp, int add) : name(name), hp(hp), add(add) {}

	virtual string getName();
	virtual int getHp();
	virtual int getAdd();
	virtual void takeDamage(int add);
	virtual Item* dropItem();

protected:
	string name;
	int hp;
	int add;
};

class ManagerTutor : Tutor 
{
public:
	ManagerTutor(string name, int hp, int add) : Tutor(name, hp, add) {}
	string getName() override;
	int getHp() override;
	int getAdd() override;
	void takeDamage(int add) override;
	Item* dropItem() override;
};

class BaeManager : public ManagerTutor 
{
	BaeManager(string name, int hp, int add) : ManagerTutor(name = "πË¿Á»Ò ∏≈¥œ¿˙¥‘", hp, add) {}
};

class ParkManager : public ManagerTutor
{

};

class BasicTutor : public Tutor
{
	BasicTutor(string name, int hp, int add) : Tutor(name, hp, add) {}
};

class HanBasic : public BasicTutor
{

};

class ParkJungBasic : public BasicTutor
{

};

class ParkKyungBasic : public BasicTutor
{

};

class StandardTutor : public Tutor
{
	StandardTutor(string name, int hp, int add) : Tutor(name, hp, add) {}
};

class MoonStandard : public StandardTutor
{

};

class ChoiStandard : public StandardTutor
{

};

class ChallengeTutor : public Tutor
{
	ChallengeTutor(string name, int hp, int add) : Tutor(name, hp, add) {}
};

class KangChallenge : public ChallengeTutor
{

};

class BossTutor : public Tutor
{
	BossTutor(string name, int hp, int add) : Tutor(name, hp, add) {}
};

class KimBoss : public BossTutor
{

};


