#pragma once

#include <string>        
#include "Item.h"     

using namespace std; 

// ItemFactory 클래스 정의
class ItemFactory
{
public:
    // 정적 메서드: 아이템 타입에 따라 객체 생성
    static Item* CreateItem(const string& itemType);
};
