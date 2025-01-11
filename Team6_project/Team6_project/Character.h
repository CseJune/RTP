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

private:
	int hp;
	int maxhp;
	int add;
	string name;
	int exp;
	int level;
	int gold;
	int need_levelUp_exp = 100;
	static Character* instance; // ���� ��� ���� ����
};

class Inventory 
{
public:
	void addItem(string& item); // ������ �߰�
	void displayInventory();
	bool useItem(string& item);

private:
	vector<string> items;
};