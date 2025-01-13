#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 전방 선언
class Inventory;

class Character
{
public:
    Character();
    void displayStatus();
    void levelUp();
    void takeDamage(int damageToTutor);
    static Character* getinstance(string name = "");

    // Getter와 Setter
    int getHp() const { return hp; }
    void setHp(int value) { hp = value; }
    int getMaxHp() const { return maxhp; }
    void setMaxHp(int value) { maxhp = value; }
    int getExp() const { return exp; }
    void setExp(int newExp) {
        exp = newExp;
        levelUp();  // 경험치 변경 후 레벨업 체크
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

    // 코딩력 증가 메서드 구현
    void IncreaseCodingPower(int codingIncrease)
    {
        add += codingIncrease;
    }

    // 체력 회복 관련 함수 구현
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

    // 최대체력 증가하는 함수 메서드 구현
    void IncreaseMaxHealth(int maxHealthIncrease)
    {
        maxhp += maxHealthIncrease; // 주어진 만큼 최대 HP 증가
        if (hp > maxhp)
        {
            hp = maxhp;
        }
    }

private:
    // 멤버 변수 선언
    int hp = 100;  // 기본값 설정
    int maxhp = 100; // 기본값 설정
    int add = 0;    // 기본값 설정
    string name;
    int exp = 0;    // 기본값 설정
    int level = 1;  // 기본값 설정
    int gold = 0;   // 기본값 설정
    int need_levelUp_exp = 100;
    static Character* instance; // 정적 멤버 변수 선언
	Inventory* inventory; // 인벤토리 객체 포인터 선언
};

// Inventory 클래스 선언
class Inventory
{
public:
    void addItem(string& item); // 아이템 추가
    void displayInventory();
    bool useItem(string& item);

private:
    vector<string> items;
};
