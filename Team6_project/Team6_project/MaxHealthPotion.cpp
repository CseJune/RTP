#include "MaxHealthPotion.h"
#include "Character.h"
#include <iostream>

using namespace std;

// 기본 생성자: 이름과 최대 체력 증가량 초기화
MaxHealthPotion::MaxHealthPotion() : name("헬스 트레이닝 프로그램"), maxHealthIncrease(20){}

// 아이템 이름 반환
string MaxHealthPotion::GetName() const
{
    return name;
}

// 캐릭터에게 최대 체력 증가 효과 적용
void MaxHealthPotion::Use(Character* character)
{
    if (character != nullptr)
    {
        // IncreaseMaxHealth를 캐릭터에서 구현하고 내용은 인자값만큼 최대 체력을 증가시키면 됨
        character->IncreaseMaxHealth(maxHealthIncrease);

        cout << "✅" << name << "사용 : 최대체력이 " << maxHealthIncrease << " 만큼 증가했습니다!" << endl;
    }
}

