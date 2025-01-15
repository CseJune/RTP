#pragma once

#include <string>
#include "Item.h"

class Character;

using namespace std;

class HealthPotion : public Item
{
private:
    string name;    // 아이템 이름
    string description = "체력 회복 아이템";    // 아이템 설명
    int healthIncrease; // 체력 증가량
    int price = 3000;   // 아이템 가격 (3000 Gold)

public:    
    HealthPotion();    // 생성자
    string GetName() const override;   // 아이템 이름 반환
    string GetDescription() const override;    // 아이템 설명 반환
    void Use(Character* character) override; // 캐릭터 체력 증가 효과 적용
    void Use(Tutor* tutor) override;    // 튜터에게 효과 없음
    int GetPrice() const override;  // 아이템 가격 반환
};
