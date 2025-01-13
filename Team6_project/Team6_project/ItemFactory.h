#pragma once
#include <functional>
#include <unordered_map>
#include <string>        
#include "Item.h"     

using namespace std; 

// ItemFactory 클래스 정의
class ItemFactory
{
public:
    // 아이템 타입과 생성 함수를 매핑하는 맵
    static unordered_map<string, function<Item*()>> itemRegistry;

private:
    // 아이템 생성 메서드
    static Item* createItem(const string& itemType);
    
    // 아이템 등록 메서드
    static void registerItem(const string& itemType, function<Item*()> createItem);
};
