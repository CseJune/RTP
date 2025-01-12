#include "TutorAttackReduction.h"
#include "Monster.h"
#include <iostream>

using namespace std;

// 기본 생성자: 이름과 공격력 감소량 초기화
TutorAttackReduction::TutorAttackReduction() : name("노이즈 캔슬링 헤드셋"),attackReduction(15){}

// 아이템 이름 반환
string TutorAttackReduction::GetName() const
{
    return name;
}

// 튜터의 공격력을 감소시키는 효과 적용
void TutorAttackReduction::Use(Tutor* tutor)
{
    // 튜터의 공격력 감소시킴
    // reduceAttack을 튜터에서 구현하고 내용은 인자값만큼 공격력 감소시키면 됨
    // tutor->reduceAttackDamage(attackReduction);   // 공격력 감소

    // 튜터 공격력 감소 메시지 출력
    cout << "✅" << name << "사용 : 튜터의 공격력이 " << attackReduction << " 만큼 감소했습니다!" << endl;
}

// Character에 대한 Use 구현 - 아무 효과 없음
void TutorAttackReduction::Use(Character* character)
{
    cout << "❌ " << name << "은(는) 캐릭터에게 효과가 없습니다." << endl;
}


