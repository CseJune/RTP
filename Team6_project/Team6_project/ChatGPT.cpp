#include "ChatGPT.h"
#include "Character.h"
#include <iostream>

using namespace std;

ChatGPT::ChatGPT() : name("ChatGPT"){}

// 아이템 이름 반환
string ChatGPT::GetName() const
{
    return name;
}
