#include "CodingBooster.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>
#include "Logger.h"
using namespace std;

//  기본 생성자: 이름과 코딩력 증가량 초기화
CodingBooster::CodingBooster() : name("곤듀님의 핑크맛 에너지 드링크"), codingIncrease(10){}

// 아이템 이름 반환
string CodingBooster::GetName() const
{
    return name;
}

// 아이템 설명 반환
string CodingBooster::GetDescription() const
{
    return description;
}

// 캐릭터의 코딩력을 증가시키는 효과 적용
void CodingBooster::Use(Character* character)
{
    // 캐릭터의 코딩력 증가시킴
    character->IncreaseCodingPower(codingIncrease);

    // 코딩력 증가 메시지 출력
   cout << name << "뭐야 뭐야~ 곤듀님, 코딩력이" << codingIncrease << "만큼이나 늘어났어요!?\n이젠 적들도 두려워하겠는걸요? ♥ " << endl;
   writeLog(name + "뭐야 뭐야~ 곤듀님, 코딩력이" + to_string(codingIncrease) + "만큼이나 늘어났어요!?\n이젠 적들도 두려워하겠는걸요? ♥ ");
}

// 튜터에게 효과 없음
void CodingBooster::Use(Tutor* tutor)
{
    // 튜터에게는 효과가 없음을 알리는 메시지
   // cout << name << "은(는) 튜터에게 효과가 없습니다." << endl;
}

// 아이템 가격 반환
int CodingBooster::GetPrice() const
{
    return price;
}

