#include "CodingBooster.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>

using namespace std;

//  기본 생성자: 이름과 코딩력 증가량 초기화
CodingBooster::CodingBooster() : name("듀얼 모니터"), codingIncrease(10){}

// 아이템 이름 반환
string CodingBooster::GetName() const
{
    return name;
}

// 캐릭터의 코딩력을 증가시키는 효과 적용
void CodingBooster::Use(Character* character)
{
    // 캐릭터의 코딩력 증가시킴
    character->IncreaseCodingPower(codingIncrease);

    // 코딩력 증가 메시지 출력
   cout << name << "사용 : 코딩력이 " << codingIncrease << " 만큼 증가했습니다!" << endl;
}

// Tutor에 대한 Use 구현 - 아무 효과 없음
void CodingBooster::Use(Tutor* tutor)
{
    // 튜터에게는 효과가 없음을 알리는 메시지
   cout << name << "은(는) 튜터에게 효과가 없습니다." << endl;
}
