#pragma once

#include <string>

#include "Item.h"

class Tutor;
class Character;

using namespace std;

class TutorAttackReduction : public Item
{
private:
    string name;    // 아이템 이름   
    int attackReduction; // 공격력 감소량
    
public:    
    TutorAttackReduction();    // 생성자
    string GetName() const override;   // 아이템 이름 반환
    void Use(Character* character) override;
    void Use(Tutor* tutor) override; // 튜터 공격력 감소 효과 적용
};

