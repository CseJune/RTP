#include "CodingBooster.h"
#include "Character.h"
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
    // IncreaseCodingPower를 캐릭터에서 구현하고 내용은 인자값만큼 코딩력을 증가시키면 됨
    character->IncreaseCodingPower(codingIncrease);

    // 코딩력 증가 메시지 출력
    cout << "✅" << name << "사용 : 코딩력이 " << codingIncrease << " 만큼 증가했습니다!" << endl;
}
