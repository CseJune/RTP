#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ���� ����
class Inventory;

class Character
{
public:
    Character();
    void displayStatus();
    void levelUp();
    void takeDamage(int damageToTutor);
    static Character* getinstance(string name = "");

    // Getter�� Setter
    int getHp() const { return hp; }
    void setHp(int value) { hp = value; }
    int getMaxHp() const { return maxhp; }
    void setMaxHp(int value) { maxhp = value; }
    int getExp() const { return exp; }
    void setExp(int newExp) {
        exp = newExp;
        levelUp();  // ����ġ ���� �� ������ üũ
    }
    int getGold() const { return gold; }
    void setGold(int value) { gold += value; }
    int getLevel() const { return level; }
    void setLevel(int value) { level = value; }
    int getAdd() const { return add; }
    void setAdd(int value) { add = value; }
    string getName() const { return name; }
    void setName(string value) { name = value; }
    Inventory* getInventory() const { return inventory; }

    // �ڵ��� ���� �޼��� ����
    void IncreaseCodingPower(int codingIncrease)
    {
        add += codingIncrease;
    }

    // ü�� ȸ�� ���� �Լ� ����
    void IncreaseHealth(int healthIncrease)
    {
        if (hp + healthIncrease > maxhp)
        {
            hp = maxhp;
        }
        else
        {
            hp += healthIncrease;
        }
    }

    // �ִ�ü�� �����ϴ� �Լ� �޼��� ����
    void IncreaseMaxHealth(int maxHealthIncrease)
    {
        maxhp += maxHealthIncrease; // �־��� ��ŭ �ִ� HP ����
        if (hp > maxhp)
        {
            hp = maxhp;
        }
    }

private:
    // ��� ���� ����
    int hp = 100;  // �⺻�� ����
    int maxhp = 100; // �⺻�� ����
    int add = 0;    // �⺻�� ����
    string name;
    int exp = 0;    // �⺻�� ����
    int level = 1;  // �⺻�� ����
    int gold = 0;   // �⺻�� ����
    int need_levelUp_exp = 100;
    static Character* instance; // ���� ��� ���� ����
	Inventory* inventory; // �κ��丮 ��ü ������ ����
};

// Inventory Ŭ���� ����
class Inventory
{
public:
    void addItem(string& item); // ������ �߰�
    void displayInventory();
    bool useItem(string& item);

private:
    vector<string> items;
};
