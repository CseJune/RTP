#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Item.h" // 아이템 관련 클래스 필요시 포함

class Character; // 전방선언

// Inventory 클래스 선언
class Inventory
{
public:
    void addItem(Item* item); // 아이템 추가
    void displayInventory() const;
    bool useItem(const string& itemName, Character* character);
    void dropItem(Item* item);
    Item* findItem(const string& itemName);
    void removeItem(const string& itemName);

private:
    vector<Item*> items;
};
