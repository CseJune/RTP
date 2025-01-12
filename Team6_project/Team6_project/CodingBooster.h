#pragma once

#include <string>

#include "Item.h"

class Character;

using namespace std;

class CodingBooster : public Item
{
private:
    string name;    // 아이템 이름   
    int codingIncrease; // 코딩력 증가량
public:    
    CodingBooster();    // 생성자
    string GetName() const override;   // 아이템 이름 반환
    void Use(Character* character) override;    // 캐릭터 코딩력 증가 효과 적용
    void Use(Tutor* tutor) override;
};