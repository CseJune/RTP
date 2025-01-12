#pragma once

#include <string>
#include "Item.h"

class Character;

using namespace std;

class HealthPotion : public Item
{
private:
    string name;    // 아이템 이름   
    int healthIncrease; // 체력 증가량

public:    
    HealthPotion();    // 생성자
    string GetName() const override;   // 아이템 이름 반환
    void Use(Character* character) override; // 캐릭터 체력 증가 효과 적용
};
