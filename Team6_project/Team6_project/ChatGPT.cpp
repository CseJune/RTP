#include "ChatGPT.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>
#include "Logger.h"
using namespace std;

// 생성자 : 이름 초기화
ChatGPT::ChatGPT() : name("ChatGPT") {}

// 아이템 이름 반환
string ChatGPT::GetName() const
{
    return name;
}

// 아이템 설명 반환
string ChatGPT::GetDescription() const
{
    return "레벨을 1 증가시켜주는 아이템";
}

void ChatGPT::Use(Character* character) // 캐릭터에게 효과 적용
{
    cout << name << " 사용: 레벨 업! 이제부터 보스와의 전투가 가능합니다." << endl;
	writeLog(name + " 사용: 레벨 업! 이제부터 보스와의 전투가 가능합니다.");

    int level = character->getLevel();
    character->setLevel(level + 1);
}

void ChatGPT::Use(Tutor* tutor) // 튜터에게 효과 적용
{
    //cout << name << "은(는) 튜터에게 효과가 없습니다." << endl;
}
