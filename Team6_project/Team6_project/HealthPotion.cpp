#include "HealthPotion.h"
#include "Character.h"
#include <iostream>
#include "Logger.h"
using namespace std;

// 기본 생성자: 이름과 체력 증가량 초기화
HealthPotion::HealthPotion() : name("카페인의 힘"), healthIncrease(50) {}

// 아이템 이름 반환
string HealthPotion::GetName() const
{
    return name;
}

// 아이템 설명 반환
string HealthPotion::GetDescription() const
{
    return description;
}

// 캐릭터에게 체력 증가 효과 적용
void HealthPotion::Use(Character* character)
{
    if (character->getHp() >= character->getMaxHp())
    {
        cout << name << " 사용 실패: 곤듀가 이미 최대 체력입니다!" << endl;
        writeLog(name + " 사용 실패: 곤듀가 이미 최대 체력입니다!");
        return;
    }

    // 체력 증가 로직
    character->IncreaseHealth(healthIncrease);

    cout << name << "곤듀님! 체력이 " << healthIncrease << "만큼 회복되었어요! ♥ \n이제 다시 적들을 혼내줄 준비 완료! ♥ " << endl;
    writeLog(name + "곤듀님! 체력이 " + to_string(healthIncrease) + "만큼 회복되었어요! ♥ \n이제 다시 적들을 혼내줄 준비 완료! ");
}

// 튜터에게 효과 없음
void HealthPotion::Use(Tutor* tutor)
{
    // cout << name << "은(는) 튜터에게 효과가 없습니다." << endl;
}

// 아이템 가격 반환
int HealthPotion::GetPrice() const
{
    return price;
}
