#pragma once

#include <string>
#include "Item.h"

using namespace std;

class MaxHealthPotion
{
private:
    string name;    // 아이템 이름   
    int maxHealthIncrease;    // 최대 체력 증가량

public:    
    MaxHealthPotion();    // 생성자
    string GetName();   // 아이템 이름 반환
    void Use(Character* character); // 캐릭터 체력 증가 효과 적용
};
