#pragma once

#include <string>
#include "Item.h"

class Character;

using namespace std;

class CodingBooster : public Item
{
private:
    string name;    // 아이템 이름
    string description = "캐릭터 코딩력 증가 아이템";    // 아이템 설명
    int codingIncrease; // 코딩력 증가량
    int price = 5000;   // 아이템 가격 (5000 Gold)
    
public:    
    CodingBooster();    // 생성자
    string GetName() const override;   // 아이템 이름 반환
    string GetDescription() const override;    // 아이템 설명 반환
    void Use(Character* character) override;    // 캐릭터 코딩력 증가 효과 적용
    void Use(Tutor* tutor) override;    // 튜터에게 효과 없음
    int GetPrice() const override;  // 아이템 가격 반환
};
