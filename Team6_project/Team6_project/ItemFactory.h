#pragma once

#include <string>        // std::string 사용
#include "Item.h"        // Item 인터페이스 포함

using namespace std; // std 네임스페이스 사용

// ItemFactory 클래스 정의
class ItemFactory
{
public:
    // 정적 메서드: 아이템 타입에 따라 객체 생성
    static Item* CreateItem(const string& itemType);
};
