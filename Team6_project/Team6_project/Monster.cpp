#include "Monster.h" // "Tutor.h"�� ����
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

//string getName();
//int getHp();
//int getAdd();
//void takeDamage(int
//	Item* dropItem();

// Tutor �ż���

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

// ManagerTutor �ż���

ManagerTutor::ManagerTutor(string name, int hp, int add)
{	
	name = "";
	randome_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(Character a.getLevel());


}