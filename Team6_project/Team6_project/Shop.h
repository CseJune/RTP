#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include "Character.h"
#include "ItemFactory.h"
#include "Inventory.h"

using namespace std;

// 상점 클래스
class Shop
{
public:
    Shop(); // 생성자
    ~Shop(); // 소멸자 선언 추가
   
    void initializeShopItems(); // 상점 아이템 초기화
    void displayItems() const; // 상점 아이템 목록 출력
    void buyItem(Character* player, const string& itemName); // 아이템 구매
    void sellItem(Character* player, const string& itemName); // 아이템 판매
    vector<Item*> getAvailableItems() const;  // availableItems 반환하는 메서드 추가

private:
    vector<Item*> availableItems; // 판매 가능한 아이템 목록
    bool isInitializing; // 상점 초기화 중인지 여부
};
