#pragma once
#include <string>

class Character;
using namespace std;

class HealthPotion
{
public:
    string name;    // 아이템 이름   
    int healthIncrease; // 체력 증가량
    
    HealthPotion();    // 생성자
    string GetName();   // 아이템 이름 반환
    void Use(Character* character); // 캐릭터 체력 증가 효과 적용
};
