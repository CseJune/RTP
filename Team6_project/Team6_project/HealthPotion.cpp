#include "HealthPotion.h"
#include "Character.h"
#include <iostream>

using namespace std;

// 기본 생성자: 이름과 체력 증가량 초기화
HealthPotion::HealthPotion() : name("카페인의 힘"), healthIncrease(50){}

// 아이템 이름 반환
string HealthPotion::GetName()
{
    return name;
}

// 캐릭터에게 체력 증가 효과 적용
void HealthPotion::Use(Character* character)
{
    if (character->GetHealth() >= character->GetMaxHealth())   
    {
        cout << "⚠️ " << name << " 사용 실패 : 캐릭터가 이미 최대 체력입니다!" << endl;
        return;
    }
    // IncreaseHealth를 캐릭터에서 구현하고 내용은 인자값만큼 체력을 증가시키면 됨
    character->IncreaseHealth(healthIncrease);
        
    cout << "✅ " << name << "사용 : 체력이 " << healthIncrease << "만큼 회복되었습니다!" << endl;
}


