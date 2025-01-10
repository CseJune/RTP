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
	void useItem();
	void visitShop();
	static Character* getinstance(string name = "");

private:
	int hp;
	int maxhp;
	int add;
	string name;
	vector<string> inventory;
	int exp;
	int level;
	int gold;
};