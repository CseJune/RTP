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
	void IncreaseCodingPower(int codingIncrease);
	int GetHealth();
	int GetMaxHealth();
	void IncreaseHealth(int healthIncrease);
	void IncreaseMaxHealth(int maxHealthIncrease);
	static Character* getinstance(string name = "");

	// Getter�� Setter
	int getHp() const { return hp; }
	void setHp(int value) { hp = value; }
	int getMaxHp() const { return maxhp; }
	void setMaxHp(int value) { maxhp = value; }
	int getExp() const { return exp; }
	void addExp(int value) { exp += value; }
	int getGold() const { return gold; }
	void addGold(int value) { gold += value; }
	int getLevel() const { return level; }
	void setLevel(int value) { level = value; }

private:
	int hp;
	int maxhp;
	int add; // �ڵ���
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