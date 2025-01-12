#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Character
{
public:
	Character();
	void displayStatus();
	void levelUp();
	//void visitShop();
	static Character* getinstance(string name = "");

	// 코딩력 증가 추가
	void IncreaseCodingPower(int codingIncrease);

	// 체력 관련 기능
	void IncreaseHealth(int healthIncrease);
	int GetHealth();
	int GetMaxHealth();

	// 최대체력 증가 함수 추가
	void IncreaseMaxHealth(int maxHealthIncrease);

private:
	int hp;
	int maxhp;
	int add;
	string name;
	int exp;
	int level;
	int gold;
	int need_levelUp_exp = 100;
	static Character* instance; // 정적 멤버 변수 선언
};

class Inventory 
{
public:
	void addItem(string& item); // 아이템 추가
	void displayInventory();
	bool useItem(string& item);

private:
	vector<string> items;
};