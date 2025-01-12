#include "Monster.h" // "Tutor.h"稽 痕井
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

// Tutor 古辞球

string Tutor::getName()
{
	return name;
}

int Tutor::getHp() 
{
	return hp;
}

int Tutor::getAdd()
{
	return add;
}

void Tutor::takeDamage(int add)
{
	hp -= add;
}

// ManagerTutor 持失切
ManagerTutor::ManagerTutor(Character a, string name) : Tutor(a, name)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(a.getLevel() * 50, a.getLevel() * 55);
	setHp(dis(gen));

	uniform_int_distribution<int> dis(a.getLevel() * 5, a.getLevel() * 10);
	setAdd(dis(gen));
}


//BasicTutor 持失切
BasicTutor::BasicTutor(Character a, string name) : Tutor(a, name)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(a.getLevel() * 70, a.getLevel() * 75);
	setHp(dis(gen));

	uniform_int_distribution<int> dis(a.getLevel() * 10, a.getLevel() * 15);
	setAdd(dis(gen));
}

//StandardTutor 持失切
StandardTutor::StandardTutor(Character a, string name) : Tutor(a, name)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(a.getLevel() * 100, a.getLevel() * 110);
	setHp(dis(gen));

	uniform_int_distribution<int> dis(a.getLevel() * 20, a.getLevel() * 25);
	setAdd(dis(gen));
}

//Challengetutor 持失切
ChallengeTutor::ChallengeTutor(Character a, string name) : Tutor(a, name)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(a.getLevel() * 150, a.getLevel() * 160);
	setHp(dis(gen));

	uniform_int_distribution<int> dis(a.getLevel() * 30, a.getLevel() * 35);
	setAdd(dis(gen));
}

//BossTutor 持失切
BossTutor::BossTutor(Character a, string name) : Tutor(a, name)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(a.getLevel() * 200, a.getLevel() * 210);
	setHp(dis(gen));

	uniform_int_distribution<int> dis(a.getLevel() * 50, a.getLevel() * 60);
	setAdd(dis(gen));
}