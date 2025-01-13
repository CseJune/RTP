#include "ChatGPT.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>

using namespace std;

// 생성자 : 이름 초기화
ChatGPT::ChatGPT() : name("ChatGPT") {}

// 아이템 이름 반환
string ChatGPT::GetName() const
{
    return name;
}

void ChatGPT::Use(Character* character) // 캐릭터에게 효과 적용
{
    //cout << name << " 사용: 코드 분석을 도와드리겠습니다!" << endl;
}

void ChatGPT::Use(Tutor* tutor) // 튜터에게 효과 적용
{
    //cout << name << "은(는) 튜터에게 효과가 없습니다." << endl;
}
