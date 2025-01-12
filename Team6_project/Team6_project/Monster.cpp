#include "Monster.h" // "Tutor.h"로 변경
#include "Item.h"
#include "Character.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

// Tutor 매서드

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

// ManagerTutor 생성자
ManagerTutor::ManagerTutor(Character a, string name) : Tutor(a, name)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 50, a.getLevel() * 55);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 5, a.getLevel() * 10);  // Add를 위한 dis
    setAdd(disAdd(gen));
}

// BasicTutor 생성자
BasicTutor::BasicTutor(Character a, string name) : Tutor(a, name)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 70, a.getLevel() * 75);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 10, a.getLevel() * 15);  // Add를 위한 dis
    setAdd(disAdd(gen));
}

// StandardTutor 생성자
StandardTutor::StandardTutor(Character a, string name) : Tutor(a, name)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 100, a.getLevel() * 110);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 20, a.getLevel() * 25);  // Add를 위한 dis
    setAdd(disAdd(gen));
}

// ChallengeTutor 생성자
ChallengeTutor::ChallengeTutor(Character a, string name) : Tutor(a, name)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 150, a.getLevel() * 160);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 30, a.getLevel() * 35);  // Add를 위한 dis
    setAdd(disAdd(gen));
}

// BossTutor 생성자
BossTutor::BossTutor(Character a, string name) : Tutor(a, name)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> disHp(a.getLevel() * 200, a.getLevel() * 210);  // HP를 위한 dis
    setHp(disHp(gen));

    uniform_int_distribution<int> disAdd(a.getLevel() * 50, a.getLevel() * 60);  // Add를 위한 dis
    setAdd(disAdd(gen));
}


//튜터 공격력 감소 아이템
//void Tutor::reduceAttackDamage(int addReduction)
//{
//
//}