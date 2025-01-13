#include "ChatGPT.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>

using namespace std;

ChatGPT::ChatGPT() : name("ChatGPT") {}

string ChatGPT::GetName() const
{
    return name;
}

void ChatGPT::Use(Character* character)
{
    //cout << "✅ " << name << " 사용: 코드 분석을 도와드리겠습니다!" << endl;
}

void ChatGPT::Use(Tutor* tutor)
{
    //cout << "❌ " << name << "은(는) 튜터에게 효과가 없습니다." << endl;
}
