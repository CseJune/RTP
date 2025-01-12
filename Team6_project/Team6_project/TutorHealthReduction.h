#pragma once

#include "Item.h" 
#include <string> 

using namespace std;

class TutorHealthReduction : public Item
{
private:
    string name;    // 아이템 이름   
    int healthReduction; // 튜터 체력 감소량

public:
    TutorHealthReduction();                  // 기본 생성자
    string GetName() const override;         // 아이템 이름 반환
    void Use(Character* character) override; 
    void Use(Tutor* tutor) override;         // 튜터의 체력을 감소
};
