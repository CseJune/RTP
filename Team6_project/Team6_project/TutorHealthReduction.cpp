#include "TutorHealthReduction.h"
#include "Monster.h" 
#include <iostream>

using namespace std;

// 기본 생성자: 이름과 체력 감소량 초기화
TutorHealthReduction::TutorHealthReduction() : name("코드 정리의 달인"), healthReduction(30){}


// 아이템 이름 반환
string TutorHealthReduction::GetName() const
{
    return name;
}

// 튜터의 체력을 감소시키는 효과 적용
void TutorHealthReduction::Use(Tutor* tutor)
{
    // 튜터의 체력을 감소시킴
    // healthReduction을 튜터에서 구현하고 내용은 인자값만큼 체력 감소시키면 됨
   //tutor->ReduceHealth(healthReduction); // 튜터 체력 감소

    // 튜터 체력 감소 메시지 출력
    //cout << name << " 사용: 튜터의 체력이 " << healthReduction << "만큼 감소했습니다!" << endl;
}
void TutorHealthReduction::Use(Character* character)
{
	//cout << name << "은(는) 캐릭터에게 효과가 없습니다." << endl;
}   