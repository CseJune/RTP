#pragma once
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

class Tutor
{
public:
	Tutor();
	Tutor(Character a, string name);

	virtual string getName();
	virtual int getHp();
	virtual void setHp(int hp);
	virtual void setAdd(int add);
	virtual int getAdd();
	virtual void takeDamage(int add);
private:
	string name;
	int hp;
	int add;
};

class ManagerTutor : Tutor 
{
public:
	ManagerTutor(Character a, string name);
};


class BasicTutor : public Tutor
{
	BasicTutor(Character a, string name);
};

class StandardTutor : public Tutor
{
	StandardTutor(Character a, string name);
};

class ChallengeTutor : public Tutor
{
	ChallengeTutor(Character a, string name);
};

class BossTutor : public Tutor
{
	BossTutor(Character a, string name);
};


